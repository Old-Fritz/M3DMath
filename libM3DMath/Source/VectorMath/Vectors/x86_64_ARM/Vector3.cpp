#include "M3DMath.h"
#include <cmath>

/// Implementation of Vector3

using namespace M3DM;

// Conversions
Vector3::Vector3(Vector4 vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
}
Vector3::operator float*()
{
	return reinterpret_cast<float*>(this);
}
Vector3::operator float const*() const
{
	return reinterpret_cast<float const*>(this);
}

// Operators
Vector3 Vector3::operator+(Vector3 vector) const
{
	Vector3 vectorRes;
	vectorRes.x = this->x + vector.x;
	vectorRes.y = this->y + vector.y;
	vectorRes.z = this->z + vector.z;

	return vectorRes;
}
Vector3 Vector3::operator-(Vector3 vector) const
{
	Vector3 vectorRes;
	vectorRes.x = this->x - vector.x;
	vectorRes.y = this->y - vector.y;
	vectorRes.z = this->z - vector.z;

	return vectorRes;
}
Vector3 Vector3::operator*(Vector3 vector) const
{
	Vector3 vectorRes;
	vectorRes.x = this->x * vector.x;
	vectorRes.y = this->y * vector.y;
	vectorRes.z = this->z * vector.z;

	return vectorRes;
}
Vector3 Vector3::operator/(Vector3 vector) const
{
	Vector3 vectorRes;
	vectorRes.x = this->x / vector.x;
	vectorRes.y = this->y / vector.y;
	vectorRes.z = this->z / vector.z;

	return vectorRes;
}
Vector3 Vector3::operator*(float scale) const
{
	Vector3 vectorRes;
	vectorRes.x = this->x * scale;
	vectorRes.y = this->y * scale;
	vectorRes.z = this->z * scale;

	return vectorRes;
}
Vector3 Vector3::operator/(float scale) const
{
	Vector3 vectorRes;
	vectorRes.x = this->x / scale;
	vectorRes.y = this->y / scale;
	vectorRes.z = this->z / scale;

	return vectorRes;
}
Vector3& Vector3::operator+=(Vector3 vector)
{
	this->x += vector.x;
	this->y += vector.y;
	this->z += vector.z;

	return *this;
}
Vector3& Vector3::operator-=(Vector3 vector)
{
	this->x -= vector.x;
	this->y -= vector.y;
	this->z -= vector.z;

	return *this;
}
Vector3& Vector3::operator*=(Vector3 vector)
{
	this->x *= vector.x;
	this->y *= vector.y;
	this->z *= vector.z;

	return *this;
}
Vector3& Vector3::operator/=(Vector3 vector)
{
	this->x /= vector.x;
	this->y /= vector.y;
	this->z /= vector.z;

	return *this;
}
Vector3& Vector3::operator*=(float scale)
{
	this->x *= scale;
	this->y *= scale;
	this->z *= scale;

	return *this;
}
Vector3& Vector3::operator/=(float scale)
{
	this->x /= scale;
	this->y /= scale;
	this->z /= scale;

	return *this;
}


// Compare functions

bool Vector3::operator==(Vector3 vector) const
{
	return x == vector.x && y == vector.y && z == vector.z;
}
bool Vector3::operator<(Vector3 vector) const
{
	return x < vector.x&& y < vector.y&& z < vector.z;
}
bool Vector3::operator>(Vector3 vector) const
{
	return vector < *this;
}
bool Vector3::operator<=(Vector3 vector) const
{
	return x <= vector.x&& y <= vector.y&& z <= vector.z;
}
bool Vector3::operator>=(Vector3 vector) const
{
	return vector <= *this;
}
bool Vector3::isEqualPrec(Vector3 vector, float precision) const
{
	return fabsf(vector.x - x) <= precision && fabsf(vector.y - y) <= precision  && fabsf(vector.z - z) <= precision;
}
bool Vector3::isEqualPrec(Vector3 vector, Vector3 precision) const
{
	return fabsf(vector.x - x) <= precision.x && fabsf(vector.y - y) <= precision.y && fabsf(vector.z - z) <= precision.z;
}
Vector3 Vector3::isEqualVec(Vector3 vector) const
{
	Vector3 result;
	result.x = vector.x == x;
	result.y = vector.y == y;
	result.z = vector.z == z;
	return result;
}
Vector3 Vector3::isEqualPrecVec(Vector3 vector, Vector3 precision) const
{
	Vector3 result;
	result.x = fabsf(vector.x - x) <= precision.x;
	result.y = fabsf(vector.y - y) <= precision.y;
	result.z = fabsf(vector.z - z) <= precision.z;
	return result;
}