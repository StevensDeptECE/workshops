#include "glheaders.hh"

// A simple introductory program; its main window contains a static picture
// of a triangle, whose three vertices are red, green and blue.  The program
// illustrates viewing with default viewing parameters only.

// Clears the current window and draws a triangle.
void display() {

  // Set every pixel in the frame buffer to the current clear color.
  glClear(GL_COLOR_BUFFER_BIT);

  // Drawing is done by specifying a sequence of vertices.  The way these
  // vertices are connected (or not connected) depends on the argument to
  // glBegin.  GL_POLYGON constructs a filled convex polygon.
  glColor3f(1, 1, 1);

  glLineWidth(5);
  glBegin(GL_LINES);
    glVertex2f(-0.6, 0.8);  glVertex2f(+0.6, 0.8);
    glVertex2f(-.9, 0);     glVertex2f(+0.9, 0);
    glVertex2f(-1, -0.85);     glVertex2f(+0.9, -.75);
  glEnd();


  glLineWidth(3);
  glColor3f(0.1, 0.2, 1);
  glBegin(GL_LINES);
    glVertex2f(-0.6, 0.6);  glVertex2f(+0.6, 0.6);
    glVertex2f(-.9, 0.3);     glVertex2f(+0.9, 0.2);
    glVertex2f(-1, -0.65);     glVertex2f(+0.9, -.55);
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

  // Position window at (80,80)-(480,300) and give it a title.
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(400, 300);
  glutCreateWindow("Gouraud Shaded Triangle");

  // Tell GLUT that whenever the main window needs to be repainted that it
  // should call the function display().
  glutDisplayFunc(display);

  // Tell GLUT to start reading and processing events.  This function
  // never returns; the program only exits when the user closes the main
  // window or kills the process.
  glutMainLoop();
}
