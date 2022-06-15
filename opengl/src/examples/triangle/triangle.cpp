#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>
using namespace std;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void window_size_callback(GLFWwindow* window, int width, int height);

int WIDTH  = 1000, HEIGHT = 1000;

void doit() {
	uint32_t shaderProgram;
	if (!glfwInit()) {
    throw "Can't initialized glfw";
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // MUST MATCH OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Triangle Demo", nullptr, nullptr);
	
	if (window == nullptr) {
		throw "GLFW: failed to create the window";
	}

	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);

	glfwMakeContextCurrent(window); //create OpenGL context

	if (glewInit() != 0) throw "GLEW: failed to init";
	
	float vertices[] = {
		-1.0f, -1.0f, // bottom left
		 0.0f, +1.0f, // top center
		 1.0f, -1.0f // bottom right
	};

	#include "simple.vs.hh"
  #include "simple.fs.hh"

	uint32_t vao; // vertex array object (holds lists of points, indices and colors on the card)
	glGenVertexArrays(1, &vao); // create 1 new vertex array object and store into vao
	glBindVertexArray(vao); // use this one until the next time I change my mind

	uint32_t vbo; //vertex buffer object (handle to an array of vertices on the graphics card)
	glGenBuffers(1, &vbo); // create it
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// connect an array on THIS COMPUTER and send to the graphics card (this takes time, uses bus)
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer
	(0,							// send this data to the vertex shader (GLSL)
	 2,						  // send 2 values
	 GL_FLOAT,      // they are floats
	 GL_FALSE,
	 0,
	 0              // offset
	);
	glEnableVertexAttribArray(0);
	
	unsigned int vertex, fragment;
	int success;
	char infoLog[1024];

	vertex = glCreateShader(GL_VERTEX_SHADER); // describes how (vertices, colors, indices, textures) get transformed
	glShaderSource(vertex, 1, &vertexSource, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertex, 1024, NULL, infoLog);
		std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: VERTEX\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
	}

// output of the vertex shader goes to the fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER); // turns primitives into pixels
	glShaderSource(fragment, 1, &fragmentSource, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragment, 1024, NULL, infoLog);
		std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: FRAGMENT\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
	}

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertex);
	glAttachShader(shaderProgram, fragment);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	glUseProgram(shaderProgram);

	glm::mat4 projection = glm::ortho(-1, +1, -1, +1);
  glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE,
                     &projection[0][0]);

// set the variable solidColor in the shader to (1.0,0.0,0.0) = red
  glUniform3f(glGetUniformLocation(shaderProgram, "solidColor"), 1.0, 0.0, 0.0);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteProgram(shaderProgram);

	glfwDestroyWindow(window);
	glfwTerminate();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, 1);
	}

	if (key == GLFW_KEY_KP_0 && action == GLFW_PRESS) {
	}

	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	;
	else if (key == GLFW_KEY_D && action == GLFW_PRESS)
		;
	else if (key == GLFW_KEY_W && action == GLFW_PRESS)
		;
	else if (key == GLFW_KEY_S && action == GLFW_PRESS)
		;

	if (key == GLFW_KEY_KP_ADD && action == GLFW_PRESS)
		;
	else if (key == GLFW_KEY_KP_SUBTRACT && action == GLFW_PRESS)
		;

	if (key == GLFW_KEY_Q && action == GLFW_PRESS)
		;
	else if (key == GLFW_KEY_E && action == GLFW_PRESS)
		;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		//glfwGetCursorPos(window, &oldX, &oldY);
	}
}


void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	if (yoffset != 0) {
	}
}

void window_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	WIDTH = width;
	HEIGHT = height;
	//glUniform2d(glGetUniformLocation(shaderProgram, "screenSize"), (double)WIDTH, (double)HEIGHT);
}

int main() {
	try {
		doit();
	} catch (const char* msg) {
		cerr << msg << '\n';
		exit(-1);
	}
}
