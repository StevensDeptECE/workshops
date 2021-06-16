#pragma once
#include <iostream>

class Vec3d {
public:
	double x, y, z;
	Vec3d(double x = 0, double y = 0, double z = 0);
	friend Vec3d operator +(Vec3d a, Vec3d b);
	friend Vec3d operator -(Vec3d a, Vec3d b);
	friend Vec3d operator -(Vec3d a);

	// compute scalar * vector and return the vector
	friend Vec3d operator *(double s, Vec3d v);

	// compute vector * scalar and return the vector
	friend Vec3d operator *(Vec3d v, double s);
	friend double dot(Vec3d a, Vec3d b);

	// r0 points to the object d0 should return the answer
	double mag() const;
	
	friend std::ostream& operator <<(std::ostream& s, Vec3d v);
};
