#include "M3DMath.h"
#include <cmath>


/// Implementation of DoubleVectorF methods

using namespace M3DM;

void DoubleVectorF::length(float& len1, float& len2) const
{
	DoubleVectorF length = lengthVec();
	len1 = length.get(0);
	len2 = length.get(4);
}

void DoubleVectorF::sqrLength(float& len1, float& len2) const
{
	DoubleVectorF length = sqrLengthVec();
	len1 = length.get(0);
	len2 = length.get(4);
}

DoubleVectorF DoubleVectorF::normalized() const
{
	return _mm256_div_ps(m_data, lengthVec());
}

DoubleVectorF DoubleVectorF::abs() const
{
	__m256i minus1 = _mm256_set1_epi32(-1);
#ifdef _AVX2_
	__m256 mask = _mm256_castsi256_ps(_mm256_srli_epi32(minus1, 1));
#endif
#if defined(_AVX_) && !defined(_AVX2_)
	__m256 mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x7fffffff));
#endif
	return _mm256_and_ps(mask, m_data);
}

DoubleVectorF DoubleVectorF::floor() const
{
	return _mm256_round_ps(m_data, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
}

DoubleVectorF DoubleVectorF::ceil() const
{
	return _mm256_round_ps(m_data, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);
}

DoubleVectorF DoubleVectorF::round() const
{
	return _mm256_round_ps(m_data, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
}

DoubleVectorF DoubleVectorF::reciprocal() const
{
	return _mm256_div_ps(_mm256_set1_ps(1), m_data);
}

DoubleVectorF DoubleVectorF::saturate() const
{
	__m256 one = _mm256_set1_ps(1);
	__m256 zero = __m256();
	return _mm256_min_ps(_mm256_max_ps(zero, m_data), one);
}

DoubleVectorF DoubleVectorF::sqrt() const
{
	return _mm256_sqrt_ps(m_data);
}

DoubleVectorF DoubleVectorF::cos() const
{
	return _mm256_cos_ps(m_data);
}

DoubleVectorF DoubleVectorF::sin() const
{
	return _mm256_sin_ps(m_data);
}

DoubleVectorF DoubleVectorF::tan() const
{
	return _mm256_tan_ps(m_data);
}

DoubleVectorF DoubleVectorF::acos() const
{
	return _mm256_acos_ps(m_data);
}

DoubleVectorF DoubleVectorF::asin() const
{
	return _mm256_asin_ps(m_data);
}

DoubleVectorF DoubleVectorF::atan() const
{
	return _mm256_atan_ps(m_data);
}

DoubleVectorF DoubleVectorF::exp2() const
{
	return _mm256_exp2_ps(m_data);
}

DoubleVectorF DoubleVectorF::expE() const
{
	return _mm256_exp_ps(m_data);
}

DoubleVectorF DoubleVectorF::log2() const
{
	return _mm256_log2_ps(m_data);
}

DoubleVectorF DoubleVectorF::logE() const
{
	return _mm256_log_ps(m_data);
}

DoubleVectorF DoubleVectorF::lengthVec() const
{
	return _mm256_sqrt_ps(_mm256_dp_ps(m_data, m_data, 0b11111111));
}

DoubleVectorF DoubleVectorF::sqrLengthVec() const
{
	return _mm256_dp_ps(m_data, m_data, 0b11111111);
}

DoubleVectorF DoubleVectorF::normalizedFast() const
{
	return _mm256_mul_ps(m_data, _mm256_rsqrt_ps(sqrLengthVec()));
}

DoubleVectorF DoubleVectorF::reciprocalFast() const
{
	return _mm256_rcp_ps(m_data);
}

DoubleVectorF DoubleVectorF::sqrtFast() const
{
	return _mm256_rcp_ps(_mm256_rsqrt_ps(m_data));
}

void DoubleVectorF::sincos(DoubleVectorF& sin, DoubleVectorF& cos) const
{
	sin = _mm256_sincos_ps(&static_cast<__m256&>(cos), m_data);
}

DoubleVectorF& DoubleVectorF::replicate(float value)
{
	m_data = _mm256_set1_ps(value);

	return *this;
}