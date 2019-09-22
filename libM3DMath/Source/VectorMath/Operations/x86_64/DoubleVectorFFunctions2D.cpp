#include "M3DMath.h"
#include <math.h>

using namespace M3DM;

DoubleVectorF VECCALL M3DM::doubleVecFCross2D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	__m256 result = _mm256_sub_ps(
		_mm256_mul_ps(vec1.getData(), _mm256_shuffle_ps(vec2.getData(), vec2.getData(), _MM_SHUFFLE(3, 2, 1, 1))),
		_mm256_mul_ps(vec2.getData(), _mm256_shuffle_ps(vec1.getData(), vec1.getData(), _MM_SHUFFLE(3, 2, 1, 1)))
	);
	return  _mm256_shuffle_ps(result, result, _MM_SHUFFLE(0, 0, 0, 0));
}
DoubleVectorF VECCALL M3DM::doubleVecFProject2D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return vec2 * doubleVecFDotVec2D(vec1, vec2) / vec2.sqrLengthVec2D();
}
DoubleVectorF VECCALL M3DM::doubleVecFReflect2D(DoubleVectorF vec, DoubleVectorF normal)
{
	// normal normalized
	DoubleVectorF ind = normal * doubleVecFDotVec2D(vec, normal);
	return vec - ind - ind;
}
DoubleVectorF VECCALL M3DM::doubleVecFRefract2D(DoubleVectorF vec, DoubleVectorF normal, Float refractionIndex)
{
	DoubleVectorF dot = doubleVecFDotVec2D(vec, normal);
	DoubleVectorF one = DoubleVectorF(1);
	DoubleVectorF refractionIndexVec = DoubleVectorF(refractionIndex);
	DoubleVectorF ref = one - refractionIndexVec * refractionIndexVec * (one - dot * dot);

	// total reflection
	DoubleVectorF zero = DoubleVectorF();
	if (ref < zero)
		return zero;

	return vec * refractionIndexVec - (refractionIndexVec * dot + ref.sqrt()) * normal;
}
DoubleVectorF VECCALL M3DM::doubleVecFIntersectLines2D(DoubleVectorF l1p1, DoubleVectorF l1p2, DoubleVectorF l2p1, DoubleVectorF l2p2)
{
	DoubleVectorF line1Vec = l1p2 - l1p1;
	DoubleVectorF line2Vec = l2p2 - l2p1;
	DoubleVectorF r = l2p1 - l1p1;
	DoubleVectorF lineCross = doubleVecFCross2D(line2Vec, line1Vec);
	DoubleVectorF rCross = doubleVecFCross2D(line2Vec, r);
	DoubleVectorF rCrossLen = rCross.lengthVec2D();
	DoubleVectorF lineCrossLen = lineCross.lengthVec2D();
	DoubleVectorF zero = DoubleVectorF();
	if (rCrossLen == zero || lineCrossLen == zero)
		return DoubleVectorF(INFINITY, INFINITY, 0, 0, INFINITY, INFINITY, 0, 0);
	DoubleVectorF shift = rCrossLen / lineCrossLen;
	DoubleVectorF sign = rCross * lineCross >= DoubleVectorF() ? DoubleVectorF(1) : DoubleVectorF(-1);
	DoubleVectorF point = l1p1 + line1Vec * shift * sign;

	return point;
}

DoubleVectorF VECCALL M3DM::doubleVecFDistanceVec2D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return (vec1 - vec2).lengthVec2D();
}
DoubleVectorF VECCALL M3DM::doubleVecFRefractVec2D(DoubleVectorF vec, DoubleVectorF normal, DoubleVectorF refractionIndex)
{
	DoubleVectorF dot = doubleVecFDotVec2D(vec, normal);
	DoubleVectorF one = DoubleVectorF(1);
	DoubleVectorF ref = one - refractionIndex * refractionIndex * (one - dot * dot);

	// total reflection
	DoubleVectorF zero = DoubleVectorF();
	if (ref < zero)
		return zero;

	return vec * refractionIndex - (refractionIndex * dot + ref.sqrt()) * normal;
}
DoubleVectorF VECCALL M3DM::doubleVecFDotVec2D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return _mm256_dp_ps(vec1.getData(), vec2.getData(), 0b00111111);
}
DoubleVectorF VECCALL M3DM::doubleVecFLinePointDistanceVec2D(DoubleVectorF linePoint1, DoubleVectorF linePoint2, DoubleVectorF point)
{
	DoubleVectorF lineVec = linePoint2 - linePoint1;
	DoubleVectorF lineToPointVec = linePoint1 - point;

	DoubleVectorF distance = doubleVecFCross2D(lineVec, lineToPointVec).abs() / lineVec.lengthVec2D();

	return distance;
}
DoubleVectorF VECCALL M3DM::doubleVecFAngleBetweenVec2D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return (doubleVecFDotVec2D(vec1, vec2) / (vec1.lengthVec2D() * vec2.lengthVec2D())).acos();
}
DoubleVectorF VECCALL M3DM::doubleVecFAngleBetweenNormalsVec2D(DoubleVectorF vec1, DoubleVectorF vec2)
{
	return doubleVecFDotVec2D(vec1, vec2).acos();
}


void VECCALL M3DM::doubleVecFDistance2D(DoubleVectorF vec1, DoubleVectorF vec2, Float& dist1, Float& dist2)
{
	(vec1 - vec2).length2D(dist1, dist2);
}
void VECCALL M3DM::doubleVecFDot2D(DoubleVectorF vec1, DoubleVectorF vec2, Float& dot1, Float& dot2)
{
	DoubleVectorF result = doubleVecFDotVec2D(vec1, vec2);
	dot1 = result.get(0);
	dot2 = result.get(4);
}
void VECCALL M3DM::doubleVecFAngleBetween2D(DoubleVectorF vec1, DoubleVectorF vec2, Float& angle1, Float& angle2)
{
	DoubleVectorF result = doubleVecFAngleBetweenVec2D(vec1, vec2);
	angle1 = result.get(0);
	angle2 = result.get(4);
}
void VECCALL M3DM::doubleVecFAngleBetweenNormals2D(DoubleVectorF vec1, DoubleVectorF vec2, Float& angle1, Float& angle2)
{
	DoubleVectorF result = doubleVecFAngleBetweenNormalsVec2D(vec1, vec2);
	angle1 = result.get(0);
	angle2 = result.get(4);
}
void VECCALL M3DM::doubleVecFLinePointDistance2D(DoubleVectorF linePoint1, DoubleVectorF linePoint2, DoubleVectorF point, Float& dist1, Float& dist2)
{
	DoubleVectorF result = doubleVecFLinePointDistanceVec2D(linePoint1, linePoint2, point);
	dist1 = result.get(0);
	dist2 = result.get(4);
}
void VECCALL M3DM::doubleVecFCmp2D(DoubleVectorF vec1, DoubleVectorF vec2, Int32 type, bool& result1, bool& result2)
{
	// create mask 1 1 0 0
	Int32 mask = 0b0011;
	__m256 cmpResult;
	// cmp
	switch(type)
	{
	case CMP_EQ:
		cmpResult = _mm256_cmp_ps(vec1.getData(), vec2.getData(), _CMP_EQ_OQ);
		break;
	case CMP_LE:
		cmpResult = _mm256_cmp_ps(vec1.getData(), vec2.getData(), _CMP_LE_OQ);
		break;
	case CMP_LT:
		cmpResult = _mm256_cmp_ps(vec1.getData(), vec2.getData(), _CMP_LT_OQ);
		break;
	case CMP_GE:
		cmpResult = _mm256_cmp_ps(vec1.getData(), vec2.getData(), _CMP_GE_OQ);
		break;
	case CMP_GT:
		cmpResult = _mm256_cmp_ps(vec1.getData(), vec2.getData(), _CMP_GT_OQ);
		break;
	default:
		cmpResult = __m256();
		break;
	}
	Int32 resultMask = _mm256_movemask_ps(cmpResult);
	result1 = (resultMask & mask) == mask;
	result2 = ((resultMask >> 4) & mask) == mask;
}
void VECCALL M3DM::doubleVecFInBound2D(DoubleVectorF vec, DoubleVectorF left, DoubleVectorF right, bool& result1, bool& result2)
{
	Bool tempResLE1, tempResLE2, tempResGE1, tempResGE2;
	doubleVecFCmp2D(vec, right, CMP_LE, tempResLE1, tempResLE2);
	doubleVecFCmp2D(vec, left, CMP_GE, tempResGE1, tempResGE2);
	result1 = tempResLE1 && tempResGE1;
	result2 = tempResLE2 && tempResGE2;
}