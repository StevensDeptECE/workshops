#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  float sum1 = 0.0f;

  int x = 3;
  int y = x++; // y = 3, x = 4
  int z = ++y; // y = 4, z = 4

  int w = x++ + x++; //4+5 = 9  4+4 = 8   x = 6 NEVER DO THIS!!!!
  w = ++x + x++; // NEVER USE TWO autoincrement/decrement in the same line

  for (float i = 1; i <= 100; i = i + 1) // i = i + 1;   i += 1;  i++;  ++i
     sum1 += 1.0f / i;
//     sum1 += 1 / i;
//     sum1 += (float)1 / i;

   cout << setprecision(8) << sum1 << '\n';

   double sum2 = 0;
   for (int i = 100; i >= 1; i--)
     sum2 = sum2 + 1 / (float)i;

  cout << setprecision(8) << sum2 << '\n';
  cout << setprecision(8) << sum1 - sum2 << '\n';
}

/*
1.23
 .876
 .929

1.23
 .876
=====
2.10
 .929
3.02

 .876
 .929
=====
1.80
1.23
3.03

*/