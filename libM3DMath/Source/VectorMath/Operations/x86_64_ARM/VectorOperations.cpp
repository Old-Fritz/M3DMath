#include "M3DMath.h"

/// Implementation of Base vector operations

using namespace M3DM;

// Vector2 and Vector3
Vector3 M3DM::operator*(const Vector3& vector1, const Vector2& vector2)
{
	Vector3 vectorRes;
	vectorRes.x = vector1.x * vector2.x;
	vectorRes.y = vector1.y * vector2.y;
	vectorRes.z = vector1.z;

	return vectorRes;
}
Vector3 M3DM::operator*(const Vector2& vector1, const Vector3& vector2)
{
	Vector3 vectorRes;
	vectorRes.x = vector1.x * vector2.x;
	vectorRes.y = vector1.y * vector2.y;
	vectorRes.z = vector2.z;

	return vectorRes;
}
Vector3 M3DM::operator/(const Vector3& vector1, const Vector2& vector2)
{
	Vector3 vectorRes;
	vectorRes.x = vector1.x / vector2.x;
	vectorRes.y = vector1.y / vector2.y;
	vectorRes.z = vector1.z;

	return vectorRes;
}
Vector3 M3DM::operator/(const Vector2& vector1, const Vector3& vector2)
{
	Vector3 vectorRes;
	vectorRes.x = vector1.x / vector2.x;
	vectorRes.y = vector1.y / vector2.y;
	vectorRes.z = vector2.z;

	return vectorRes;
}
Vector3 M3DM::operator+(const Vector3& vector1, const Vector2& vector2)
{
	Vector3 vectorRes;
	vectorRes.x = vector1.x + vector2.x;
	vectorRes.y = vector1.y + vector2.y;
	vectorRes.z = vector1.z;

	return vectorRes;
}
Vector3 M3DM::operator+(const Vector2& vector1, const Vector3& vector2)
{
	Vector3 vectorRes;
	vectorRes.x = vector1.x + vector2.x;
	vectorRes.y = vector1.y + vector2.y;
	vectorRes.z = vector2.z;

	return vectorRes;
}
Vector3 M3DM::operator-(const Vector3& vector1, const Vector2& vector2)
{
	Vector3 vectorRes;
	vectorRes.x = vector1.x - vector2.x;
	vectorRes.y = vector1.y - vector2.y;
	vectorRes.z = vector1.z;

	return vectorRes;
}
Vector3 M3DM::operator-(const Vector2& vector1, const Vector3& vector2)
{
	Vector3 vectorRes;
	vectorRes.x = vector1.x - vector2.x;
	vectorRes.y = vector1.y - vector2.y;
	vectorRes.z = -vector2.z;

	return vectorRes;
}

// Vector2 and Vector4
Vector4 M3DM::operator*(const Vector4& vector1, const Vector2& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x * vector2.x;
	vectorRes.y = vector1.y * vector2.y;
	vectorRes.z = vector1.z;
	vectorRes.w = vector1.w;

	return vectorRes;
}
Vector4 M3DM::operator*(const Vector2& vector1, const Vector4& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x * vector2.x;
	vectorRes.y = vector1.y * vector2.y;
	vectorRes.z = vector2.z;
	vectorRes.w = vector2.w;

	return vectorRes;
}
Vector4 M3DM::operator/(const Vector4& vector1, const Vector2& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x / vector2.x;
	vectorRes.y = vector1.y / vector2.y;
	vectorRes.z = vector1.z;
	vectorRes.w = vector1.w;

	return vectorRes;
}
Vector4 M3DM::operator/(const Vector2& vector1, const Vector4& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x / vector2.x;
	vectorRes.y = vector1.y / vector2.y;
	vectorRes.z = vector2.z;
	vectorRes.w = vector2.w;

	return vectorRes;
}
Vector4 M3DM::operator+(const Vector4& vector1, const Vector2& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x + vector2.x;
	vectorRes.y = vector1.y + vector2.y;
	vectorRes.z = vector1.z;
	vectorRes.w = vector1.w;

	return vectorRes;
}
Vector4 M3DM::operator+(const Vector2& vector1, const Vector4& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x + vector2.x;
	vectorRes.y = vector1.y + vector2.y;
	vectorRes.z = vector2.z;
	vectorRes.w = vector2.w;

	return vectorRes;
}
Vector4 M3DM::operator-(const Vector4& vector1, const Vector2& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x - vector2.x;
	vectorRes.y = vector1.y - vector2.y;
	vectorRes.z = vector1.z;
	vectorRes.w = vector1.w;

	return vectorRes;
}
Vector4 M3DM::operator-(const Vector2& vector1, const Vector4& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x - vector2.x;
	vectorRes.y = vector1.y - vector2.y;
	vectorRes.z = -vector2.z;
	vectorRes.w = -vector2.w;

	return vectorRes;
}

// Vector3 and Vector4
Vector4 M3DM::operator*(const Vector4& vector1, const Vector3& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x * vector2.x;
	vectorRes.y = vector1.y * vector2.y;
	vectorRes.z = vector1.z * vector2.z;
	vectorRes.w = vector1.w;

	return vectorRes;
}
Vector4 M3DM::operator*(const Vector3& vector1, const Vector4& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x * vector2.x;
	vectorRes.y = vector1.y * vector2.y;
	vectorRes.z = vector1.z * vector2.z;
	vectorRes.w = vector2.w;

	return vectorRes;
}
Vector4 M3DM::operator/(const Vector4& vector1, const Vector3& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x / vector2.x;
	vectorRes.y = vector1.y / vector2.y;
	vectorRes.z = vector1.z / vector2.z;
	vectorRes.w = vector1.w;

	return vectorRes;
}
Vector4 M3DM::operator/(const Vector3& vector1, const Vector4& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x / vector2.x;
	vectorRes.y = vector1.y / vector2.y;
	vectorRes.z = vector1.z / vector2.z;
	vectorRes.w = vector2.w;

	return vectorRes;
}
Vector4 M3DM::operator+(const Vector4& vector1, const Vector3& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x + vector2.x;
	vectorRes.y = vector1.y + vector2.y;
	vectorRes.z = vector1.z + vector2.z;
	vectorRes.w = vector1.w;

	return vectorRes;
}
Vector4 M3DM::operator+(const Vector3& vector1, const Vector4& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x + vector2.x;
	vectorRes.y = vector1.y + vector2.y;
	vectorRes.z = vector1.z + vector2.z;
	vectorRes.w = vector2.w;

	return vectorRes;
}
Vector4 M3DM::operator-(const Vector4& vector1, const Vector3& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x - vector2.x;
	vectorRes.y = vector1.y - vector2.y;
	vectorRes.z = vector1.z - vector2.z;
	vectorRes.w = vector1.w;

	return vectorRes;
}
Vector4 M3DM::operator-(const Vector3& vector1, const Vector4& vector2)
{
	Vector4 vectorRes;
	vectorRes.x = vector1.x - vector2.x;
	vectorRes.y = vector1.y - vector2.y;
	vectorRes.z = vector1.z - vector2.z;
	vectorRes.w = -vector2.w;

	return vectorRes;
}

// Scalar operations
Vector2 M3DM::operator*(Float scale, const Vector2& vector)
{
	return vector*scale;
}
Vector3 M3DM::operator*(Float scale, const Vector3& vector)
{
	return vector*scale;
}
Vector4 M3DM::operator*(Float scale, const Vector4& vector)
{
	return vector*scale;
}
Vector2 M3DM::operator/(Float scale, const Vector2& vector)
{
	Vector2 vectorRes;
	vectorRes.x = scale / vector.x;
	vectorRes.y = scale / vector.y;

	return vectorRes;
}
Vector3 M3DM::operator/(Float scale, const Vector3& vector)
{
	Vector3 vectorRes;
	vectorRes.x = scale / vector.x;
	vectorRes.y = scale / vector.y;
	vectorRes.z = scale / vector.z;

	return vectorRes;
}
Vector4 M3DM::operator/(Float scale, const Vector4& vector)
{
	Vector4 vectorRes;
	vectorRes.x = scale / vector.x;
	vectorRes.y = scale / vector.y;
	vectorRes.z = scale / vector.z;
	vectorRes.w = scale / vector.w;

	return vectorRes;
}
