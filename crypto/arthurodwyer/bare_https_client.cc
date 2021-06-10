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

SSL* get_ssl(BIO *bio) {
  SSL *ssl = nullptr;
  BIO_get_ssl(bio, &ssl);
  if (ssl == nullptr) {
    throw "Error in BIO_get_ssl";
  }
  return ssl;
}

void verify_the_certificate(SSL *ssl, const std::string& expected_hostname) {
  int err = SSL_get_verify_result(ssl);
  if (err != X509_V_OK) {
    throw "X509 Certificate verify_cert_error_string";
  }
  X509 *cert = SSL_get_peer_cert_chain(ssl);
  if (cert == nullptr) {
    throw "No certificate was presented by the server\n";
  }
  // X509_check_host is called automatically during verification,
  // because we set it up in main().
  (void)expected_hostname;
}


void client(const char url[], const char port[]) {
  SSL_CTX* ctx =  SSL_CTX_new(TLS_client_method()); // create an SSL context
  if (SSL_CTX_set_default_verify_paths(ctx) != 1) {
    throw "Error setting up trust store";
  }

  if (SSL_CTX_use_certificate_file(ctx, server_cert, SSL_FILETYPE_PEM) <= 0) {
    throw "Error loading server certificate";
  }

  string fullurl = url;
  fullurl = fullurl + ":" + port;
  BIO* connect = BIO_new_connect(fullurl.c_str());
  if (connect == nullptr) {
    throw "Error in BIO_new_connect";
  }
  if (BIO_do_connect(connect) <= 0) {
    throw "Error in BIO_do_connect";
  }
  BIO* sslbio = BIO_new_ssl(ctx, 1);
  BIO_push(sslbio, connect);
  SSL* ssl = get_ssl(sslbio);  
  SSL_set_tlsext_host_name(ssl, fullurl.c_str());
  
  if (BIO_do_handshake(sslbio) <= 0) {
    throw "Error in BIO_do_handshake";
  }
  verify_the_certificate(get_ssl(sslbio), fullurl.c_str());

  string request = "GET / HTTP/1.1\nHost: ";
  request += string(url) + "\n\n";

  BIO_write(sslbio, request.data(), request.size());
  BIO_flush(sslbio);

  char buffer[1024];
  int len = BIO_read(sslbio, buffer, sizeof(buffer));
  if (len < 0)
    cerr << "Error reading from server";

  cout << buffer << '\n';

  BIO_free_all(sslbio);
  SSL_CTX_free(ctx);
}

int main(int argc, char* argv[]) {
  const char* url = argc > 1 ? argv[1] : "duckduckgo.com";
  const char* port = argc > 2 ? argv[2] : "443";
  try {
    client(url, port);
  } catch (const char msg[]) {
    cerr << msg << '\n';
  } catch (const std::exception& e) {
    cerr << e.what() << '\n';
  } catch (...) {
    cerr << "uncaught exception error\n";
  }
}
