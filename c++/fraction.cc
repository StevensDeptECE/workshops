#include <iostream>
#include <fstream>
using namespace std;

class Fraction {
private:
  int num_, den_; // instance variables (what the object remembers)  
public:
  Fraction(int n, int d) : num_(n), den_(d) {
    if (d == 0)
      throw "Division by zero";
    cout << "in the constructor\n";
  }
  void print() const {
    cout << num_ << "/" << den_;
  }

  int num() const { return num_; }  // member function(C++), method (object-oriented)

  //always define methods as const if they should not modify the object
  int den() const {
     return den_;
  }

  friend Fraction operator +(Fraction x, Fraction y) {
    Fraction ans(x.num_*y.den_+y.num_*x.den_ , x.den_ * y.den_);
    return ans;
  }
#if 0
  friend Fraction operator +(Fraction x, Fraction y) {
    return Fraction(x.num_*y.den_+y.num_*x.den_ , x.den_ * y.den_);
  }
#endif
  friend ostream& operator <<(ostream& s, const Fraction& f) {
    return s << f.num_ << '/' << f.den_;
  }


};

void f(const Fraction & a) {
  
}

int main() {
  const Fraction a(1,2);  // 1/2
  const Fraction b(1,3);  // 1/3
  Fraction c = a + b;
  a.print();            //internally method print(Fraction*, )
  b.print();
  c.print();
  cout << c << '\n';
  cout << a.num() << '\n';
  ofstream f("test.dat");
  f << c << '\n';
 // a.den = 0;
  //cout << c;
  try {
    const Fraction c(1,0);
    c.print();
  } catch (const char msg[]) {
    cerr << msg << '\n';
  }
  return 0;
}