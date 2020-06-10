#include <iostream>
using namespace std;

int main() {
  int prod = 1;
  for (int i = 1; i < 5; i++)
    prod *= i;
  cout << prod;
}