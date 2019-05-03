#pragma once

#include "M3DMath.h"

/// Implementation of DoubleVectorF

using namespace M3DM;


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
DoubleVectorF::DoubleVectorF(const Vector2& vector1, const Vector2& vector2, const Vector2& vector3,
	const Vector2& vector4)
{
	load(vector1, vector2, vector3, vector4);
}
DoubleVectorF::DoubleVectorF(const VectorF& vector)
{
	load(vector);
}
DoubleVectorF::DoubleVectorF(const VectorF& vector1, const VectorF& vector2)
{
	load(vector1, vector2);
}
DoubleVectorF::operator __m256() const
{
	return m_data;
}

// Base operations
DoubleVectorF DoubleVectorF::operator+(const DoubleVectorF& vector) const
{
	return _mm256_add_ps(m_data, vector.m_data);
}
DoubleVectorF DoubleVectorF::operator-(const DoubleVectorF& vector) const
{
	return _mm256_sub_ps(m_data, vector.m_data);
}
DoubleVectorF DoubleVectorF::operator*(const DoubleVectorF& vector) const
{
	return _mm256_mul_ps(m_data, vector.m_data);
}
DoubleVectorF DoubleVectorF::operator/(const DoubleVectorF& vector) const
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
DoubleVectorF& DoubleVectorF::operator+=(const DoubleVectorF& vector)
{
	m_data = _mm256_add_ps(m_data, vector.m_data);
	return *this;
}
DoubleVectorF& DoubleVectorF::operator-=(const DoubleVectorF& vector)
{
	m_data = _mm256_sub_ps(m_data, vector.m_data);
	return *this;
}
DoubleVectorF& DoubleVectorF::operator*=(const DoubleVectorF& vector)
{
	m_data = _mm256_mul_ps(m_data, vector.m_data);
	return *this;
}
DoubleVectorF& DoubleVectorF::operator/=(const DoubleVectorF& vector)
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
bool DoubleVectorF::operator==(const DoubleVectorF& vector) const
{
	__m256 dataEqual = _mm256_cmp_ps(m_data, vector.m_data, 0);
    return _mm256_testc_si256(_mm256_castps_si256(dataEqual), _mm256_castps_si256(_mm256_cmp_ps(dataEqual,dataEqual, 0)));
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
void DoubleVectorF::load(const VectorF& vector)
{
	m_data = _mm256_insertf128_ps(__m256(), vector, 1);
}
void DoubleVectorF::load(const VectorF& vector1, const VectorF& vector2)
{
    m_data =  _mm256_insertf128_ps(_mm256_castps128_ps256(vector1), (vector2), 0x1);
}

void DoubleVectorF::store(float& x1, float& y1, float& z1, float& w1, float& x2, float& y2, float& z2, float& w2) const
{
	float vector[8];
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
	float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector = Vector2(vectorData);
}
void DoubleVectorF::store(Vector3& vector) const
{
	float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector = Vector3(vectorData);
}
void DoubleVectorF::store(Vector4& vector) const
{
	float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector = Vector4(vectorData);
}
void DoubleVectorF::store(Vector2& vector1, Vector2& vector2) const
{
	float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector1 = Vector2(vectorData);
	vector2 = Vector2(vectorData+4);
}
void DoubleVectorF::store(Vector3& vector1, Vector3& vector2) const
{
	float vectorData[8];
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
	float vectorData[8];
	_mm256_store_ps(vectorData, m_data);
	vector1 = Vector2(vectorData);
	vector2 = Vector2(vectorData + 2);
	vector3 = Vector2(vectorData + 4);
	vector4 = Vector2(vectorData + 6);
}
void DoubleVectorF::store(VectorF& vector) const
{
	vector = _mm256_extractf128_ps(m_data, 1);
}
void DoubleVectorF::store(VectorF& vector1, VectorF& vector2) const
{
	vector1 = _mm256_extractf128_ps(m_data, 1);
	vector2 = _mm256_extractf128_ps(m_data, 0);
}