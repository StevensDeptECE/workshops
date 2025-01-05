#include <GL/glew.h>    // OpenGL API
#include <GLFW/glfw3.h> // Window API
#include <glm/glm.hpp>  // Matrix and vector math for OpenGL
#include <glm/ext.hpp>

// all demos use a window, declared globally in common.cc
extern GLFWwindow* win;
GLFWwindow* createWindow(uint32_t w, uint32_t h, const char title[]);
GLuint loadShaders(const char vertexPath[], const char * fragmentPath);

// the signature of the function to write, automatically called by main
void glmain();

/*
	we provide a standardized main, because it's always the same
  It catches exceptions and quits if there is a problem
	you write glmain instead
*/
int main(int argc, char* argv[]);
void dump(glm::mat4& mat);
void transpt(glm::mat4& m, double x, double y, double z);
GLuint loadWebPTexture(const char* filePath);
