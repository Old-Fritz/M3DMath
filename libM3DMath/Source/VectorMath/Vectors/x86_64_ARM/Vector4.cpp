#include "M3DMath.h"
#include <cmath>

/// Implementation of Vector4

using namespace M3DM;

// Conversions
Vector4::operator float*()
{
	return reinterpret_cast<float*>(this);
}
Vector4::operator float const*() const
{
	return reinterpret_cast<float const*>(this);
}

// Operators
Vector4 Vector4::operator+(const Vector4& vector) const
{
	Vector4 vectorRes;
	vectorRes.x = this->x + vector.x;
	vectorRes.y = this->y + vector.y;
	vectorRes.z = this->z + vector.z;
	vectorRes.w = this->w + vector.w;

	return vectorRes;
}
Vector4 Vector4::operator-(const Vector4& vector) const
{
	Vector4 vectorRes;
	vectorRes.x = this->x - vector.x;
	vectorRes.y = this->y - vector.y;
	vectorRes.z = this->z - vector.z;
	vectorRes.w = this->w - vector.w;

	return vectorRes;
}
Vector4 Vector4::operator*(const Vector4& vector) const
{
	Vector4 vectorRes;
	vectorRes.x = this->x * vector.x;
	vectorRes.y = this->y * vector.y;
	vectorRes.z = this->z * vector.z;
	vectorRes.w = this->w * vector.w;

	return vectorRes;
}
Vector4 Vector4::operator/(const Vector4& vector) const
{
	Vector4 vectorRes;
	vectorRes.x = this->x / vector.x;
	vectorRes.y = this->y / vector.y;
	vectorRes.z = this->z / vector.z;
	vectorRes.w = this->w / vector.w;

	return vectorRes;
}
Vector4 Vector4::operator*(float scale) const
{
	Vector4 vectorRes;
	vectorRes.x = this->x * scale;
	vectorRes.y = this->y * scale;
	vectorRes.z = this->z * scale;
	vectorRes.w = this->w * scale;

	return vectorRes;
}
Vector4 Vector4::operator/(float scale) const
{
	Vector4 vectorRes;
	vectorRes.x = this->x / scale;
	vectorRes.y = this->y / scale;
	vectorRes.z = this->z / scale;
	vectorRes.w = this->w / scale;

	return vectorRes;
}
Vector4& Vector4::operator+=(const Vector4& vector)
{
	this->x += vector.x;
	this->y += vector.y;
	this->z += vector.z;
	this->w += vector.w;

	return *this;
}
Vector4& Vector4::operator-=(const Vector4& vector)
{
	this->x -= vector.x;
	this->y -= vector.y;
	this->z -= vector.z;
	this->w -= vector.w;

	return *this;
}
Vector4& Vector4::operator*=(const Vector4& vector)
{
	this->x *= vector.x;
	this->y *= vector.y;
	this->z *= vector.z;
	this->w *= vector.w;

	return *this;
}
Vector4& Vector4::operator/=(const Vector4& vector)
{
	this->x /= vector.x;
	this->y /= vector.y;
	this->z /= vector.z;
	this->w /= vector.w;

	return *this;
}
Vector4& Vector4::operator*=(float scale)
{
	this->x *= scale;
	this->y *= scale;
	this->z *= scale;
	this->w *= scale;

	return *this;
}
Vector4& Vector4::operator/=(float scale)
{
	this->x /= scale;
	this->y /= scale;
	this->z /= scale;
	this->w /= scale;

	return *this;
}
Vector4 Vector4::operator-() const
{
	Vector4 vectorRes;
	vectorRes.x = -x;
	vectorRes.y = -y;
	vectorRes.z = -z;
	vectorRes.w = -w;

	return vectorRes;
}

// Compare functions
bool Vector4::operator==(const Vector4& vector) const
{
	return x == vector.x && y == vector.y && z == vector.z && w == vector.w;
}
bool Vector4::operator<(const Vector4& vector) const
{
	return x < vector.x&& y < vector.y&& z < vector.z&& w < vector.w;
}
bool Vector4::operator>(const Vector4& vector) const
{
	return vector < *this;
}
bool Vector4::operator<=(const Vector4& vector) const
{
	return x <= vector.x && y <= vector.y && z <= vector.z && w <= vector.w;
}
bool Vector4::operator>=(const Vector4& vector) const
{
	return vector <= *this;
}
bool Vector4::isEqualPrec(const Vector4& vector, float precision) const
{
	return fabsf(vector.x - x) <= precision && fabsf(vector.y - y) <= precision && fabsf(vector.z - z) <= precision && fabsf(vector.w - w) <= precision;
}
bool Vector4::isEqualPrec(const Vector4& vector, const Vector4& precision) const
{
	return fabsf(vector.x - x) <= precision.x && fabsf(vector.y - y) <= precision.y && fabsf(vector.z - z) <= precision.z && fabs(vector.w - w) <= precision.w;
}
Vector4 Vector4::isEqualVec(const Vector4& vector) const
{
	Vector4 result;
	result.x = vector.x == x;
	result.y = vector.y == y;
	result.z = vector.z == z;
	result.w = vector.w == w;
	return result;
}
Vector4 Vector4::isEqualPrecVec(const Vector4& vector, const Vector4& precision) const
{
	Vector4 result;
	result.x = fabsf(vector.x - x) <= precision.x;
	result.y = fabsf(vector.y - y) <= precision.y;
	result.z = fabsf(vector.z - z) <= precision.z;
	result.w = fabsf(vector.w - w) <= precision.w;
	return result;
}
