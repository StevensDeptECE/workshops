#pragma once

#include <cstdint>
#include <string>

#include "opengl/Shape.hh"

/**
 * @brief Represent a unit sphere in OpenGL. Right now we have an r, but will show it is not useful
 */
class Sphere : public Shape {
 private:
	uint32_t vbo; // handle to the point data on the graphics card
	//TODO: get rid of sbo and just darw the whole vbo array (2 triangles)
  uint32_t lbo; // handle to buffer of indices for lines for wireframe sphere
  double r;
  uint32_t resolution;
  uint32_t textureID; /**< ID associated with the texture we will create */
 public:
  /**
   * @brief Construct a sphere
   *
   * @param r radius of the sphere
   * @param latRes resolution of the grid in latitude
   * @param lonRes resolution of the grid in latitude
   */
  Sphere(double r, uint32_t latRes, uint32_t lonRes);

  /**
   * @brief OpenGL setup for this object, called before rendering
   */
  void init() override;

  /**
   * @brief Renders the sphere
   */
  void render(glm::mat4& projection) override;

  /**
   * @brief If the image is to be modified, update may be written
   *
   */
  void update() override;

	void cleanup() override;
  void renderPoints(glm::mat4& proj) const;
  void renderGrid(glm::mat4& proj) const;
  void renderSolid(glm::mat4& proj) const;
  void renderTexture(glm::mat4& proj) const;

};
