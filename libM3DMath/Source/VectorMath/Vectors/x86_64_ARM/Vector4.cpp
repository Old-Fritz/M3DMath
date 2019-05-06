#include "M3DMath.h"

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

bool Vector4::operator==(const Vector4& vector) const
{
	return x == vector.x && y == vector.y && z == vector.z && w == vector.w;
}