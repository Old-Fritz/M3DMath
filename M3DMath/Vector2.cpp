#pragma once

#include "M3DMath.h"

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

Vector2 Vector2::operator*(float scale) const
{
	Vector2 vectorRes;
	vectorRes.x = this->x  * scale;
	vectorRes.y = this->y  * scale;

	return vectorRes;
}

Vector2 Vector2::operator/(float scale) const
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

Vector2& Vector2::operator*=(float scale)
{
	this->x *= scale;
	this->y *= scale;

	return *this;
}

Vector2& Vector2::operator/=(float scale)
{
	this->x /= scale;
	this->y /= scale;

	return *this;
}

bool Vector2::operator==(const Vector2& vector) const
{
	return x == vector.x && y == vector.y;
}
