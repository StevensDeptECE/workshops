#include <iostream>
using namespace std;

int factorial(int a) {
  int prod=1;
  for (int i = 1; i < a + 1; i++){
    prod=prod*i;
  }
 return prod;
}

int main(){
    cout << factorial(5) << endl;
}