COMP	:= g++ -g -I/usr/include/GL  #-Iinclude  add any directory you want...
# -O3 max optimization


ifeq ($(OS),Windows_NT)
	LIBS	:= -I/mingw64/include/GL -L/mingw64/lib -lOpenGL32 -lfreeglut -lGLU32
else
	# assuming if not windows, then linux. This will break for unsupported OS or OS that does not declare properly. This will break on OSX.
	LIBS	:=	-lGL -lglut -lGLU 
endif

# LIBS := -lfreeglut -lopengl32 -lGLU32 -Wl,--subsystem,windows -mwindows
#sudo apt install freeglut3-dev libglu-dev

all: 00a_quad 00b_triangle 01tetrahedron 02torus 03colorcube_flyby 04sierpinski 05comet 07moonphases 08bouncingball

00a_quad: 00a_quad.cc glheaders.hh
	$(COMP) $< -o $@ ${LIBS}

00b_triangle: 00b_triangle.cc glheaders.hh
	$(COMP) $< -o $@ $(LIBS)

01tetrahedron: 01tetrahedron.cc glheaders.hh
	$(COMP) $< -o $@ $(LIBS)

02torus: 02torus.cc glheaders.hh
	$(COMP) $< -o $@ $(LIBS)

03colorcube_flyby: 03colorcube_flyby.cc glheaders.hh
	$(COMP) $< -o $@ $(LIBS)

04sierpinski: 04sierpinski.cc glheaders.hh
	$(COMP) $< -o $@ $(LIBS)

05comet: 05comet.cc glheaders.hh
	$(COMP) $< -o $@ $(LIBS)

07moonphases: 07moonphases.cc glheaders.hh
	$(COMP) $< -o $@ $(LIBS)

08bouncingball: 08bouncingball.cc glheaders.hh
	$(COMP) $< -o $@ $(LIBS)
