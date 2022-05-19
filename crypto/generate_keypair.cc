#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>

class RSAKeyPair {
private:
	static constexpr int	bits = 2048;
	static constexpr unsigned long e = RSA_F4; // encryption method
	static constexpr int padding = 0; //TODO: what should padding be?
	RSA* rsa;
public:
	RSAKeyPair(const char pubkey[], const char privkey[]) {
		generate_key(pubkey, privkey);
	}
	void generate_key(const char pubkey[], const char privkey[]);

	/*
		Encrypt using keypair.
		Note that RSA is vulnerable to a plaintext attack so only use this
		to encrypt random keys which are then used to encrypt a message
	*/
	void encrypt(uint8_t msg[], uint8_t encrypted[], int len);

	/*
		decrypt using the private key
	 */
	void decrypt(uint8_t msg[], uint8_t decrypted[], int len);

	void sign(uint8_t msg[], uint32_t len,
						uint8_t signature[], uint32_t siglen);
	bool verify_signature(uint8_t msg[], uint32_t len,
												uint8_t signature[], uint32_t siglen);
};
#if 0
 int RSA_sign(int type, unsigned char *m, unsigned int m_len,
    unsigned char *sigret, unsigned int *siglen, RSA *rsa);
 int RSA_verify(int type, unsigned char *m, unsigned int m_len,
    unsigned char *sigbuf, unsigned int siglen, RSA *rsa);
#endif

void RSAKeyPair::sign(uint8_t msg[], uint32_t len,
											uint8_t signature[], uint32_t siglen) {

}

bool RSAKeyPair::verify_signature(uint8_t msg[], uint32_t len,
																	uint8_t signature[], uint32_t siglen) {
	return false;
}


void RSAKeyPair::encrypt(uint8_t msg[], uint8_t encrypted[], int len) {
	int padding = 0; //TODO: what should padding be?
	int ret = RSA_public_encrypt(len, msg, encrypted, rsa, padding);
	if (ret == 0) {
		std::cerr << "RSA encrypt failed";
	}
}

void RSAKeyPair::decrypt(uint8_t msg[], uint8_t encrypted[], int len) {
	uint8_t* decrypted;
	int ret = RSA_private_decrypt(len, msg, decrypted, rsa, padding);
	if (ret == 0) {
		std::cerr << "RSA decrypt failed\n";
	}
}

void RSAKeyPair::generate_key(const char pubkey[], const char privkey[]) {
	// 1. generate rsa key
	BIGNUM* bne = BN_new();
	if (BN_set_word(bne, e) != 1)
		throw "cannot create big number\n";
	RSA* r = RSA_new();
	if ( RSA_generate_key_ex(r, bits, bne, nullptr) != 1)
		throw "cannot generate RSA key\n";
	BIO* bp_public = BIO_new_file(pubkey, "w+");
	if ( PEM_write_bio_RSAPublicKey(bp_public, r) != 1)
		throw "cannot create public key file\n";
	BIO* bp_private = BIO_new_file(privkey, "w+");
	if (PEM_write_bio_RSAPrivateKey(bp_private, r,
																	nullptr, nullptr, 0,
																	nullptr, nullptr) != 1)
		throw "cannot create private key file";
#if 0
	BIO_free_all(bp_public);
	BIO_free_all(bp_private);
	RSA_free(r);
	BN_free(bne);
#endif
}

int main(int argc, char* argv[]) {
	RSAKeyPair keypair("serverpub.pem", "serverpriv.pem");
	return 0;
}

		
