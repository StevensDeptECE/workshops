#include "glheaders.hh"

// A simple introductory program; its main window contains a static picture
// of a triangle, whose three vertices are red, green and blue.  The program
// illustrates viewing with default viewing parameters only.

// Clears the current window and draws a triangle.
void display() {

  // Set every pixel in the frame buffer to the current clear color.
  glClear(GL_COLOR_BUFFER_BIT);

  // by default the screen coordinates are x = [-1, 1], y = [-1, 1]
  glBegin(GL_POLYGON); // create a filled convex polygon.
  //glBegin(GL_LINE_LOOP); // try this instead of polygon
    glColor3f(0, 1, 0);  // set the color once to red
    glVertex2f(-0.8, 0.8); // specify 4 2_D points to create a quadrilateral
    glVertex2f(0.8, -0.9);
    glVertex2f(-0.6, -0.75);
    glVertex2f(0.9, 0.85);
  glEnd();

  // Flush drawing command buffer to make drawing happen as soon as possible.
  glFlush();
}

void init() {}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// enters the main event loop.
int main(int argc, char** argv) {

  // Use a single buffered window in RGB mode (as opposed to a double-buffered
  // window or color-index mode).
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  // Position window at (80,80)-(480,380) and give it a title.
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(400, 300);
  glutCreateWindow("Bad Quad");

  // Tell GLUT that whenever the main window needs to be repainted that it
  // should call the function display().
  glutDisplayFunc(display);

  // Tell GLUT to start reading and processing events.  This function
  // never returns; the program only exits when the user closes the main
  // window or kills the process.
  glutMainLoop();
}
