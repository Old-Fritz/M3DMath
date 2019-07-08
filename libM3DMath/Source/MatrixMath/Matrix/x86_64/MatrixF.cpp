#include "M3DMath.h"
#include <cmath>

/// Row matricies funcs

// for row major matrix
// we use __m128 to represent 2x2 matrix as A = | A0  A1 |
//                                              | A2  A3 |
// 2x2 row major Matrix multiply A*B
__forceinline __m128 VECCALL matrixF2Mul(__m128 vec1, __m128 vec2)
{
	return
		_mm_add_ps(_mm_mul_ps(vec1, vecFSwizzle(vec2, 0, 3, 0, 3)),
			_mm_mul_ps(vecFSwizzle(vec1, 1, 0, 3, 2), vecFSwizzle(vec2, 2, 1, 2, 1)));
}
// 2x2 row major Matrix adjugate multiply (A#)*B
__forceinline __m128 VECCALL matrixF2AdjMul(__m128 vec1, __m128 vec2)
{
	return
		_mm_sub_ps(_mm_mul_ps(vecFSwizzle(vec1, 3, 3, 0, 0), vec2),
			_mm_mul_ps(vecFSwizzle(vec1, 1, 1, 2, 2), vecFSwizzle(vec2, 2, 3, 0, 1)));
}
// 2x2 row major Matrix multiply adjugate A*(B#)
__forceinline __m128 VECCALL matrixF2MulAdj(__m128 vec1, __m128 vec2)
{
	return
		_mm_sub_ps(_mm_mul_ps(vec1, vecFSwizzle(vec2, 3, 0, 3, 0)),
			_mm_mul_ps(vecFSwizzle(vec1, 1, 0, 3, 2), vecFSwizzle(vec2, 2, 1, 2, 1)));
}

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
	matrixResult.m_row2 = m_row2 - matrix.m_row2;
	matrixResult.m_row3 = m_row3 - matrix.m_row3;
	matrixResult.m_row4 = m_row4 - matrix.m_row4;

	return matrixResult;
}
MatrixF VECCALL MatrixF::operator*(MatrixF matrix) const
{
	MatrixF matrixResult;

	MatrixF tempMatrix = matrix.transpose();
	__m128 tmpDp;

	// row 1
	matrixResult.m_row1 = _mm_dp_ps(m_row1.getData(), tempMatrix.m_row1.getData(), 0b11110001); // c11
	tmpDp = _mm_dp_ps(m_row1.getData(), tempMatrix.m_row2.getData(), 0b11110010); // c12
	matrixResult.m_row1 = _mm_or_ps(matrixResult.m_row1.getData(), tmpDp);
	tmpDp = _mm_dp_ps(m_row1.getData(), tempMatrix.m_row3.getData(), 0b11110100); // c13
	matrixResult.m_row1 = _mm_or_ps(matrixResult.m_row1.getData(), tmpDp);
	tmpDp = _mm_dp_ps(m_row1.getData(), tempMatrix.m_row4.getData(), 0b11111000); // c14
	matrixResult.m_row1 = _mm_or_ps(matrixResult.m_row1.getData(), tmpDp);

	// row 2
	matrixResult.m_row2 = _mm_dp_ps(m_row2.getData(), tempMatrix.m_row1.getData(), 0b11110001); // c11
	tmpDp = _mm_dp_ps(m_row2.getData(), tempMatrix.m_row2.getData(), 0b11110010); // c12
	matrixResult.m_row2 = _mm_or_ps(matrixResult.m_row2.getData(), tmpDp);
	tmpDp = _mm_dp_ps(m_row2.getData(), tempMatrix.m_row3.getData(), 0b11110100); // c13
	matrixResult.m_row2 = _mm_or_ps(matrixResult.m_row2.getData(), tmpDp);
	tmpDp = _mm_dp_ps(m_row2.getData(), tempMatrix.m_row4.getData(), 0b11111000); // c14
	matrixResult.m_row2 = _mm_or_ps(matrixResult.m_row2.getData(), tmpDp);

	// row 3
	matrixResult.m_row3 = _mm_dp_ps(m_row3.getData(), tempMatrix.m_row1.getData(), 0b11110001); // c11
	tmpDp = _mm_dp_ps(m_row3.getData(), tempMatrix.m_row2.getData(), 0b11110010); // c12
	matrixResult.m_row3 = _mm_or_ps(matrixResult.m_row3.getData(), tmpDp);
	tmpDp = _mm_dp_ps(m_row3.getData(), tempMatrix.m_row3.getData(), 0b11110100); // c13
	matrixResult.m_row3 = _mm_or_ps(matrixResult.m_row3.getData(), tmpDp);
	tmpDp = _mm_dp_ps(m_row3.getData(), tempMatrix.m_row4.getData(), 0b11111000); // c14
	matrixResult.m_row3 = _mm_or_ps(matrixResult.m_row3.getData(), tmpDp);

	// row 4
	matrixResult.m_row4 = _mm_dp_ps(m_row4.getData(), tempMatrix.m_row1.getData(), 0b11110001); // c11
	tmpDp = _mm_dp_ps(m_row4.getData(), tempMatrix.m_row2.getData(), 0b11110010); // c12
	matrixResult.m_row4 = _mm_or_ps(matrixResult.m_row4.getData(), tmpDp);
	tmpDp = _mm_dp_ps(m_row4.getData(), tempMatrix.m_row3.getData(), 0b11110100); // c13
	matrixResult.m_row4 = _mm_or_ps(matrixResult.m_row4.getData(), tmpDp);
	tmpDp = _mm_dp_ps(m_row4.getData(), tempMatrix.m_row4.getData(), 0b11111000); // c14
	matrixResult.m_row4 = _mm_or_ps(matrixResult.m_row4.getData(), tmpDp);

	return matrixResult;
}
MatrixF VECCALL MatrixF::operator*(float scale) const
{
	MatrixF matrixResult;

	matrixResult.m_row1 = m_row1 * scale;
	matrixResult.m_row2 = m_row2 * scale;
	matrixResult.m_row3 = m_row3 * scale;
	matrixResult.m_row4 = m_row4 * scale;

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
	*this = *this * matrix;

	return *this;
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
	m_row3.load(m31, m32, m33, m34);
	m_row4.load(m41, m42, m43, m44);
}
void VECCALL MatrixF::load(const float* pArray)
{
	m_row1.load(pArray);
	m_row2.load(pArray + 4);
	m_row3.load(pArray + 8);
	m_row4.load(pArray + 12);
}
void VECCALL MatrixF::load(const MatrixScalar& matrix)
{
	m_row1.load(matrix);
	m_row2.load(matrix + 4);
	m_row3.load(matrix + 8);
	m_row4.load(matrix + 12);
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
	m_row3.store(m31, m32, m33, m34);
	m_row4.store(m41, m42, m43, m44);
}
void VECCALL MatrixF::store(float* pArray) const
{
	m_row1.store(pArray);
	m_row2.store(pArray + 4);
	m_row3.store(pArray + 8);
	m_row4.store(pArray + 12);
}

void VECCALL MatrixF::store(MatrixScalar& matrix) const
{
	m_row1.store(matrix);
	m_row2.store(matrix+4);
	m_row3.store(matrix+8);
	m_row4.store(matrix+12);
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
	tmp1 = _mm_shuffle_ps(m_row1.getData(), m_row2.getData(), 0x44);
	tmp3 = _mm_shuffle_ps(m_row1.getData(), m_row2.getData(), 0xEE);
	tmp2 = _mm_shuffle_ps(m_row3.getData(), m_row4.getData(), 0x44);
	tmp4 = _mm_shuffle_ps(m_row3.getData(), m_row4.getData(), 0xEE);

	matrixResult.m_row1 = _mm_shuffle_ps(tmp1, tmp2, 0x88);
	matrixResult.m_row2 = _mm_shuffle_ps(tmp1, tmp2, 0xDD);
	matrixResult.m_row3 = _mm_shuffle_ps(tmp3, tmp4, 0x88);
	matrixResult.m_row4 = _mm_shuffle_ps(tmp3, tmp4, 0xDD);


	return matrixResult;
}
MatrixF VECCALL MatrixF::inverse() const
{
	MatrixF matrixResult;

	// use block matrix method

	// sub matrices
	__m128 A = vecFShuffle_0101(m_row1.getData(), m_row2.getData());
	__m128 B = vecFShuffle_2323(m_row1.getData(), m_row2.getData());
	__m128 C = vecFShuffle_0101(m_row3.getData(), m_row4.getData());
	__m128 D = vecFShuffle_2323(m_row3.getData(), m_row4.getData());

	// determinant as (|A| |B| |C| |D|)
	__m128 detSub = _mm_sub_ps(
		_mm_mul_ps(vecFShuffle(m_row1.getData(), m_row3.getData(), 0, 2, 0, 2), vecFShuffle(m_row2.getData(), m_row4.getData(), 1, 3, 1, 3)),
		_mm_mul_ps(vecFShuffle(m_row1.getData(), m_row3.getData(), 1, 3, 1, 3), vecFShuffle(m_row2.getData(), m_row4.getData(), 0, 2, 0, 2))
	);
	__m128 detA = vecFSwizzle1(detSub, 0);
	__m128 detB = vecFSwizzle1(detSub, 1);
	__m128 detC = vecFSwizzle1(detSub, 2);
	__m128 detD = vecFSwizzle1(detSub, 3);

	// let iM = 1/|M| * | X  Y |
	//                  | Z  W |

	// D#C
	__m128 D_C = matrixF2AdjMul(D, C);
	// A#B
	__m128 A_B = matrixF2AdjMul(A, B);
	// X# = |D|A - B(D#C)
	__m128 X_ = _mm_sub_ps(_mm_mul_ps(detD, A), matrixF2Mul(B, D_C));
	// W# = |A|D - C(A#B)
	__m128 W_ = _mm_sub_ps(_mm_mul_ps(detA, D), matrixF2Mul(C, A_B));

	// Y# = |B|C - D(A#B)#
	__m128 Y_ = _mm_sub_ps(_mm_mul_ps(detB, C), matrixF2MulAdj(D, A_B));
	// Z# = |C|B - A(D#C)#
	__m128 Z_ = _mm_sub_ps(_mm_mul_ps(detC, B), matrixF2MulAdj(A, D_C));

	// calc determinant 
	// tr((A#B)(D#C))
	__m128 tr = _mm_mul_ps(A_B, vecFSwizzle(D_C, 0, 2, 1, 3));
	tr = _mm_hadd_ps(tr, tr);
	tr = _mm_hadd_ps(tr, tr);

	// |M| = |A|*|D| + |B|*|C| - tr((A#B)(D#C)
	__m128 detM = _mm_mul_ps(detA, detD);
	detM = _mm_add_ps(detM, _mm_mul_ps(detB, detC));
	detM = _mm_sub_ps(detM, tr);

	// calc scale determinant
	const __m128 adjSignMask = _mm_set_ps(1, -1, -1, 1);
	// (1/|M|, -1/|M|, -1/|M|, 1/|M|)
	__m128 rDetM = _mm_div_ps(adjSignMask, detM);

	X_ = _mm_mul_ps(X_, rDetM);
	Y_ = _mm_mul_ps(Y_, rDetM);
	Z_ = _mm_mul_ps(Z_, rDetM);
	W_ = _mm_mul_ps(W_, rDetM);


	// apply adjugate and store, here we combine adjugate shuffle and store shuffle
	matrixResult.m_row1 = vecFShuffle(X_, Y_, 3, 1, 3, 1);
	matrixResult.m_row2 = vecFShuffle(X_, Y_, 2, 0, 2, 0);
	matrixResult.m_row3 = vecFShuffle(Z_, W_, 3, 1, 3, 1);
	matrixResult.m_row4 = vecFShuffle(Z_, W_, 2, 0, 2, 0);

	return matrixResult;
}
VectorF VECCALL MatrixF::determinantVec() const
{
	VectorF vectorResult;
	//VectorF det1, det2, det3, det4;

	//det1 = matrixF3DeterminantVec(m_row2, m_row3, m_row4);
	//det2 = matrixF3DeterminantVec(m_row1, m_row3, m_row4);
	//det3 = matrixF3DeterminantVec(m_row1, m_row2, m_row4);
	//det4 = matrixF3DeterminantVec(m_row1, m_row2, m_row3);

	//vectorResult = det1 + det2 + det3 + det4;
	//vectorResult = det4 * m_row4 - det3 * m_row3 + det2 * m_row2 - det1 * m_row1;
	//vectorResult = _mm_dp_ps(vectorResult.getData(), )

	
	__m128 row1, row2, row3, row4;
	__m128 det1, det2, det3, det4;
	__m128 shuffle1, shuffle2, shuffle3;
	row1 = m_row1.getData();
	row2 = m_row2.getData();
	row3 = m_row3.getData();
	row4 = m_row4.getData();

	shuffle1 = _mm_shuffle_ps(row1, row1, _MM_SHUFFLE(3, 0, 2, 1));
	shuffle2 = _mm_shuffle_ps(row2, row2, _MM_SHUFFLE(3, 0, 2, 1));
	shuffle3 = _mm_shuffle_ps(row3, row3, _MM_SHUFFLE(3, 0, 2, 1));

	// calculate triple dot product for 4 sub matricies
	det1 = _mm_sub_ps(
		_mm_mul_ps(row2, shuffle3),
		_mm_mul_ps(row3, shuffle2)
	);
	det1 = _mm_dp_ps(_mm_shuffle_ps(det1, det1, _MM_SHUFFLE(3, 0, 2, 1)), row4, 0b01111111);

	det2 = _mm_sub_ps(
		_mm_mul_ps(row1, shuffle3),
		_mm_mul_ps(row3, shuffle1)
	);
	det2 = _mm_dp_ps(_mm_shuffle_ps(det2, det2, _MM_SHUFFLE(3, 0, 2, 1)), row4, 0b01111111);

	det3 = _mm_sub_ps(
		_mm_mul_ps(row1, shuffle2),
		_mm_mul_ps(row2, shuffle1)
	);
	det3 = _mm_dp_ps(_mm_shuffle_ps(det3, det3, _MM_SHUFFLE(3, 0, 2, 1)), row4, 0b01111111);

	det4 = _mm_sub_ps(
		_mm_mul_ps(row1, shuffle2),
		_mm_mul_ps(row2, shuffle1)
	);
	det4 = _mm_dp_ps(_mm_shuffle_ps(det4, det4, _MM_SHUFFLE(3, 0, 2, 1)), row3, 0b01111111);

	// calculate final result
	__m128 result = _mm_add_ps(_mm_sub_ps(_mm_mul_ps(det4, row4), _mm_mul_ps(det3, row3)), _mm_sub_ps(_mm_mul_ps(det2, row2), _mm_mul_ps(det1, row1)));

	// mov last element to other
	result = vecFSwizzle1(result, 3);

	vectorResult = result;
	

	return vectorResult;
}
float VECCALL MatrixF::determinant() const
{
	return determinantVec().get(0);
}

//functions
VectorF VECCALL M3DM::matrixF3DeterminantVec(VectorF vec1, VectorF vec2, VectorF vec3)
{
	return vecFDotVec3D(vecFCross3D(vec1, vec2), vec3);
}
float VECCALL M3DM::matrixF3Determinant(VectorF vec1, VectorF vec2, VectorF vec3)
{
	return vecFDot3D(vecFCross3D(vec1, vec2), vec3);
}
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