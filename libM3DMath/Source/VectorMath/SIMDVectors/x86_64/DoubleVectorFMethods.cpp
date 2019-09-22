#include "M3DMath.h"
#include <cmath>


/// Implementation of DoubleVectorF methods

using namespace M3DM;

// Functions common
DoubleVectorF VECCALL DoubleVectorF::abs() const
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
DoubleVectorF VECCALL DoubleVectorF::floor() const
{
	return _mm256_round_ps(m_data, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
}
DoubleVectorF VECCALL DoubleVectorF::ceil() const
{
	return _mm256_round_ps(m_data, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);
}
DoubleVectorF VECCALL DoubleVectorF::round() const
{
	return _mm256_round_ps(m_data, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
}
DoubleVectorF VECCALL DoubleVectorF::reciprocal() const
{
	return _mm256_div_ps(_mm256_set1_ps(1), m_data);
}
DoubleVectorF VECCALL DoubleVectorF::saturate() const
{
	__m256 one = _mm256_set1_ps(1);
	__m256 zero = __m256();
	return _mm256_min_ps(_mm256_max_ps(zero, m_data), one);
}
DoubleVectorF VECCALL DoubleVectorF::sqrt() const
{
	return _mm256_sqrt_ps(m_data);
}
DoubleVectorF VECCALL DoubleVectorF::cos() const
{
	return _mm256_cos_ps(m_data);
}
DoubleVectorF VECCALL DoubleVectorF::sin() const
{
	return _mm256_sin_ps(m_data);
}
DoubleVectorF VECCALL DoubleVectorF::tan() const
{
	return _mm256_tan_ps(m_data);
}
DoubleVectorF VECCALL DoubleVectorF::acos() const
{
	return _mm256_acos_ps(m_data);
}
DoubleVectorF VECCALL DoubleVectorF::asin() const
{
	return _mm256_asin_ps(m_data);
}
DoubleVectorF VECCALL DoubleVectorF::atan() const
{
	return _mm256_atan_ps(m_data);
}
DoubleVectorF VECCALL DoubleVectorF::exp2() const
{
	return _mm256_exp2_ps(m_data);
}
DoubleVectorF VECCALL DoubleVectorF::expE() const
{
	return _mm256_exp_ps(m_data);
}
DoubleVectorF VECCALL DoubleVectorF::log2() const
{
	return _mm256_log2_ps(m_data);
}
DoubleVectorF VECCALL DoubleVectorF::logE() const
{
	return _mm256_log_ps(m_data);
}
DoubleVectorF VECCALL DoubleVectorF::reciprocalFast() const
{
	return _mm256_rcp_ps(m_data);
}
DoubleVectorF VECCALL DoubleVectorF::sqrtFast() const
{
	return _mm256_rcp_ps(_mm256_rsqrt_ps(m_data));
}
void VECCALL DoubleVectorF::sincos(DoubleVectorF& sin, DoubleVectorF& cos) const
{
	sin = _mm256_sincos_ps(&cos.getDataRef(), m_data);
}

// functions 2d
void VECCALL DoubleVectorF::length2D(Float& len1, Float& len2) const
{
	DoubleVectorF length = lengthVec2D();
	len1 = length.get(0);
	len2 = length.get(4);
}
void VECCALL DoubleVectorF::sqrLength2D(Float& len1, Float& len2) const
{
	DoubleVectorF length = sqrLengthVec2D();
	len1 = length.get(0);
	len2 = length.get(4);
}
DoubleVectorF VECCALL DoubleVectorF::normalized2D() const
{
	return _mm256_div_ps(m_data, lengthVec2D().getData());
}
DoubleVectorF VECCALL DoubleVectorF::orthogonal2D() const
{
	DoubleVectorF vecResult = -*this;
	vecResult = _mm256_shuffle_ps(m_data, vecResult.getData(), _MM_SHUFFLE(1, 1, 0, 0));
	vecResult = _mm256_shuffle_ps(vecResult.getData(), vecResult.getData(), _MM_SHUFFLE(0, 0, 0, 2));
	return vecResult;
}
DoubleVectorF VECCALL DoubleVectorF::lengthVec2D() const
{
	return _mm256_sqrt_ps(sqrLengthVec2D().getData());
}
DoubleVectorF VECCALL DoubleVectorF::sqrLengthVec2D() const
{
	return _mm256_dp_ps(m_data, m_data, 0b00111111);
}
DoubleVectorF VECCALL DoubleVectorF::normalizedFast2D() const
{
	return _mm256_mul_ps(m_data, _mm256_rsqrt_ps(sqrLengthVec2D().getData()));
}

// functions 3d
void VECCALL DoubleVectorF::length3D(Float& len1, Float& len2) const
{
	DoubleVectorF length = lengthVec3D();
	len1 = length.get(0);
	len2 = length.get(4);
}
void VECCALL DoubleVectorF::sqrLength3D(Float& len1, Float& len2) const
{
	DoubleVectorF length = sqrLengthVec3D();
	len1 = length.get(0);
	len2 = length.get(4);
}
DoubleVectorF VECCALL DoubleVectorF::normalized3D() const
{
	return _mm256_div_ps(m_data, lengthVec3D().getData());
}
DoubleVectorF VECCALL DoubleVectorF::orthogonal3D() const
{
	DoubleVectorF resultVec;
	ALIGN(32) Float data[8];
	DoubleVectorF mask = DoubleVectorF(0, 0, 0, FNAN, 0, 0, 0, FNAN);
	store(data);
	Float value1 = -data[0] - data[1];
	Float value2 = -data[4] - data[5];

	resultVec = _mm256_shuffle_ps(m_data, m_data, 0b11101010);
	resultVec.set(2, value1);
	resultVec.set(6, value2);
	DoubleVectorF checkVec = _mm256_and_ps(m_data, mask.getData());
	if (resultVec == checkVec) //chech that result is not zero vector
	{
		value1 = -data[1] - data[2];
		value2 = -data[4] - data[6];
		resultVec = _mm256_shuffle_ps(m_data, m_data, 0b11000000);
		resultVec.set(0, value1);
		resultVec.set(4, value2);
	}


	return resultVec;
}
DoubleVectorF VECCALL DoubleVectorF::lengthVec3D() const
{
	return _mm256_sqrt_ps(sqrLengthVec3D().getData());
}
DoubleVectorF VECCALL DoubleVectorF::sqrLengthVec3D() const
{
	return _mm256_dp_ps(m_data, m_data, 0b01111111);
}
DoubleVectorF VECCALL DoubleVectorF::normalizedFast3D() const
{
	return _mm256_mul_ps(m_data, _mm256_rsqrt_ps(sqrLengthVec3D().getData()));
}

// functions 4d
void VECCALL DoubleVectorF::length4D(Float& len1, Float& len2) const
{
	DoubleVectorF length = lengthVec4D();
	len1 = length.get(0);
	len2 = length.get(4);
}
void VECCALL DoubleVectorF::sqrLength4D(Float& len1, Float& len2) const
{
	DoubleVectorF length = sqrLengthVec4D();
	len1 = length.get(0);
	len2 = length.get(4);
}
DoubleVectorF VECCALL DoubleVectorF::normalized4D() const
{
	return _mm256_div_ps(m_data, lengthVec4D().getData());
}
DoubleVectorF VECCALL DoubleVectorF::orthogonal4D() const
{
	DoubleVectorF vecResult = -*this;
	vecResult = _mm256_shuffle_ps(m_data, vecResult.m_data, 0b01001110);
	return vecResult;
}
DoubleVectorF VECCALL DoubleVectorF::lengthVec4D() const
{
	return _mm256_sqrt_ps(sqrLengthVec4D().getData());
}
DoubleVectorF VECCALL DoubleVectorF::sqrLengthVec4D() const
{
	return _mm256_dp_ps(m_data, m_data, 0b11111111);
}
DoubleVectorF VECCALL DoubleVectorF::normalizedFast4D() const
{
	return _mm256_mul_ps(m_data, _mm256_rsqrt_ps(sqrLengthVec4D().getData()));
}