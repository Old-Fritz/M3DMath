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


// constructors
MatrixF::MatrixF()
{
	for (Int32 i = 0; i < 4; i++)
		m_rows[i] = __m128();
}
MatrixF::MatrixF(Float m11, Float m12, Float m13, Float m14,
	Float m21, Float m22, Float m23, Float m24,
	Float m31, Float m32, Float m33, Float m34,
	Float m41, Float m42, Float m43, Float m44)
{
	load(m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44);
}

// convertions
MatrixF::MatrixF(const Float* pArray)
{
	load(pArray);
}
MatrixF::MatrixF(const MatrixScalar& matrix)
{
	load(matrix);
}
MatrixF::MatrixF(VectorF row1, VectorF row2, VectorF row3, VectorF row4)
{
	load(row1, row2, row3, row4);
}

#ifdef DIRECTX
MatrixF::MatrixF(DirectX::XMMATRIX matrix)
{
	for (Int32 i = 0; i < 4; i++)
		m_rows[i] = matrix.r[i];
}
DirectX::XMMATRIX VECCALL MatrixF::XMMatrix()
{
	DirectX::XMMATRIX matrixResult;
	MatrixScalar matrixScalar;
	store(matrixScalar);

	return matrixScalar.XMMatrix();
}
#endif

// getters and setters
Float VECCALL MatrixF::get(Char  ind) const
{
	Int32 row = ind / 4;
	return VectorF(m_rows[row]).get(ind % 4);
}

void VECCALL MatrixF::set(Char ind, Float value)
{
	Int32 row = ind / 4;
	VectorF tmp(m_rows[row]);
	tmp.set(ind % 4, value);
	m_rows[row] = tmp.getData();
}
Int32 VECCALL MatrixF::getInt(Char ind) const
{
	Int32 row = ind / 4;
	return VectorF(m_rows[row]).getInt(ind % 4);
}
void VECCALL MatrixF::setInt(Char ind, Int32 value)
{
	Int32 row = ind / 4;
	VectorF tmp(m_rows[row]);
	tmp.setInt(ind % 4, value);
	m_rows[row] = tmp.getData();
}


// base operations
MatrixF VECCALL MatrixF::operator+(MatrixF matrix) const
{
	MatrixF matrixResult;

	for (Int32 i = 0; i < 4; i++)
		matrixResult.m_rows[i] = _mm_add_ps(m_rows[i], matrix.m_rows[i]);

	return matrixResult;
}
MatrixF VECCALL MatrixF::operator-(MatrixF matrix) const
{
	MatrixF matrixResult;

	for (Int32 i = 0; i < 4; i++)
		matrixResult.m_rows[i] = _mm_sub_ps(m_rows[i], matrix.m_rows[i]);

	return matrixResult;
}
MatrixF VECCALL MatrixF::operator*(MatrixF matrix) const
{
	MatrixF matrixResult;

	MatrixF tempMatrix = matrix.transpose();
	__m128 tmpDp;

	// row 1
	matrixResult.m_rows[0] = _mm_dp_ps(m_rows[0], tempMatrix.m_rows[0], 0b11110001); // c11
	tmpDp = _mm_dp_ps(m_rows[0], tempMatrix.m_rows[1], 0b11110010); // c12
	matrixResult.m_rows[0] = _mm_or_ps(matrixResult.m_rows[0], tmpDp);
	tmpDp = _mm_dp_ps(m_rows[0], tempMatrix.m_rows[2], 0b11110100); // c13
	matrixResult.m_rows[0] = _mm_or_ps(matrixResult.m_rows[0], tmpDp);
	tmpDp = _mm_dp_ps(m_rows[0], tempMatrix.m_rows[3], 0b11111000); // c14
	matrixResult.m_rows[0] = _mm_or_ps(matrixResult.m_rows[0], tmpDp);

	// row 2
	matrixResult.m_rows[1] = _mm_dp_ps(m_rows[1], tempMatrix.m_rows[0], 0b11110001); // c11
	tmpDp = _mm_dp_ps(m_rows[1], tempMatrix.m_rows[1], 0b11110010); // c12
	matrixResult.m_rows[1] = _mm_or_ps(matrixResult.m_rows[1], tmpDp);
	tmpDp = _mm_dp_ps(m_rows[1], tempMatrix.m_rows[2], 0b11110100); // c13
	matrixResult.m_rows[1] = _mm_or_ps(matrixResult.m_rows[1], tmpDp);
	tmpDp = _mm_dp_ps(m_rows[1], tempMatrix.m_rows[3], 0b11111000); // c14
	matrixResult.m_rows[1] = _mm_or_ps(matrixResult.m_rows[1], tmpDp);

	// row 3
	matrixResult.m_rows[2] = _mm_dp_ps(m_rows[2], tempMatrix.m_rows[0], 0b11110001); // c11
	tmpDp = _mm_dp_ps(m_rows[2], tempMatrix.m_rows[1], 0b11110010); // c12
	matrixResult.m_rows[2] = _mm_or_ps(matrixResult.m_rows[2], tmpDp);
	tmpDp = _mm_dp_ps(m_rows[2], tempMatrix.m_rows[2], 0b11110100); // c13
	matrixResult.m_rows[2] = _mm_or_ps(matrixResult.m_rows[2], tmpDp);
	tmpDp = _mm_dp_ps(m_rows[2], tempMatrix.m_rows[3], 0b11111000); // c14
	matrixResult.m_rows[2] = _mm_or_ps(matrixResult.m_rows[2], tmpDp);

	// row 4
	matrixResult.m_rows[3] = _mm_dp_ps(m_rows[3], tempMatrix.m_rows[0], 0b11110001); // c11
	tmpDp = _mm_dp_ps(m_rows[3], tempMatrix.m_rows[1], 0b11110010); // c12
	matrixResult.m_rows[3] = _mm_or_ps(matrixResult.m_rows[3], tmpDp);
	tmpDp = _mm_dp_ps(m_rows[3], tempMatrix.m_rows[2], 0b11110100); // c13
	matrixResult.m_rows[3] = _mm_or_ps(matrixResult.m_rows[3], tmpDp);
	tmpDp = _mm_dp_ps(m_rows[3], tempMatrix.m_rows[3], 0b11111000); // c14
	matrixResult.m_rows[3] = _mm_or_ps(matrixResult.m_rows[3], tmpDp);

	return matrixResult;
}
MatrixF VECCALL MatrixF::operator*(Float scale) const
{
	MatrixF matrixResult;

	for (Int32 i = 0; i < 4; i++)
		matrixResult.m_rows[i] = _mm_mul_ps(m_rows[i], _mm_set_ps1(scale));

	return matrixResult;
}
MatrixF VECCALL MatrixF::operator/(Float scale) const
{
	MatrixF matrixResult;

	for (Int32 i = 0; i < 4; i++)
		matrixResult.m_rows[i] = _mm_div_ps(m_rows[i], _mm_set_ps1(scale));

	return matrixResult;
}
MatrixF& VECCALL MatrixF::operator+=(MatrixF matrix)
{

	for (Int32 i = 0; i < 4; i++)
		m_rows[i] = _mm_add_ps(m_rows[i], matrix.m_rows[i]);

	return *this;
}
MatrixF& VECCALL MatrixF::operator-=(MatrixF matrix)
{
	for (Int32 i = 0; i < 4; i++)
		m_rows[i] = _mm_sub_ps(m_rows[i], matrix.m_rows[i]);

	return *this;
}
MatrixF& VECCALL MatrixF::operator*=(MatrixF matrix)
{
	*this = *this * matrix;

	return *this;
}
MatrixF& VECCALL MatrixF::operator*=(Float scale)
{
	for (Int32 i = 0; i < 4; i++)
		m_rows[i] = _mm_mul_ps(m_rows[i], _mm_set_ps1(scale));

	return *this;
}
MatrixF& VECCALL MatrixF::operator/=(Float scale)
{
	for (Int32 i = 0; i < 4; i++)
		m_rows[i] = _mm_div_ps(m_rows[i], _mm_set_ps1(scale));

	return *this;
}
MatrixF VECCALL MatrixF::operator-() const
{
	MatrixF matrixResult;

	for (Int32 i = 0; i < 4; i++)
		matrixResult.m_rows[i] = _mm_sub_ps(__m128(), m_rows[i]);

	return matrixResult;
}

// additional operations
MatrixF VECCALL M3DM::operator*(Float scale, MatrixF matrix)
{
	MatrixF matrixResult;

	for (Int32 i = 0; i < 4; i++)
		matrixResult.m_rows[i] = _mm_mul_ps(matrix.m_rows[i], _mm_set_ps1(scale));

	return matrixResult;
}
MatrixF VECCALL M3DM::operator/(Float scale, MatrixF matrix)
{
	MatrixF matrixResult;

	for (Int32 i = 0; i < 4; i++)
		matrixResult.m_rows[i] = _mm_div_ps(_mm_set_ps1(scale), matrix.m_rows[i]);

	return matrixResult;
}

// compare
Bool VECCALL MatrixF::operator==(MatrixF matrix) const
{
	Bool result = true;

	for (Int32 i = 0; i < 4; i++)
		result = result && (VectorF(m_rows[i]) == VectorF(matrix.m_rows[i]));

	return result;
}
Bool VECCALL MatrixF::operator<(MatrixF matrix) const
{
	Bool result = true;

	for (Int32 i = 0; i < 4; i++)
		result = result && (VectorF(m_rows[i]) < VectorF(matrix.m_rows[i]));

	return result;
}
Bool VECCALL MatrixF::operator>(MatrixF matrix) const
{
	Bool result = true;

	for (Int32 i = 0; i < 4; i++)
		result = result && (VectorF(m_rows[i]) > VectorF(matrix.m_rows[i]));

	return result;
}
Bool VECCALL MatrixF::operator<=(MatrixF matrix) const
{
	Bool result = true;

	for (Int32 i = 0; i < 4; i++)
		result = result && (VectorF(m_rows[i]) <= VectorF(matrix.m_rows[i]));

	return result;
}
Bool VECCALL MatrixF::operator>=(MatrixF matrix) const
{
	Bool result = true;

	for (Int32 i = 0; i < 4; i++)
		result = result && (VectorF(m_rows[i]) >= VectorF(matrix.m_rows[i]));

	return result;
}
Bool VECCALL MatrixF::isEqualPrec(MatrixF matrix, Float precision) const
{

	Bool result = true;

	for (Int32 i = 0; i < 4; i++)
		result = result && (VectorF(m_rows[i]).isEqualPrec(VectorF(matrix.m_rows[i]), precision));

	return result;
}
Bool VECCALL MatrixF::isEqualPrec(MatrixF matrix, MatrixF precision) const
{
	Bool result = true;

	for (Int32 i = 0; i < 4; i++)
		result = result && (VectorF(m_rows[i]).isEqualPrec(VectorF(matrix.m_rows[i]), VectorF(precision.m_rows[i])));

	return result;
}

// store/load
void VECCALL MatrixF::load(Float m11, Float m12, Float m13, Float m14,
	Float m21, Float m22, Float m23, Float m24,
	Float m31, Float m32, Float m33, Float m34,
	Float m41, Float m42, Float m43, Float m44)
{
	

	m_rows[0] = _mm_setr_ps(m11, m12, m13, m14); 
	m_rows[1] = _mm_setr_ps(m21, m22, m23, m24);
	m_rows[2] = _mm_setr_ps(m31, m32, m33, m34);
	m_rows[3] = _mm_setr_ps(m41, m42, m43, m44);
}
void VECCALL MatrixF::load(const Float* pArray)
{
	m_rows[0] = _mm_load_ps(pArray);
	m_rows[1] = _mm_load_ps(pArray + 4);
	m_rows[2] = _mm_load_ps(pArray + 8);
	m_rows[3] = _mm_load_ps(pArray + 12);
}
void VECCALL MatrixF::load(const MatrixScalar& matrix)
{
	m_rows[0] = _mm_load_ps(matrix);
	m_rows[1] = _mm_load_ps(matrix + 4);
	m_rows[2] = _mm_load_ps(matrix + 8);
	m_rows[3] = _mm_load_ps(matrix + 12);
}
void VECCALL MatrixF::load(VectorF row1, VectorF row2, VectorF row3, VectorF row4)
{
	m_rows[0] = row1.getData();
	m_rows[1] = row2.getData();
	m_rows[2] = row3.getData();
	m_rows[3] = row4.getData();
}

void VECCALL MatrixF::store(Float& m11, Float& m12, Float& m13, Float& m14,
	Float& m21, Float& m22, Float& m23, Float& m24,
	Float& m31, Float& m32, Float& m33, Float& m34,
	Float& m41, Float& m42, Float& m43, Float& m44) const
{
	VectorF(m_rows[0]).store(m11, m12, m13, m14);
	VectorF(m_rows[1]).store(m21, m22, m23, m24);
	VectorF(m_rows[2]).store(m31, m32, m33, m34);
	VectorF(m_rows[3]).store(m41, m42, m43, m44);
}
void VECCALL MatrixF::store(Float* pArray) const
{
	VectorF(m_rows[0]).store(pArray);
	VectorF(m_rows[1]).store(pArray + 4);
	VectorF(m_rows[2]).store(pArray + 8);
	VectorF(m_rows[3]).store(pArray + 12);
}

void VECCALL MatrixF::store(MatrixScalar& matrix) const
{
	VectorF(m_rows[0]).store(matrix);
	VectorF(m_rows[1]).store(matrix+4);
	VectorF(m_rows[2]).store(matrix+8);
	VectorF(m_rows[3]).store(matrix+12);
}
void VECCALL MatrixF::store(VectorF& row1, VectorF& row2, VectorF& row3, VectorF& row4) const
{
	row1 = m_rows[0];
	row2 = m_rows[1];
	row3 = m_rows[2];
	row4 = m_rows[3];
}
// methods
MatrixF VECCALL MatrixF::transpose() const
{
	MatrixF matrixResult;

	__m128 tmp1, tmp2, tmp3, tmp4;
	tmp1 = _mm_shuffle_ps(m_rows[0], m_rows[1], 0x44);
	tmp3 = _mm_shuffle_ps(m_rows[0], m_rows[1], 0xEE);
	tmp2 = _mm_shuffle_ps(m_rows[2], m_rows[3], 0x44);
	tmp4 = _mm_shuffle_ps(m_rows[2], m_rows[3], 0xEE);

	matrixResult.m_rows[0] = _mm_shuffle_ps(tmp1, tmp2, 0x88);
	matrixResult.m_rows[1] = _mm_shuffle_ps(tmp1, tmp2, 0xDD);
	matrixResult.m_rows[2] = _mm_shuffle_ps(tmp3, tmp4, 0x88);
	matrixResult.m_rows[3] = _mm_shuffle_ps(tmp3, tmp4, 0xDD);


	return matrixResult;
}
VectorF VECCALL MatrixF::determinantVec() const
{
	VectorF vectorResult;
	//VectorF det1, det2, det3, det4;

	//det1 = matrixF3DeterminantVec(m_rows[1], m_rows[2], m_rows[3]);
	//det2 = matrixF3DeterminantVec(m_rows[0], m_rows[2], m_rows[3]);
	//det3 = matrixF3DeterminantVec(m_rows[0], m_rows[1], m_rows[3]);
	//det4 = matrixF3DeterminantVec(m_rows[0], m_rows[1], m_rows[2]);

	//vectorResult = det1 + det2 + det3 + det4;
	//vectorResult = det4 * m_rows[3] - det3 * m_rows[2] + det2 * m_row2 - det1 * m_rows[0];
	//vectorResult = _mm_dp_ps(vectorResult.getData(), )

	
	__m128 row1, row2, row3, row4;
	__m128 det1, det2, det3, det4;
	__m128 shuffle1, shuffle2, shuffle3;
	row1 = m_rows[0];
	row2 = m_rows[1];
	row3 = m_rows[2];
	row4 = m_rows[3];

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
Float VECCALL MatrixF::determinant() const
{
	return determinantVec().get(0);
}
MatrixF VECCALL MatrixF::inverse() const
{
	MatrixF matrixResult;

	// use block matrix method

	// sub matrices
	__m128 A = vecFShuffle_0101(m_rows[0], m_rows[1]);
	__m128 B = vecFShuffle_2323(m_rows[0], m_rows[1]);
	__m128 C = vecFShuffle_0101(m_rows[2], m_rows[3]);
	__m128 D = vecFShuffle_2323(m_rows[2], m_rows[3]);

	// determinant as (|A| |B| |C| |D|)
	__m128 detSub = _mm_sub_ps(
		_mm_mul_ps(vecFShuffle(m_rows[0], m_rows[2], 0, 2, 0, 2), vecFShuffle(m_rows[1], m_rows[3], 1, 3, 1, 3)),
		_mm_mul_ps(vecFShuffle(m_rows[0], m_rows[2], 1, 3, 1, 3), vecFShuffle(m_rows[1], m_rows[3], 0, 2, 0, 2))
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
	matrixResult.m_rows[0] = vecFShuffle(X_, Y_, 3, 1, 3, 1);
	matrixResult.m_rows[1] = vecFShuffle(X_, Y_, 2, 0, 2, 0);
	matrixResult.m_rows[2] = vecFShuffle(Z_, W_, 3, 1, 3, 1);
	matrixResult.m_rows[3] = vecFShuffle(Z_, W_, 2, 0, 2, 0);

	return matrixResult;
}
MatrixF VECCALL MatrixF::inverseTransform() const
{
	MatrixF matrixResult;

	// transpose 3x3, we know m03 = m13 = m23 = 0
	__m128 t0 = vecFShuffle_0101(m_rows[0], m_rows[1]); // 00, 01, 10, 11
	__m128 t1 = vecFShuffle_2323(m_rows[0], m_rows[1]); // 02, 03, 12, 13
	matrixResult.m_rows[0] = vecFShuffle(t0, m_rows[2], 0, 2, 0, 3); // 00, 10, 20, 23(=0)
	matrixResult.m_rows[1] = vecFShuffle(t0, m_rows[2], 1, 3, 1, 3); // 01, 11, 21, 23(=0)
	matrixResult.m_rows[2] = vecFShuffle(t1, m_rows[2], 0, 2, 2, 3); // 02, 12, 22, 23(=0)

	// (SizeSqr(m_rows[0]), SizeSqr(m_rows[1]), SizeSqr(m_rows[2]), 0)
	__m128 sizeSqr;
	sizeSqr = _mm_mul_ps(matrixResult.m_rows[0], matrixResult.m_rows[0]);
	sizeSqr = _mm_add_ps(sizeSqr, _mm_mul_ps(matrixResult.m_rows[1], matrixResult.m_rows[1]));
	sizeSqr = _mm_add_ps(sizeSqr, _mm_mul_ps(matrixResult.m_rows[2], matrixResult.m_rows[2]));

	// optional test to avoid divide by 0
	__m128 one = _mm_set_ps1(1.f);
	// for each component, if(sizeSqr < SMALL_NUMBER) sizeSqr = 1;
	__m128 rSizeSqr = _mm_blendv_ps(
		_mm_div_ps(one, sizeSqr),
		one,
		_mm_cmplt_ps(sizeSqr, _mm_set_ps1(1.e-8f))
	);

	matrixResult.m_rows[0] = _mm_mul_ps(matrixResult.m_rows[0], rSizeSqr);
	matrixResult.m_rows[1] = _mm_mul_ps(matrixResult.m_rows[1], rSizeSqr);
	matrixResult.m_rows[2] = _mm_mul_ps(matrixResult.m_rows[2], rSizeSqr);

	// last line
	matrixResult.m_rows[3] = _mm_mul_ps(matrixResult.m_rows[0], vecFSwizzle1(m_rows[3], 0));
	matrixResult.m_rows[3] = _mm_add_ps(matrixResult.m_rows[3], _mm_mul_ps(matrixResult.m_rows[1], vecFSwizzle1(m_rows[3], 1)));
	matrixResult.m_rows[3] = _mm_add_ps(matrixResult.m_rows[3], _mm_mul_ps(matrixResult.m_rows[2], vecFSwizzle1(m_rows[3], 2)));
	matrixResult.m_rows[3] = _mm_sub_ps(_mm_setr_ps(0.f, 0.f, 0.f, 1.f), matrixResult.m_rows[3]);


	return matrixResult;
}
MatrixF VECCALL MatrixF::inverseTransformNoScale() const
{
	MatrixF matrixResult;

	// transpose 3x3, we know m03 = m13 = m23 = 0
	__m128 t0 = vecFShuffle_0101(m_rows[0], m_rows[0]); // 00, 01, 10, 11
	__m128 t1 = vecFShuffle_2323(m_rows[0], m_rows[0]); // 02, 03, 12, 13
	matrixResult.m_rows[0] = vecFShuffle(t0, m_rows[2], 0, 2, 0, 3); // 00, 10, 20, 23(=0)
	matrixResult.m_rows[1] = vecFShuffle(t0, m_rows[2], 1, 3, 1, 3); // 01, 11, 21, 23(=0)
	matrixResult.m_rows[2] = vecFShuffle(t1, m_rows[2], 0, 2, 2, 3); // 02, 12, 22, 23(=0)

	// last line
	matrixResult.m_rows[3] = _mm_mul_ps(matrixResult.m_rows[0], vecFSwizzle1(m_rows[3], 0));
	matrixResult.m_rows[3] = _mm_add_ps(matrixResult.m_rows[3], _mm_mul_ps(matrixResult.m_rows[1], vecFSwizzle1(matrixResult.m_rows[3], 1)));
	matrixResult.m_rows[3] = _mm_add_ps(matrixResult.m_rows[3], _mm_mul_ps(matrixResult.m_rows[2], vecFSwizzle1(matrixResult.m_rows[3], 2)));
	matrixResult.m_rows[3] = _mm_sub_ps(_mm_setr_ps(0.f, 0.f, 0.f, 1.f), matrixResult.m_rows[3]);

	return matrixResult;
}

//functions
VectorF VECCALL M3DM::matrixF3DeterminantVec(VectorF vec1, VectorF vec2, VectorF vec3)
{
	return vecFDotVec3D(vecFCross3D(vec1, vec2), vec3);
}
Float VECCALL M3DM::matrixF3Determinant(VectorF vec1, VectorF vec2, VectorF vec3)
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