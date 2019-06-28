#include "M3DMath.h"
#include <math.h>

using namespace M3DM;

DoubleVectorF VECCALL M3DM::doubleVecFCross3D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	__m256 result = _mm256_sub_ps(
		_mm256_mul_ps(vec1, _mm256_shuffle_ps(vec2, vec2, _MM_SHUFFLE(3, 0, 2, 1))),
		_mm256_mul_ps(vec2, _mm256_shuffle_ps(vec1, vec1, _MM_SHUFFLE(3, 0, 2, 1)))
	);
	return  _mm256_shuffle_ps(result, result, _MM_SHUFFLE(3, 0, 2, 1));
}
DoubleVectorF VECCALL M3DM::doubleVecFProject3D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return vec2 * doubleVecFDotVec3D(vec1, vec2) / vec2.sqrLengthVec3D();
}
DoubleVectorF VECCALL M3DM::doubleVecFReflect3D(DoubleVectorF vec, DoubleVectorF normal)
{
	// normal normalized
	DoubleVectorF ind = normal * doubleVecFDotVec3D(vec, normal);
	return vec - ind - ind;
}
DoubleVectorF VECCALL M3DM::doubleVecFRefract3D(DoubleVectorF vec, DoubleVectorF normal, float refractionIndex)
{
	DoubleVectorF dot = doubleVecFDotVec3D(vec, normal);
	DoubleVectorF one = DoubleVectorF(1);
	DoubleVectorF refractionIndexVec = DoubleVectorF(refractionIndex);
	DoubleVectorF ref = one - refractionIndexVec * refractionIndexVec * (one - dot * dot);

	// total reflection
	DoubleVectorF zero = DoubleVectorF();
	if (ref < zero)
		return zero;

	return vec * refractionIndexVec - (refractionIndexVec * dot + ref.sqrt()) * normal;
}
DoubleVectorF VECCALL M3DM::doubleVecFIntersectLines3D(DoubleVectorF l1p1, DoubleVectorF l1p2, DoubleVectorF l2p1, DoubleVectorF l2p2)
{
	DoubleVectorF line1Vec = l1p2 - l1p1;
	DoubleVectorF line2Vec = l2p2 - l2p1;
	DoubleVectorF r = l2p1 - l1p1;
	DoubleVectorF lineCross = doubleVecFCross3D(line2Vec, line1Vec);
	DoubleVectorF rCross = doubleVecFCross3D(line2Vec, r);
	DoubleVectorF rCrossLen = rCross.lengthVec3D();
	DoubleVectorF lineCrossLen = lineCross.lengthVec3D();
	DoubleVectorF zero = DoubleVectorF();
	if (rCrossLen == zero || lineCrossLen == zero)
		return DoubleVectorF(INFINITY, INFINITY, INFINITY, 0, INFINITY, INFINITY, INFINITY, 0);
	DoubleVectorF shift = rCrossLen / lineCrossLen;
	DoubleVectorF sign = rCross * lineCross >= DoubleVectorF() ? DoubleVectorF(1) : DoubleVectorF(-1);
	DoubleVectorF point = l1p1 + line1Vec * shift * sign;

	return point;
}

DoubleVectorF VECCALL M3DM::doubleVecFDistanceVec3D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return (vec1 - vec2).lengthVec3D();
}
DoubleVectorF VECCALL M3DM::doubleVecFRefractVec3D(DoubleVectorF vec, DoubleVectorF normal, DoubleVectorF refractionIndex)
{
	DoubleVectorF dot = doubleVecFDotVec3D(vec, normal);
	DoubleVectorF one = DoubleVectorF(1);
	DoubleVectorF ref = one - refractionIndex * refractionIndex * (one - dot * dot);

	// total reflection
	DoubleVectorF zero = DoubleVectorF();
	if (ref < zero)
		return zero;

	return vec * refractionIndex - (refractionIndex * dot + ref.sqrt()) * normal;
}
DoubleVectorF VECCALL M3DM::doubleVecFDotVec3D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return _mm256_dp_ps(vec1, vec2, 0b01111111);
}
DoubleVectorF VECCALL M3DM::doubleVecFLinePointDistanceVec3D(DoubleVectorF linePoint1, DoubleVectorF linePoint2, DoubleVectorF point)
{
	DoubleVectorF lineVec = linePoint2 - linePoint1;
	DoubleVectorF lineToPointVec = linePoint1 - point;

	DoubleVectorF distance = doubleVecFCross3D(lineVec, lineToPointVec).lengthVec3D() / lineVec.lengthVec3D();

	return distance;
}
DoubleVectorF VECCALL M3DM::doubleVecFAngleBetweenVec3D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return (doubleVecFDotVec3D(vec1, vec2) / (vec1.lengthVec3D() * vec2.lengthVec3D())).acos();
}
DoubleVectorF VECCALL M3DM::doubleVecFAngleBetweenNormalsVec3D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return doubleVecFDotVec3D(vec1, vec2).acos();
}


void VECCALL M3DM::doubleVecFDistance3D(DoubleVectorF vec1, DoubleVectorF vec2, float& dist1, float& dist2)
{
	(vec1 - vec2).length3D(dist1, dist2);
}
void VECCALL M3DM::doubleVecFDot3D(DoubleVectorF vec1, DoubleVectorF vec2, float& dot1, float& dot2)
{
	DoubleVectorF result = doubleVecFDotVec3D(vec1, vec2);
	dot1 = result.get(0);
	dot2 = result.get(4);
}
void VECCALL M3DM::doubleVecFAngleBetween3D(DoubleVectorF vec1, DoubleVectorF vec2, float& angle1, float& angle2)
{
	DoubleVectorF result = doubleVecFAngleBetweenVec3D(vec1, vec2);
	angle1 = result.get(0);
	angle2 = result.get(4);
}
void VECCALL M3DM::doubleVecFAngleBetweenNormals3D(DoubleVectorF vec1, DoubleVectorF vec2, float& angle1, float& angle2)
{
	DoubleVectorF result = doubleVecFAngleBetweenNormalsVec3D(vec1, vec2);
	angle1 = result.get(0);
	angle2 = result.get(4);
}
void VECCALL M3DM::doubleVecFLinePointDistance3D(DoubleVectorF linePoint1, DoubleVectorF linePoint2, DoubleVectorF point, float& dist1, float& dist2)
{
	DoubleVectorF result = doubleVecFLinePointDistanceVec3D(linePoint1, linePoint2, point);
	dist1 = result.get(0);
	dist2 = result.get(4);
}
void VECCALL M3DM::doubleVecFCmp3D(DoubleVectorF vec1, DoubleVectorF vec2, int type, bool& result1, bool& result2)
{
	// create mask 1 1 1 0
	int mask = 0b0111;
	__m256 cmpResult;
	// cmp
	switch (type)
	{
	case CMP_EQ:
		cmpResult = _mm256_cmp_ps(vec1, vec2, _CMP_EQ_OQ);
		break;
	case CMP_LE:
		cmpResult = _mm256_cmp_ps(vec1, vec2, _CMP_LE_OQ);
		break;
	case CMP_LT:
		cmpResult = _mm256_cmp_ps(vec1, vec2, _CMP_LT_OQ);
		break;
	case CMP_GE:
		cmpResult = _mm256_cmp_ps(vec1, vec2, _CMP_GE_OQ);
		break;
	case CMP_GT:
		cmpResult = _mm256_cmp_ps(vec1, vec2, _CMP_GT_OQ);
		break;
	default:
		cmpResult = __m256();
		break;
	}
	int resultMask = _mm256_movemask_ps(cmpResult);
	result1 = (resultMask & mask) == mask;
	result2 = ((resultMask >> 4) & mask) == mask;
}
void VECCALL M3DM::doubleVecFInBound3D(DoubleVectorF vec, DoubleVectorF left, DoubleVectorF right, bool& result1, bool& result2)
{
	bool tempResLE1, tempResLE2, tempResGE1, tempResGE2;
	doubleVecFCmp3D(vec, right, CMP_LE, tempResLE1, tempResLE2);
	doubleVecFCmp3D(vec, left, CMP_GE, tempResGE1, tempResGE2);
	result1 = tempResLE1 && tempResGE1;
	result2 = tempResLE2 && tempResGE2;
}