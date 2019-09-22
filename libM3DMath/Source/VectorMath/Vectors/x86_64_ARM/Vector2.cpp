#include "M3DMath.h"
#include <cmath>

/// Implementation of Vector2

using namespace M3DM;

// Conversions
Vector2::Vector2(const Vector3& vector)
{
	x = vector.x;
	y = vector.y;
}
Vector2::Vector2(const Vector4& vector)
{
	x = vector.x;
	y = vector.y;
}
Vector2::operator Float*()
{
	return reinterpret_cast<Float*>(this);
}
Vector2::operator Float const*() const
{
	return reinterpret_cast<Float const*>(this);
}

// Operators
Vector2 Vector2::operator+(const Vector2& vector) const
{
	Vector2 vectorRes;
	vectorRes.x = this->x + vector.x;
	vectorRes.y = this->y + vector.y;

	return vectorRes;
}
Vector2 Vector2::operator-(const Vector2& vector) const
{
	Vector2 vectorRes;
	vectorRes.x = this->x - vector.x;
	vectorRes.y = this->y - vector.y;

	return vectorRes;
}
Vector2 Vector2::operator*(const Vector2& vector) const
{
	Vector2 vectorRes;
	vectorRes.x = this->x * vector.x;
	vectorRes.y = this->y * vector.y;

	return vectorRes;
}
Vector2 Vector2::operator/(const Vector2& vector) const
{
	Vector2 vectorRes;
	vectorRes.x = this->x / vector.x;
	vectorRes.y = this->y / vector.y;

	return vectorRes;
}
Vector2 Vector2::operator*(Float scale) const
{
	Vector2 vectorRes;
	vectorRes.x = this->x  * scale;
	vectorRes.y = this->y  * scale;

	return vectorRes;
}
Vector2 Vector2::operator/(Float scale) const
{
	Vector2 vectorRes;
	vectorRes.x = this->x / scale;
	vectorRes.y = this->y / scale;

	return vectorRes;
}
Vector2& Vector2::operator+=(const Vector2& vector)
{
	this->x += vector.x;
	this->y += vector.y;

	return *this;
}
Vector2& Vector2::operator-=(const Vector2& vector)
{
	this->x -= vector.x;
	this->y -= vector.y;

	return *this;
}
Vector2& Vector2::operator*=(const Vector2& vector)
{
	this->x *= vector.x;
	this->y *= vector.y;

	return *this;
}
Vector2& Vector2::operator/=(const Vector2& vector)
{
	this->x /= vector.x;
	this->y /= vector.y;

	return *this;
}
Vector2& Vector2::operator*=(Float scale)
{
	this->x *= scale;
	this->y *= scale;

	return *this;
}
Vector2& Vector2::operator/=(Float scale)
{
	this->x /= scale;
	this->y /= scale;

	return *this;
}
Vector2 Vector2::operator-()  const
{
	Vector2 vectorRes;
	vectorRes.x = -x;
	vectorRes.y = -y;
	return vectorRes;
}



// Compare functions

Bool Vector2::operator==(const Vector2& vector) const
{
	return x == vector.x && y == vector.y;
}
Bool Vector2::operator<(const Vector2& vector) const
{
	return x < vector.x&& y < vector.y;
}
Bool Vector2::operator>(const Vector2& vector) const
{
	return vector < *this;
}
Bool Vector2::operator<=(const Vector2& vector) const
{
	return x <= vector.x && y <= vector.y;
}
Bool Vector2::operator>=(const Vector2& vector) const
{
	return vector <= *this;
}
Bool Vector2::isEqualPrec(const Vector2& vector, Float precision) const
{
	return fabsf(vector.x - x) <= precision && fabsf(vector.y - y) <= precision;
}
Bool Vector2::isEqualPrec(const Vector2& vector, const Vector2& precision) const
{
	return fabsf(vector.x - x) <= precision.x && fabsf(vector.y - y) <= precision.y;
}
Vector2 Vector2::isEqualVec(const Vector2& vector) const
{
	Vector2 result;
	result.x = vector.x == x;
	result.y = vector.y == y;
	return result;
}
Vector2 Vector2::isEqualPrecVec(const Vector2& vector, const Vector2& precision) const
{
	Vector2 result;
	result.x = fabsf(vector.x - x) <= precision.x;
	result.y = fabsf(vector.y - y) <= precision.y;
	return result;
}