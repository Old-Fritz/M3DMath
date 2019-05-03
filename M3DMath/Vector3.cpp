#pragma once

#include "M3DMath.h"

/// Implementation of Vector3

using namespace M3DM;

// Conversions
Vector3::Vector3(const Vector4& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
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

bool Vector3::operator==(const Vector3& vector) const
{
	return x == vector.x && y == vector.y && z == vector.z;
}
