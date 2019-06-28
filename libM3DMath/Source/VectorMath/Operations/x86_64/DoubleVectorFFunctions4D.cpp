#include "M3DMath.h"
#include <math.h>

using namespace M3DM;

DoubleVectorF VECCALL M3DM::doubleVecFMax(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return _mm256_max_ps(vec1, vec2);
}
DoubleVectorF VECCALL M3DM::doubleVecFMin(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return _mm256_min_ps(vec1, vec2);
}
DoubleVectorF VECCALL M3DM::doubleVecFPow(DoubleVectorF vec, DoubleVectorF pow)
{
	return _mm256_pow_ps(vec, pow);
}
DoubleVectorF VECCALL M3DM::doubleVecFPow(DoubleVectorF vec, float pow)
{
	return _mm256_pow_ps(vec, _mm256_set1_ps(pow));
}
DoubleVectorF VECCALL M3DM::doubleVecFLerp(DoubleVectorF vec1, DoubleVectorF vec2, float value)
{
	DoubleVectorF one = DoubleVectorF(1);
	DoubleVectorF valueVec = DoubleVectorF(value);
	return vec1 * valueVec + vec2 * (one - valueVec);
}


DoubleVectorF VECCALL M3DM::doubleVecFProject4D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return vec2 * doubleVecFDotVec4D(vec1, vec2) / vec2.sqrLengthVec4D();
}
DoubleVectorF VECCALL M3DM::doubleVecFReflect4D(DoubleVectorF vec, DoubleVectorF normal)
{
	// normal normalized
	DoubleVectorF ind = normal * doubleVecFDotVec4D(vec, normal);
	return vec - ind - ind;
}
DoubleVectorF VECCALL M3DM::doubleVecFRefract4D(DoubleVectorF vec, DoubleVectorF normal, float refractionIndex)
{
	DoubleVectorF dot = doubleVecFDotVec4D(vec, normal);
	DoubleVectorF one = DoubleVectorF(1);
	DoubleVectorF refractionIndexVec = DoubleVectorF(refractionIndex);
	DoubleVectorF ref = one - refractionIndexVec * refractionIndexVec * (one - dot * dot);

	// total reflection
	DoubleVectorF zero = DoubleVectorF();
	if (ref < zero)
		return zero;

	return vec * refractionIndexVec - (refractionIndexVec * dot + ref.sqrt()) * normal;
}

DoubleVectorF VECCALL M3DM::doubleVecFDistanceVec4D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return (vec1 - vec2).lengthVec4D();
}
DoubleVectorF VECCALL M3DM::doubleVecFRefractVec4D(DoubleVectorF vec, DoubleVectorF normal, DoubleVectorF refractionIndex)
{
	DoubleVectorF dot = doubleVecFDotVec4D(vec, normal);
	DoubleVectorF one = DoubleVectorF(1);
	DoubleVectorF ref = one - refractionIndex * refractionIndex * (one - dot * dot);

	// total reflection
	DoubleVectorF zero = DoubleVectorF();
	if (ref < zero)
		return zero;

	return vec * refractionIndex - (refractionIndex * dot + ref.sqrt()) * normal;
}
DoubleVectorF VECCALL M3DM::doubleVecFDotVec4D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return _mm256_dp_ps(vec1, vec2, 0b11111111);
}
DoubleVectorF VECCALL M3DM::doubleVecFAngleBetweenVec4D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return (doubleVecFDotVec4D(vec1, vec2) / (vec1.lengthVec4D() * vec2.lengthVec4D())).acos();
}
DoubleVectorF VECCALL M3DM::doubleVecFAngleBetweenNormalsVec4D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return doubleVecFDotVec4D(vec1, vec2).acos();
}


void VECCALL M3DM::doubleVecFDistance4D(DoubleVectorF vec1, DoubleVectorF vec2, float& dist1, float& dist2)
{
	(vec1 - vec2).length4D(dist1, dist2);
}
void VECCALL M3DM::doubleVecFDot4D(DoubleVectorF vec1, DoubleVectorF vec2, float& dot1, float& dot2)
{
	DoubleVectorF result = doubleVecFDotVec4D(vec1, vec2);
	dot1 = result.get(0);
	dot2 = result.get(4);
}
void VECCALL M3DM::doubleVecFAngleBetween4D(DoubleVectorF vec1, DoubleVectorF vec2, float& angle1, float& angle2)
{
	DoubleVectorF result = doubleVecFAngleBetweenVec4D(vec1, vec2);
	angle1 = result.get(0);
	angle2 = result.get(4);
}
void VECCALL M3DM::doubleVecFAngleBetweenNormals4D(DoubleVectorF vec1, DoubleVectorF vec2, float& angle1, float& angle2)
{
	DoubleVectorF result = doubleVecFAngleBetweenNormalsVec4D(vec1, vec2);
	angle1 = result.get(0);
	angle2 = result.get(4);
}
void VECCALL M3DM::doubleVecFCmp4D(DoubleVectorF vec1, DoubleVectorF vec2, int type, bool& result1, bool& result2)
{
	// create mask 1 1 1 1
	int mask = 0b1111;
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
void VECCALL M3DM::doubleVecFInBound4D(DoubleVectorF vec, DoubleVectorF left, DoubleVectorF right, bool& result1, bool& result2)
{
	bool tempResLE1, tempResLE2, tempResGE1, tempResGE2;
	doubleVecFCmp4D(vec, right, CMP_LE, tempResLE1, tempResLE2);
	doubleVecFCmp4D(vec, left, CMP_GE, tempResGE1, tempResGE2);
	result1 = tempResLE1 && tempResGE1;
	result2 = tempResLE2 && tempResGE2;
}