#include "opengl/StyledMultiShape2D.hh"
#include "util/DynArray.hh"

class ModifiableMultiShape : StyledMultiShape2D {
private:
  struct SolidInfo {
    uint32_t startVertex; // starting position within vertices
    uint32_t size; // how many floating point numbers does this use?
    uint32_t startSolidIndex; // start position in sbo
    uint32_t solidSize;
  };
  struct LineInfo {
    uint32_t startVertex; // starting position within vertices
    uint32_t size; // how many floating point numbers does this use?
    uint32_t startLineIndex; // start position in lbo
    uint32_t lineSize;
  };
  DynArray<SolidInfo> solidList;
  DynArray<LineInfo> lineList;
public:
// create a rectangle, returning a handle to delete it if needed?
  uint32_t fillRectangle(...) {
    uint32_t index = solidList.size();
    solidList.add(SolidInfo( , , ,  ));
    // change StyledMultiShape2d so if you are bigger than the original size, reallocate
    StyledMultiShape2D::fillRectangle (...)
    return index; // solidList.size() - 1;
  }

//TODO: come up with easy API to modify existing StyledMultiShape2Ds...
  void removeSolid(uint32_t index) {}
  void removeLastSolid() {}
  void removeLastLine() {}  

};