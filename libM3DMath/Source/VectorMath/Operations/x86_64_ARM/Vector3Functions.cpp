#include "M3DMath.h"
#include <cmath>

using namespace M3DM;

/// Implementation of Vector3  functions

Vector3 M3DM::vec3Cross(const Vector3& vec1, const Vector3& vec2)
{
	Vector3 vecResult;

	vecResult.x = vec1.y * vec2.z - vec1.z * vec2.y;
	vecResult.y = vec1.z * vec2.x - vec1.x * vec2.z;
	vecResult.z = vec1.x * vec2.y - vec1.y * vec2.x;

	return vecResult;
}

Vector3 M3DM::vec3Lerp(const Vector3& vec1, const Vector3& vec2, float value)
{
	return vec1 * value + vec2 * (1 - value);
}

Vector3 M3DM::vec3Max(const Vector3& vec1, const Vector3& vec2)
{
	Vector3 vecResult;

	vecResult.x = fmaxf(vec1.x, vec2.x);
	vecResult.y = fmaxf(vec1.y, vec2.y);
	vecResult.z = fmaxf(vec1.z, vec2.z);

	return vecResult;
}

Vector3 M3DM::vec3Min(const Vector3& vec1, const Vector3& vec2)
{
	Vector3 vecResult;

	vecResult.x = fminf(vec1.x, vec2.x);
	vecResult.y = fminf(vec1.y, vec2.y);
	vecResult.z = fminf(vec1.z, vec2.z);

	return vecResult;
}

Vector3 M3DM::vec3Project(const Vector3& vec1, const Vector3& vec2)
{
	return vec2 * vec3Dot(vec1, vec2) / vec2.sqrLength();
}

Vector3 M3DM::vec3IntersectLines(const Vector3& l1p1, const Vector3& l1p2, const Vector3& l2p1, const Vector3& l2p2)
{
	// point = l1p1 + cross(l2p2-l2p1, l2p1-l1p1)/cross(l2p2-l2p1, l1p2-l1p1)*(l1p2-l1p1)

	Vector3 line1Vec = l1p2 - l1p1;
	Vector3 line2Vec = l2p2 - l2p1;
	Vector3 r = l2p1 - l1p1;
	Vector3 lineCross = vec3Cross(line2Vec, line1Vec);
	Vector3 rCross = vec3Cross(line2Vec, r);
	float rCrossLen = rCross.length();
	float lineCrossLen = lineCross.length();
	if (rCrossLen == 0 || lineCrossLen == 0)
		return Vector3(INFINITY, INFINITY, INFINITY);
	float shift = rCrossLen / lineCrossLen;
	float sign = rCross * lineCross >= Vector3() ? 1 : -1;
	Vector3 point = l1p1 + line1Vec * shift * sign;

	return point;
}

Vector3 M3DM::vec3Reflect(const Vector3& vec, const Vector3& normal)
{
	// normal normalized
	return vec - 2 * vec3Dot(vec, normal) * normal;
}

Vector3 M3DM::vec3Refract(const Vector3& vec, const Vector3& normal, float refractionIndex)
{
	float dot = vec3Dot(vec, normal);
	float ref = 1 - refractionIndex * refractionIndex * (1 - dot * dot);

	// total reflection
	if (ref < 0)
		return Vector3();

	return vec * refractionIndex - (refractionIndex * dot + sqrt(ref)) * normal;
}

Vector3 M3DM::vec3Pow(const Vector3& vec, const Vector3& pow)
{
	Vector3 vectorRes;

	vectorRes.x = powf(vec.x, pow.x);
	vectorRes.y = powf(vec.y, pow.y);
	vectorRes.z = powf(vec.z, pow.z);

	return vectorRes;
}

Vector3 M3DM::vec3Pow(const Vector3& vec, float pow)
{
	Vector3 vectorRes;

	vectorRes.x = powf(vec.x, pow);
	vectorRes.y = powf(vec.y, pow);
	vectorRes.z = powf(vec.z, pow);

	return vectorRes;
}

float M3DM::vec3Dot(const Vector3& vec1, const Vector3& vec2)
{
	return vec1.x* vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

float M3DM::vec3Distance(const Vector3& vec1, const Vector3& vec2)
{
	return (vec1 - vec2).length();
}

float M3DM::vec3LinePointDistance(const Vector3& linePoint1, const Vector3& linePoint2, const Vector3& point)
{
	Vector3 lineVec = linePoint2 - linePoint1;
	Vector3 lineToPointVec = linePoint1 - point;

	float distance = vec3Cross(lineVec, lineToPointVec).length() / lineVec.length();

	return distance;
}

float M3DM::vec3AngleBetween(const Vector3& vec1, const Vector3& vec2)
{
	return acosf(vec3Dot(vec1, vec2) / (vec1.length() * vec2.length()));
}

float M3DM::vec3AngleBetweenNormals(const Vector3& vec1, const Vector3& vec2)
{
	return acosf(vec3Dot(vec1, vec2));
}

bool M3DM::vec3InBound(const Vector3& vec, const Vector3& left, const Vector3& right)
{
	return vec <= right && vec >= left;
}