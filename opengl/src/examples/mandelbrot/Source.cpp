#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define LOG(x) std::cout << x << std::endl;

#ifdef _WIN32 // hides console if on windows
	#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

int WIDTH  = 800;
int HEIGHT = 600;

int itr = 200;
double zoom = 100.0;
double offsetX = 0.0;
double offsetY = 0.0;

bool dragging = false;
double oldX, oldY;

unsigned int shaderProgram;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void window_size_callback(GLFWwindow* window, int width, int height);

#include "mandelbrot.vs.hh"
#include "mandelbrot.fs.hh"

int main() {
	if (!glfwInit()) LOG("GLFW: failed to init")
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // MUST MATCH OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Mandelbrot Set", NULL, NULL);
	
	if (!window) {
		LOG("GLFW: failed to create the window")
		glfwTerminate();
	}

	glfwSetErrorCallback([](int e, const char *s) { std::cerr << s << std::endl; });
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);

	glfwMakeContextCurrent(window); //create OpenGL context

	if (glewInit() != 0) LOG("GLEW: failed to init")
	
	float vertices[] = {
		-1.0f, -1.0f,
		 1.0f, -1.0f,
		 1.0f,  1.0f,

		 1.0f,  1.0f,
		-1.0f,  1.0f,
		-1.0f, -1.0f
	};

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
	
	glUniform2d(glGetUniformLocation(shaderProgram, "screenSize"), (double)WIDTH, (double)HEIGHT);
	glUniform2d(glGetUniformLocation(shaderProgram, "offset"), offsetX, offsetY);
	glUniform1d(glGetUniformLocation(shaderProgram, "zoom"), zoom);
	glUniform1i(glGetUniformLocation(shaderProgram, "itr"), itr);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 6);

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
		itr = 200;
		zoom = 100.0;
		offsetX = 0.0;
		offsetY = 0.0;
	}

	if (key == GLFW_KEY_A && action == GLFW_PRESS)
		offsetX += 20 / zoom;
	else if (key == GLFW_KEY_D && action == GLFW_PRESS)
		offsetX -= 20 / zoom;
	else if (key == GLFW_KEY_W && action == GLFW_PRESS)
		offsetY -= 20 / zoom;
	else if (key == GLFW_KEY_S && action == GLFW_PRESS)
		offsetY += 20 / zoom;

	if (key == GLFW_KEY_KP_ADD && action == GLFW_PRESS)
		zoom *= 2;
	else if (key == GLFW_KEY_KP_SUBTRACT && action == GLFW_PRESS)
		zoom /= 2;

	if (key == GLFW_KEY_Q && action == GLFW_PRESS)
		itr += 50;
	else if (key == GLFW_KEY_E && action == GLFW_PRESS)
		(itr > 100) ? itr -= 50 : itr = 50;

	glUniform1i(glGetUniformLocation(shaderProgram, "itr"), itr);
	glUniform1d(glGetUniformLocation(shaderProgram, "zoom"), zoom);
	glUniform2d(glGetUniformLocation(shaderProgram, "offset"), offsetX, offsetY);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		glfwGetCursorPos(window, &oldX, &oldY);
		dragging = true;
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
		dragging = false;
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	if (dragging) {
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		offsetX += (xpos - oldX) / zoom;
		offsetY += (oldY - ypos) / zoom;

		oldX = xpos;
		oldY = ypos;

		glUniform2d(glGetUniformLocation(shaderProgram, "offset"), offsetX, offsetY);
	}
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	if (yoffset != 0) {
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		double dx = (xpos - WIDTH / 2) / zoom - offsetX;
		double dy = (HEIGHT - ypos - HEIGHT / 2) / zoom - offsetY;
		offsetX = -dx;
		offsetY = -dy;
		if (yoffset < 0)
			zoom /= 1.2;
		else
			zoom *= 1.2;

		dx = (xpos - WIDTH / 2) / zoom;
		dy = (HEIGHT - ypos - HEIGHT / 2) / zoom;
		offsetX += dx;
		offsetY += dy;

		glUniform1d(glGetUniformLocation(shaderProgram, "zoom"), zoom);
		glUniform2d(glGetUniformLocation(shaderProgram, "offset"), offsetX, offsetY);
	}
}

void window_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	WIDTH = width;
	HEIGHT = height;
	glUniform2d(glGetUniformLocation(shaderProgram, "screenSize"), (double)WIDTH, (double)HEIGHT);
}
