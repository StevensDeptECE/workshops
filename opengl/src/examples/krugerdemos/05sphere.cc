#include <GL/glew.h>
#include "Shape.hh"
#include "common/common.hh"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <numbers>
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <string>

using namespace std;
using namespace std::numbers;
/**
 * @brief Represent a unit sphere in OpenGL. Right now we have an r, but will show it is not useful
 */
class Sphere : public Shape {
 private:
	uint32_t vbo; // handle to the point data on the graphics card
	//TODO: get rid of sbo and just darw the whole vbo array (2 triangles)
  uint32_t lbo; // handle to buffer of indices for lines for wireframe sphere

  uint32_t vaoSolid; // handle to the vao containing points and solid indices to draw solids
	uint32_t sbo; // handle to list of triangles to draw on graphics card
  uint32_t latRes, lonRes;
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
	void initSolid();
  void render(glm::mat4& projection) override;
  void cleanup() override;

  void renderPoints(glm::mat4& proj) const;
  void renderGrid(glm::mat4& proj) const;
  void renderSolid(glm::mat4& proj) const;
  void renderTexture(glm::mat4& proj) const;
};

using namespace std;
//using namespace std::numbers;
uint32_t progid;

Sphere::Sphere(double r, uint32_t latRes, uint32_t lonRes) : latRes(latRes), lonRes(lonRes),
   resolution((2*latRes-2)*lonRes + 2) {
	progid = loadShaders( "05_3d.vert", "02simple.frag" );
  double dlon = 2.0*pi / lonRes, dlat = pi / latRes;
  double z;
  double lat = -pi/2 + dlat; // latitude in radians
  double rcircle;
  float vert[resolution*3]; // float* vert = new float[(2*latRes-2)*lonRes + 2]; will delete at the end automatically
  uint32_t c = 0;
  for (uint32_t j = 0; j < 2*latRes-2; j++, lat += dlat) {
    //what is the radius of hte circle at that height?
    rcircle = r* cos(lat); // size of the circle at this latitude
    z = r * sin(lat); // height of each circle
    double t = 0;
    cout << setprecision(2) << "z=" << z << ": ";
    for (uint32_t i = 0; i < lonRes; i++, t += dlon) {
      vert[c++] = rcircle * cos(t);
      vert[c++] = rcircle * sin(t);
      vert[c++] = z;
      if (!(i % 5))
        cout << setprecision(2) << "<" << vert[c - 2] << " " << vert[c-1] << "> ";
    }
    cout << endl;
  }
  // south pole
  vert[c++] = 0;
  vert[c++] = 0;
  vert[c++] = -r;
  
  // north pole
  vert[c++] = 0;
  vert[c++] = 0;
  vert[c++] = r;

  cout << "resolution: " << resolution << endl;
  cout << "predicted num vert components: " << resolution*3 << endl;  
  cout << "actual num vert components: " << c << endl;

  glGenVertexArrays(1, &vao);  // Creating rect VAO
  glBindVertexArray(vao);
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, resolution, vert, GL_STATIC_DRAW);
  glBindVertexArray(0);
}

void Sphere::init() {
	//initPoints();
	//initGrid();
	//initSolid();
}

void Sphere::initSolid() {
	glGenVertexArrays(1, &vaoSolid);  // Creating rect VAO
  glBindVertexArray(vaoSolid);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glGenBuffers(1, &sbo); // solid index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sbo); 
  uint32_t solidIndices[2*resolution];
	uint32_t c = 0;
	for (uint32_t i = 0; i < 2*lonRes; i += 2, c++) {
    solidIndices[i] = c;
	  solidIndices[i+1] = c + lonRes;
	}
  glBufferData(GL_ARRAY_BUFFER, 2*lonRes, solidIndices, GL_STATIC_DRAW);
  glBindVertexArray(0);
}

void Sphere::render(glm::mat4& projection) {
  renderPoints(projection);
  renderGrid(projection);
  //renderSolid(projection);
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
	uint32_t matrixID = glGetUniformLocation(progid, "trans");
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &proj[0][0]);

	uint32_t colorID = glGetUniformLocation(progid, "solidColor");
	glUniform4f(colorID, 1,0,0,1);

  glBindVertexArray(vao);
	glVertexAttribPointer(
   	0,                  // first parameter to shader, numbered 0
		3,                  // 3 floating point numbers (x,y,z)
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // this is the entire set of data, move on
	  (void*)0            // array buffer offset
	);
  glEnableVertexAttribArray(0); // pass x,y to shader

  glEnable(GL_PROGRAM_POINT_SIZE);

  glDrawArrays(GL_POINT, 0, resolution);
	glDrawArrays(GL_LINE_STRIP, 0, resolution);
  //dump(proj);
  //apply(proj, glm::vec4(0.0f,0.0f,0.0f,1.0f));
 // apply(proj, glm::vec4(3.0f,0.0f,0.0f,1.0f));
  glDisableVertexAttribArray(0);
}

void Sphere::renderGrid(glm::mat4& proj) const {

}
void Sphere::renderSolid(glm::mat4& proj) const {
	uint32_t matrixID = glGetUniformLocation(progid, "trans");
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &proj[0][0]);

//	uint32_t colorID = glGetUniformLocation(progid, "solidColor");
//	glUniform4f(colorID, 1,0,0,1);

  glBindVertexArray(vaoSolid);
	glVertexAttribPointer(
   	0,                  // first parameter to shader, numbered 0
		3,                  // 3 floating point numbers (x,y,z)
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // this is the entire set of data, move on
	  (void*)0            // array buffer offset
	);
  glEnableVertexAttribArray(0); // pass x,y to shader

  glEnable(GL_PROGRAM_POINT_SIZE);

  glDrawElements(GL_TRIANGLE_STRIP, 2*lonRes, GL_UNSIGNED_INT, (void*)0);
	glDisableVertexAttribArray(0);
  glBindVertexArray(0);
}
void Sphere::renderTexture(glm::mat4& proj) const {
  
}

void Sphere::cleanup() {
	glDeleteBuffers(1, &vbo);	// remove vbo memory from graphics card
	glDeleteVertexArrays(1, &vao); // remove vao from graphics card
}

using namespace std;

void glmain() {
	win = createWindow(1000, 800, "Sphere demo");

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);	// Dark blue background

	// Create and compile our GLSL program from the shaders
	Sphere sphere(1.0, 30, 15);
	sphere.init();
	glm::mat4 trans(0.5);    // default should be identity matrix
  //trans = glm::ortho(-3, +3, -3, +3, -5, 100);
	glm::vec3 eye(10,5,10);
	do {
		glClear( GL_COLOR_BUFFER_BIT );  	// Clear the screen
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDisable(GL_DEPTH_TEST);
		//glDepthFunc(GL_LESS);
		trans= glm::lookAt(glm::vec3(0,0,0), eye, glm::vec3(0,1,0));

		glUseProgram(progid);      		// Use the shader
		sphere.render(trans);
		glfwSwapBuffers(win);             // double buffer
		glfwPollEvents();
		eye.z -= 0.01;
	}	while( glfwGetKey(win, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
					 glfwWindowShouldClose(win) == 0 );
	sphere.cleanup();
	glDeleteProgram(progid);
}
