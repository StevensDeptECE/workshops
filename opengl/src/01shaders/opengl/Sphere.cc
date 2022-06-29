#include <glad/glad.h>
#include "opengl/Sphere.hh"
#include "opengl/Shader.hh"
#include "opengl/GLWin.hh"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <numbers>
#include <iomanip>

using namespace std;
using namespace std::numbers;

Sphere::Sphere(double r, uint32_t latRes, uint32_t lonRes) : resolution((2*latRes-2)*lonRes + 2) {
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
  Shader* s = Shader::useShader(GLWin::COMMON_SHADER);
  s->setMat4("projection", proj);
  s->setVec4("solidColor", glm::vec4(0,0,0,1));
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

}

