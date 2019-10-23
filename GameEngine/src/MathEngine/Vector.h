#pragma once
#include <cmath>

class Vector {
private:
	float x;
	float y;
	float z;

public:

	Vector();
	Vector(float _x, float _y, float _z);
	Vector(const Vector& v);

	inline float X() const { return x; }
	inline float Y() const { return y; }
	inline float Z() const { return z; }

	static Vector Zero() { return Vector(0, 0, 0); }
	static Vector One() { return Vector(1, 1, 1); }

	float Dot(const Vector v) const;
	Vector Cross(const Vector v) const;
	Vector Normalize() const;
	void Normalize();
	float Length() const;

	Vector operator+(const Vector v) const;
	void operator+=(const Vector v);
	Vector operator-(const Vector v) const;
	void operator-=(const Vector v);
	Vector operator*(const float f) const;
	void operator*=(const float f);
	Vector operator/(const float f) const;
	void operator/=(const float f);
	bool operator==(const Vector v) const;
	bool operator!=(const Vector v) const;
};

