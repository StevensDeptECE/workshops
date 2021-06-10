#include <iostream>
class A {
private:
  int* p;
public:
  A(int n) : p(new int[n]) {

  }
  ~A() {
     delete [] p;
  }
};

class Test {
private:
  double x,y,z;
public:
  Text(double x, double y, double z) : x(x), y(y), z(z) {}
};

int main() {
  A a1(100);
  int*p = malloc(1024*sizeof(int)); // allocate 1024 integer

  free(p);


  int * s = new int[1024];


  delete [] s;
  delete [] s;


  unique_ptr<Test> x = make_unique<Test>(1, 2, 3);
  Test x;
  unique_ptr<uint64_t[]> mem = make_unique<uint64_t[]>(n);
}
