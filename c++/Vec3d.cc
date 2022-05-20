#include <iostream>
#include <cmath>
using namespace std;
class Vec3D {
 private:
  double x, y, z;

 public:
  // constructor showing the 3 different ways of setting member data:
  // assignment with a different variable name
  // assignment with the same variable name so using this-> to identify the
  // member variable vs the parameter third, the initializer list for z
  Vec3D(double x_, double y, double z) : z(z) {
    x = x_;
    this->y = y;
    // this->z = z;
  }
  Vec3D() : x(0), y(0), z(0) {}

  friend ostream& operator <<(ostream& s, Vec3D v) {
    s << v.x << ", " << v.y << ", " << v.z;
    return s; //if you print to a stream you return to the stream
  }
  ostream& print(ostream& s) { // in this case, x means this->x
    return s << x << ", " << this->y << ", " << this->z; // this->y and this->z not required
  }
  friend Vec3D operator + (Vec3D v, const Vec3D& w) { // const after ) is only legal for member operators that have a this->
    Vec3D sum;
    sum.x = v.x + w.x;
    sum.y = v.y + w.y;
    sum.z = v.z + w.z;

    return sum;
//    return Vec3D(v.x+w.x, v.y+w.y, v.z+w.z);
  }
  double abs() const{ // abs is READONLY. It does not change the object. PROMISE!!!
    return sqrt(x*x + y*y+ z*z);
  } 

  
};


int main() {
  const Vec3D a(1.0, 2.5, 3.0);
  const Vec3D b(-1.0, 2.0, -1.5);
  const Vec3D c;  // c = (0,0,0)
  const Vec3D d = a + b;
  double m = a.abs();
  cout << a << " " << b << '\n'; // 1.0, 2.5, 3.0
  //int d = 2 + 3 + 4;
  a.print(cout) << "\n";
  cout << d << '\n';
  cout << "magnitude: " << m << '\n';

  //<< '\n';
  // cout << c << '\n';

  return 0;
}