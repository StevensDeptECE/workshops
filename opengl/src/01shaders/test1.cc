#include "opengl/GrailGUI.hh"
#include "opengl/Image.hh"

using namespace std;
using namespace grail;

class TestImage : public Member {
 public:
  TestImage(Tab* tab) : Member(tab, -1, 0) {
    MainCanvas* c = tab->getMainCanvas();
    StyledMultiShape2D* gui = c->getGui();
    gui->fillRectangle(500, 600, 200, 200, red);

    Image* img = c->addLayer(new Image(100, 100, 200, 200, "river.webp"));
  }
};

void grailmain(int argc, char* argv[], GLWin* w, Tab* t) {
  w->setTitle("Simple Grail Test");
  w->setSize(1024, 800);
  new TestImage(t);
}
