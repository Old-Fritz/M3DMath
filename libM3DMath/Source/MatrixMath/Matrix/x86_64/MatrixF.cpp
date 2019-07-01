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
	return true;
}
bool VECCALL MatrixF::operator<(MatrixF matrix) const
{
	return true;
}
bool VECCALL MatrixF::operator>(MatrixF matrix) const
{
	return true;
}
bool VECCALL MatrixF::operator<=(MatrixF matrix) const
{
	return true;
}
bool VECCALL MatrixF::operator>=(MatrixF matrix) const
{
	return true;
}
bool VECCALL MatrixF::isEqualPrec(MatrixF matrix, float precision) const
{
	return true;
}
bool VECCALL MatrixF::isEqualPrec(MatrixF matrix, MatrixF precision) const
{
	return true;
}

// store/load
void VECCALL MatrixF::load(float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44)
{

}
void VECCALL MatrixF::load(const float* pArray)
{

}
void VECCALL MatrixF::load(const MatrixScalar& matrix)
{

}
void VECCALL MatrixF::load(VectorF row1, VectorF row2, VectorF row3, VectorF row4)
{

}

void VECCALL MatrixF::store(float& m11, float& m12, float& m13, float& m14,
	float& m21, float& m22, float& m23, float& m24,
	float& m31, float& m32, float& m33, float& m34,
	float& m41, float& m42, float& m43, float& m44) const
{

}
void VECCALL MatrixF::store(float* pArray) const
{

}
void VECCALL MatrixF::store(MatrixScalar& matrix) const
{

}
void VECCALL MatrixF::store(VectorF& row1, VectorF& row2, VectorF& row3, VectorF& row4) const
{

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
	MatrixF matrixResult;

	return matrixResult;
}
MatrixF VECCALL M3DM::matrixFInfinity()
{
	MatrixF matrixResult;

	return matrixResult;
}