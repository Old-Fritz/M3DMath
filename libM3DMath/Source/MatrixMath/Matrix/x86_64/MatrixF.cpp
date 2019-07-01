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
	if (ind < 8)
		return part1.get(ind);
	else
		return part2.get(ind - 8);
}
void VECCALL MatrixF::set(char ind, float value)
{
	if (ind < 8)
		part1.set(ind, value);
	else
		part2.set(ind - 8, value);
}
int VECCALL MatrixF::getInt(char ind) const
{
	if (ind < 8)
		return part1.getInt(ind);
	else
		return part2.getInt(ind - 8);
}
void VECCALL MatrixF::setInt(char ind, int value)
{
	if (ind < 8)
		part1.setInt(ind, value);
	else
		part2.setInt(ind - 8, value);
}


// base operations
MatrixF VECCALL MatrixF::operator+(MatrixF matrix) const
{
	MatrixF matrixResult;

	matrixResult.part1 = part1 + matrix.part1;
	matrixResult.part2 = part2 + matrix.part2;

	return matrixResult;
}
MatrixF VECCALL MatrixF::operator-(MatrixF matrix) const
{
	MatrixF matrixResult;

	matrixResult.part1 = part1 - matrix.part1;
	matrixResult.part2 = part2 - matrix.part2;

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

	matrixResult.part1 = part1 * scale;
	matrixResult.part2 = part2 * scale;

	return matrixResult;
}
MatrixF VECCALL MatrixF::operator/(float scale) const
{
	MatrixF matrixResult;

	matrixResult.part1 = part1 / scale;
	matrixResult.part2 = part2 / scale;

	return matrixResult;
}
MatrixF& VECCALL MatrixF::operator+=(MatrixF matrix)
{
	part1 += matrix.part1;
	part2 += matrix.part2;

	return *this;
}
MatrixF& VECCALL MatrixF::operator-=(MatrixF matrix)
{
	part1 -= matrix.part1;
	part2 -= matrix.part2;

	return *this;
}
MatrixF& VECCALL MatrixF::operator*=(MatrixF matrix)
{
	MatrixF matrixResult;

	return matrixResult;
}
MatrixF& VECCALL MatrixF::operator*=(float scale)
{
	part1 *= scale;
	part2 *= scale;

	return *this;
}
MatrixF& VECCALL MatrixF::operator/=(float scale)
{
	part1 /= scale;
	part2 /= scale;

	return *this;
}
MatrixF VECCALL MatrixF::operator-() const
{
	MatrixF matrixResult;

	matrixResult.part1 = -part1;
	matrixResult.part2 = -part2;

	return matrixResult;
}

// additional operations
MatrixF VECCALL M3DM::operator*(float scale, MatrixF matrix)
{
	MatrixF matrixResult;

	matrixResult.part1 = matrix.part1 * scale;
	matrixResult.part2 = matrix.part2 * scale;

	return matrixResult;
}
MatrixF VECCALL M3DM::operator/(float scale, MatrixF matrix)
{
	MatrixF matrixResult;

	matrixResult.part1 = scale / matrix.part1;
	matrixResult.part2 = scale / matrix.part2;

	return matrixResult;
}

// compare
bool VECCALL MatrixF::operator==(MatrixF matrix) const
{
	return (part1 == matrix.part1) && (part2 == matrix.part2);
}
bool VECCALL MatrixF::operator<(MatrixF matrix) const
{
	return (part1 < matrix.part1) && (part2 < matrix.part2);
}
bool VECCALL MatrixF::operator>(MatrixF matrix) const
{
	return (part1 > matrix.part1) && (part2 > matrix.part2);
}
bool VECCALL MatrixF::operator<=(MatrixF matrix) const
{
	return (part1 <= matrix.part1) && (part2 <= matrix.part2);
}
bool VECCALL MatrixF::operator>=(MatrixF matrix) const
{
	return (part1 >= matrix.part1) && (part2 >= matrix.part2);
}
bool VECCALL MatrixF::isEqualPrec(MatrixF matrix, float precision) const
{
	return (part1.isEqualPrec(matrix.part1, precision)) && (part2.isEqualPrec(matrix.part2, precision));
}
bool VECCALL MatrixF::isEqualPrec(MatrixF matrix, MatrixF precision) const
{
	return (part1.isEqualPrec(matrix.part1, precision.part1)) && (part2.isEqualPrec(matrix.part2, precision.part2));
}

// store/load
void VECCALL MatrixF::load(float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44)
{
	part1.load(m11, m12, m13, m14, m21, m22, m23, m24);
	part2.load(m31, m32, m33, m34, m41, m42, m43, m44);
}
void VECCALL MatrixF::load(const float* pArray)
{
	part1.load(pArray);
	part2.load(pArray+8);
}
void VECCALL MatrixF::load(const MatrixScalar& matrix)
{
	part1.load(matrix);
	part2.load(matrix+8);
}
void VECCALL MatrixF::load(VectorF row1, VectorF row2, VectorF row3, VectorF row4)
{
	part1.load(row1, row2);
	part2.load(row3, row4);
}

void VECCALL MatrixF::store(float& m11, float& m12, float& m13, float& m14,
	float& m21, float& m22, float& m23, float& m24,
	float& m31, float& m32, float& m33, float& m34,
	float& m41, float& m42, float& m43, float& m44) const
{
	part1.store(m11, m12, m13, m14, m21, m22, m23, m24);
	part2.store(m31, m32, m33, m34, m41, m42, m43, m44);
}
void VECCALL MatrixF::store(float* pArray) const
{
	part1.store(pArray);
	part2.store(pArray + 8);
}
void VECCALL MatrixF::store(MatrixScalar& matrix) const
{
	part1.store(matrix);
	part2.store(matrix + 8);
}
void VECCALL MatrixF::store(VectorF& row1, VectorF& row2, VectorF& row3, VectorF& row4) const
{
	part1.store(row1, row2);
	part2.store(row3, row4);
}

// methods
MatrixF VECCALL MatrixF::transpose() const
{
	MatrixF matrixResult;

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