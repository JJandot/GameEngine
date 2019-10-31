#include "../stdafx.h"
#include "Vector.h"

Vector::Vector() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector::Vector(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}

Vector::Vector(const Vector& v) {
	x = v.X();
	y = v.Y();
	z = v.Z();
}

float Vector::Dot(Vector v) const {
	return x * v.X() + y * v.Y() + z * v.Z();
}

Vector Vector::Cross(Vector v) const {
	return Vector(y * v.Z() - z * v.Y(), z * v.X() - x * v.Z(), x * v.Y() - y * v.X());
}

void Vector::Normalize() {
	float max = max(z, max(x, y));
	x /= max;
	y /= max;
	z /= max;
}

float Vector::Length() const {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector Vector::operator+(Vector v) const {
	return Vector(x + v.X(), y + v.Y(), z + v.Z());
}

void Vector::operator+=(const Vector v) {
	x += v.X();
	y += v.Y();
	z += v.Z();
}

Vector Vector::operator-(Vector v) const {
	return Vector(x - v.X(), y - v.Y(), z - v.Z());
}

void Vector::operator-=(const Vector v) {
	x -= v.X();
	y -= v.Y();
	z -= v.Z();
}

Vector Vector::operator*(float f) const {
	return Vector(x * f, y * f, z * f);
}

void Vector::operator*=(const float f) {
	x *= f;
	y *= f;
	z *= f;

}

Vector Vector::operator/(float f) const {
	return Vector(x / f, y / f, z / f);
}

void Vector::operator/=(const float f) {
	x /= f;
	y /= f;
	z /= f;
}

bool Vector::operator==(const Vector v) const {
	return v.X() == x && v.Y() == y && v.Z() == z;
}

bool Vector::operator!=(const Vector v) const {
	return v.X() != x || v.Y() != y || v.Z() != z;
}
