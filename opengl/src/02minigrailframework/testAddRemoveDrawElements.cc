#include "opengl/GrailGUI.hh"
#include "ModifiableMultiShape.hh"
using namespace std;
using namespace grail;

class ReactingToInput : public Member {
  private:
    ModifiableMultiShape *m;
    float y = 0;
  public:
  ReactingToInput(Tab* t) : Member(t, -1, 0) {
    MainCanvas* c = t->getMainCanvas();
    m = c->addLayer(new ModifiableMultiShape());
    m->fillRectangle(500, 600, 200, 200, red);
  }

  void addNewRectangle() {
    handle = m->fillRectangle(10, y, 200, 200, red);
    y += 50;
    m->update();
  }
  void removeLastRectangle() {
     // remove the last one on the list in ModifiableMultiShape?
    
  }

}

void grailmain(int argc, char* argv[], GLWin* w, Tab* t) {
  w->setTitle("Simple add and remove draw elements");
  w->setSize(1024,800);
  new ReactingToInput(t);
}
