#include "M3DMath.h"
#include <cmath>

/// Implementation of MatrixScalar

using namespace M3DM;

// Conversions
MatrixScalar::operator float* ()
{
	return reinterpret_cast<float*>(this);
}
MatrixScalar::operator float const* () const
{
	return reinterpret_cast<float const*>(this);
}


// base operations
MatrixScalar MatrixScalar::operator+(const MatrixScalar& matrix) const
{
	MatrixScalar matrixResult;
	// convert to arrays
	const float* matrix1Array = *this;
	const float* matrix2Array = matrix;
	float* resultArray = matrixResult;

	// calcuate
	for (int i = 0; i < 16; i++)
		resultArray[i] = matrix1Array[i] + matrix2Array[i];

	return matrixResult;
}
MatrixScalar MatrixScalar::operator-(const MatrixScalar& matrix) const
{
	MatrixScalar matrixResult;
	// convert to arrays
	const float* matrix1Array = *this;
	const float* matrix2Array = matrix;
	float* resultArray = matrixResult;

	// calcuate
	for (int i = 0; i < 16; i++)
		resultArray[i] = matrix1Array[i] - matrix2Array[i];

	return matrixResult;
}
MatrixScalar MatrixScalar::operator*(const MatrixScalar& matrix) const
{
	MatrixScalar matrixResult;
	// convert to arrays
	const float* matrix1Array = *this;
	const float* matrix2Array = matrix;
	float* resultArray = matrixResult;

	// calculate result
	resultArray[0] = matrix1Array[0] * matrix2Array[0] + matrix1Array[1] * matrix2Array[4] + matrix1Array[2] * matrix2Array[8 ] + matrix1Array[3] * matrix2Array[12];
	resultArray[1] = matrix1Array[0] * matrix2Array[1] + matrix1Array[1] * matrix2Array[5] + matrix1Array[2] * matrix2Array[9 ] + matrix1Array[3] * matrix2Array[13];
	resultArray[2] = matrix1Array[0] * matrix2Array[2] + matrix1Array[1] * matrix2Array[6] + matrix1Array[2] * matrix2Array[10] + matrix1Array[3] * matrix2Array[14];
	resultArray[3] = matrix1Array[0] * matrix2Array[3] + matrix1Array[1] * matrix2Array[7] + matrix1Array[2] * matrix2Array[11] + matrix1Array[3] * matrix2Array[15];

	resultArray[4] = matrix1Array[4] * matrix2Array[0] + matrix1Array[5] * matrix2Array[4] + matrix1Array[6] * matrix2Array[8 ] + matrix1Array[7] * matrix2Array[12];
	resultArray[5] = matrix1Array[4] * matrix2Array[1] + matrix1Array[5] * matrix2Array[5] + matrix1Array[6] * matrix2Array[9 ] + matrix1Array[7] * matrix2Array[13];
	resultArray[6] = matrix1Array[4] * matrix2Array[2] + matrix1Array[5] * matrix2Array[6] + matrix1Array[6] * matrix2Array[10] + matrix1Array[7] * matrix2Array[14];
	resultArray[7] = matrix1Array[4] * matrix2Array[3] + matrix1Array[5] * matrix2Array[7] + matrix1Array[6] * matrix2Array[11] + matrix1Array[7] * matrix2Array[15];

	resultArray[8] = matrix1Array[8] * matrix2Array[0] + matrix1Array[9] * matrix2Array[4] + matrix1Array[10] * matrix2Array[8 ] + matrix1Array[11] * matrix2Array[12];
	resultArray[9] = matrix1Array[8] * matrix2Array[1] + matrix1Array[9] * matrix2Array[5] + matrix1Array[10] * matrix2Array[9 ] + matrix1Array[11] * matrix2Array[13];
	resultArray[10] = matrix1Array[8] * matrix2Array[2] + matrix1Array[9] * matrix2Array[6] + matrix1Array[10] * matrix2Array[10] + matrix1Array[11] * matrix2Array[14];
	resultArray[11] = matrix1Array[8] * matrix2Array[3] + matrix1Array[9] * matrix2Array[7] + matrix1Array[10] * matrix2Array[11] + matrix1Array[11] * matrix2Array[15];

	resultArray[12] = matrix1Array[12] * matrix2Array[0] + matrix1Array[13] * matrix2Array[4] + matrix1Array[14] * matrix2Array[8 ] + matrix1Array[15] * matrix2Array[12];
	resultArray[13] = matrix1Array[12] * matrix2Array[1] + matrix1Array[13] * matrix2Array[5] + matrix1Array[14] * matrix2Array[9 ] + matrix1Array[15] * matrix2Array[13];
	resultArray[14] = matrix1Array[12] * matrix2Array[2] + matrix1Array[13] * matrix2Array[6] + matrix1Array[14] * matrix2Array[10] + matrix1Array[15] * matrix2Array[14];
	resultArray[15] = matrix1Array[12] * matrix2Array[3] + matrix1Array[13] * matrix2Array[7] + matrix1Array[14] * matrix2Array[11] + matrix1Array[15] * matrix2Array[15];

	return matrixResult;
}
MatrixScalar MatrixScalar::operator*(float scale) const
{
	MatrixScalar matrixResult;
	// convert to arrays
	const float* matrix1Array = *this;
	float* resultArray = matrixResult;

	// calcuate
	for (int i = 0; i < 16; i++)
		resultArray[i] = matrix1Array[i] * scale;

	return matrixResult;
}
MatrixScalar MatrixScalar::operator/(float scale) const
{
	MatrixScalar matrixResult;
	// convert to arrays
	const float* matrix1Array = *this;
	float* resultArray = matrixResult;

	// calcuate
	for (int i = 0; i < 16; i++)
		resultArray[i] = matrix1Array[i] / scale;

	return matrixResult;
}
MatrixScalar& MatrixScalar:: operator+=(const MatrixScalar& matrix)
{
	// convert to arrays
	float* matrix1Array = *this;
	const float* matrix2Array = matrix;

	// calcuate
	for (int i = 0; i < 16; i++)
		matrix1Array[i] = matrix1Array[i] + matrix2Array[i];

	return *this;
}
MatrixScalar& MatrixScalar::operator-=(const MatrixScalar& matrix)
{
	// convert to arrays
	float* matrix1Array = *this;
	const float* matrix2Array = matrix;

	// calcuate
	for (int i = 0; i < 16; i++)
		matrix1Array[i] = matrix1Array[i] - matrix2Array[i];

	return *this;
}
MatrixScalar& MatrixScalar::operator*=(const MatrixScalar& matrix)
{
	*this = *this * matrix;
	return *this;
}
MatrixScalar& MatrixScalar::operator*=(float scale)
{
	// convert to arrays
	float* matrix1Array = *this;

	// calcuate
	for (int i = 0; i < 16; i++)
		matrix1Array[i] = matrix1Array[i] * scale;

	return *this;
}
MatrixScalar& MatrixScalar::operator/=(float scale)
{
	// convert to arrays
	float* matrix1Array = *this;

	// calcuate
	for (int i = 0; i < 16; i++)
		matrix1Array[i] = matrix1Array[i] / scale;

	return *this;
}
MatrixScalar MatrixScalar::operator-() const
{
	MatrixScalar matrixResult;
	// convert to arrays
	const float* matrix1Array = *this;
	float* resultArray = matrixResult;

	// calcuate
	for (int i = 0; i < 16; i++)
		matrixResult[i] = -matrix1Array[i];

	return matrixResult;
}

// additional operations
MatrixScalar M3DM::operator*(float scale, const MatrixScalar& matrix)
{
	MatrixScalar matrixResult;
	// convert to arrays
	const float* matrix1Array = matrix;
	float* resultArray = matrixResult;

	// calcuate
	for (int i = 0; i < 16; i++)
		resultArray[i] = matrix1Array[i] * scale;

	return matrixResult;
}
MatrixScalar M3DM::operator/(float scale, const MatrixScalar& matrix)
{
	MatrixScalar matrixResult;
	// convert to arrays
	const float* matrix1Array = matrix;
	float* resultArray = matrixResult;

	// calcuate
	for (int i = 0; i < 16; i++)
		resultArray[i] = scale / matrix1Array[i];

	return matrixResult;
}

// compare
bool MatrixScalar::operator==(const MatrixScalar& matrix) const
{
	// convert to arrays
	const float* matrix1Array = *this;
	const float* matrix2Array = matrix;

	// calcuate
	for (int i = 0; i < 16; i++)
		if (matrix1Array[i] != matrix2Array[i])
			return false;

	return true;
}
bool MatrixScalar::operator<(const MatrixScalar& matrix) const
{
	// convert to arrays
	const float* matrix1Array = *this;
	const float* matrix2Array = matrix;

	// calcuate
	for (int i = 0; i < 16; i++)
		if (matrix1Array[i] >= matrix2Array[i])
			return false;

	return true;
}
bool MatrixScalar::operator>(const MatrixScalar& matrix) const
{
	// convert to arrays
	const float* matrix1Array = *this;
	const float* matrix2Array = matrix;

	// calcuate
	for (int i = 0; i < 16; i++)
		if (matrix1Array[i] <= matrix2Array[i])
			return false;

	return true;
}
bool MatrixScalar::operator<=(const MatrixScalar& matrix) const
{
	// convert to arrays
	const float* matrix1Array = *this;
	const float* matrix2Array = matrix;

	// calcuate
	for (int i = 0; i < 16; i++)
		if (matrix1Array[i] > matrix2Array[i])
			return false;

	return true;
}
bool MatrixScalar::operator>=(const MatrixScalar& matrix) const
{
	// convert to arrays
	const float* matrix1Array = *this;
	const float* matrix2Array = matrix;

	// calcuate
	for (int i = 0; i < 16; i++)
		if (matrix1Array[i] < matrix2Array[i])
			return false;

	return true;
}
bool MatrixScalar::isEqualPrec(const MatrixScalar& matrix, float precision) const
{
	// convert to arrays
	const float* matrix1Array = *this;
	const float* matrix2Array = matrix;

	// calcuate
	for (int i = 0; i < 16; i++)
		if (abs(matrix1Array[i] - matrix2Array[i]) > precision)
			return false;

	return true;
}
bool MatrixScalar::isEqualPrec(const MatrixScalar& matrix, const MatrixScalar& precision) const
{
	// convert to arrays
	const float* matrix1Array = *this;
	const float* matrix2Array = matrix;
	const float* precisionArray = precision;

	// calcuate
	for (int i = 0; i < 16; i++)
		if (abs(matrix1Array[i] - matrix2Array[i]) > precisionArray[i])
			return false;

	return true;
}


// methods
MatrixScalar MatrixScalar::transpose() const
{
	MatrixScalar matrixResult;

	// move matrix elements
	matrixResult.m11 = m11;
	matrixResult.m12 = m21;
	matrixResult.m13 = m31;
	matrixResult.m14 = m41;

	matrixResult.m21 = m12;
	matrixResult.m22 = m22;
	matrixResult.m23 = m32;
	matrixResult.m24 = m42;

	matrixResult.m31 = m13;
	matrixResult.m32 = m23;
	matrixResult.m33 = m33;
	matrixResult.m34 = m43;

	matrixResult.m41 = m14;
	matrixResult.m42 = m24;
	matrixResult.m43 = m34;
	matrixResult.m44 = m44;

	return matrixResult;
}
MatrixScalar MatrixScalar::inverse() const
{
	MatrixScalar resultMatrix;
	float det = determinant();
	if (!det)
	{
		return matrixScalarInfinity();
	}

	resultMatrix.m11 = matrixScalar3Determinant(m22, m23, m24, m32, m33, m34, m42, m43, m44);
	resultMatrix.m21 = -matrixScalar3Determinant(m21, m23, m24, m31, m33, m34, m41, m43, m44);
	resultMatrix.m31 = matrixScalar3Determinant(m21, m22, m24, m31, m32, m34, m41, m42, m44);
	resultMatrix.m41 = -matrixScalar3Determinant(m21, m22, m23, m31, m32, m33, m41, m42, m43);
	resultMatrix.m12 = -matrixScalar3Determinant(m12, m13, m14, m32, m33, m34, m42, m43, m44);
	resultMatrix.m22 = matrixScalar3Determinant(m11, m13, m14, m31, m33, m34, m41, m43, m44);
	resultMatrix.m32 = -matrixScalar3Determinant(m11, m12, m14, m31, m32, m34, m41, m42, m44);
	resultMatrix.m42 = matrixScalar3Determinant(m11, m12, m13, m31, m32, m33, m41, m42, m43);
	resultMatrix.m13 = matrixScalar3Determinant(m12, m13, m14, m22, m23, m24, m42, m43, m44);
	resultMatrix.m23 = -matrixScalar3Determinant(m11, m13, m14, m21, m23, m24, m41, m43, m44);
	resultMatrix.m33 = matrixScalar3Determinant(m11, m12, m14, m21, m22, m24, m41, m42, m44);
	resultMatrix.m43 = -matrixScalar3Determinant(m11, m12, m13, m21, m22, m23, m41, m42, m43);
	resultMatrix.m14 = -matrixScalar3Determinant(m12, m13, m14, m22, m23, m24, m32, m33, m34);
	resultMatrix.m24 = matrixScalar3Determinant(m11, m13, m14, m21, m23, m24, m31, m33, m34);
	resultMatrix.m34 = -matrixScalar3Determinant(m11, m12, m14, m21, m22, m24, m31, m32, m34);
	resultMatrix.m44 = matrixScalar3Determinant(m11, m12, m13, m21, m22, m23, m31, m32, m33);

	resultMatrix *= 1 / det;

	return resultMatrix;
}
float MatrixScalar::determinant() const
{
	float det1, det2, det3, det4;

	// calculate determinant by first row
	det1 = matrixScalar3Determinant(m22, m23, m24,
		m32, m33, m34,
		m42, m43, m44);
	det2 = matrixScalar3Determinant(m21, m23, m24,
		m31, m33, m34,
		m41, m43, m44);
	det3 = matrixScalar3Determinant(m21, m22, m24,
		m31, m32, m34,
		m41, m42, m44);
	det4 = matrixScalar3Determinant(m21, m22, m23,
		m31, m32, m33,
		m41, m42, m43);

	return m11* det1 - m12 * det2 + m13 * det3 - m14 * det4;
}

//functions
float M3DM::matrixScalar3Determinant(float m11, float m12, float m13,
	float m21, float m22, float m23,
	float m31, float m32, float m33)
{
	return m11 * m22* m33 -
		m11 * m23 * m32 -
		m12 * m21 * m33 +
		m12 * m23 * m31 +
		m13 * m21 * m32 -
		m13 * m22 * m31;
}

MatrixScalar M3DM::matrixScalarIdentity()
{
	return MatrixScalar(1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1);
}
MatrixScalar M3DM::matrixScalarInfinity()
{
	return MatrixScalar(INFINITY, INFINITY, INFINITY, INFINITY,
		INFINITY, INFINITY, INFINITY, INFINITY,
		INFINITY, INFINITY, INFINITY, INFINITY,
		INFINITY, INFINITY, INFINITY, INFINITY);
}