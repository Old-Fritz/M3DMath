#pragma once

#include "M3DMath.h"

/// Implementation of VectorF

using namespace M3DM;

// Conversions
VectorF::VectorF(float x, float y, float z, float w)
{
	load(x, y, z, w);
}
VectorF::VectorF(float* pArray)
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
VectorF::operator __m128() const
{
	return m_data;
}

// Base operations
VectorF VectorF::operator+(const VectorF& vector) const
{
	return _mm_add_ps(m_data, vector.m_data);
}
VectorF VectorF::operator-(const VectorF& vector) const
{
	return _mm_sub_ps(m_data, vector.m_data);
}
VectorF VectorF::operator*(const VectorF& vector) const
{
	return _mm_mul_ps(m_data, vector.m_data);
}
VectorF VectorF::operator/(const VectorF& vector) const
{
	return _mm_div_ps(m_data, vector.m_data);
}
VectorF VectorF::operator*(float scale) const
{
	__m128 data2 = _mm_load_ps1(&scale);
	return _mm_mul_ps(m_data, data2);
}
VectorF VectorF::operator/(float scale) const
{
	__m128 data2 = _mm_load_ps1(&scale);
	return _mm_div_ps(m_data, data2);
}
VectorF& VectorF::operator+=(const VectorF& vector)
{
	m_data = _mm_add_ps(m_data, vector.m_data);
	return *this;
}
VectorF& VectorF::operator-=(const VectorF& vector)
{
	m_data = _mm_sub_ps(m_data, vector.m_data);
	return *this;
}
VectorF& VectorF::operator*=(const VectorF& vector)
{
	m_data = _mm_mul_ps(m_data, vector.m_data);
	return *this;
}
VectorF& VectorF::operator/=(const VectorF& vector)
{
	m_data = _mm_div_ps(m_data, vector.m_data);
	return *this;
}
VectorF& VectorF::operator*=(float scale)
{
	__m128 data2 = _mm_load_ps1(&scale);
	m_data = _mm_mul_ps(m_data, data2);
	return *this;
}
VectorF& VectorF::operator/=(float scale)
{
	__m128 data2 = _mm_load_ps1(&scale);
	m_data = _mm_div_ps(m_data, data2);
	return *this;
}
bool VectorF::operator==(const VectorF& vector) const
{
	__m128 dataEqual = _mm_cmpeq_ps(m_data, vector.m_data);
	return _mm_test_all_ones(_mm_castps_si128(dataEqual));
}

// Load/store
void VectorF::load(float x, float y, float z, float w)
{
	m_data = _mm_set_ps(x, y, z, w);
}
void VectorF::load(const float* pArray)
{
	m_data = _mm_load_ps(pArray);
}
void VectorF::load(const Vector2& vector)
{
	m_data = _mm_load_ps(Vector4(vector));
}
void VectorF::load(const Vector3& vector)
{
	m_data = _mm_load_ps(Vector4(vector));
}
void VectorF::load(const Vector4& vector)
{
	m_data = _mm_load_ps(vector);
}
void VectorF::load(const Vector2& vector1, const Vector2& vector2)
{
	m_data = _mm_load_ps(Vector4(vector1, vector2));
}

void VectorF::store(float& x, float& y, float& z, float& w) const
{
	float vector[4];
	_mm_store_ps(vector, m_data);
	x = vector[0];
	y = vector[1];
	z = vector[2];
	w = vector[3];
}
void VectorF::store(float* pArray) const
{
	_mm_store_ps(pArray, m_data);
}
void VectorF::store(Vector2& vector) const
{
	float vectorData[4];
	_mm_store_ps(vectorData, m_data);
	vector = Vector2(vectorData);
}
void VectorF::store(Vector3& vector) const
{
	float vectorData[4];
	_mm_store_ps(vectorData, m_data);
	vector = Vector3(vectorData);
}
void VectorF::store(Vector4& vector) const
{
	_mm_store_ps(vector, m_data);
}
void VectorF::store(Vector2& vector1, Vector2& vector2) const
{
	float vectorData[4];
	_mm_store_ps(vectorData, m_data);
	vector1 = Vector2(vectorData);
	vector2 = Vector2(vectorData + 2);

}