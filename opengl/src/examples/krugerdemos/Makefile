DEBUG	:=	-g #-std=c++20
OPT	:=	-O2
COMP	:=	g++ $(OPT) $(DEBUG)

ifeq ($(OS),Windows_NT)
	LIBS	:= common.o -I/mingw64/include/GL -L/mingw64/lib -lOpenGL32 -lglfw3 -lglew32
else
	# assuming if not windows, then linux. This will break for unsupported OS or OS that does not declare properly. This will break on OSX.
	LIBS	:= common.o	-lGL -lglfw -lGLEW
endif

all: bin/01window bin/02triangle bin/03gouraud bin/04transform bin/05sphere

#this builds the single common object file used by all demos
#which contains a standard main, loader for shaders,
# and function to open windows
common.o:  common/common.cc common/common.hh
	$(COMP) -c $<

bin/01window: 01window.cc common.o
	$(COMP) $< -o $@ $(LIBS)

bin/02triangle: 02triangle.cc common.o
	$(COMP) $< -o $@ $(LIBS)

bin/03gouraud: 03gouraud.cc common.o
	$(COMP) $< -o $@ $(LIBS)

bin/04transform: 04transform.cc common.o
	$(COMP) $< -o $@ $(LIBS)

bin/05sphere: 05sphere.cc Shape.hh Shape.cc common.o
	$(COMP) $< Shape.cc -o $@ $(LIBS)

#bin/05lights: 05lights.cc common.o
#	$(COMP) $< -o $@ $(LIBS)

clean:
	rm bin/*
