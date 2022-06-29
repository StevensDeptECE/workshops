#include "opengl/GrailGUI.hh"
#include "opengl/Shader.hh"
#include "glad/glad.h"
using namespace std;
using namespace grail;

class CustomShader : public Shape {
private:
  uint32_t shaderID; // the handle to the shader
  uint32_t vbo; // vertex buffer object, holds the points to be drawn
public:
CustomShader() {
  shaderID = Shader::load("gradient.bin", "shaders/Texture.vert", "shaders/01simplegradient.frag");
}

void init() override;
void render(glm::mat4& proj) override;
void update() override;
void cleanup() override;
};

void CustomShader::init() {
  //TODO: add Shape::init(); // call the parent to create a VAO

  glGenVertexArrays(1, &vao);   // Creating rect VAO
  glBindVertexArray(vao);
/*
   1     4 

   2     3

*/
  const float x = 0, y = 0, width = 100, height = 100;
  float vertices[16] = {
  //x        y            u  v  (u,v) is the coordinate in shader world!
  	x,	     y,           0, 0,
    x,       y+height,    0, 1,
    x+width, y,           1, 0,
    x+width, y+height,    1, 1
  };
  glGenBuffers(1, &vbo);  // create vertex buffer object on graphics card
 
  glBindBuffer(GL_ARRAY_BUFFER, vbo); // bind it so it's the current one in use

  // copy the points into it
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);
  // position attribute
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
  // texture coord attribute
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float),
                        (void*)(2 * sizeof(float)));
}

void CustomShader::render(glm::mat4& proj) {
  glBindVertexArray(vao);
  glEnableVertexAttribArray(0); //xy
  glEnableVertexAttribArray(1); //uv
 
  Shader* s = Shader::useShader(shaderID);
  proj = glm::scale(proj, glm::vec3(2,2,0));
  s->setMat4("projection", proj);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(0);
  glBindVertexArray(0);
}

void CustomShader::update() {
}

void CustomShader::cleanup() {
}

void grailmain(int argc, char* argv[], GLWin* w, Tab* t) {
  w->setTitle("Example of custom shader");
  t->setFrameRate(-1); // don't animate, nothing happening
  MainCanvas* c = t->getMainCanvas();  
  CustomShader* cs = c->addLayer(new CustomShader());
  
}
