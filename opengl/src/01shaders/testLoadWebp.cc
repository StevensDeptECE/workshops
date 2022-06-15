#include <fstream>
#include <iostream>

#include "opengl/Image.hh"
#include "webp/decode.h"

using namespace std;

void testImage(const char filename[]) {
  uint32_t len;
  uint8_t* p;
  if (!readEntireFile(filename, &p, &len)) throw "error opening file";

  int w, h;
  int status = WebPGetInfo(p, len, &w, &h);
  cout << w << ',' << h << '\n';

  WebPDecoderConfig config;
  if (!WebPInitDecoderConfig(&config)) throw "cannot initialize config";
  if(WebPGetFeatures(p, len, &config.input) != VP8_STATUS_OK) throw "cannot get features";
	const uint32_t SIZE = w*h*(3+config.input.has_alpha);
  // Specify the desired output colorspace:
  config.output.colorspace = MODE_BGR;
  config.output.is_external_memory = 1;
  // Have config.output point to an external buffer:
  config.output.u.RGBA.rgba = (uint8_t*)new uint8_t[SIZE*4];  // size of image with transparency 4 bytes per pixel;
  config.output.u.RGBA.stride = w*(3+config.input.has_alpha);                        // scanline_stride;
  config.output.u.RGBA.size = SIZE*4;

  int err = 0;
  if ((err = WebPDecode(p, len, &config)) != VP8_STATUS_OK) {
    std::cerr << "WebPDecode error " << err << '\n';
    throw "webp corrupt";
  }
  const uint32_t* pixels = (const uint32_t*)config.output.u.RGBA.rgba;
  cout << "pixels\n";
  for (uint32_t i = 0; i < w * h; i++) {
    cout << hex << (int)pixels[i] << ' ';
  }
  	WebPFreeDecBuffer(&config.output);
}

int main() { testImage("river.webp"); }
