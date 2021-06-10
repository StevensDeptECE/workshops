#include <memory>
#include <signal.h>
#include <stdexcept>
#include <cstring>
#include <string>
#include <unistd.h>
#include <iostream>
#include <exception>

#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/ssl.h>

using namespace std;
#include "serverinfo.hh"
const char server_private[] = "server-private.pem";

void server() {
  SSL_CTX* ctx =  SSL_CTX_new(TLS_method()); // create an SSL context
  SSL_CTX_set_min_proto_version(ctx,  TLS1_2_VERSION);

  if (SSL_CTX_use_certificate_file(ctx, server_cert, SSL_FILETYPE_PEM) <= 0) {
    throw "Error loading server certificate";
  }
  if (SSL_CTX_use_PrivateKey_file(ctx, "server-private.pem", SSL_FILETYPE_PEM) <= 0) {
    throw "Error loading server private key";
  }

  BIO* mainsock = BIO_new_accept(port); // open a socket, listen on 8080
  if (mainsock == nullptr) {
    throw "Error in binding to port";
  }
  char buffer[1024];
  
  while (true) {
    int status = BIO_do_accept(mainsock);
    if (status < 0) 
      throw "Error in accept on socket";
    BIO* ssl = BIO_new_ssl(ctx, 0);
    BIO_push(ssl, mainsock);

    int len = BIO_read(ssl, buffer, sizeof(buffer));
    if (len < 0)
      cerr << "***error in BIO_read\n";
    cout << buffer;
    string body = "testing testing 123";
    string response = "HTTP/1.1 200 OK\nContent-Length: " +std::to_string(body.size()) + "\n\n";
    BIO_write(ssl, response.data(), response.size());
    BIO_write(ssl, body.data(), body.size());
    BIO_flush(ssl);
    BIO_pop(mainsock);
  }
  BIO_free_all(mainsock);
  SSL_CTX_free(ctx);
}

int main() {
  try {
    server();
  } catch (const char msg[]) {
    cerr << msg << '\n';
  } catch (const std::exception& e) {
    cerr << e.what() << '\n';
  } catch (...) {
    cerr << "uncaught exception error\n";
  }
}
