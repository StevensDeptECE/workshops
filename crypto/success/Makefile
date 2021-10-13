#
# Dov Kruger
# you leave this stuff for 10 minutes and forget everything!
# here's the scoop
#
# 
#
#

all: dovhttpclient decryptaes256example

# this requires openssl1.1  don't know if it will work with openssl3, that
# evidently changed a lot

# these libraries had to be installed on ubuntu
# sudo apt install libssl-dev
dovhttpclient: dovhttpclient.cc
	g++ -g $< -lssl -lcrypto  #note you have to include crypto, not just ssl!


#example decrypting hardcoded string. encrypt is available on command line in openssl encrypt file

decryptaes256example: decryptaes256example.cc
	g++ -g decryptaes256example.cc -lssl -lcrypto
