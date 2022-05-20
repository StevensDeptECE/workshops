class Complex{
  private:
  double real, imag;

  public: 
  Complex(double r, double i):real(r), imag(i){}
  Complex():real(0), imag(0){}
  Complex(double r): real(r), imag(0){}

  Complex operator + (Complex second){
    return Complex(this->real + second.real, this->imag + second.imag);
  }

  friend Complex operator - (Complex first, Complex second){
    return Complex(first.real - second.real, first.imag - second.imag);
  }
/*
  Complex operator - (){
    real = -real;
    imag= -imag;
    return this;
  }
*/




};



int main() {
  const Complex a(2.0, 3.5); // real=2.0, imag = 3.5
  const Complex b(1.5);      // real = 1.5, imag = 0.0
  const Complex c;           // real = 0.0, imag = 0.0
  const Complex d = a + b;   // use member syntax (lefthand side is this, righthand passed as parameter)
  const Complex e = a - b;   // use friend syntax (specify both parameters)
  const Complex f = -a;      // use member syntax (no parameter, this points to the object a)
  const Complex g = +a;      // use friend syntax
  cout << a << '\n';
  cout << b << '\n';
  cout << c << '\n';
  cout << d << '\n';
  cout << e << '\n';
  cout << f << '\n';
  cout << g << '\n';
  cout << a.abs() << '\n'; // compute the magnitude
}