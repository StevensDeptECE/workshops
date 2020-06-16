#include <iostream>
using namespace std;

class Fraction {
private:
  int num, den; // instance variables (what the object remembers)  
public:
  Fraction(int n, int d) : num(n), den(d) {
//    num = n; den = d;
    cout << "in the constructor\n";
    //cout << n << "/" << d;
  }
  void print() {
    cout << num << "/" << den;
  }

};

void f() {

}
int main() {
  Fraction a(1,2);  // 1/2
  Fraction b(1,3);  // 1/3
  //Fraction c = a + b;
  a.print();
  //cout << c;


  return 0;
}