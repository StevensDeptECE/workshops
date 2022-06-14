.PHONY: all run clean

SOURCE := Source.cpp
BINARY := Mandelbrot
DEPS   := glfw3 glew

CFLAGS := -Wall
#LIBS   := $(shell pkg-config --static --cflags --libs $(DEPS))
LIBS   := $(shell pkg-config --cflags --libs $(DEPS))

all: $(BINARY)

$(BINARY): $(SOURCE) mandelbrot.vs.hh mandelbrot.fs.hh
	$(CXX) $(CFLAGS)  -o $@ $^ $(LIBS)

run:
	./$(BINARY)

clean:
	rm -f ./$(BINARY)
