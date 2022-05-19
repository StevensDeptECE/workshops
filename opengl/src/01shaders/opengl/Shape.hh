#pragma once
#include <cstdint>

class Inputs;
class Canvas;
class GLWin;
class Shape {
 protected:
  uint32_t vao;
 public:
  Shape();
  virtual ~Shape();

  /**
   * @brief Get a pointer to the GLWin object
   * 
   * @return GLWin* Window containing the Shape
   */
  GLWin* getWin() const;

	/**
	 * @brief Get a pointer to the GLWin object
	 */
  virtual void init() = 0;
  virtual void render(glm::mat4& proj) = 0;
  virtual void update() = 0;
  virtual void cleanup() = 0;
};
