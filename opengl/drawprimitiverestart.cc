/*

   ---------------------------------------------------------------

                                                 oooo
                                                 '888
                  oooo d8b  .ooooo.  oooo    ooo  888  oooo  oooo
                  '888""8P d88' '88b  '88b..8P'   888  '888  '888
                   888     888   888    Y888'     888   888   888
                   888     888   888  .o8"'88b    888   888   888
                  d888b    'Y8bod8P' o88'   888o o888o  'V88V"V8P'

                                                    www.roxlu.com
                                            www.twitter.com/roxlu

  ---------------------------------------------------------------



  PRIMITIVE RESTART
  ==================

  This is a quick experiment that shows how to use primitive restart. Primitive
  restart allows you to flag an index of a element buffer as "special". Every
  time GL reads this value from the index buffer it will start a new primitive.

  This is nice, because this allows you to use one array-buffer and one
  element-buffer to draw separate GL_LINE_STRIPS or GL_TRIANGLE_STRIPS for
  example. You can even use glDrawArrays() and "restart" every N-th draw vertex
  (not showing here).

 */
//#include <dlfcn.h>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <stdio.h>
#include <stdlib.h>

#include <sstream>
#include <vector>

void button_callback(GLFWwindow* win, int bt, int action, int mods);
void cursor_callback(GLFWwindow* win, double x, double y);
void key_callback(GLFWwindow* win, int key, int scancode, int action, int mods);
void char_callback(GLFWwindow* win, unsigned int key);
void error_callback(int err, const char* desc);
void resize_callback(GLFWwindow* window, int width, int height);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

/* -------------------------------------------- */

int win_w = 1280;
int win_h = 720;

struct vertex {
  float x;
  float y;
};

/* -------------------------------------------- */

int main() {
  glfwSetErrorCallback(error_callback);

  if (!glfwInit()) {
    printf("Error: cannot setup glfw.\n");
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GL_FALSE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  GLFWwindow* win = NULL;
  int w = win_w;
  int h = win_h;

  win = glfwCreateWindow(w, h, "Primitive restart v1.0", NULL, NULL);
  if (!win) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwSetFramebufferSizeCallback(win, resize_callback);
  glfwSetKeyCallback(win, key_callback);
  glfwSetCharCallback(win, char_callback);
  glfwSetCursorPosCallback(win, cursor_callback);
  glfwSetMouseButtonCallback(win, button_callback);
  glfwSetScrollCallback(win, scroll_callback);
  glfwMakeContextCurrent(win);
  glfwSwapInterval(1);

  if (!gladLoadGL()) {
    printf("Cannot load GL.\n");
    exit(1);
  }

  // ----------------------------------------------------------------
  // THIS IS WHERE YOU START CALLING OPENGL FUNCTIONS, NOT EARLIER!!
  // ----------------------------------------------------------------

  /* Fill our vertex and index buffers. 0xFFFF is our primitive restart value.
   */
  int num_particles = 3;
  int num_points = 40;
  std::vector<int> indices;
  std::vector<vertex> vertices;

  for (int i = 0; i < num_particles; ++i) {
    for (int j = 0; j < num_points; ++j) {
      indices.push_back(vertices.size());
      vertices.push_back(vertex{100 + i * 10.0f, 100 + j * 5.0f});
    }
    indices.push_back(0xFFFF);
  }

  GLuint rib_vbo = 0;
  glGenBuffers(1, &rib_vbo);
  glBindBuffer(GL_ARRAY_BUFFER, rib_vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * vertices.size(),
               &vertices[0].x, GL_STATIC_DRAW);

  GLuint rib_ebo = 0;
  glGenBuffers(1, &rib_ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rib_ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indices.size(),
               &indices[0], GL_STATIC_DRAW);

  /* Create the VAO that we use when drawing. */
  GLuint rib_vao = 0;
  glGenVertexArrays(1, &rib_vao);
  glBindVertexArray(rib_vao);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rib_ebo);
  glBindBuffer(GL_ARRAY_BUFFER, rib_vbo);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);

  /* ==================================================== */
  /* DRAW SHADER                                          */
  /* ==================================================== */

  const char* dvss =
      ""
      "#version 330\n"
      "uniform mat4 u_pm;\n"
      "layout (location = 0) in vec2 a_pos;\n"
      "void main() {\n"
      "  gl_Position = u_pm * vec4(a_pos, 0.0, 1.0);\n"
      "}";

  GLuint draw_vs = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(draw_vs, 1, (const char**)&dvss, NULL);
  glCompileShader(draw_vs);

  const char* dfss =
      ""
      "#version 330\n"
      "uniform vec3 u_color;\n"
      "layout (location = 0) out vec4 fragcolor;\n"
      "void main() {\n"
      "  fragcolor = vec4(u_color, 1.0);\n"
      "}";

  GLuint draw_fs = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(draw_fs, 1, (const char**)&dfss, NULL);
  glCompileShader(draw_fs);

  GLuint draw_prog = glCreateProgram();
  glAttachShader(draw_prog, draw_vs);
  glAttachShader(draw_prog, draw_fs);
  glLinkProgram(draw_prog);

  float pm[16] = {0.0f};
  pm[0] = 2.0 / win_w;
  pm[5] = 2.0f / -win_h;
  pm[10] = -1.0f;
  pm[12] = -1.0;
  pm[13] = 1.0f;
  pm[15] = 1.0f;

  GLint u_pm = glGetUniformLocation(draw_prog, "u_pm");
  GLint u_color = glGetUniformLocation(draw_prog, "u_color");

  glUseProgram(draw_prog);
  glUniformMatrix4fv(u_pm, 1, GL_FALSE, pm);
  glUniform3f(u_color, 1.0f, 1.0f, 1.0f);

  /* ==================================================== */

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  while (!glfwWindowShouldClose(win)) {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, w, h);
    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /*
      This is where we enable primitive restart; Note that we have one draw call
      but we're drawing multiple separate GL_LINE_STRIPs.
     */
    glEnable(GL_PRIMITIVE_RESTART);
    glPrimitiveRestartIndex(0xFFFF);
    glUseProgram(draw_prog);
    glBindVertexArray(rib_vao);
    glDrawElements(GL_LINE_STRIP, indices.size(), GL_UNSIGNED_INT, (GLvoid*)0);

    glfwSwapBuffers(win);
    glfwPollEvents();
  }

  glfwTerminate();

  return EXIT_SUCCESS;
}

void char_callback(GLFWwindow* win, unsigned int key) {}

void key_callback(GLFWwindow* win, int key, int scancode, int action,
                  int mods) {
  if (GLFW_RELEASE == action) {
    return;
  }
  switch (key) {
    case GLFW_KEY_SPACE: {
      break;
    }
    case GLFW_KEY_ESCAPE: {
      glfwSetWindowShouldClose(win, GL_TRUE);
      break;
    }
  };
}

void resize_callback(GLFWwindow* window, int width, int height) {}

void cursor_callback(GLFWwindow* win, double x, double y) {}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {}

void button_callback(GLFWwindow* win, int bt, int action, int mods) {
  double mx = 0.0;
  double my = 0.0;
  glfwGetCursorPos(win, &mx, &my);

  if (GLFW_PRESS == action) {
  } else if (GLFW_RELEASE == action) {
  }
}

void error_callback(int err, const char* desc) {
  printf("GLFW error: %s (%d)\n", desc, err);
}
