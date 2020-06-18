#include <iostream>
using namespace std;

void hello() {
  cout << "hello";
}

double f(double x) {
  return x*x;
}

double f(double x, double y) {
  return x*x;
}

double cube(double x = 0, double y = 0) {
  return x*x*x * y*y*y;
}

int f(int x) {
  return 2*x;
}

int main() {
  cout << f(2.0) << '\n';
  cout << f(3) << '\n';
  cout << cube(4,2) << '\n';
  //cout << f("abc");
}