#include "M3DMath.h"

/// Implementation of VectorF

using namespace M3DM;


// Conversions
VectorF::VectorF(float value)
{
	load(value);
}
VectorF::VectorF(float x, float y, float z, float w)
{
	load(x, y, z, w);
}
VectorF::VectorF(const float* pArray)
{
	load(pArray);
}
VectorF::VectorF(const Vector2& vector)
{
	load(vector);
}
VectorF::VectorF(const Vector3& vector)
{
	load(vector);
}
VectorF::VectorF(const Vector4& vector)
{
	load(vector);
}
VectorF::VectorF(const Vector2& vector1, const Vector2& vector2)
{
	load(vector1, vector2);
}
VECCALL VectorF::operator __m128() const
{
	return m_data;
}
/*
VECCALL VectorF::operator __m128&()
{
	return m_data;
}
VECCALL VectorF::operator const __m128& () const
{
	return m_data;
}
*/

// getters and setters
float VECCALL VectorF::get(const char ind)  const
{
	switch (ind%4)
	{
	case 0:
		return int2Float(_mm_extract_ps(m_data, 0));
		break;
	case 1:
		return int2Float(_mm_extract_ps(m_data, 1));
		break;
	case 2:
		return int2Float(_mm_extract_ps(m_data, 2));
		break;
	case 3:
		return int2Float(_mm_extract_ps(m_data, 3));
		break;
	}
	
}
void VECCALL VectorF::set(char ind, float value)
{
	switch (ind % 4)
	{
	case 0:
		m_data = _mm_insert_ps(m_data, _mm_set1_ps(value), 0 << 4);
		break;
	case 1:
		m_data = _mm_insert_ps(m_data, _mm_set1_ps(value), 1 << 4);
		break;
	case 2:
		m_data = _mm_insert_ps(m_data, _mm_set1_ps(value), 2 << 4);
		break;
	case 3:
		m_data = _mm_insert_ps(m_data, _mm_set1_ps(value), 3 << 4);
		break;
	}
	
}
int VECCALL VectorF::getInt(char ind)  const
{
	switch (ind % 4)
	{
	case 0:
		return _mm_extract_epi32(_mm_castps_si128(m_data), 0);
		break;
	case 1:
		return _mm_extract_epi32(_mm_castps_si128(m_data), 1);
		break;
	case 2:
		return _mm_extract_epi32(_mm_castps_si128(m_data), 2);
		break;
	case 3:
		return _mm_extract_epi32(_mm_castps_si128(m_data), 3);
		break;
	}
	
}
void VECCALL VectorF::setInt(char ind, int value)
{
	switch (ind % 4)
	{
	case 0:
		m_data = _mm_castsi128_ps(_mm_insert_epi32(_mm_castps_si128(m_data), value, 0));
		break;
	case 1:
		m_data = _mm_castsi128_ps(_mm_insert_epi32(_mm_castps_si128(m_data), value, 1));
		break;
	case 2:
		m_data = _mm_castsi128_ps(_mm_insert_epi32(_mm_castps_si128(m_data), value, 2));
		break;
	case 3:
		m_data = _mm_castsi128_ps(_mm_insert_epi32(_mm_castps_si128(m_data), value, 3));
		break;
	}
	
}

// Base operations
VectorF VECCALL VectorF::operator+(VectorF vector) const
{
	return _mm_add_ps(m_data, vector.m_data);
}
VectorF VECCALL VectorF::operator-(VectorF vector) const
{
	return _mm_sub_ps(m_data, vector.m_data);
}
VectorF VECCALL VectorF::operator*(VectorF vector) const
{
	return _mm_mul_ps(m_data, vector.m_data);
}
VectorF VECCALL VectorF::operator/(VectorF vector) const
{
	return _mm_div_ps(m_data, vector.m_data);
}
VectorF VECCALL VectorF::operator*(float scale) const
{
	__m128 data2 = _mm_set_ps1(scale);
	return _mm_mul_ps(m_data, data2);
}
VectorF VECCALL VectorF::operator/(float scale) const
{
	__m128 data2 = _mm_set_ps1(scale);
	return _mm_div_ps(m_data, data2);
}
VectorF& VECCALL VectorF::operator+=(VectorF vector)
{
	m_data = _mm_add_ps(m_data, vector.m_data);
	return *this;
}
VectorF& VECCALL VectorF::operator-=(VectorF vector)
{
	m_data = _mm_sub_ps(m_data, vector.m_data);
	return *this;
}
VectorF& VECCALL VectorF::operator*=(VectorF vector)
{
	m_data = _mm_mul_ps(m_data, vector.m_data);
	return *this;
}
VectorF& VECCALL VectorF::operator/=(VectorF vector)
{
	m_data = _mm_div_ps(m_data, vector.m_data);
	return *this;
}
VectorF& VECCALL VectorF::operator*=(float scale)
{
	__m128 data2 = _mm_set_ps1(scale);
	m_data = _mm_mul_ps(m_data, data2);
	return *this;
}
VectorF& VECCALL VectorF::operator/=(float scale)
{
	__m128 data2 = _mm_set_ps1(scale);
	m_data = _mm_div_ps(m_data, data2);
	return *this;
}
VectorF VECCALL VectorF::operator-() const
{
	return _mm_sub_ps(__m128(), m_data);
}

VectorF VECCALL M3DM::operator*(float scale, VectorF vector)
{
	return vector * scale;
}
VectorF VECCALL  M3DM::operator/(float scale, VectorF vector)
{
	__m128 data2 = _mm_set_ps1(scale);
	return _mm_div_ps(data2, vector.m_data);
}


// Compare functions
bool VECCALL VectorF::operator==(VectorF vector) const
{
	__m128 dataEqual = _mm_castsi128_ps(_mm_cmpeq_epi32(_mm_castps_si128(m_data), _mm_castps_si128(vector.m_data)));
	//__m128 dataEqual = _mm_cmpeq_(m_data, vector.m_data);
	return _mm_test_all_ones(_mm_castps_si128(dataEqual));
}
bool VECCALL VectorF::operator<(VectorF vector) const
{
	__m128 dataCmp = _mm_cmplt_ps(m_data, vector.m_data);
	return _mm_test_all_ones(_mm_castps_si128(dataCmp));
}
bool VECCALL VectorF::operator>(VectorF vector) const
{
	__m128 dataCmp = _mm_cmpgt_ps(m_data, vector.m_data);
	return _mm_test_all_ones(_mm_castps_si128(dataCmp));
}
bool VECCALL VectorF::operator<=(VectorF vector) const
{
	__m128 dataCmp = _mm_cmple_ps(m_data, vector.m_data);
	return _mm_test_all_ones(_mm_castps_si128(dataCmp));
}
bool VECCALL VectorF::operator>=(VectorF vector) const
{
	__m128 dataCmp = _mm_cmpge_ps(m_data, vector.m_data);
	return _mm_test_all_ones(_mm_castps_si128(dataCmp));
}
bool VECCALL VectorF::isEqualPrec(VectorF vector, float precision, int mask) const
{
	__m128 delta = (*this - vector).abs();
	__m128 dataCmp = _mm_cmple_ps(delta, _mm_set_ps1(precision));
	return (_mm_movemask_ps(dataCmp) & mask) == mask;
}
bool VECCALL VectorF::isEqualPrec(VectorF vector, VectorF precision, int mask) const
{
	__m128 delta = (*this - vector).abs();
	__m128 dataCmp = _mm_cmple_ps(delta, precision);
	return (_mm_movemask_ps(dataCmp) & mask) == mask;
}
VectorF VECCALL VectorF::isEqualVec(VectorF vector) const
{
	return _mm_cmpeq_ps(m_data, vector.m_data);
}
VectorF VECCALL VectorF::isEqualPrecVec(VectorF vector, VectorF precision) const
{
	__m128 delta = (*this - vector).abs();
	return _mm_cmple_ps(delta, precision);
}

// Load/store
void VECCALL VectorF::load(float value)
{
	m_data = _mm_set_ps1(value);
}
void VECCALL VectorF::load(float x, float y, float z, float w)
{
	m_data = _mm_setr_ps(x, y, z, w);
}
void VECCALL VectorF::load(const float* pArray)
{
	m_data = _mm_load_ps(pArray);
}
void VECCALL VectorF::load(const Vector2& vector)
{
	m_data = _mm_load_ps(Vector4(vector));
}
void VECCALL VectorF::load(const Vector3& vector)
{
	m_data = _mm_load_ps(Vector4(vector));
}
void VECCALL VectorF::load(const Vector4& vector)
{
	m_data = _mm_load_ps(vector);
}
void VECCALL VectorF::load(const Vector2& vector1, const Vector2& vector2)
{
	
	m_data = _mm_load_ps(Vector4(vector1, vector2));
}

void VECCALL VectorF::store(float& x, float& y, float& z, float& w) const
{
	alignas(16) float vector[4];
	_mm_store_ps(vector, m_data);
	x = vector[0];
	y = vector[1];
	z = vector[2];
	w = vector[3];
}
void VECCALL VectorF::store(float* pArray) const
{
	_mm_store_ps(pArray, m_data);
}
void VECCALL VectorF::store(Vector2& vector) const
{
	alignas(16) float vectorData[4];
	_mm_store_ps(vectorData, m_data);
	vector = Vector2(vectorData);
}
void VECCALL VectorF::store(Vector3& vector) const
{
	alignas(16) float vectorData[4];
	_mm_store_ps(vectorData, m_data);
	vector = Vector3(vectorData);
}
void VECCALL VectorF::store(Vector4& vector) const
{
	_mm_store_ps(vector, m_data);
}
void VECCALL VectorF::store(Vector2& vector1, Vector2& vector2) const
{
	alignas(16) float vectorData[4];
	_mm_store_ps(vectorData, m_data);
	vector1 = Vector2(vectorData);
	vector2 = Vector2(vectorData + 2);

}


