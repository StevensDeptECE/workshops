#include "opengl/Image.hh"

#include <string>

#include "glad/glad.h"
#include "opengl/Canvas.hh"
//#include "stb/stb_image.h"
//#include "stb/stb_image_write.h"
#include "webp/decode.h"
#include "util/Ex.hh"
using namespace std;

inline void Image::setupTexture() {
  glGenTextures(1, &textureID); // generate a single texture in textureId
  glBindTexture(GL_TEXTURE_2D, textureID); // bind to current texture

  // set texture wrapping to GL_REPEAT (default wrapping method)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  // set texture filtering parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

inline void Image::setupBuffers(float u0, float v0, float u1, float v1) {
	vertices[0] = x;	vertices[1] = y;
	vertices[2] = u0;	vertices[3] = v1;

	vertices[4] = x;	vertices[5] = y+height;
	vertices[6] = u1;	vertices[7] = v0;

	vertices[8] = x+width;	vertices[9] = y+height;
	vertices[10] = u1;	    vertices[11] = v0;

	vertices[12] = x+width;	vertices[13] = y;
	vertices[14] = u1;	    vertices[15] = v1;
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 2;
	indices[4] = 1;
	indices[5] = 3;
}

bool readEntireFile(const char filename[], uint8_t** buf, uint32_t* len) {
  ifstream f(filename);
	f.seek(0, std::ios::end);  // go to the end
	uint32_t n = f.tellg();           // report location (this is the length)
	*buf = new uint8_t[n];
	f.seekg(0, std::ios::beg);
	f.read(buf, n);
	*len = n;
	return true;
}

inline void Image::setImage(const char filename[]) {
	uint32_t len;
	uint8_t* p;
	if (!readEntireFile(filename, &p, &len))
		throw "error opening file";

	int w, h;
	int status = WebPGetInfo(p, len, &w, &h);
	cout << w << ',' << h << '\n';

	WebPDecoderConfig config;
	// Specify the desired output colorspace:
	config.output.colorspace = MODE_BGRA;
	// Have config.output point to an external buffer:
	const uint8_t* data = new char[w*h]; //allocate memory
	if (data == nullptr)
    throw Ex2(Errcode::IMAGE_LOAD, filePath);
	config.output.u.RGBA.rgba = data;
	config.output.u.RGBA.stride = 0;// scanline_stride;
	config.output.u.RGBA.size = w*h*4;
	config.output.is_external_memory = 1;

	if (WebPDecode(p, len, &config) == VP8_STATUS_OK)
    throw Ex2(Errcode::IMAGE_LOAD, filePath);
	
	// generate texture and bind it to current object
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0,
							 GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	delete [] data;
}

Image::Image(float x, float y, float width, float height,
						 uint32_t textureID)
    : x(x), y(y), width(width), height(height), textureID(textureID) {
  setupBuffers();
}

Image::Image(float x, float y, float width, float height,
             const char filePath[])
    : x(x), y(y), width(width), height(height) {
  setupBuffers();
  setupTexture();
  setImage(filePath);
}


void Image::init() {
  glGenVertexArrays(1, &vao);   // Creating rect VAO
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0],
							 GL_STATIC_DRAW);

  // Index array object
  glGenBuffers(1, &sbo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sbo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0],
							 GL_STATIC_DRAW);

  // position attribute
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
  // texture coord attribute
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float),
                        (void*)(2 * sizeof(float)));
}

void Image::render(glm::mat4& proj) {
  glBindVertexArray(vao);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  Shader* s = Shader::useShader(GLWin::TEXTURE_SHADER);
  s->setMat4("projection", *(parentCanvas->getProjection()));
  s->setInt("ourTexture", 0);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, textureID);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sbo);
  glDrawElements(GL_TRIANGLES, vertices.size() * 3 / 8, GL_UNSIGNED_INT, 0);

  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(0);
  glBindVertexArray(0);
}
