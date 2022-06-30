#include <GL/glew.h>
#include "Shape.hh"
#include "common/common.hh"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
//#include <numbers>
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <string>

using namespace std;
#define pi 3.14159265358979
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

  void init() override;
  void render(glm::mat4& projection) override;
  void update() override;
  void cleanup() override;

  void renderPoints(glm::mat4& proj) const;
  void renderGrid(glm::mat4& proj) const;
  void renderSolid(glm::mat4& proj) const;
  void renderTexture(glm::mat4& proj) const;
};

using namespace std;
//using namespace std::numbers;
uint32_t progid;

Sphere::Sphere(double r, uint32_t latRes, uint32_t lonRes) : resolution((2*latRes-2)*lonRes + 2) {
	progid = loadShaders("02simple.vert", "02simple.frag");
  double dlon = 2*pi / lonRes, dlat = pi / latRes;
  glGenVertexArrays(1, &vao);  // Creating rect VAO
  glBindVertexArray(vao);
  double z;
  double lat = -pi/2 + dlat;
  double rcircle;
  float vert[resolution*3]; // float* vert = new float[(2*latRes-2)*lonRes + 2]; will delete at the end automatically
  uint32_t c = 0;
  for (uint32_t j = 0; j < 2*latRes-2; j++, lat += dlat) {
    //what is the radius of hte circle at that height?
    rcircle = r* cos(lat);
    z = r * sin(lat);
    double t = 0;
    for (uint32_t i = 0; i < lonRes; i++, t += dlon) {
      vert[c++] = rcircle * cos(t);
      vert[c++] = rcircle * sin(t);
      vert[c++] = z;
    }
  }
  // south pole
  vert[c++] = 0;
  vert[c++] = 0;
  vert[c++] = -r;
  
  // north pole
  vert[c++] = 0;
  vert[c++] = 0;
  vert[c++] = r;
  
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, resolution, vert, GL_STATIC_DRAW);
  glBindVertexArray(0);
}

void Sphere::init() {
}

void Sphere::render(glm::mat4& projection) {
  renderPoints(projection);
  renderGrid(projection);
  renderSolid(projection);
  renderTexture(projection);
}

void dump(const glm::mat4& m) {
  cout << setprecision(8)
   << setw(14) << m[0][0] << setw(14) << m[0][1] << setw(14) << m[0][2] << setw(14) << m[0][3] << endl
   << setw(14) << m[1][0] << setw(14) << m[1][1] << setw(14) << m[1][2] << setw(14) << m[1][3] << endl
   << setw(14) << m[2][0] << setw(14) << m[2][1] << setw(14) << m[2][2] << setw(14) << m[2][3] << endl
   << setw(14) << m[3][0] << setw(14) << m[3][1] << setw(14) << m[3][2] << setw(14) << m[3][3] << endl;
}

void apply(const glm::mat4& m, const glm::vec4& v) {
  glm::vec4 v4 = m * v;
  cout << "x=" << v4.x << ", y=" << v4.y << ", z=" << v4.z << endl;
}
void Sphere::renderPoints(glm::mat4& proj) const {
	uint32_t matrixID = glGetUniformLocation(progid, "transform");
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &proj[0][0]);

	uint32_t colorID = glGetUniformLocation(progid, "solidColor");
	glUniform4f(colorID, 0,0,0,1);
  glBindVertexArray(vao);

  glPointSize(5);
  glDrawArrays(GL_POINT, 0, resolution);
  dump(proj);
  //apply(proj, glm::vec4(0.0f,0.0f,0.0f,1.0f));
 // apply(proj, glm::vec4(3.0f,0.0f,0.0f,1.0f));
}

void Sphere::renderGrid(glm::mat4& proj) const {

}
void Sphere::renderSolid(glm::mat4& proj) const {

}
void Sphere::renderTexture(glm::mat4& proj) const {
  
}

void Sphere::update() {

}

void Sphere::cleanup() {
	glDeleteBuffers(1, &vbo);	// remove vbo memory from graphics card
	glDeleteVertexArrays(1, &vao); // remove vao from graphics card
}

using namespace std;

void glmain() {
	win = createWindow(1000, 800, "Gouraud triangle demo");

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);	// Dark blue background

	// Create and compile our GLSL program from the shaders
	uint32_t programID = loadShaders( "02simple.vert", "02simple.frag" );
	Sphere sphere(3.0, 15, 20);
	glm::mat4 trans;    // default should be identity matrix
  trans = glm::ortho(-3, +3, -3, +3, -5, 100);
	do {
		glClear( GL_COLOR_BUFFER_BIT );  	// Clear the screen
		glUseProgram(programID);      		// Use the shader
		sphere.render(trans);
		glfwSwapBuffers(win);             // double buffer
		glfwPollEvents();
	}	while( glfwGetKey(win, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
					 glfwWindowShouldClose(win) == 0 );
	sphere.cleanup();
	glDeleteProgram(programID);
}
