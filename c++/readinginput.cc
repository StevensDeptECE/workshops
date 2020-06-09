#include <iostream>
using namespace std;

void f() {
  int a; // random, whatever was in memory!!!
  int b;
  int c;
  cout << a << ' ' << b << c << '\n';


  cout << a << '\n';
}

void g() {
    double array[1024] = {1, 5, 2, 6, 99};
}
int main() {
  int x;
  float y;
  double z;
  g();
  f();
 
}