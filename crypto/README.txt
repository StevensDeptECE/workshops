gcc c compiler
g++ same compiler, c++

.cc  .cpp --> compile in C++

openssl is all in C

-g debugging
-O2 optimziation (we won't)

Windows: .dll (dynamic link Library)
Linux    .a  (archive = collection of .o files)
	 .so

libssl.a
libssl.so
libssl.so.1

g++ -g code.cc -lssl --> merge code.o with whatever it needs from libssl.a

