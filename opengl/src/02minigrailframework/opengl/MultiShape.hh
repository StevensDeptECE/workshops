#pragma once

#include <vector>

#include "opengl/Shape.hh"

class MultiShape : public Shape {
 protected:
 uint32_t vbo;
 uint32_t sbo; // solid indices
 uint32_t lbo; // line indices
 uint32_t pbo; // point indices
  uint32_t vboCapacity;
  uint32_t sboCapacity;
  uint32_t lboCapacity;
  uint32_t pboCapacity;

  std::vector<float> vertices;
  std::vector<uint32_t> solidIndices;
  std::vector<uint32_t> lineIndices;
  std::vector<uint32_t> pointIndices;
  std::vector<float> colorIndices;

 public:
  MultiShape(uint32_t vertCount = 1024,
             uint32_t solidIndCount = 1024, uint32_t lineIndCount = 1024,
             uint32_t pointIndCount = 1024, uint32_t colorIndCount = 1024)
      : Shape() {
    vertices.reserve(vertCount * 2);
    solidIndices.reserve(solidIndCount);
    lineIndices.reserve(lineIndCount);
    pointIndices.reserve(pointIndCount);
    colorIndices.reserve(colorIndCount);
  }
  ~MultiShape();
  void update() override;
  void updatePoints();
  void updateSolidIndices();
  void updateLineIndices();
  void updatePointIndices();

  void addPoint(float x, float y) {
    vertices.push_back(x);
    vertices.push_back(y);
  }
};
