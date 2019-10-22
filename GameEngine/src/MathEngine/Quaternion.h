#pragma once
#include "Vector.h"

class Quaternion
{
private:
	float scalar;
	Vector v;
public:
	Quaternion(float scalar, Vector v);
	Quaternion(const Quaternion& q);

	Quaternion operator+(const Quaternion q) const;
	void operator+=(const Quaternion q);
	Quaternion operator-(const Quaternion q) const;
	void operator-=(const Quaternion q);
	Quaternion operator*(const Quaternion q) const;
	void operator*=(const Quaternion q);
	Quaternion operator*(const float f) const;
	void operator*=(const float f);

	float Norm() const;
	Quaternion Normalize() const;
	void Normalize();
};

