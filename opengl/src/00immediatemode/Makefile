COMP	:= g++ -g -I/usr/include/GL
LIBS	:= -lGL -lglut -lGLU
#sudo apt install freeglut3-dev libglu-dev

all:00a_triangle 00b_triangle 01tetrahedron 02torus 03colorcube_flyby 04sierpinski 05comet

00a_quad: 00a_quad.cc
	$(COMP) $< -o $@ $(LIBS)

00b_triangle: 00b_triangle.cc
	$(COMP) $< -o $@ $(LIBS)

01tetrahedron: 01tetrahedron.cc
	$(COMP) $< -o $@ $(LIBS)

02torus: 02torus.cc
	$(COMP) $< -o $@ $(LIBS)

03colorcube_flyby: 03colorcube_flyby.cc
	$(COMP) $< -o $@ $(LIBS)

04sierpinski: 04sierpinski.cc
	$(COMP) $< -o $@ $(LIBS)

05comet: 05comet.cc
	$(COMP) $< -o $@ $(LIBS)

07moonphases: 07moonphases.cc
	$(COMP) $< -o $@ $(LIBS)

08bouncingball: 08bouncingball.cc
	$(COMP) $< -o $@ $(LIBS)
