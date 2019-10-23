#pragma once
#include "Vector.h"

class Quaternion
{
private:
	float scalar;
	Vector vector;
public:
	Quaternion(float _scalar, Vector _vector);
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
	Quaternion Conjugate() const;
	Quaternion Inverse() const;

};

