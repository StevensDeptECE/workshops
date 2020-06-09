#include <iostream>
#include <iomanip>
#include <cstdint>

using namespace std;
int main() {
  cout << "hello";
  int old1; // on this machine integer +/- 2.1billion or so (2**31)  
  // 16bit <= short int <= int <= long int <=  long long int
  // signed or not? who knows!
  unsigned int old2 = 12412U;

  int8_t a = 2; // signed: -128 ... -1 0 .. 127
  int16_t b = 1000; // signed -32768 .. 32767 
  int32_t c = 2000000000; // +/- 2.1 billion
  int64_t d = -123456789012345678;

  uint8_t e = 123;
  uint32_t g = 12312414U;
  uint64_t h = 121241254ULL;

//IEEE 754 floating point
  float f = 1.234567f; // float is 32 bits
  float f2 = 12345.67f;
  float f3 = 1.2345e+22f;

  double d1 = 1.23456789012345;// double is 64 bits
  double d2 = 1.2345e+305;

  //quad precision (128 bits)
  long double x = 1.2345678901234567890123456789012345L;
  cout << setprecision(32) << x << '\n';
}