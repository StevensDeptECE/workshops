#include "glheaders.hh"

/*
	 Simple introduction to 3d projection using gluLookAt() which allows
   specifying the viewpoint of the camera and the volume being looked at.
   This is conceptually simpler than transforming
	 objects to move into a predefined view volume.
*/

// Clears the window and draws the torus.
void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0, 1.0, 1.0);// draw in white
  glutWireTorus(0.5, 3, 15, 30);// innerradius=0.5, outer radius=3
	// 15 stacks and 30 slices.


  // Draw a red x-axis, a green y-axis, and a blue z-axis.  Each of the
  // axes are ten units long.
  glBegin(GL_LINES);
    glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(10, 0, 0);
    glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 10, 0);
    glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 10);
  glEnd();

  glFlush();
}

// Sets up global attributes like clear color and drawing color, and sets up
// the desired projection and modelview matrices.
void init() {

  // Set the current clear color to black and the current drawing color to
  // white.
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glColor3f(1.0, 1.0, 1.0);

  // Set the camera lens to have a 60 degree (vertical) field of view, an
  // aspect ratio of 4/3, and have everything closer than 1 unit to the
  // camera and greater than 40 units distant clipped away.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 4.0/3.0, 1, 40);

  // Position camera at (4, 6, 5) looking at (0, 0, 0) with the vector
  // <0, 1, 0> pointing upward.
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(4, 6, 5, 0, 0, 0, 0, 1, 0);
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 600);
  glutCreateWindow("A Simple Torus");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}

