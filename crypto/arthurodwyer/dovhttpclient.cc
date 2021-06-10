#include <openssl/bio.h>
#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
	BIO* bio = nullptr;
  const char* url = argc > 1 ?  argv[1] : "duckduckgo.com";
	const char* port = argc > 2 ? argv[2] : "80";
	string urlandport = url;
	urlandport += ":";
	urlandport += port;
	try {
		bio = BIO_new_connect((string(url)+":" + port).c_str());
		if (bio == nullptr) {
			throw "Error in BIO_new_connect";
		}
    if (BIO_do_connect(bio) <= 0) {
			throw "Error in BIO_do_connect";
    }
		string request = "GET / HTTP/1.1\n";
    request += "Host: " + string(url) + "\n\n";

    BIO_write(bio, request.c_str(), request.size());
    BIO_flush(bio);
		constexpr int BUFSIZE = 2048;
		char buffer[BUFSIZE+1];
		buffer[BUFSIZE]='\0';
    int len = BIO_read(bio, buffer, BUFSIZE);
		cout << buffer << '\n';
	} catch(const char msg[]) {
		cerr << msg << '\n';
	}
	if (bio != nullptr)
		BIO_free_all(bio);
}
