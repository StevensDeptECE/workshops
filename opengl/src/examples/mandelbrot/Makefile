.PHONY: all run clean

SOURCE := Source.cpp
BINARY := Mandelbrot
DEPS   := glfw3 glew

CFLAGS := -Wall -g
#LIBS   := $(shell pkg-config --static --cflags --libs $(DEPS))
LIBS   := $(shell pkg-config --cflags --libs $(DEPS))

ifeq ($(OS),Windows_NT)
	LIBS	:= -I/mingw64/include/GL -L/mingw64/lib -lOpenGL32 $(LIBS)
else
	# assuming if not windows, then linux. This will break for unsupported OS or OS that does not declare properly. This will break on OSX.
	LIBS	:= -lGL $(LIBS)
endif

all: $(BINARY)

$(BINARY): $(SOURCE) mandelbrot.vs.hh mandelbrot.fs.hh
	$(CXX) $(CFLAGS)  -o $@ $^ $(LIBS)

run:
	./$(BINARY)

clean:
	rm -f ./$(BINARY)
