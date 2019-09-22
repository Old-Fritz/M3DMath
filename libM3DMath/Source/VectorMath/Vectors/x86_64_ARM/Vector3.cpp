#include "M3DMath.h"
#include <cmath>

/// Implementation of Vector3

using namespace M3DM;

// Conversions
Vector3::Vector3(const Vector4& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
}
Vector3::operator Float*()
{
	return reinterpret_cast<Float*>(this);
}
Vector3::operator Float const*() const
{
	return reinterpret_cast<Float const*>(this);
}

// Operators
Vector3 Vector3::operator+(const Vector3& vector) const
{
	Vector3 vectorRes;
	vectorRes.x = this->x + vector.x;
	vectorRes.y = this->y + vector.y;
	vectorRes.z = this->z + vector.z;

	return vectorRes;
}
Vector3 Vector3::operator-(const Vector3& vector) const
{
	Vector3 vectorRes;
	vectorRes.x = this->x - vector.x;
	vectorRes.y = this->y - vector.y;
	vectorRes.z = this->z - vector.z;

	return vectorRes;
}
Vector3 Vector3::operator*(const Vector3& vector) const
{
	Vector3 vectorRes;
	vectorRes.x = this->x * vector.x;
	vectorRes.y = this->y * vector.y;
	vectorRes.z = this->z * vector.z;

	return vectorRes;
}
Vector3 Vector3::operator/(const Vector3& vector) const
{
	Vector3 vectorRes;
	vectorRes.x = this->x / vector.x;
	vectorRes.y = this->y / vector.y;
	vectorRes.z = this->z / vector.z;

	return vectorRes;
}
Vector3 Vector3::operator*(Float scale) const
{
	Vector3 vectorRes;
	vectorRes.x = this->x * scale;
	vectorRes.y = this->y * scale;
	vectorRes.z = this->z * scale;

	return vectorRes;
}
Vector3 Vector3::operator/(Float scale) const
{
	Vector3 vectorRes;
	vectorRes.x = this->x / scale;
	vectorRes.y = this->y / scale;
	vectorRes.z = this->z / scale;

	return vectorRes;
}
Vector3& Vector3::operator+=(const Vector3& vector)
{
	this->x += vector.x;
	this->y += vector.y;
	this->z += vector.z;

	return *this;
}
Vector3& Vector3::operator-=(const Vector3& vector)
{
	this->x -= vector.x;
	this->y -= vector.y;
	this->z -= vector.z;

	return *this;
}
Vector3& Vector3::operator*=(const Vector3& vector)
{
	this->x *= vector.x;
	this->y *= vector.y;
	this->z *= vector.z;

	return *this;
}
Vector3& Vector3::operator/=(const Vector3& vector)
{
	this->x /= vector.x;
	this->y /= vector.y;
	this->z /= vector.z;

	return *this;
}
Vector3& Vector3::operator*=(Float scale)
{
	this->x *= scale;
	this->y *= scale;
	this->z *= scale;

	return *this;
}
Vector3& Vector3::operator/=(Float scale)
{
	this->x /= scale;
	this->y /= scale;
	this->z /= scale;

	return *this;
}
Vector3 Vector3::operator-()  const
{
	Vector3 vectorRes;
	vectorRes.x = -x;
	vectorRes.y = -y;
	vectorRes.z = -z;

	return vectorRes;
}

// Compare functions

Bool Vector3::operator==(const Vector3& vector) const
{
	return x == vector.x && y == vector.y && z == vector.z;
}
Bool Vector3::operator<(const Vector3& vector) const
{
	return x < vector.x&& y < vector.y&& z < vector.z;
}
Bool Vector3::operator>(const Vector3& vector) const
{
	return vector < *this;
}
Bool Vector3::operator<=(const Vector3& vector) const
{
	return x <= vector.x&& y <= vector.y&& z <= vector.z;
}
Bool Vector3::operator>=(const Vector3& vector) const
{
	return vector <= *this;
}
Bool Vector3::isEqualPrec(const Vector3& vector, Float precision) const
{
	return fabsf(vector.x - x) <= precision && fabsf(vector.y - y) <= precision  && fabsf(vector.z - z) <= precision;
}
Bool Vector3::isEqualPrec(const Vector3& vector, const Vector3& precision) const
{
	return fabsf(vector.x - x) <= precision.x && fabsf(vector.y - y) <= precision.y && fabsf(vector.z - z) <= precision.z;
}
Vector3 Vector3::isEqualVec(const Vector3& vector) const
{
	Vector3 result;
	result.x = vector.x == x;
	result.y = vector.y == y;
	result.z = vector.z == z;
	return result;
}
Vector3 Vector3::isEqualPrecVec(const Vector3& vector, const Vector3& precision) const
{
	Vector3 result;
	result.x = fabsf(vector.x - x) <= precision.x;
	result.y = fabsf(vector.y - y) <= precision.y;
	result.z = fabsf(vector.z - z) <= precision.z;
	return result;
}