#include "M3DMath.h"
#include <math.h>

using namespace M3DM;

VectorF VECCALL M3DM::vecFCross2D(VectorF vec1, VectorF vec2)
{
	__m128 result = _mm_sub_ps(
		_mm_mul_ps(vec1.getData(), _mm_shuffle_ps(vec2.getData(), vec2.getData(), _MM_SHUFFLE(3, 2, 1, 1))),
		_mm_mul_ps(vec2.getData(), _mm_shuffle_ps(vec1.getData(), vec1.getData(), _MM_SHUFFLE(3, 2, 1, 1)))
	);
	return  _mm_shuffle_ps(result, result, _MM_SHUFFLE(0, 0, 0, 0));
}
VectorF VECCALL M3DM::vecFProject2D(VectorF vec1, VectorF vec2)
{
	return vec2 * vecFDotVec2D(vec1, vec2) / vec2.sqrLengthVec2D();
}
VectorF VECCALL M3DM::vecFReflect2D(VectorF vec, VectorF normal)
{
	// normal normalized
	VectorF ind = normal * vecFDotVec2D(vec, normal);
	return vec - ind - ind;
}
VectorF VECCALL M3DM::vecFRefract2D(VectorF vec, VectorF normal, float refractionIndex)
{
	VectorF dot = vecFDotVec2D(vec, normal);
	VectorF one = VectorF(1);
	VectorF refractionIndexVec = VectorF(refractionIndex);
	VectorF ref = one - refractionIndexVec * refractionIndexVec * (one - dot * dot);

	// total reflection
	VectorF zero = VectorF();
	if (ref < zero)
		return zero;

	return vec * refractionIndexVec - (refractionIndexVec * dot + ref.sqrt()) * normal;
}
VectorF VECCALL M3DM::vecFIntersectLines2D(VectorF l1p1, VectorF l1p2, VectorF l2p1, VectorF l2p2)
{
	VectorF line1Vec = l1p2 - l1p1;
	VectorF line2Vec = l2p2 - l2p1;
	VectorF r = l2p1 - l1p1;
	VectorF lineCross = vecFCross2D(line2Vec, line1Vec);
	VectorF rCross = vecFCross2D(line2Vec, r);
	VectorF rCrossLen = rCross.lengthVec2D();
	VectorF lineCrossLen = lineCross.lengthVec2D();
	VectorF zero = VectorF();
	if (rCrossLen == zero || lineCrossLen == zero)
		return VectorF(INFINITY, INFINITY, INFINITY, 0);
	VectorF shift = rCrossLen / lineCrossLen;
	VectorF sign = rCross * lineCross >= VectorF() ? VectorF(1) : VectorF(-1);
	VectorF point = l1p1 + line1Vec * shift * sign;

	return point;
}

VectorF VECCALL M3DM::vecFDistanceVec2D(VectorF vec1, VectorF vec2)
{
	return (vec1 - vec2).lengthVec2D();
}
VectorF VECCALL M3DM::vecFRefractVec2D(VectorF vec, VectorF normal, VectorF refractionIndex)
{
	VectorF dot = vecFDotVec2D(vec, normal);
	VectorF one = VectorF(1);
	VectorF ref = one - refractionIndex * refractionIndex * (one - dot * dot);

	// total reflection
	VectorF zero = VectorF();
	if (ref < zero)
		return zero;

	return vec * refractionIndex - (refractionIndex * dot + ref.sqrt()) * normal;
}
VectorF VECCALL M3DM::vecFDotVec2D(VectorF vec1, VectorF vec2)
{
	return _mm_dp_ps(vec1.getData(), vec2.getData(), 0b00111111);
}
VectorF VECCALL M3DM::vecFLinePointDistanceVec2D(VectorF linePoint1, VectorF linePoint2, VectorF point)
{
	VectorF lineVec = linePoint2 - linePoint1;
	VectorF lineToPointVec = linePoint1 - point;

	VectorF distance = vecFCross2D(lineVec, lineToPointVec).abs() / lineVec.lengthVec2D();

	return distance;
}
VectorF VECCALL M3DM::vecFAngleBetweenVec2D(VectorF vec1, VectorF vec2)
{
	return (vecFDotVec2D(vec1, vec2) / (vec1.lengthVec2D() * vec2.lengthVec2D())).acos();
}
VectorF VECCALL M3DM::vecFAngleBetweenNormalsVec2D(VectorF vec1, VectorF vec2)
{
	return vecFDotVec2D(vec1, vec2).acos();
}


float VECCALL M3DM::vecFDistance2D(VectorF vec1, VectorF vec2)
{
	return (vec1 - vec2).length2D();
}
float VECCALL M3DM::vecFDot2D(VectorF vec1, VectorF vec2)
{
	return vecFDotVec2D(vec1, vec2).get(0);
}
float VECCALL M3DM::vecFAngleBetween2D(VectorF vec1, VectorF vec2)
{
	return acosf(vecFDot2D(vec1, vec2) / (vec1.length2D() * vec2.length2D()));
}
float VECCALL M3DM::vecFAngleBetweenNormals2D(VectorF vec1, VectorF vec2)
{
	return acosf(vecFDot2D(vec1, vec2));
}
float VECCALL M3DM::vecFLinePointDistance2D(VectorF linePoint1, VectorF linePoint2, VectorF point)
{
	return vecFLinePointDistanceVec2D(linePoint1, linePoint2, point).get(0);
}
bool VECCALL M3DM::vecFCmp2D(VectorF vec1, VectorF vec2, int type)
{
	// create mask 1 1 0 0
	int mask = 0b0011;
	__m128 cmpResult;
	// cmp
	switch(type)
	{
	case CMP_EQ:
		cmpResult = _mm_cmpeq_ps(vec1.getData(), vec2.getData());
		break;
	case CMP_LE:
		cmpResult = _mm_cmple_ps(vec1.getData(), vec2.getData());
		break;
	case CMP_LT:
		cmpResult = _mm_cmplt_ps(vec1.getData(), vec2.getData());
		break;
	case CMP_GE:
		cmpResult = _mm_cmpge_ps(vec1.getData(), vec2.getData());
		break;
	case CMP_GT:
		cmpResult = _mm_cmpgt_ps(vec1.getData(), vec2.getData());
		break;
	default:
		cmpResult = __m128();
		break;
	}
	return (_mm_movemask_ps(cmpResult) & mask) == mask;
}
bool VECCALL M3DM::vecFInBound2D(VectorF vec, VectorF left, VectorF right)
{
	return vecFCmp2D(vec, right, CMP_LE) && vecFCmp2D(vec, left, CMP_GE);
}