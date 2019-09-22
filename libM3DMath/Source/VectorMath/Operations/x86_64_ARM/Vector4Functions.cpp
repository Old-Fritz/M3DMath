#include "M3DMath.h"
#include <cmath>

using namespace M3DM;

/// Implementation of Vector4 functions

Vector4 M3DM::vec4Cross3D(const Vector4& vec1, const Vector4& vec2)
{
	Vector4 vecResult;

	vecResult.x = vec1.y * vec2.z - vec1.z * vec2.y;
	vecResult.y = vec1.z * vec2.x - vec1.x * vec2.z;
	vecResult.z = vec1.x * vec2.y - vec1.y * vec2.x;
	vecResult.w = 0;

	return vecResult;
}

Vector4 M3DM::vec4Lerp(const Vector4& vec1, const Vector4& vec2, Float value)
{
	return vec1 * value + vec2 * (1 - value);
}

Vector4 M3DM::vec4Max(const Vector4& vec1, const Vector4& vec2)
{
	Vector4 vecResult;

	vecResult.x = fmaxf(vec1.x, vec2.x);
	vecResult.y = fmaxf(vec1.y, vec2.y);
	vecResult.z = fmaxf(vec1.z, vec2.z);
	vecResult.w = fmaxf(vec1.w, vec2.w);

	return vecResult;
}

Vector4 M3DM::vec4Min(const Vector4& vec1, const Vector4& vec2)
{
	Vector4 vecResult;

	vecResult.x = fminf(vec1.x, vec2.x);
	vecResult.y = fminf(vec1.y, vec2.y);
	vecResult.z = fminf(vec1.z, vec2.z);
	vecResult.w = fminf(vec1.w, vec2.w);

	return vecResult;
}

Vector4 M3DM::vec4Project(const Vector4& vec1, const Vector4& vec2)
{
	return vec2 * vec4Dot(vec1, vec2) / vec2.sqrLength();
}

Vector4 M3DM::vec4IntersectLines3D(const Vector4& l1p1, const Vector4& l1p2, const Vector4& l2p1, const Vector4& l2p2)
{
	// point = l1p1 + cross(l2p2-l2p1, l2p1-l1p1)/cross(l2p2-l2p1, l1p2-l1p1)*(l1p2-l1p1)

	Vector4 line1Vec = l1p2 - l1p1;
	Vector4 line2Vec = l2p2 - l2p1;
	Vector4 r = l2p1 - l1p1;
	Vector4 lineCross = vec4Cross3D(line2Vec, line1Vec);
	Vector4 rCross = vec4Cross3D(line2Vec, r);
	Float rCrossLen = rCross.length();
	Float lineCrossLen = lineCross.length();
	if (rCrossLen == 0 || lineCrossLen == 0)
		return Vector4(INFINITY, INFINITY, INFINITY, 0);
	Float shift = rCrossLen / lineCrossLen;
	Float sign = rCross * lineCross >= Vector4() ? 1 : -1;
	Vector4 point = l1p1 + line1Vec * shift * sign;

	return point;
}

Vector4 M3DM::vec4Reflect(const Vector4& vec, const Vector4& normal)
{
	// normal normalized
	return vec - 2 * vec4Dot(vec, normal) * normal;
}

Vector4 M3DM::vec4Refract(const Vector4& vec, const Vector4& normal, Float refractionIndex)
{
	Float dot = vec4Dot(vec, normal);
	Float ref = 1 - refractionIndex * refractionIndex * (1 - dot * dot);

	// total reflection
	if (ref < 0)
		return Vector4();

	return vec * refractionIndex - (refractionIndex * dot + sqrt(ref)) * normal;
}

Vector4 M3DM::vec4Pow(const Vector4& vec, const Vector4& pow)
{
	Vector4 vectorRes;

	vectorRes.x = powf(vec.x, pow.x);
	vectorRes.y = powf(vec.y, pow.y);
	vectorRes.z = powf(vec.z, pow.z);
	vectorRes.w = powf(vec.w, pow.w);

	return vectorRes;
}

Vector4 M3DM::vec4Pow(const Vector4& vec, Float pow)
{
	Vector4 vectorRes;

	vectorRes.x = powf(vec.x, pow);
	vectorRes.y = powf(vec.y, pow);
	vectorRes.z = powf(vec.z, pow);
	vectorRes.w = powf(vec.w, pow);

	return vectorRes;
}

Float M3DM::vec4Dot(const Vector4& vec1, const Vector4& vec2)
{
	return vec1.x* vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;
}

Float M3DM::vec4Distance(const Vector4& vec1, const Vector4& vec2)
{
	return (vec1 - vec2).length();
}

Float M3DM::vec4LinePointDistance3D(const Vector4& linePoint1, const Vector4& linePoint2, const Vector4& point)
{
	Vector4 lineVec = linePoint2 - linePoint1;
	lineVec.w = 0;
	Vector4 lineToPointVec = linePoint1 - point;

	Float distance = vec4Cross3D(lineVec, lineToPointVec).length() / lineVec.length();

	return distance;
}

Float M3DM::vec4AngleBetween(const Vector4& vec1, const Vector4& vec2)
{
	return acosf(vec4Dot(vec1, vec2) / (vec1.length() * vec2.length()));
}

Float M3DM::vec4AngleBetweenNormals(const Vector4& vec1, const Vector4& vec2)
{
	return acosf(vec4Dot(vec1, vec2));
}

Bool M3DM::vec4InBound(const Vector4& vec, const Vector4& left, const Vector4& right)
{
	return vec <= right && vec >= left;
}
