#include "point3D.h"
#include <cmath>
#define PI 3.141592654
point3D::point3D()
{
}

point3D::point3D(double x, double y, double z){
	X = x;
	Y = y;
	Z = z;
	//double temp = x*x + y*y;
	R = sqrt(x*x + y*y);
	if (y > 0)
		theta = acos(x / R) * 180 / PI;
	else theta = 360 - acos(x / R) * 180 / PI;
	//phi = acos(R / sqrt(x*x + y*y + z*z));
}

bool point3D::operator <(point3D &a){
	bool result = Z < a.Z && a.Z - Z > tol;
	return (result);
}

bool point3D::operator >(point3D &a){
	bool result = Z > a.Z && Z - a.Z > tol;
	return (result);
}

bool point3D::operator ==(point3D &a){
	bool result = a.Z - Z > -tol && a.Z - Z < tol;
	return (result);
}

bool point3D::operator <=(point3D &a){
	bool result = *this < a || *this == a;
	return (result);
}

bool point3D::operator >=(point3D &a){
	bool result = *this > a || *this == a;
	return (result);
}

point3D::~point3D()
{
}

