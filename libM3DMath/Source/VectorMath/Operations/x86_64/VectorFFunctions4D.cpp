#include "M3DMath.h"
#include <cmath>

using namespace M3DM;

VectorF VECCALL M3DM::vecFMax(VectorF vec1, VectorF vec2)
{
	return _mm_max_ps(vec1, vec2);
}
VectorF VECCALL M3DM::vecFMin(VectorF vec1, VectorF vec2)
{
	return _mm_min_ps(vec1, vec2);
}
VectorF VECCALL M3DM::vecFPow(VectorF vec, VectorF pow)
{
	return _mm_pow_ps(vec, pow);
}
VectorF VECCALL M3DM::vecFPow(VectorF vec, float pow)
{
	return _mm_pow_ps(vec, _mm_set_ps1(pow));
}
VectorF VECCALL M3DM::vecFLerp(VectorF vec1, VectorF vec2, float value)
{
	VectorF one = VectorF(1);
	VectorF valueVec = VectorF(value);
	return vec1 * valueVec + vec2 * (one - valueVec);
}


VectorF VECCALL M3DM::vecFProject4D(VectorF vec1, VectorF vec2)
{
	return vec2 * vecFDotVec4D(vec1, vec2) / vec2.sqrLengthVec4D();
}
VectorF VECCALL M3DM::vecFReflect4D(VectorF vec, VectorF normal)
{
	// normal normalized
	VectorF ind = normal * vecFDotVec4D(vec, normal);
	return vec - ind - ind;
}
VectorF VECCALL M3DM::vecFRefract4D(VectorF vec, VectorF normal, float refractionIndex)
{
	VectorF dot = vecFDotVec4D(vec, normal);
	VectorF one = VectorF(1);
	VectorF refractionIndexVec = VectorF(refractionIndex);
	VectorF ref = one - refractionIndexVec * refractionIndexVec * (one - dot * dot);

	// total reflection
	VectorF zero = VectorF();
	if (ref < zero)
		return zero;

	return vec * refractionIndexVec - (refractionIndexVec * dot + ref.sqrt()) * normal;
}

VectorF VECCALL M3DM::vecFDistanceVec4D(VectorF vec1, VectorF vec2)
{
	return (vec1 - vec2).lengthVec4D();
}
VectorF VECCALL M3DM::vecFRefractVec4D(VectorF vec, VectorF normal, VectorF refractionIndex)
{
	VectorF dot = vecFDotVec4D(vec, normal);
	VectorF one = VectorF(1);
	VectorF ref = one - refractionIndex * refractionIndex * (one - dot * dot);

	// total reflection
	VectorF zero = VectorF();
	if (ref < zero)
		return zero;

	return vec * refractionIndex - (refractionIndex * dot + ref.sqrt()) * normal;
}
VectorF VECCALL M3DM::vecFDotVec4D(VectorF vec1, VectorF vec2)
{
	return _mm_dp_ps(vec1, vec2, 0b11111111);
}
VectorF VECCALL M3DM::vecFAngleBetweenVec4D(VectorF vec1, VectorF vec2)
{
	return (vecFDotVec4D(vec1, vec2) / (vec1.lengthVec4D() * vec2.lengthVec4D())).acos();
}
VectorF VECCALL M3DM::vecFAngleBetweenNormalsVec4D(VectorF vec1, VectorF vec2)
{
	return vecFDotVec4D(vec1, vec2).acos();
}

float VECCALL M3DM::vecFDistance4D(VectorF vec1, VectorF vec2)
{
	return vecFDistanceVec4D(vec1, vec2).get(0);
}
float VECCALL M3DM::vecFDot4D(VectorF vec1, VectorF vec2)
{
	return vecFDotVec4D(vec1, vec2).get(0);
}
float VECCALL M3DM::vecFAngleBetween4D(VectorF vec1, VectorF vec2)
{
	return vecFAngleBetweenVec4D(vec1, vec2).get(0);
}
float VECCALL M3DM::vecFAngleBetweenNormals4D(VectorF vec1, VectorF vec2)
{
	return vecFAngleBetweenNormalsVec4D(vec1, vec2).get(0);
}
bool VECCALL M3DM::vecFCmp4D(VectorF vec1, VectorF vec2, int type)
{
	// create mask 1 1 1 1
	int mask = 0b1111;
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
bool VECCALL M3DM::vecFInBound4D(VectorF vec, VectorF left, VectorF right)
{
	return vecFCmp4D(vec, right, CMP_LE) && vecFCmp4D(vec, left, CMP_GE);
}