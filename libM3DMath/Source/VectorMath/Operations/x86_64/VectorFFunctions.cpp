#include "M3DMath.h"
#include <cmath>

using namespace M3DM;

VectorF VECCALL M3DM::vecFCross3D(VectorF vec1, VectorF vec2)
{
	__m128 result = _mm_sub_ps(
		_mm_mul_ps(vec1, _mm_shuffle_ps(vec2, vec2, _MM_SHUFFLE(3, 0, 2, 1))),
		_mm_mul_ps(vec2, _mm_shuffle_ps(vec1, vec1, _MM_SHUFFLE(3, 0, 2, 1)))
	);
	return  _mm_shuffle_ps(result, result, _MM_SHUFFLE(3, 0, 2, 1));
}

VectorF VECCALL M3DM::vecFMax(VectorF vec1, VectorF vec2)
{
	return _mm_max_ps(vec1, vec2);
}

VectorF VECCALL M3DM::vecFMin(VectorF vec1, VectorF vec2)
{
	return _mm_min_ps(vec1, vec2);
}

VectorF VECCALL M3DM::vecFProject(VectorF vec1, VectorF vec2)
{
	return vec2 * vecFDotVec(vec1, vec2) / vec2.sqrLengthVec();
}

VectorF VECCALL M3DM::vecFIntersectLines3D(VectorF l1p1, VectorF l1p2, VectorF l2p1, VectorF l2p2)
{
	// point = l1p1 + cross(l2p2-l2p1, l2p1-l1p1)/cross(l2p2-l2p1, l1p2-l1p1)*(l1p2-l1p1)

	VectorF line1Vec = l1p2 - l1p1;
	VectorF line2Vec = l2p2 - l2p1;
	VectorF r = l2p1 - l1p1;
	VectorF lineCross = vecFCross3D(line2Vec, line1Vec);
	VectorF rCross = vecFCross3D(line2Vec, r);
	VectorF rCrossLen = rCross.lengthVec();
	VectorF lineCrossLen = lineCross.lengthVec();
	VectorF zero = VectorF();
	if (rCrossLen == zero || lineCrossLen == zero)
		return VectorF(INFINITY, INFINITY, INFINITY, 0);
	VectorF shift = rCrossLen / lineCrossLen;
	VectorF sign = rCross * lineCross >= VectorF() ? VectorF().replicate(1) : VectorF().replicate(-1);
	VectorF point = l1p1 + line1Vec * shift * sign;

	return point;
}

VectorF VECCALL M3DM::vecFReflect(VectorF vec, VectorF normal)
{
	// normal normalized
	return vec - normal* 2 * vecFDot(vec, normal);
}

VectorF VECCALL M3DM::vecFPow(VectorF vec, VectorF pow)
{
	return _mm_pow_ps(vec, pow);
}

VectorF VECCALL M3DM::vecFPow(VectorF vec, float pow)
{
	return _mm_pow_ps(vec, _mm_set_ps1(pow));
}

VectorF VECCALL M3DM::vecFRefract(VectorF vec, VectorF normal, float refractionIndex)
{
	VectorF dot = vecFDotVec(vec, normal);
	VectorF one = VectorF().replicate(1);
	VectorF refractionIndexVec = VectorF().replicate(refractionIndex);
	VectorF ref = one - refractionIndexVec * refractionIndexVec * (one - dot * dot);

	// total reflection
	VectorF zero = VectorF();
	if (ref < zero)
		return zero;

	return vec * refractionIndexVec - (refractionIndexVec * dot + ref.sqrt()) * normal;
}

VectorF VECCALL M3DM::vecFLerp(VectorF vec1, VectorF vec2, float value)
{
	VectorF one = VectorF().replicate(1);
	VectorF valueVec = VectorF().replicate(value);
	return vec1 * valueVec + vec2 * (one-valueVec);
}

float VECCALL M3DM::vecFDistance(VectorF vec1, VectorF vec2)
{
	return (vec1 - vec2).length();
}

float VECCALL M3DM::vecFDot(VectorF vec1, VectorF vec2)
{
	return vecFDotVec(vec1, vec2).get(0);
}

float VECCALL M3DM::vecFDot3D(VectorF vec1, VectorF vec2)
{
	return vecFDotVec3D(vec1, vec2).get(0);
}

float VECCALL M3DM::vecFLinePointDistance3D(VectorF linePoint1, VectorF linePoint2, VectorF point)
{
	VectorF lineVec = linePoint2 - linePoint1;
	VectorF lineToPointVec = linePoint1 - point;

	float distance = vecFCross3D(lineVec, lineToPointVec).length3D() / lineVec.length3D();

	return distance;
}

float VECCALL M3DM::vecFAngleBetween(VectorF vec1, VectorF vec2)
{
	return acosf(vecFDot(vec1, vec2) / (vec1.length() * vec2.length()));
}

float VECCALL M3DM::vecFAngleBetweenNormals(VectorF vec1, VectorF vec2)
{
	return acosf(vecFDot(vec1, vec2));
}

bool VECCALL M3DM::vecFInBound(VectorF vec, VectorF left, VectorF right)
{
	return vec <= right && vec >= left;
}

VectorF VECCALL M3DM::vecFDistanceVec(VectorF vec1, VectorF vec2)
{
	return (vec1 - vec2).lengthVec();
}

VectorF VECCALL M3DM::vecFRefractVec(VectorF vec, VectorF normal, VectorF refractionIndex)
{
	VectorF dot = vecFDotVec(vec, normal);
	VectorF one = VectorF().replicate(1);
	VectorF ref = one - refractionIndex * refractionIndex * (one - dot * dot);

	// total reflection
	VectorF zero = VectorF();
	if (ref < zero)
		return zero;

	return vec * refractionIndex - (refractionIndex * dot + ref.sqrt()) * normal;
}


VectorF VECCALL M3DM::vecFLerpVec(VectorF vec1, VectorF vec2, VectorF value)
{
	VectorF one = VectorF().replicate(1);
	return vec1 * value + vec2 * (one - value);
}

VectorF VECCALL M3DM::vecFDotVec(VectorF vec1, VectorF vec2)
{
	return _mm_dp_ps(vec1, vec2, 0b11111111);
}

VectorF VECCALL M3DM::vecFDotVec3D(VectorF vec1, VectorF vec2)
{
	return _mm_dp_ps(vec1, vec2, 0b01111111);
}

VectorF VECCALL M3DM::vecFLinePointDistanceVec3D(VectorF linePoint1, VectorF linePoint2, VectorF point)
{
	VectorF lineVec = linePoint2 - linePoint1;
	VectorF lineToPointVec = linePoint1 - point;

	VectorF distance = vecFCross3D(lineVec, lineToPointVec).lengthVec3D() / lineVec.lengthVec3D();

	return distance;
}

VectorF VECCALL M3DM::vecFAngleBetweenVec(VectorF vec1, VectorF vec2)
{
	return (vecFDotVec(vec1, vec2) / (vec1.lengthVec() * vec2.lengthVec())).acos();
}

VectorF VECCALL M3DM::vecFAngleBetweenNormalsVec(VectorF vec1, VectorF vec2)
{
	return vecFDotVec(vec1, vec2).acos();
}