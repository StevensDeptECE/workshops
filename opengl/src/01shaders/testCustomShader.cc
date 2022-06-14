#include "opengl/GrailGUI.hh"
#include "opengl/Shader.hh"
using namespace std;
using namespace grail;

class CustomShader : public Shape {
private:
  uint32_t shaderID; // the handle to the shader
  uint32_t vbo; // vertex buffer object, holds the points to be drawn
public:
CustomShader() {
  shaderID = Shader::load("weather.bin", "common.vert", "weather.frag");
}

void init() override;
void render(glm::mat4& proj) override;
void update() override;
void cleanup() override;
};

void CustomShader::init() {
  Shape::init(); // call the parent to create a VAO
  float vertices[16] = {
  	x,	     y,           0, 0,
    x,       y+height,    0, 1,
    x+width, y,           1, 0,
    x+width, y+height,    1, 1
  };
  glGenBuffers(1, &vbo);  // create vertex buffer object on graphics card
 
  glBindBuffer(GL_ARRAY_BUFFER, vbo); // bind it so it's the current one in use

  // copy the points into it
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

}

void CustomShader::render(glm::mat4& proj) {
  glBindVertexArray(vao);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  Shader* s = Shader::useShader(shaderID);
  s->setMat4("projection", proj);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(0);
  glBindVertexArray(0);

}

void CustomShader::update() {
    
}

void CustomShader:cleanup() {
    
}
void grailmain(int argc, char* argv[], GLWin* w, Tab* t) {
  w->setTitle("");
  
}
