#include "GravSim.hh"
using namespace std;

Body::Body(const char name[16],
					 const char orbits[16],
					 double m,
					 double x, double y, double z,
					 double vx, double vy, double vz) :
	m(m),
	pos(x,y,z), v(vx, vy, vz), a() {
	strncpy(this->name, name, 16);
}

ostream& operator <<(ostream& s, Body b) {
	return s << b.name << "\t\t" << b.pos << "\t\t" << b.v << "\t\t" << b.a;
}

Vec3d Body::gravAccel(Body b) {
	Vec3d dpos = pos - b.pos;
	double r = dpos.mag();
	double amag = G * b.m / (r*r);
	return Vec3d(dpos.x/r*amag, dpos.y/r*amag, dpos.z/r*amag);
}
