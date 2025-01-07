#include <fstream>
#include <iostream>

#include "opengl/Image.hh"
#include "webp/decode.h"
//#include "util/FileUtil.hh"
using namespace std;

void testImage(const char filename[]) {
  uint32_t len;
  uint8_t* p;
  if (readEntireFile(filename, &p, &len)) throw "error opening file";

  int w, h;
  int status = WebPGetInfo(p, len, &w, &h);
  cout << w << ',' << h << '\n';

  WebPDecoderConfig config;
  // Specify the desired output colorspace:
  config.output.colorspace = MODE_BGRA;
  // Have config.output point to an external buffer:
	const uint32_t SIZE = w*h*4;
  config.output.u.RGBA.rgba = (uint8_t*)new char[SIZE];  // size of image with transparency 4 bytes per pixel;
  config.output.u.RGBA.stride = 0;                        // scanline_stride;
  config.output.u.RGBA.size = SIZE;
  config.output.is_external_memory = 1;

  if (WebPDecode(p, len, &config) == VP8_STATUS_OK) throw "webp corrupt";
  const uint32_t* pixels = (const uint32_t*)config.output.u.RGBA.rgba;
  cout << hex << '\n';
  cout << "pixels\n";
  for (uint32_t i = 0; i < w * h; i++) {
    cout << pixels[i] << ' ';
  }
  //	WebPFreeDecBuffer(&config.output);
}

int main() { testImage("river.webp"); }
