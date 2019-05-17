#include "M3DMath.h"
#include <cmath>

using namespace M3DM;

/// Implementation of Vector2  functions

float M3DM::vec2Distance(const Vector2& vec1, const Vector2& vec2)
{
	return (vec1 - vec2).length();
}

Vector2 M3DM::vec2Max(const Vector2& vec1, const Vector2& vec2)
{
	Vector2 vecResult;

	vecResult.x = fmaxf(vec1.x, vec2.x);
	vecResult.y = fmaxf(vec1.y, vec2.y);

	return vecResult;
}

Vector2 M3DM::vec2Min(const Vector2& vec1, const Vector2& vec2)
{
	Vector2 vecResult;

	vecResult.x = fminf(vec1.x, vec2.x);
	vecResult.y = fminf(vec1.y, vec2.y);

	return vecResult;
}

Vector2 M3DM::vec2Project(const Vector2& vec1, const Vector2& vec2)
{
	// (normalized vec2) * projection length (dot(vec1, vec2)/vec2.length)
	// = vec2 * dot(vec1, vec2)/(vec2.length)^2

	return vec2 * vec2Dot(vec1, vec2) / vec2.sqrLength();
}

Vector2 M3DM::vec2IntersectLines(const Vector2& l1p1, const Vector2& l1p2, const Vector2& l2p1, const Vector2& l2p2)
{
	// TODO: for 3d:  point = l1p1 + cross(l2p2-l2p1, l2p1-l1p1)/cross(l2p2-l2p1, l1p2-l1p1)*(l1p2-l1p1)
	Vector2 line1Vec = l1p2 - l1p1;
	Vector2 line2Vec = l2p2 - l2p1;
	Vector2 r = l2p1 - l1p1;
	float dot = vec2Cross(line2Vec, line1Vec);
	float line1Dot = vec2Cross(line2Vec, r);
	float shift = line1Dot / dot;
	Vector2 point = l1p1 + line1Vec * shift;

	return point;
}

Vector2 M3DM::vec2Reflect(const Vector2& vec, const Vector2& normal)
{
	// normal normalized
	return vec - 2 * vec2Dot(vec, normal) * normal;
}

Vector2 M3DM::vec2Refract(const Vector2& vec, const Vector2& normal, float refractionIndex)
{
	float dot = vec2Dot(vec, normal);
	float ref = 1 - refractionIndex * refractionIndex * (1 - dot * dot);

	// total reflection
	if (ref < 0)
		return Vector2();

	return vec * refractionIndex - (refractionIndex * dot + sqrt(ref)) * normal;
}

Vector2 M3DM::vec2Pow(const Vector2& vec, const Vector2& pow)
{
	Vector2 vectorRes;

	vectorRes.x = powf(vec.x, pow.x);
	vectorRes.y = powf(vec.y, pow.y);

	return vectorRes;
}

Vector2 M3DM::vec2Pow(const Vector2& vec, float pow)
{
	Vector2 vectorRes;

	vectorRes.x = powf(vec.x, pow);
	vectorRes.y = powf(vec.y, pow);

	return vectorRes;
}

Vector2 M3DM::vec2Lerp(const Vector2& vec1, const Vector2& vec2, float value)
{
	return vec1 * value + vec2 * (1 - value);
}

float M3DM::vec2Dot(const Vector2& vec1, const Vector2& vec2)
{
	return vec1.x* vec2.x + vec1.y * vec2.y;
}

float M3DM::vec2Cross(const Vector2& vec1, const Vector2& vec2)
{
	return vec1.x* vec2.y - vec1.y * vec2.x;
}

float M3DM::vec2LinePointDistance(const Vector2& linePoint1, const Vector2& linePoint2, const Vector2& point)
{
	Vector2 lineVec = linePoint2 - linePoint1;
	Vector2 lineToPointVec = linePoint1 - point;

	float distance = abs(vec2Cross(lineVec, lineToPointVec)) / lineVec.length();

	return distance;
}

float M3DM::vec2AngleBetween(const Vector2& vec1, const Vector2& vec2)
{
	return acosf(vec2Dot(vec1, vec2)/(vec1.length()*vec2.length()));
}

bool M3DM::vec2InBound(const Vector2& vec, const Vector2& left, const Vector2& right)
{
	return vec <= right && vec >= left;
}
