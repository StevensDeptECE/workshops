#include "opengl/GrailGUI.hh"
#include "opengl/Image.hh"
#include <numbers>
using namespace std;
using namespace grail;
using namespace glm;

void grailmain(int argc, char* argv[], GLWin* w, Tab* t) {
  w->setTitle("transformations");
  w->setSize(1024, 800);
  MainCanvas* c = w->getMainCanvas();
  
  constexpr float PI = std::numbers::pi;
  mat4& proj = *c->getProjection();
#if 0
  {
    proj = translate(proj, vec3(300,300,0));
  }
#endif
#if 0
  {
    proj = translate(proj, vec3(300,300,0));
    proj = rotate(proj, PI/6, vec3(0,0,1));
  }
  #endif
#if 1
  {
    proj = translate(proj, vec3(150,150,0));
    //proj = rotate(proj, -PI/12, vec3(1,0,0));
  }
#endif
#if 0
  {
    proj = translate(proj, vec3(300,300,0));
    //proj = rotate(proj, -PI/12, vec3(1,0,0));
  }
#endif
  Image* img = c->addLayer(new Image(100, 100, 400, 400, "river.webp"));
}
