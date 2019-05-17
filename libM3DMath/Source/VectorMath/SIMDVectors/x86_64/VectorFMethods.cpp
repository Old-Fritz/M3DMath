#include "M3DMath.h"
#include <cmath>


/// Implementation of VectorF methods

using namespace M3DM;

float VectorF::length()
{
	return VectorF(_mm_sqrt_ps(_mm_dp_ps(m_data, m_data, 0b11111111))).get(0);
}

float VectorF::sqrLength()
{
	return VectorF(_mm_dp_ps(m_data, m_data, 0b11111111)).get(0);
}

VectorF VectorF::normalized()
{
	//return _mm_mul_ps(m_data, _mm_rcp_ps(_mm_sqrt_ps(_mm_dp_ps(m_data, m_data, 0b11111111))));
	return _mm_div_ps(m_data, _mm_sqrt_ps(_mm_dp_ps(m_data, m_data, 0b11111111)));
}

VectorF VectorF::abs()
{
	__m128i minus1 = _mm_set1_epi32(-1);
	__m128 mask = _mm_castsi128_ps(_mm_srli_epi32(minus1, 1));
	return _mm_and_ps(mask, m_data);
}

VectorF VectorF::floor()
{
	return _mm_round_ps(m_data, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
}

VectorF VectorF::ceil()
{
	return _mm_round_ps(m_data, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);
}

VectorF VectorF::round()
{
	return _mm_round_ps(m_data, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
}

VectorF VectorF::reciprocal()
{
	return _mm_div_ps(_mm_set_ps1(1), m_data);
}

VectorF VectorF::saturate()
{
	__m128 one = _mm_set_ps1(1);
	__m128 zero = __m128();
	return _mm_min_ps(_mm_max_ps(zero, m_data), one);
}

VectorF VectorF::sqrt()
{
	return _mm_sqrt_ps(m_data);
}

VectorF VectorF::cos()
{
	return _mm_cos_ps(m_data);
}

VectorF VectorF::sin()
{
	return _mm_sin_ps(m_data);
}

VectorF VectorF::tan()
{
	return _mm_tan_ps(m_data);
}

VectorF VectorF::acos()
{
	return _mm_acos_ps(m_data);
}

VectorF VectorF::asin()
{
	return _mm_asin_ps(m_data);
}

VectorF VectorF::atan()
{
	return _mm_atan_ps(m_data);
}

VectorF VectorF::exp2()
{
	return _mm_exp2_ps(m_data);
}

VectorF VectorF::expE()
{
	return _mm_exp_ps(m_data);
}

VectorF VectorF::log2()
{
	return _mm_log2_ps(m_data);
}

VectorF VectorF::logE()
{
	return _mm_log_ps(m_data);
}

void VectorF::sincos(VectorF& sin, VectorF& cos)
{
	sin = _mm_sincos_ps(&static_cast<__m128&>(cos), m_data);
}

VectorF& VectorF::replicate(float value)
{
	m_data = _mm_set_ps1(value);

	return *this;
}

VectorF VectorF::lengthVec()
{
	return _mm_sqrt_ps(_mm_dp_ps(m_data, m_data, 0b11111111));
}

VectorF VectorF::sqrLengthVec()
{
	return _mm_dp_ps(m_data, m_data, 0b11111111);
}

VectorF VectorF::normalizedFast()
{
	return _mm_mul_ps(m_data, _mm_rsqrt_ps(sqrLengthVec()));
}

VectorF VectorF::reciprocalFast()
{
	return _mm_rcp_ps(m_data);
}

VectorF VectorF::sqrtFast()
{
	return _mm_rcp_ps(_mm_rsqrt_ps(m_data));
}