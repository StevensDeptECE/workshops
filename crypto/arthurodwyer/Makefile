CXX	:= g++ -g
LIBS	:= -L openssl -lssl -lcrypto

server: server.cc
	$(CXX) $< -o $@

client: client.cc
	$(CXX) $< -o $@
