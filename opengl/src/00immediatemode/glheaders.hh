/*
	This is the standard set of OpenGL headers used in these demos.

	The purpose of these demos is to clean up and make everything as simple
	as possible for getting started.

	All programs use the old immediate OpenGL API where the computer
	transfers points to the graphics card every time rendering is done.
	It was only later that OpenGL morphed into a far more efficient, but
	unfortunately also dramatically more complicated API where we
	download data to the card, and then can render it without
	intervention from the main program.
	
	The reason these demos are here is that all the basic drawing operations

	* clipping
	* colors
  * most drawing primitives
	* transformation
  * materials and lighting

	are the same, so it's easier to show them here without additional
	complication.

	Cleaned up by Dov Kruger
	Original code at: https://cs.lmu.edu/~ray/notes/openglexamples/

 */
#include "glut.h"
#include <gl.h>
#include <cmath>

typedef void (*reshape_callback)(GLint w, GLint h);
typedef void (*display_callback)();

void init();
inline void init_app(int argc, char** argv, int x, int y, int w, int h, const char title[],
							reshape_callback reshape, display_callback display) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(x, y);
  glutInitWindowSize(w, h);
  glutCreateWindow(title);
	if (reshape != nullptr)
		glutReshapeFunc(reshape);
	if (display != nullptr)
    glutDisplayFunc(display);
  init();
  glutMainLoop();
}
