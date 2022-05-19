#include "webp/decode.h"
#include <iostream>
#include <fstream>

using namespace std;
bool readEntireFile(const char filename[], uint8_t** buf, uint32_t* len) {
  ifstream f(filename);
	f.seekg(0, ios::end);  // go to the end
	uint32_t n = f.tellg();           // report location (this is the length)
	uint8_t *p = new uint8_t[n];
	*buf = p;
	f.seekg(0, ios::beg);
	f.read((char*)p, n);
	*len = n;
	return true;
}

void testImage(const char filename[]) {
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
	config.output.u.RGBA.rgba = (uint8_t*)new char[w*h]; //memory_buffer;
	config.output.u.RGBA.stride =0;// scanline_stride;
	config.output.u.RGBA.size = w*h*4;
	config.output.is_external_memory = 1;

	if (WebPDecode(p, len, &config) == VP8_STATUS_OK)
		throw "webp corrupt";
	const uint32_t* pixels = (const uint32_t*)config.output.u.RGBA.rgba;
	cout << hex;
	for (uint32_t i = 0; i < w*h; i++) {
		cout << pixels[i] << ' ';
	}
	//	WebPFreeDecBuffer(&config.output);
}

int main() {
	testImage("river.webp");
}
