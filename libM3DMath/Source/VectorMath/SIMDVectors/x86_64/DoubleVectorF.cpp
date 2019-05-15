#include "M3DMath.h"

/// Implementation of DoubleVectorF

using namespace M3DM;

#define _mm256_test_all_ones(data) _mm256_testc_si256(_mm256_castps_si256((data)), _mm256_castps_si256(_mm256_cmp_ps((data), (data), _CMP_EQ_OQ)));

// TODO: replace in M3DMath.h
__m256 vecabs_and(__m256 v) {
	__m256i minus1 = _mm256_set1_epi32(-1);
#ifdef _AVX2_
	__m256 mask = _mm256_castsi256_ps(_mm256_srli_epi32(minus1, 1));
#endif
#if defined(_AVX_) && !defined(_AVX2_)
	__m256 mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x7fffffff));
#endif
	return _mm256_and_ps(mask, v);
}

// Conversions
DoubleVectorF::DoubleVectorF(float x1, float y1, float z1, float w1, float x2, float y2, float z2, float w2)
{
	load(x1, y1, z1, w1, x2, y2, z2, w2);
}
DoubleVectorF::DoubleVectorF(float* pArray)
{
	load(pArray);
}
DoubleVectorF::DoubleVectorF(const Vector2& vector)
{
	load(vector);
}
DoubleVectorF::DoubleVectorF(const Vector3& vector)
{
	load(vector);
}
DoubleVectorF::DoubleVectorF(const Vector4& vector)
{
	load(vector);
}
DoubleVectorF::DoubleVectorF(const Vector2& vector1, const Vector2& vector2)
{
	load(vector1, vector2);
}
DoubleVectorF::DoubleVectorF(const Vector3& vector1, const Vector3& vector2)
{
	load(vector1, vector2);
}
DoubleVectorF::DoubleVectorF(const Vector4& vector1, const Vector4& vector2)
{
	load(vector1, vector2);
}
DoubleVectorF::DoubleVectorF(const Vector2& vector1, const Vector2& vector2, const Vector2& vector3, const Vector2& vector4)
{
	load(vector1, vector2, vector3, vector4);
}
DoubleVectorF::DoubleVectorF(VectorF vector)
{
	load(vector);
}
DoubleVectorF::DoubleVectorF(VectorF vector1, VectorF vector2)
{
	load(vector1, vector2);
}
DoubleVectorF::operator __m256() const
{
	return m_data;
}

// getters and setters
float DoubleVectorF::get(const char ind)  const
{
	switch (ind % 8)
	{
	case 0:
		return int2Float(_mm256_extract_epi32(_mm256_castps_si256(m_data), 0));
		break;
	case 1:
		return int2Float(_mm256_extract_epi32(_mm256_castps_si256(m_data), 1));
		break;
	case 2:
		return int2Float(_mm256_extract_epi32(_mm256_castps_si256(m_data), 2));
		break;
	case 3:
		return int2Float(_mm256_extract_epi32(_mm256_castps_si256(m_data), 3));
		break;
	case 4:
		return int2Float(_mm256_extract_epi32(_mm256_castps_si256(m_data), 4));
		break;
	case 5:
		return int2Float(_mm256_extract_epi32(_mm256_castps_si256(m_data), 5));
		break;
	case 6:
		return int2Float(_mm256_extract_epi32(_mm256_castps_si256(m_data), 6));
		break;
	case 7:
		return int2Float(_mm256_extract_epi32(_mm256_castps_si256(m_data), 7));
		break;
	}

}
void DoubleVectorF::set(char ind, float value)
{
	switch (ind % 8)
	{
	case 0:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), float2Int(value), 0));
		break;
	case 1:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), float2Int(value), 1));
		break;
	case 2:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), float2Int(value), 2));
		break;
	case 3:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), float2Int(value), 3));
		break;
	case 4:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), float2Int(value), 4));
		break;
	case 5:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), float2Int(value), 5));
		break;
	case 6:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), float2Int(value), 6));
		break;
	case 7:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), float2Int(value), 7));
		break;
	}
}
int DoubleVectorF::getInt(char ind)  const
{
	switch (ind % 8)
	{
	case 0:
		return _mm256_extract_epi32(_mm256_castps_si256(m_data), 0);
		break;
	case 1:
		return _mm256_extract_epi32(_mm256_castps_si256(m_data), 1);
		break;
	case 2:
		return _mm256_extract_epi32(_mm256_castps_si256(m_data), 2);
		break;
	case 3:
		return _mm256_extract_epi32(_mm256_castps_si256(m_data), 3);
		break;
	case 4:
		return _mm256_extract_epi32(_mm256_castps_si256(m_data), 4);
		break;
	case 5:
		return _mm256_extract_epi32(_mm256_castps_si256(m_data), 5);
		break;
	case 6:
		return _mm256_extract_epi32(_mm256_castps_si256(m_data), 6);
		break;
	case 7:
		return _mm256_extract_epi32(_mm256_castps_si256(m_data), 7);
		break;
	}
}
void DoubleVectorF::setInt(char ind, int value)
{
	switch (ind % 8)
	{
	case 0:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), value, 0));
		break;
	case 1:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), value, 1));
		break;
	case 2:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), value, 2));
		break;
	case 3:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), value, 3));
		break;
	case 4:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), value, 4));
		break;
	case 5:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), value, 5));
		break;
	case 6:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), value, 6));
		break;
	case 7:
		m_data = _mm256_castsi256_ps(_mm256_insert_epi32(_mm256_castps_si256(m_data), value, 7));
		break;
	}
}

// Base operations
DoubleVectorF DoubleVectorF::operator+(DoubleVectorF vector) const
{
	return _mm256_add_ps(m_data, vector.m_data);
}
DoubleVectorF DoubleVectorF::operator-(DoubleVectorF vector) const
{
	return _mm256_sub_ps(m_data, vector.m_data);
}
DoubleVectorF DoubleVectorF::operator*(DoubleVectorF vector) const
{
	return _mm256_mul_ps(m_data, vector.m_data);
}
DoubleVectorF DoubleVectorF::operator/(DoubleVectorF vector) const
{
	return _mm256_div_ps(m_data, vector.m_data);
}
DoubleVectorF DoubleVectorF::operator*(float scale) const
{
	__m256 data2 = _mm256_set1_ps(scale);
	return _mm256_mul_ps(m_data, data2);
}
DoubleVectorF DoubleVectorF::operator/(float scale) const
{
	__m256 data2 = _mm256_set1_ps(scale);
	return _mm256_div_ps(m_data, data2);
}
DoubleVectorF& DoubleVectorF::operator+=(DoubleVectorF vector)
{
	m_data = _mm256_add_ps(m_data, vector.m_data);
	return *this;
}
DoubleVectorF& DoubleVectorF::operator-=(DoubleVectorF vector)
{
	m_data = _mm256_sub_ps(m_data, vector.m_data);
	return *this;
}
DoubleVectorF& DoubleVectorF::operator*=(DoubleVectorF vector)
{
	m_data = _mm256_mul_ps(m_data, vector.m_data);
	return *this;
}
DoubleVectorF& DoubleVectorF::operator/=(DoubleVectorF vector)
{
	m_data = _mm256_div_ps(m_data, vector.m_data);
	return *this;
}
DoubleVectorF& DoubleVectorF::operator*=(float scale)
{
	__m256 data2 = _mm256_set1_ps(scale);
	m_data = _mm256_mul_ps(m_data, data2);
	return *this;
}
DoubleVectorF& DoubleVectorF::operator/=(float scale)
{
	__m256 data2 = _mm256_set1_ps(scale);
	m_data = _mm256_div_ps(m_data, data2);
	return *this;
}
DoubleVectorF DoubleVectorF::operator-()
{
	return _mm256_sub_ps(__m256(), m_data);
}

// Compare functions
bool DoubleVectorF::operator==(DoubleVectorF vector) const
{
	//__m256 dataEqual = _mm256_cmp_ps(m_data, vector.m_data, _CMP_EQ_OQ);

#ifdef _AVX2_
	__m256 dataEqual = _mm256_castsi256_ps(_mm256_cmpeq_epi32(_mm256_castps_si256(m_data), _mm256_castps_si256(vector.m_data)));
	return _mm256_test_all_ones(dataEqual);
#endif
#if defined(_AVX_) && !defined(_AVX2_)
	//VectorF vec11, vec21, vec12, vec22;
	//this->store(vec11, vec12);
	//vector.store(vec21, vec22);
	//return vec11 == vec21 && vec12 == vec22;
	__m256i xorValue = _mm256_castps_si256(_mm256_xor_ps(m_data, vector.m_data));
	return _mm256_testz_si256(xorValue, xorValue);
#endif
	
}
bool DoubleVectorF::operator<(DoubleVectorF vector) const
{
	__m256 dataEqual = _mm256_cmp_ps(m_data, vector.m_data, _CMP_LT_OQ); 
	return _mm256_test_all_ones(dataEqual);
}
bool DoubleVectorF::operator>(DoubleVectorF vector) const
{
	__m256 dataEqual = _mm256_cmp_ps(m_data, vector.m_data, _CMP_GT_OQ);
	return _mm256_test_all_ones(dataEqual);
}
bool DoubleVectorF::operator<=(DoubleVectorF vector) const
{
	__m256 dataEqual = _mm256_cmp_ps(m_data, vector.m_data, _CMP_LE_OQ);
	return _mm256_test_all_ones(dataEqual);
}
bool DoubleVectorF::operator>=(DoubleVectorF vector) const
{
	__m256 dataEqual = _mm256_cmp_ps(m_data, vector.m_data, _CMP_GE_OQ);
	return _mm256_test_all_ones(dataEqual);
}
bool DoubleVectorF::isEqualPrec(DoubleVectorF vector, float precision) const
{
	__m256 delta = vecabs_and(static_cast<__m256>(*this - vector));
	__m256 dataCmp = _mm256_cmp_ps(delta, _mm256_set1_ps(precision), _CMP_LE_OQ);
	return _mm256_test_all_ones(dataCmp);
	
}
bool DoubleVectorF::isEqualPrec(DoubleVectorF vector, DoubleVectorF precision) const
{
	__m256 delta = vecabs_and(static_cast<__m256>(*this - vector));
	__m256 dataCmp = _mm256_cmp_ps(delta, precision, _CMP_LE_OQ);
	return _mm256_test_all_ones(dataCmp);
}
DoubleVectorF DoubleVectorF::isEqualVec(DoubleVectorF vector) const
{
	return _mm256_cmp_ps(m_data, vector.m_data, _CMP_EQ_OQ);
}
DoubleVectorF DoubleVectorF::isEqualPrecVec(DoubleVectorF vector, DoubleVectorF precision) const
{
	__m256 delta = vecabs_and(static_cast<__m256>(*this - vector));
	return _mm256_cmp_ps(delta, precision, _CMP_LE_OQ);
}


// Load/store
void DoubleVectorF::load(float x1, float y1, float z1, float w1, float x2, float y2, float z2, float w2)
{
	m_data = _mm256_setr_ps(x1, y1, z1, w1, x2, y2, z2, w2);
}
void DoubleVectorF::load(const float* pArray)
{
	m_data = _mm256_load_ps(pArray);
}
void DoubleVectorF::load(const Vector2& vector)
{
	m_data = _mm256_setr_ps(vector.x, vector.y, 0, 0, 0, 0, 0, 0);
}
void DoubleVectorF::load(const Vector3& vector)
{
	m_data = _mm256_setr_ps(vector.x, vector.y, vector.z, 0, 0, 0, 0, 0);
}
void DoubleVectorF::load(const Vector4& vector)
{
	m_data = _mm256_setr_ps(vector.x, vector.y, vector.z, vector.w, 0, 0, 0, 0);
}
void DoubleVectorF::load(const Vector2& vector1, const Vector2& vector2)
{
	m_data = _mm256_setr_ps(vector1.x, vector1.y, 0, 0, vector2.x, vector2.y, 0, 0);
}
void DoubleVectorF::load(const Vector3& vector1, const Vector3& vector2)
{
	m_data = _mm256_setr_ps(vector1.x, vector1.y, vector1.z, 0, vector2.x, vector2.y, vector2.z, 0);
}
void DoubleVectorF::load(const Vector4& vector1, const Vector4& vector2)
{
	load(VectorF(vector1), VectorF(vector2));
}
void DoubleVectorF::load(const Vector2& vector1, const Vector2& vector2, const Vector2& vector3, const Vector2& vector4)
{
	load(VectorF(vector1, vector2), VectorF(vector3, vector4));
}
void DoubleVectorF::load(VectorF vector)
{
	m_data = _mm256_insertf128_ps(__m256(), vector, 0);
}
void DoubleVectorF::load(VectorF vector1, VectorF vector2)
{
    m_data = _mm256_insertf128_ps(_mm256_castps128_ps256(vector1), (vector2), 0x1);
}

void DoubleVectorF::store(float& x1, float& y1, float& z1, float& w1, float& x2, float& y2, float& z2, float& w2) const
{
	alignas(32) float vector[8];
	_mm256_store_ps(vector, m_data);
	x1 = vector[0];
	y1 = vector[1];
	z1 = vector[2];
	w1 = vector[3];
	x2 = vector[4];
	y2 = vector[5];
	z2 = vector[6];
	w2 = vector[7];
}
void DoubleVectorF::store(float* pArray) const
{
	_mm256_store_ps(pArray, m_data);
}
void DoubleVectorF::store(Vector2& vector) const
{
	alignas(32) float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector = Vector2(vectorData);
}
void DoubleVectorF::store(Vector3& vector) const
{
	alignas(32) float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector = Vector3(vectorData);
}
void DoubleVectorF::store(Vector4& vector) const
{
	alignas(32) float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector = Vector4(vectorData);
}
void DoubleVectorF::store(Vector2& vector1, Vector2& vector2) const
{
	alignas(32) float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector1 = Vector2(vectorData);
	vector2 = Vector2(vectorData+4);
}
void DoubleVectorF::store(Vector3& vector1, Vector3& vector2) const
{
	alignas(32) float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector1 = Vector3(vectorData);
	vector2 = Vector3(vectorData + 4);
}
void DoubleVectorF::store(Vector4& vector1, Vector4& vector2) const
{
    alignas(32) float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector1 = Vector4(vectorData);
	vector2 = Vector4(vectorData + 4);
}
void DoubleVectorF::store(Vector2& vector1, Vector2& vector2, Vector2& vector3, Vector2& vector4) const
{
	alignas(32) float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector1 = Vector2(vectorData);
	vector2 = Vector2(vectorData + 2);
	vector3 = Vector2(vectorData + 4);
	vector4 = Vector2(vectorData + 6);
}
void DoubleVectorF::store(VectorF& vector) const
{
	vector = _mm256_extractf128_ps(m_data, 0);
}
void DoubleVectorF::store(VectorF& vector1, VectorF& vector2) const
{
	vector1 = _mm256_extractf128_ps(m_data, 0);
	vector2 = _mm256_extractf128_ps(m_data, 1);
}