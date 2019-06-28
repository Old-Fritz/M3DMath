#include "M3DMath.h"
#include <math.h>

using namespace M3DM;

VectorF VECCALL M3DM::vecFCross3D(VectorF vec1, VectorF vec2)
{
	__m128 result = _mm_sub_ps(
		_mm_mul_ps(vec1, _mm_shuffle_ps(vec2, vec2, _MM_SHUFFLE(3, 0, 2, 1))),
		_mm_mul_ps(vec2, _mm_shuffle_ps(vec1, vec1, _MM_SHUFFLE(3, 0, 2, 1)))
	);
	return  _mm_shuffle_ps(result, result, _MM_SHUFFLE(3, 0, 2, 1));
}
VectorF VECCALL M3DM::vecFProject3D(VectorF vec1, VectorF vec2)
{
	return vec2 * vecFDotVec3D(vec1, vec2) / vec2.sqrLengthVec3D();
}
VectorF VECCALL M3DM::vecFReflect3D(VectorF vec, VectorF normal)
{
	// normal normalized
	VectorF ind = normal * vecFDotVec3D(vec, normal);
	return vec - ind - ind;
}
VectorF VECCALL M3DM::vecFRefract3D(VectorF vec, VectorF normal, float refractionIndex)
{
	VectorF dot = vecFDotVec3D(vec, normal);
	VectorF one = VectorF(1);
	VectorF refractionIndexVec = VectorF(refractionIndex);
	VectorF ref = one - refractionIndexVec * refractionIndexVec * (one - dot * dot);

	// total reflection
	VectorF zero = VectorF();
	if (ref < zero)
		return zero;

	return vec * refractionIndexVec - (refractionIndexVec * dot + ref.sqrt()) * normal;
}
VectorF VECCALL M3DM::vecFIntersectLines3D(VectorF l1p1, VectorF l1p2, VectorF l2p1, VectorF l2p2)
{
	VectorF line1Vec = l1p2 - l1p1;
	VectorF line2Vec = l2p2 - l2p1;
	VectorF r = l2p1 - l1p1;
	VectorF lineCross = vecFCross3D(line2Vec, line1Vec);
	VectorF rCross = vecFCross3D(line2Vec, r);
	VectorF rCrossLen = rCross.lengthVec3D();
	VectorF lineCrossLen = lineCross.lengthVec3D();
	VectorF zero = VectorF();
	if (rCrossLen == zero || lineCrossLen == zero)
		return VectorF(INFINITY, INFINITY, INFINITY, 0);
	VectorF shift = rCrossLen / lineCrossLen;
	VectorF sign = rCross * lineCross >= VectorF() ? VectorF(1) : VectorF(-1);
	VectorF point = l1p1 + line1Vec * shift * sign;

	return point;
}

VectorF VECCALL M3DM::vecFDistanceVec3D(VectorF vec1, VectorF vec2)
{
	return (vec1 - vec2).lengthVec3D();
}
VectorF VECCALL M3DM::vecFRefractVec3D(VectorF vec, VectorF normal, VectorF refractionIndex)
{
	VectorF dot = vecFDotVec3D(vec, normal);
	VectorF one = VectorF(1);
	VectorF ref = one - refractionIndex * refractionIndex * (one - dot * dot);

	// total reflection
	VectorF zero = VectorF();
	if (ref < zero)
		return zero;

	return vec * refractionIndex - (refractionIndex * dot + ref.sqrt()) * normal;
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
VectorF VECCALL M3DM::vecFAngleBetweenVec3D(VectorF vec1, VectorF vec2)
{
	return (vecFDotVec3D(vec1, vec2) / (vec1.lengthVec3D() * vec2.lengthVec3D())).acos();
}
VectorF VECCALL M3DM::vecFAngleBetweenNormalsVec3D(VectorF vec1, VectorF vec2)
{
	return vecFDotVec3D(vec1, vec2).acos();
}


float VECCALL M3DM::vecFDistance3D(VectorF vec1, VectorF vec2)
{
	return (vec1 - vec2).length3D();
}
float VECCALL M3DM::vecFDot3D(VectorF vec1, VectorF vec2)
{
	return vecFDotVec3D(vec1, vec2).get(0);
}
float VECCALL M3DM::vecFAngleBetween3D(VectorF vec1, VectorF vec2)
{
	return acosf(vecFDot3D(vec1, vec2) / (vec1.length3D() * vec2.length3D()));
}
float VECCALL M3DM::vecFAngleBetweenNormals3D(VectorF vec1, VectorF vec2)
{
	return acosf(vecFDot3D(vec1, vec2));
}
float VECCALL M3DM::vecFLinePointDistance3D(VectorF linePoint1, VectorF linePoint2, VectorF point)
{
	return vecFLinePointDistanceVec3D(linePoint1, linePoint2, point).get(0);
}
bool VECCALL M3DM::vecFCmp3D(VectorF vec1, VectorF vec2, int type)
{
	// create mask 1 1 1 0
	int mask = 0b0111;
	__m128 cmpResult;
	// cmp
	switch (type)
	{
	case CMP_EQ:
		cmpResult = _mm_cmpeq_ps(vec1, vec2);
		break;
	case CMP_LE:
		cmpResult = _mm_cmple_ps(vec1, vec2);
		break;
	case CMP_LT:
		cmpResult = _mm_cmplt_ps(vec1, vec2);
		break;
	case CMP_GE:
		cmpResult = _mm_cmpge_ps(vec1, vec2);
		break;
	case CMP_GT:
		cmpResult = _mm_cmpgt_ps(vec1, vec2);
		break;
	default:
		cmpResult = __m128();
		break;
	}
	return (_mm_movemask_ps(cmpResult) & mask) == mask;
}
bool VECCALL M3DM::vecFInBound3D(VectorF vec, VectorF left, VectorF right)
{
	return vecFCmp3D(vec, right, CMP_LE) && vecFCmp3D(vec, left, CMP_GE);
}