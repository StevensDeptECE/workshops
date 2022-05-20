# in C++  f(void) --> _Z1fv
#//https://www.oreilly.com/library/view/c-cookbook/0596007612/ch01s05.html

DEBUG	:=	-g
CXX	:=	g++ $(DEBUG)
LIBS	:=	-Lopenssl -lssl -lcrypto
# example of building a static library
libdov.a: makingalibrary.c
	gcc -O2 -c makingalibrary.c	#the library code is C!!!
	ar r libdov.a makingalibrary.o

# example of building c++ code using a static library
mycode: mycode.cc libdov.a
	$(CXX) -O2 $< -L . -ldov  #look for library libdov.a in the current dir
	#link to the C library code from c++

# example of building adynamic library
libdov.so: makingalibrary.c
	gcc -O2 -c -fPIC makingalibrary.c  #the library code is C!!!
	g++ -shared makingalibrary.o -o libdov.so

# example of building C++ code using the dynamic library
mycode2: mycode.cc libdov.so
	$(CXX) -O2 mycode.cc -o mycode2 -Bdynamic -L . -ldov   #look for library libdov.so


sslclient: sslclient.cc
	$(CXX) $< -o $@ $(LIBS)

aes_decryption: aes_decryption.cc
	$(CXX) $< -o $@ $(LIBS)

bio_connect: bio_connect.cc
	$(CXX) $< -o $@ $(LIBS)

fastrandtest: fastrandtest.cc
	g++ -g -mavx2 -O2 -m64 -mrdseed -mrdrnd $< -o $@ -lcrypto
	g++ -O2 -mavx2 -S -m64 -mrdseed -mrdrnd $<

fastudpsecure: fastudpsecure.cc
	g++ -g -m64 -mrdrnd $< -o $@ -lcrypto

clean:
	rm *.o *~ libdov.a libdov.so aes_decryption fastrandtest
