#include <iostream>
#include <iomanip>
#include <cstdint>
#include <cmath>

using namespace std;

/*
int a;
long b;
long long c;

long - target type will have width of at least 32 bits.
long long - target type will have width of at least 64 bits.
*/
// https://en.cppreference.com/w/cpp/types/integer

uint64_t sum2(uint64_t a, uint64_t b) {
  return a + b;
}



// sum of all numbers from a to b, inclusive
uint64_t sum(uint64_t a, uint64_t b) {
  uint64_t ans;   // must initialize, otherwise it's a random value
  for (int i = a; i <= b; i++) {
    ans += i;
  }
  return ans;
}

uint32_t doubleme(uint32_t a) {
  return 16*a; // a << 4
}

void roundoffpractice() {
  cout << setprecision(8);
  for (float x = 0.0; x <= 10; x += 0.1)
    cout << x << ", ";
  cout << '\n';

}


void rect2polar(double x, double y, double& r, double& theta) {
  r = sqrt(x * x + y * y);
  theta = atan2(y,x);
}

int main() {
  cout << sum(1,5) << '\n';
  cout << sum(1,1000000) << '\n';
  cout << sum2(3,4) << '\n';
  double x, y, r, theta;
  cin >> x >> y;
  rect2polar(x, y, r, theta);
  cout << "r=" << r << " theta=" << theta << endl;
  roundoffpractice();
}