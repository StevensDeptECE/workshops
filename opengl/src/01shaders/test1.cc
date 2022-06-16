#include "opengl/GrailGUI.hh"
#include "opengl/Image.hh"

using namespace std;
using namespace grail;

void grailmain(int argc, char* argv[], GLWin* w, Tab* t) {
  w->setTitle("Simple Grail Test");
  w->setSize(1024, 800);
  MainCanvas* c = w->getMainCanvas();
  StyledMultiShape2D* gui = c->getGui();
  gui->fillRectangle(500, 600, 200, 200, red);

  Image* img = c->addLayer(new Image(100, 100, 400, 400, "river.webp"));
}
