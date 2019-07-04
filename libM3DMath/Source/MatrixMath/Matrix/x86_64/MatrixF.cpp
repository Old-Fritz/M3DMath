#include "M3DMath.h"
#include <cmath>

/// Implementation of MatrixF

using namespace M3DM;

// convertions
#ifdef DIRECTX
DirectX::XMMATRIX VECCALL MatrixF::XMMatrix()
{
	DirectX::XMMATRIX matrixResult;
	MatrixScalar matrixScalar;
	store(matrixScalar);

	return matrixScalar.XMMatrix();
}
#endif

// getters and setters
float VECCALL MatrixF::get(char  ind) const
{
	int row = ind / 4;
	switch (row)
	{
	case 0:
		return m_row1.get(ind % 4);
		break;
	case 1:
		return m_row2.get(ind % 4);
		break;
	case 2:
		return m_row3.get(ind % 4);
		break;
	case 3:
		return m_row4.get(ind % 4);
		break;
	}
}

void VECCALL MatrixF::set(char ind, float value)
{
	int row = ind / 4;
	switch (row)
	{
	case 0:
		m_row1.set(ind % 4, value);
		break;
	case 1:
		m_row2.set(ind % 4, value);
		break;
	case 2:
		m_row3.set(ind % 4, value);
		break;
	case 3:
		m_row4.set(ind % 4, value);
		break;
	}
}
int VECCALL MatrixF::getInt(char ind) const
{
	int row = ind / 4;
	switch (row)
	{
	case 0:
		return m_row1.getInt(ind % 4);
		break;
	case 1:
		return m_row2.getInt(ind % 4);
		break;
	case 2:
		return m_row3.getInt(ind % 4);
		break;
	case 3:
		return m_row4.getInt(ind % 4);
		break;
	}
}
void VECCALL MatrixF::setInt(char ind, int value)
{
	int row = ind / 4;
	switch (row)
	{
	case 0:
		m_row1.setInt(ind % 4, value);
		break;
	case 1:
		m_row2.setInt(ind % 4, value);
		break;
	case 2:
		m_row3.setInt(ind % 4, value);
		break;
	case 3:
		m_row4.setInt(ind % 4, value);
		break;
	}
}


// base operations
MatrixF VECCALL MatrixF::operator+(MatrixF matrix) const
{
	MatrixF matrixResult;

	matrixResult.m_row1 = m_row1 + matrix.m_row1;
	matrixResult.m_row2 = m_row2 + matrix.m_row2;
	matrixResult.m_row3 = m_row3 + matrix.m_row3;
	matrixResult.m_row4 = m_row4 + matrix.m_row4;

	return matrixResult;
}

MatrixF VECCALL MatrixF::operator-(MatrixF matrix) const
{
	MatrixF matrixResult;

	matrixResult.m_row1 = m_row1 - matrix.m_row1;
	matrixResult.m_row1 = m_row2 - matrix.m_row2;
	matrixResult.m_row1 = m_row3 - matrix.m_row3;
	matrixResult.m_row1 = m_row4 - matrix.m_row4;

	return matrixResult;
}
MatrixF VECCALL MatrixF::operator*(MatrixF matrix) const
{
	MatrixF matrixResult;

	

	return matrixResult;
}
MatrixF VECCALL MatrixF::operator*(float scale) const
{
	MatrixF matrixResult;

	matrixResult.m_row1 = m_row1 * scale;
	matrixResult.m_row1 = m_row2 * scale;
	matrixResult.m_row1 = m_row3 * scale;
	matrixResult.m_row1 = m_row4 * scale;

	return matrixResult;
}
MatrixF VECCALL MatrixF::operator/(float scale) const
{
	MatrixF matrixResult;

	matrixResult.m_row1 = m_row1 / scale;
	matrixResult.m_row2 = m_row2 / scale;
	matrixResult.m_row3 = m_row3 / scale;
	matrixResult.m_row4 = m_row4 / scale;

	return matrixResult;
}
MatrixF& VECCALL MatrixF::operator+=(MatrixF matrix)
{
	m_row1 += matrix.m_row1;
	m_row2 += matrix.m_row2;
	m_row3 += matrix.m_row3;
	m_row4 += matrix.m_row4;

	return *this;
}
MatrixF& VECCALL MatrixF::operator-=(MatrixF matrix)
{
	m_row1 -= matrix.m_row1;
	m_row2 -= matrix.m_row2;
	m_row3 -= matrix.m_row3;
	m_row4 -= matrix.m_row4;

	return *this;
}
MatrixF& VECCALL MatrixF::operator*=(MatrixF matrix)
{
	MatrixF matrixResult;

	

	return matrixResult;
}
MatrixF& VECCALL MatrixF::operator*=(float scale)
{
	m_row1 *= scale;
	m_row2 *= scale;
	m_row3 *= scale;
	m_row4 *= scale;

	return *this;
}
MatrixF& VECCALL MatrixF::operator/=(float scale)
{
	m_row1 /= scale;
	m_row2 /= scale;
	m_row3 /= scale;
	m_row4 /= scale;

	return *this;
}
MatrixF VECCALL MatrixF::operator-() const
{
	MatrixF matrixResult;

	matrixResult.m_row1 = -m_row1;
	matrixResult.m_row2 = -m_row2;
	matrixResult.m_row3 = -m_row3;
	matrixResult.m_row4 = -m_row4;

	return matrixResult;
}

// additional operations
MatrixF VECCALL M3DM::operator*(float scale, MatrixF matrix)
{
	MatrixF matrixResult;

	matrixResult.m_row1 = matrix.m_row1 * scale;
	matrixResult.m_row2 = matrix.m_row2 * scale;
	matrixResult.m_row3 = matrix.m_row3 * scale;
	matrixResult.m_row4 = matrix.m_row4 * scale;

	return matrixResult;
}
MatrixF VECCALL M3DM::operator/(float scale, MatrixF matrix)
{
	MatrixF matrixResult;

	matrixResult.m_row1 = scale / matrix.m_row1;
	matrixResult.m_row2 = scale / matrix.m_row2;
	matrixResult.m_row3 = scale / matrix.m_row3;
	matrixResult.m_row4 = scale / matrix.m_row4;

	return matrixResult;
}

// compare
bool VECCALL MatrixF::operator==(MatrixF matrix) const
{
	return (m_row1 == matrix.m_row1) && (m_row2 == matrix.m_row2) && (m_row3 == matrix.m_row3) && (m_row4 == matrix.m_row4);
}
bool VECCALL MatrixF::operator<(MatrixF matrix) const
{
	return (m_row1 < matrix.m_row1) && (m_row2 < matrix.m_row2) && (m_row3 < matrix.m_row3) && (m_row4 < matrix.m_row4);
}
bool VECCALL MatrixF::operator>(MatrixF matrix) const
{
	return (m_row1 > matrix.m_row1) && (m_row2 > matrix.m_row2) && (m_row3 > matrix.m_row3) && (m_row4 > matrix.m_row4);
}
bool VECCALL MatrixF::operator<=(MatrixF matrix) const
{
	return (m_row1 <= matrix.m_row1) && (m_row2 <= matrix.m_row2) && (m_row3 <= matrix.m_row3) && (m_row4 <= matrix.m_row4);
}
bool VECCALL MatrixF::operator>=(MatrixF matrix) const
{
	return (m_row1 >= matrix.m_row1) && (m_row2 >= matrix.m_row2) && (m_row3 >= matrix.m_row3) && (m_row4 >= matrix.m_row4);
}
bool VECCALL MatrixF::isEqualPrec(MatrixF matrix, float precision) const
{
	return (m_row1.isEqualPrec(matrix.m_row1, precision)) && (m_row2.isEqualPrec(matrix.m_row2, precision)) 
		&& (m_row3.isEqualPrec(matrix.m_row3, precision)) && (m_row4.isEqualPrec(matrix.m_row4, precision));
}
bool VECCALL MatrixF::isEqualPrec(MatrixF matrix, MatrixF precision) const
{
	return (m_row1.isEqualPrec(matrix.m_row1, precision.m_row1)) && (m_row2.isEqualPrec(matrix.m_row2, precision.m_row2)) 
		&& (m_row3.isEqualPrec(matrix.m_row3, precision.m_row3)) && (m_row4.isEqualPrec(matrix.m_row4, precision.m_row4));
}

// store/load
void VECCALL MatrixF::load(float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44)
{
	m_row1.load(m11, m12, m13, m14); 
	m_row2.load(m21, m22, m23, m24);
	m_row2.load(m31, m32, m33, m34);
	m_row4.load(m41, m42, m43, m44);
}
void VECCALL MatrixF::load(const float* pArray)
{
	m_row1.load(pArray);
	m_row2.load(pArray + 4);
	m_row3.load(pArray + 8);
	m_row3.load(pArray + 12);
}
void VECCALL MatrixF::load(const MatrixScalar& matrix)
{
	m_row1.load(matrix);
	m_row2.load(matrix + 4);
	m_row3.load(matrix + 8);
	m_row3.load(matrix + 12);
}
void VECCALL MatrixF::load(VectorF row1, VectorF row2, VectorF row3, VectorF row4)
{
	m_row1 = row1;
	m_row2 = row2;
	m_row3 = row3;
	m_row4 = row4;
}

void VECCALL MatrixF::store(float& m11, float& m12, float& m13, float& m14,
	float& m21, float& m22, float& m23, float& m24,
	float& m31, float& m32, float& m33, float& m34,
	float& m41, float& m42, float& m43, float& m44) const
{
	m_row1.store(m11, m12, m13, m14);
	m_row2.store(m21, m22, m23, m24);
	m_row2.store(m31, m32, m33, m34);
	m_row4.store(m41, m42, m43, m44);
}
void VECCALL MatrixF::store(float* pArray) const
{
	m_row1.store(pArray);
	m_row2.store(pArray + 4);
	m_row3.store(pArray + 8);
	m_row3.store(pArray + 12);
}

void VECCALL MatrixF::store(MatrixScalar& matrix) const
{
	m_row1.store(matrix);
	m_row2.store(matrix+4);
	m_row3.store(matrix+8);
	m_row3.store(matrix+12);
}
void VECCALL MatrixF::store(VectorF& row1, VectorF& row2, VectorF& row3, VectorF& row4) const
{
	row1 = m_row1;
	row2 = m_row2;
	row3 = m_row3;
	row4 = m_row4;
}
// methods
MatrixF VECCALL MatrixF::transpose() const
{
	MatrixF matrixResult;

	__m128 tmp1, tmp2, tmp3, tmp4;
	tmp1 = _mm_shuffle_ps(m_row1, m_row2, 0x44);
	tmp3 = _mm_shuffle_ps(m_row1, m_row2, 0xEE);
	tmp2 = _mm_shuffle_ps(m_row3, m_row4, 0x44);
	tmp4 = _mm_shuffle_ps(m_row3, m_row4, 0xEE);

	matrixResult.m_row1 = _mm_shuffle_ps(tmp1, tmp2, 0x88);
	matrixResult.m_row2 = _mm_shuffle_ps(tmp1, tmp2, 0xDD);
	matrixResult.m_row3 = _mm_shuffle_ps(tmp3, tmp4, 0x88);
	matrixResult.m_row4 = _mm_shuffle_ps(tmp3, tmp4, 0xDD);


	return matrixResult;
}
MatrixF VECCALL MatrixF::inverse() const
{
	MatrixF matrixResult;

	return matrixResult;
}
VectorF VECCALL MatrixF::determinantVec() const
{
	VectorF vectorResult;

	return vectorResult;
}
float VECCALL MatrixF::determinant() const
{
	return 0;
}

//functions
MatrixF VECCALL M3DM::matrixFIdentity()
{
	return MatrixF(1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1);
}
MatrixF VECCALL M3DM::matrixFInfinity()
{
	return MatrixF(INFINITY, INFINITY, INFINITY, INFINITY,
		INFINITY, INFINITY, INFINITY, INFINITY,
		INFINITY, INFINITY, INFINITY, INFINITY,
		INFINITY, INFINITY, INFINITY, INFINITY);
}