CXX	:= g++ -g
LIBS	:= -lssl -lcrypto

all: http_server http_client https_server https_client

bare_https_server: bare_https_server.cc
	g++ -g $< -o $@ -L../openssl -lssl -lcrypto

bare_https_client: bare_https_client.cc
	g++ -g $< -o $@ -L../openssl -lssl -lcrypto

server-cert.pem:
	openssl req -newkey rsa:2048 -nodes -keyout server-private.pem -x509 -days 365 -out server-cert.pem


http_server: http_server.cc
	$(CXX) $< -o $@

http_client: http_client.cc
	$(CXX) $< -o $@

https_server: https_server.cc
	$(CXX) $< -o $@

https_client: https_client.cc
	$(CXX) $< -o $@

proxy_server: proxy_server.cc
	$(CXX) $< -o $@

proxy_client: proxy_client.cc
	$(CXX) $< -o $@

clean:
	rm *.o *~ http_server http_client https_server https_client proxy_client proxy_server
