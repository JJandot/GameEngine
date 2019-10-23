#include "Quaternion.h"

Quaternion::Quaternion(float _scalar, Vector _vector) {
	scalar = _scalar;
	vector = _vector;
}

Quaternion::Quaternion(const Quaternion& q) {
	scalar = q.scalar;
	vector = q.vector;
}

Quaternion Quaternion::operator+(const Quaternion q) const {
	return Quaternion(scalar + q.scalar, vector + q.vector);
}

void Quaternion::operator+=(const Quaternion q) {
	scalar += q.scalar;
	vector += q.vector;
}

Quaternion Quaternion::operator-(const Quaternion q) const {
	return Quaternion(scalar - q.scalar, vector - q.vector);
}

void Quaternion::operator-=(const Quaternion q) {
	scalar -= q.scalar;
	vector -= q.vector;
}

Quaternion Quaternion::operator*(const Quaternion q) const {
	float s;
	s = scalar * q.scalar - vector.Dot(q.vector);

	Vector w;
	w = q.vector * s + vector * q.scalar + vector.Cross(q.vector);

	return Quaternion(s, w);

}

void Quaternion::operator*=(const Quaternion q) {
	float s;
	s = scalar * q.scalar - vector.Dot(q.vector);

	Vector w;
	w = q.vector * s + vector * q.scalar + vector.Cross(q.vector);

	scalar = s;
	vector = w;
}

Quaternion Quaternion::operator*(const float f) const {
	return Quaternion(f * scalar, vector * f);
}

void Quaternion::operator*=(const float f) {
	scalar *= f;
	vector *= f;
}

float Quaternion::Norm() const {
	return sqrt(pow(scalar, 2) + pow(vector.X(), 2) + pow(vector.Y(), 2) + pow(vector.Z(), 2));
}

Quaternion Quaternion::Normalize() const {
	float factor = 1.0f / Norm();
	return (*this) * factor;
}

void Quaternion::Normalize() {
	float factor = 1.0f / Norm();
	scalar *= factor;
	vector *= factor;
}

Quaternion Quaternion::Conjugate() const {
	return Quaternion(scalar, vector * -1.0f);
}

Quaternion Quaternion::Inverse() const {
	float factor = 1.0f / pow(Norm(), 2);
	return Conjugate() * factor;
}
