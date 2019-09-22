#include "M3DMath.h"

/// Implementation of DoubleVectorF

using namespace M3DM;

#define _mm256_test_all_ones(data) _mm256_testc_si256(_mm256_castps_si256((data)), _mm256_castps_si256(_mm256_cmp_ps((data), (data), _CMP_EQ_OQ)));

DoubleVectorF::DoubleVectorF(Float value)
{
	load(value);
}

// Conversions
DoubleVectorF::DoubleVectorF(Float x1, Float y1, Float z1, Float w1, Float x2, Float y2, Float z2, Float w2)
{
	load(x1, y1, z1, w1, x2, y2, z2, w2);
}
DoubleVectorF::DoubleVectorF(const Float* pArray)
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

// getters and setters
Float VECCALL DoubleVectorF::get(const Char ind)  const
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
void VECCALL DoubleVectorF::set(Char ind, Float value)
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
Int32 VECCALL DoubleVectorF::getInt(Char ind)  const
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
void VECCALL DoubleVectorF::setInt(Char ind, Int32 value)
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
DoubleVectorF VECCALL DoubleVectorF::operator+(DoubleVectorF vector) const
{
	return _mm256_add_ps(m_data, vector.m_data);
}
DoubleVectorF VECCALL DoubleVectorF::operator-(DoubleVectorF vector) const
{
	return _mm256_sub_ps(m_data, vector.m_data);
}
DoubleVectorF VECCALL DoubleVectorF::operator*(DoubleVectorF vector) const
{
	return _mm256_mul_ps(m_data, vector.m_data);
}
DoubleVectorF VECCALL DoubleVectorF::operator/(DoubleVectorF vector) const
{
	return _mm256_div_ps(m_data, vector.m_data);
}
DoubleVectorF VECCALL DoubleVectorF::operator*(Float scale) const
{
	__m256 data2 = _mm256_set1_ps(scale);
	return _mm256_mul_ps(m_data, data2);
}
DoubleVectorF VECCALL DoubleVectorF::operator/(Float scale) const
{
	__m256 data2 = _mm256_set1_ps(scale);
	return _mm256_div_ps(m_data, data2);
}
DoubleVectorF& VECCALL DoubleVectorF::operator+=(DoubleVectorF vector)
{
	m_data = _mm256_add_ps(m_data, vector.m_data);
	return *this;
}
DoubleVectorF& VECCALL DoubleVectorF::operator-=(DoubleVectorF vector)
{
	m_data = _mm256_sub_ps(m_data, vector.m_data);
	return *this;
}
DoubleVectorF& VECCALL DoubleVectorF::operator*=(DoubleVectorF vector)
{
	m_data = _mm256_mul_ps(m_data, vector.m_data);
	return *this;
}
DoubleVectorF& VECCALL DoubleVectorF::operator/=(DoubleVectorF vector)
{
	m_data = _mm256_div_ps(m_data, vector.m_data);
	return *this;
}
DoubleVectorF& VECCALL DoubleVectorF::operator*=(Float scale)
{
	__m256 data2 = _mm256_set1_ps(scale);
	m_data = _mm256_mul_ps(m_data, data2);
	return *this;
}
DoubleVectorF& VECCALL DoubleVectorF::operator/=(Float scale)
{
	__m256 data2 = _mm256_set1_ps(scale);
	m_data = _mm256_div_ps(m_data, data2);
	return *this;
}
DoubleVectorF VECCALL DoubleVectorF::operator-() const
{
	return _mm256_sub_ps(__m256(), m_data);
}

DoubleVectorF VECCALL M3DM::operator*(Float scale, DoubleVectorF vector)
{
	return vector * scale;
}
DoubleVectorF VECCALL  M3DM::operator/(Float scale, DoubleVectorF vector)
{
	__m256 data2 = _mm256_set1_ps(scale);
	return _mm256_div_ps(data2, vector.m_data);
}

// Compare functions
Bool VECCALL DoubleVectorF::operator==(DoubleVectorF vector) const
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
Bool VECCALL DoubleVectorF::operator<(DoubleVectorF vector) const
{
	__m256 dataEqual = _mm256_cmp_ps(m_data, vector.m_data, _CMP_LT_OQ); 
	return _mm256_test_all_ones(dataEqual);
}
Bool VECCALL DoubleVectorF::operator>(DoubleVectorF vector) const
{
	__m256 dataEqual = _mm256_cmp_ps(m_data, vector.m_data, _CMP_GT_OQ);
	return _mm256_test_all_ones(dataEqual);
}
Bool VECCALL DoubleVectorF::operator<=(DoubleVectorF vector) const
{
	__m256 dataEqual = _mm256_cmp_ps(m_data, vector.m_data, _CMP_LE_OQ);
	return _mm256_test_all_ones(dataEqual);
}
Bool VECCALL DoubleVectorF::operator>=(DoubleVectorF vector) const
{
	__m256 dataEqual = _mm256_cmp_ps(m_data, vector.m_data, _CMP_GE_OQ);
	return _mm256_test_all_ones(dataEqual);
}
Bool VECCALL DoubleVectorF::isEqualPrec(DoubleVectorF vector, Float precision, Int32 mask) const
{
	__m256 delta = (*this - vector).abs().getData();
	__m256 dataCmp = _mm256_cmp_ps(delta, _mm256_set1_ps(precision), _CMP_LE_OQ);
	return (_mm256_movemask_ps(dataCmp)&mask)==mask;
	
}
Bool VECCALL DoubleVectorF::isEqualPrec(DoubleVectorF vector, DoubleVectorF precision, Int32 mask) const
{
	__m256 delta = (*this - vector).abs().getData();
	__m256 dataCmp = _mm256_cmp_ps(delta, precision.getData(), _CMP_LE_OQ);
	return (_mm256_movemask_ps(dataCmp) & mask) == mask;
}
DoubleVectorF VECCALL DoubleVectorF::isEqualVec(DoubleVectorF vector) const
{
	return _mm256_cmp_ps(m_data, vector.m_data, _CMP_EQ_OQ);
}
DoubleVectorF VECCALL DoubleVectorF::isEqualPrecVec(DoubleVectorF vector, DoubleVectorF precision) const
{
	__m256 delta = (*this - vector).abs().getData();
	return _mm256_cmp_ps(delta, precision.getData(), _CMP_LE_OQ);
}


// Load/store
void VECCALL DoubleVectorF::load(Float value)
{
	m_data = _mm256_set1_ps(value);
}
void VECCALL DoubleVectorF::load(Float x1, Float y1, Float z1, Float w1, Float x2, Float y2, Float z2, Float w2)
{
	m_data = _mm256_setr_ps(x1, y1, z1, w1, x2, y2, z2, w2);
}
void VECCALL DoubleVectorF::load(const Float* pArray)
{
	m_data = _mm256_load_ps(pArray);
}
void VECCALL DoubleVectorF::load(const Vector2& vector)
{
	m_data = _mm256_setr_ps(vector.x, vector.y, 0, 0, 0, 0, 0, 0);
}
void VECCALL DoubleVectorF::load(const Vector3& vector)
{
	m_data = _mm256_setr_ps(vector.x, vector.y, vector.z, 0, 0, 0, 0, 0);
}
void VECCALL DoubleVectorF::load(const Vector4& vector)
{
	m_data = _mm256_setr_ps(vector.x, vector.y, vector.z, vector.w, 0, 0, 0, 0);
}
void VECCALL DoubleVectorF::load(const Vector2& vector1, const Vector2& vector2)
{
	m_data = _mm256_setr_ps(vector1.x, vector1.y, 0, 0, vector2.x, vector2.y, 0, 0);
}
void VECCALL DoubleVectorF::load(const Vector3& vector1, const Vector3& vector2)
{
	m_data = _mm256_setr_ps(vector1.x, vector1.y, vector1.z, 0, vector2.x, vector2.y, vector2.z, 0);
}
void VECCALL DoubleVectorF::load(const Vector4& vector1, const Vector4& vector2)
{
	load(VectorF(vector1), VectorF(vector2));
}
void VECCALL DoubleVectorF::load(const Vector2& vector1, const Vector2& vector2, const Vector2& vector3, const Vector2& vector4)
{
	load(VectorF(vector1, vector2), VectorF(vector3, vector4));
}
void VECCALL DoubleVectorF::load(VectorF vector)
{
	m_data = _mm256_insertf128_ps(__m256(), vector.getData(), 0);
}
void VECCALL DoubleVectorF::load(VectorF vector1, VectorF vector2)
{
    m_data = _mm256_insertf128_ps(_mm256_castps128_ps256(vector1.getData()), (vector2.getData()), 0x1);
}

void VECCALL DoubleVectorF::store(Float& x1, Float& y1, Float& z1, Float& w1, Float& x2, Float& y2, Float& z2, Float& w2) const
{
	alignas(32) Float vector[8];
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
void VECCALL DoubleVectorF::store(Float* pArray) const
{
	_mm256_store_ps(pArray, m_data);
}
void VECCALL DoubleVectorF::store(Vector2& vector) const
{
	alignas(32) Float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector = Vector2(vectorData);
}
void VECCALL DoubleVectorF::store(Vector3& vector) const
{
	alignas(32) Float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector = Vector3(vectorData);
}
void VECCALL DoubleVectorF::store(Vector4& vector) const
{
	alignas(32) Float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector = Vector4(vectorData);
}
void VECCALL DoubleVectorF::store(Vector2& vector1, Vector2& vector2) const
{
	alignas(32) Float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector1 = Vector2(vectorData);
	vector2 = Vector2(vectorData+4);
}
void VECCALL DoubleVectorF::store(Vector3& vector1, Vector3& vector2) const
{
	alignas(32) Float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector1 = Vector3(vectorData);
	vector2 = Vector3(vectorData + 4);
}
void VECCALL DoubleVectorF::store(Vector4& vector1, Vector4& vector2) const
{
    alignas(32) Float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector1 = Vector4(vectorData);
	vector2 = Vector4(vectorData + 4);
}
void VECCALL DoubleVectorF::store(Vector2& vector1, Vector2& vector2, Vector2& vector3, Vector2& vector4) const
{
	alignas(32) Float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector1 = Vector2(vectorData);
	vector2 = Vector2(vectorData + 2);
	vector3 = Vector2(vectorData + 4);
	vector4 = Vector2(vectorData + 6);
}
void VECCALL DoubleVectorF::store(VectorF& vector) const
{
	vector = _mm256_extractf128_ps(m_data, 0);
}
void VECCALL DoubleVectorF::store(VectorF& vector1, VectorF& vector2) const
{
	vector1 = _mm256_extractf128_ps(m_data, 0);
	vector2 = _mm256_extractf128_ps(m_data, 1);
}


