COMP	:= g++ -g -I/usr/include/GL  #-Iinclude  add any directory you want...
# -O3 max optimization


ifeq ($(OS),Windows_NT)
	LIBS	:= -I/mingw64/include/GL -L/mingw64/lib -lOpenGL32 -lglfw3
else
	# assuming if not windows, then linux. This will break for unsupported OS or OS that does not declare properly. This will break on OSX.
	LIBS	:=	-lGL -lglfw -lGLEW
endif

# LIBS := -lfreeglut -lopengl32 -lGLU32 -Wl,--subsystem,windows -mwindows
#sudo apt install freeglut3-dev libglu-dev

triangle: triangle.cpp
	$(COMP) triangle.cpp -o triangle $(LIBS)
