COMP	:= g++ -g -I/usr/include/GL
LIBS	:= -lGL -lglut -lGLU

all:00triangle 01tetrahedron 02torus 03colorcube_flyby 04sierpinski 05comet

00triangle: 00triangle.cc
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
