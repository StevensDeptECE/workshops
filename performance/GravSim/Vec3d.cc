#include "Vec3d.hh"
#include <cmath>
using namespace std;

Vec3d::Vec3d(double x, double y, double z) :
	x(x), y(y), z(z) {}

Vec3d operator +(Vec3d a, Vec3d b) {
	return Vec3d(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vec3d operator -(Vec3d a, Vec3d b) {
	return Vec3d(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vec3d operator -(Vec3d a) {
	return Vec3d(-a.x, -a.y, -a.z);
}

// compute scalar * vector and return the vector
Vec3d operator *(double s, Vec3d v) {
	return Vec3d(s * v.x, s * v.y, s * v.z);
}

// compute vector * scalar and return the vector
Vec3d operator *(Vec3d v, double s) {
	return Vec3d(v.x * s, v.y * s, v.z * s);
}
	
double dot(Vec3d a, Vec3d b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

// r0 points to the object d0 should return the answer
double Vec3d::mag() const {
	return sqrt(x*x + y*y + z*z);
}
	
ostream& operator <<(ostream& s, Vec3d v) {
	return s << v.x << ',' << v.y << ',' << v.z;
}
