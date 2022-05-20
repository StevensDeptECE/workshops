// Client side implementation of UDP client-server model
#include <iostream>
//#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <openssl/ec.h>
#include <openssl/ssl.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <immintrin.h>

#define ECCTYPE    "secp521r1"
using namespace std;

class UDPConnect {
private:
  uint64_t randBlock[128]; // 1024 bytes of random scratch memory
  uint64_t r; // random number generated differently than randBlock
  EVP_CIPHER_CTX *ctx;
  EC_KEY*         ecc;
  //  EVP_PKEY_CTX* pctx;
  EVP_PKEY *      pkey;
  struct sockaddr_in	 servaddr; // the server to connect to
  int sock;
  struct Client {
    uint64_t nonce[4]; // 256 bit number
    uint32_t seq;
  };
  Client clients[256]; // create room for some clients to call
  // need compile flag -mrdrnd 

  UDPConnect() : ctx(nullptr), ecc(nullptr), pkey(nullptr)
  { }

  
  static constexpr int BUFSIZE=1024;
  void randomize();
  void getRand() {
    __builtin_ia32_rdrand64_step ((long long unsigned int*)&r);
  }
  void commonInit() {
    randomize(); // generate random bits for use later
    getRand();
    if ( (sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
      throw "socket creation failed";
    }
    memset(&servaddr, 0, sizeof(servaddr));
    //AES-256
    if (nullptr == (ctx = EVP_CIPHER_CTX_new()))
      throw "failed to create new cypher context";
    // assume we set up the right bytes for the key and iv
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
      throw handleOpenSSLErrors();
    EVP_CIPHER_CTX_set_key_length(ctx, EVP_MAX_KEY_LENGTH);


    // ECC
    int eccgrp = OBJ_txt2nid("secp521r1");
    ecc = EC_KEY_new_by_curve_name(eccgrp);

    // For cert signing, use the OPENSSL_EC_NAMED_CURVE flag
    EC_KEY_set_asn1_flag(ecc, OPENSSL_EC_NAMED_CURVE);

    // Create the public/private EC key pair
    if (! (EC_KEY_generate_key(ecc)))
      throw "failed to generate ECC key";

    pkey = EVP_PKEY_new(); // create new public/private keypair
    if (!EVP_PKEY_assign_EC_KEY(pkey, ecc)) // copy in from ecc specific
      throw "failed to copy ECC key into pkey";

    // Extract EC-specifics from the key
    ecc = EVP_PKEY_get1_EC_KEY(pkey); // redundant?
    const EC_GROUP *ecgrp = EC_KEY_get0_group(ecc);

    // display key length and curve type
    cout << "ECC Key size " << EVP_PKEY_bits(pkey) << "bits\n";
    cout << "ECC Key Type " << OBJ_nid2sn(EC_GROUP_get_curve_name(ecgrp)) << '\n';

  }
public:
  ~UDPConnect() {
    if (ctx != nullptr)
      EVP_CIPHER_CTX_free(ctx);
    if (pkey != nullptr)
      EVP_PKEY_free(pkey);
    if (ecc != nullptr)
      EC_KEY_free(ecc);
  }
  
  UDPConnect(UDPConnect&& orig)
    : ctx(orig.ctx), ecc(orig.ecc), pkey(orig.pkey),
      servaddr(orig.servaddr), sock(orig.sock) {
    memcpy(randBlock, orig.randBlock, sizeof(randBlock));
    orig.ctx = nullptr;
    orig.ecc = nullptr;
    orig.pkey = nullptr;
    orig.sock = -1;
  }
  
  static UDPConnect client(const char addr[], int port) {
    UDPConnect conn;
    conn.commonInit(); // do all the setup of random blocks, keys, etc
    // Filling server information
    conn.servaddr.sin_family = AF_INET;
    conn.servaddr.sin_port = htons(port);
    conn.servaddr.sin_addr.s_addr = INADDR_ANY; //TODO: wrong geeksforgeeks...
    return conn;
  }

  static UDPConnect server(const char addr[], int port) {
    UDPConnect conn;
    conn.commonInit();
    // Filling server information
    conn.servaddr.sin_family = AF_INET;
    conn.servaddr.sin_port = htons(port);
    conn.servaddr.sin_addr.s_addr = INADDR_ANY;
    return conn;
  }
  
  void fillRand(char* buf, uint32_t len) {
    memcpy(buf, (char*)randBlock, len); // copy random numbers into desired place
    uint32_t words = (len+7)/8;
    
    int rc = RAND_bytes((uint8_t*)randBlock, len); // refill block with new random numbers
    // modify the generated random by xoring with separately calculated r
    // trust no one. recalculate r at random intervals in background.
    uint64_t* p = randBlock;
    for (uint32_t i = words; i > 0; i--)
      *p++ ^= r;
  }

  void fastContactServer() {
    uint32_t seqNum = 0; // pick random seq number to start
    char buffer[BUFSIZE];
    fillRand((char*)&clients[0], sizeof(Client));
    memcpy(buffer, clients, sizeof(Client));
	
    //    sendto(sock, buffer, strlen(hello), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));
		
    //n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &servaddr, &len);
    //  buffer[n] = '\0';
  }
};

/*
  Start random number generator.
  Seed a block of numbers and use with new random numbers
 */
void UDPConnect::randomize() {
  const RAND_METHOD* rm = RAND_get_rand_method();
  int rc = RAND_set_rand_method(rm);
  //  if (!rc)
  cerr << "Random method set: " << rc << '\n';
  rc = RAND_bytes((uint8_t*)randBlock, sizeof(randBlock)); // fill block with random numbers

  if (!rc) {
    unsigned long err = ERR_get_error();
    cerr << "Error calling RAND_bytes " << err << '\n';
  }  
}



//generic key generation for Diffie Hellman
#if 0
      // generic parameter negotiation. Let's do it manually instead
    /* Use built-in parameters */
    if (nullptr == (params = EVP_PKEY_new()))
      throw "failed to create asymmetric keypair";
    if (1 != EVP_PKEY_assign(params, EVP_PKEY_DHX, DH_get_2048_256())) handleErrors();

/* Create context for the key generation */
if(!(kctx = EVP_PKEY_CTX_new(params, NULL))) handleErrors();

/* Generate a new key */
if(1 != EVP_PKEY_keygen_init(kctx)) handleErrors();
if(1 != EVP_PKEY_keygen(kctx, &dhkey)) handleErrors();

/* Optional : useful if you want to check your private key*/
BIO* fp = BIO_new_fp(stdout, BIO_NOCLOSE);
EVP_PKEY_print_private(fp, dhkey, 0, NULL);
#endif


//ECC horrible instructions from openssl wiki
//poorly documented, seemingly redundant calls
#if 0
    if (nullptr == (pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, nullptr)))
      throw "failed to create ECC key pair mem";
    if(!EVP_PKEY_paramgen_init(pctx)) // redundant with paramgen?
      throw "failed to generate parameter for ECC";
    if(!EVP_PKEY_CTX_set_ec_paramgen_curve_nid(pctx, NID_X9_62_prime256v1))
      throw "failed to generate ECC key";
    if (!EVP_PKEY_paramgen(pctx, &params))
      throw "failed to generate parameters for ecc key";
    if(params != nullptr) {
      if(!(kctx = EVP_PKEY_CTX_new(params, NULL)))
	throw "filed to create new Pkey? WTF?";
    } else {
      /* Create context for the key generation */
      if(!(kctx = EVP_PKEY_CTX_new_id(type, NULL)))
	throw "failed to create new Pkey id? redundant with first call.";
    }
#endif


int main() {
  UDPConnect conn = UDPConnect::client("127.0.0.1", 9090);
}
