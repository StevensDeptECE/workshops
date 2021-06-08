CXX	:= g++ -g
LIBS	:= -lssl -lcrypto

all: http_server http_client https_server https_client

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
