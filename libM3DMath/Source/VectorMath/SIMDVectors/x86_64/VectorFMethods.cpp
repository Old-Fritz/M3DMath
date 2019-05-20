#include "M3DMath.h"
#include <cmath>


/// Implementation of VectorF methods

using namespace M3DM;

// Functions common
VectorF VectorF::abs() const
{
	__m128i minus1 = _mm_set1_epi32(-1);
	__m128 mask = _mm_castsi128_ps(_mm_srli_epi32(minus1, 1));
	return _mm_and_ps(mask, m_data);
}
VectorF VectorF::floor() const
{
	return _mm_round_ps(m_data, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
}
VectorF VectorF::ceil() const
{
	return _mm_round_ps(m_data, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);
}
VectorF VectorF::round() const
{
	return _mm_round_ps(m_data, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
}
VectorF VectorF::reciprocal() const
{
	return _mm_div_ps(_mm_set_ps1(1), m_data);
}
VectorF VectorF::saturate() const
{
	__m128 one = _mm_set_ps1(1);
	__m128 zero = __m128();
	return _mm_min_ps(_mm_max_ps(zero, m_data), one);
}
VectorF VectorF::sqrt() const
{
	return _mm_sqrt_ps(m_data);
}
VectorF VectorF::cos() const
{
	return _mm_cos_ps(m_data);
}
VectorF VectorF::sin() const
{
	return _mm_sin_ps(m_data);
}
VectorF VectorF::tan() const
{
	return _mm_tan_ps(m_data);
}
VectorF VectorF::acos() const
{
	return _mm_acos_ps(m_data);
}
VectorF VectorF::asin() const
{
	return _mm_asin_ps(m_data);
}
VectorF VectorF::atan() const
{
	return _mm_atan_ps(m_data);
}
VectorF VectorF::exp2() const
{
	return _mm_exp2_ps(m_data);
}
VectorF VectorF::expE() const
{
	return _mm_exp_ps(m_data);
}
VectorF VectorF::log2() const
{
	return _mm_log2_ps(m_data);
}
VectorF VectorF::logE() const
{
	return _mm_log_ps(m_data);
}
VectorF VectorF::reciprocalFast() const
{
	return _mm_rcp_ps(m_data);
}
VectorF VectorF::sqrtFast() const
{
	return _mm_rcp_ps(_mm_rsqrt_ps(m_data));
}
void VectorF::sincos(VectorF& sin, VectorF& cos) const
{
	sin = _mm_sincos_ps(&static_cast<__m128&>(cos), m_data);
}

// functions 2d
float VectorF::length2D() const
{
	return lengthVec2D().get(0);
}
float VectorF::sqrLength2D() const
{
	return sqrLengthVec2D().get(0);
}
VectorF VectorF::normalized2D() const
{
	return _mm_div_ps(m_data, lengthVec2D());
}
VectorF VectorF::orthogonal2D() const
{
	VectorF vecResult = -*this;
	vecResult = _mm_shuffle_ps(m_data, vecResult, _MM_SHUFFLE(1, 1, 0, 0));
	vecResult = _mm_shuffle_ps(vecResult, vecResult, _MM_SHUFFLE(0, 0, 0, 2));
	return vecResult;
}
VectorF VectorF::lengthVec2D() const
{
	return _mm_sqrt_ps(sqrLengthVec2D());
}
VectorF VectorF::sqrLengthVec2D() const
{
	return _mm_dp_ps(m_data, m_data, 0b00111111);
}
VectorF VectorF::normalizedFast2D() const
{
	return _mm_mul_ps(m_data, _mm_rsqrt_ps(sqrLengthVec2D()));
}

// functions 3d
float VectorF::length3D() const
{
	return lengthVec3D().get(0);
}
float VectorF::sqrLength3D() const
{
	return sqrLengthVec3D().get(0);
}
VectorF VectorF::normalized3D() const
{
	return _mm_div_ps(m_data, lengthVec3D());
}
VectorF VectorF::orthogonal3D() const
{
	VectorF resultVec;
	Vector4 data;
	VectorF mask = VectorF(0, 0, 0, FNAN);
	store(data);
	float value = -data.x - data.y;

	resultVec = _mm_shuffle_ps(m_data, m_data, 0b11101010);
	resultVec.set(2, value);
	VectorF checkVec = _mm_and_ps(m_data, mask);
	if (resultVec == checkVec) //chech that result is not zero vector
	{
		value = -data.y - data.z;
		resultVec = _mm_shuffle_ps(m_data, m_data, 0b11000000);
		resultVec.set(0, value);
	}


	return resultVec;
}
VectorF VectorF::lengthVec3D() const
{
	return _mm_sqrt_ps(sqrLengthVec3D());
}
VectorF VectorF::sqrLengthVec3D() const
{
	return _mm_dp_ps(m_data, m_data, 0b01111111);
}
VectorF VectorF::normalizedFast3D() const
{
	return _mm_mul_ps(m_data, _mm_rsqrt_ps(sqrLengthVec3D()));
}


// functions 4d
float VectorF::length4D() const
{
	return lengthVec4D().get(0);
}
float VectorF::sqrLength4D() const
{
	return sqrLengthVec4D().get(0);
}
VectorF VectorF::normalized4D() const
{
	return _mm_div_ps(m_data, lengthVec4D());
}
VectorF VectorF::orthogonal4D() const
{
	VectorF vecResult = -*this;
	vecResult = _mm_shuffle_ps(m_data, vecResult.m_data, 0b01001110);
	return vecResult;
}
VectorF VectorF::lengthVec4D() const
{
	return _mm_sqrt_ps(sqrLengthVec4D());
}
VectorF VectorF::sqrLengthVec4D() const
{
	return _mm_dp_ps(m_data, m_data, 0b11111111);
}
VectorF VectorF::normalizedFast4D() const
{
	return _mm_mul_ps(m_data, _mm_rsqrt_ps(sqrLengthVec4D()));
}

