#include "opengl/GrailGUI.hh"
#include "opengl/Sphere.hh"

using namespace std;
using namespace grail;

void grailmain(int argc, char* argv[], GLWin* w, Tab* t) {
  w->setTitle("Building a Sphere");
  w->setSize(1024, 1024);
  MainCanvas* c = w->getMainCanvas();
  const Style* s = c->getStyle();
  StyledMultiShape2D* shapes = new StyledMultiShape2D(s);
  shapes->fillCircle(100,100,50,1,grail::red);
  c->addLayer(shapes);

  c->setProjection(
    glm::lookAt(glm::vec3(10,10,20), glm::vec3(0,0,0), glm::vec3(0,1,0))
  );
  #if 0
  c->setLookAtProjection(20,20,30, // camera is at x=20,y=20,z=30 looking down and left
                         0,0,0,     // the point the camera is looking at (0,0,0)
                         0,1,0);    // camera is straight up (upside down would be 0,-1, 0)
  #endif

  //Sphere* s = new Sphere(3, 15, 20);
  //c->addLayer(s);
}
