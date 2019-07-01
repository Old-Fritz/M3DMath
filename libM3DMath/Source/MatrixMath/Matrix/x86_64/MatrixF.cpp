#include "M3DMath.h"
#include <cmath>

/// Implementation of MatrixF

using namespace M3DM;

// convertions
#ifdef DIRECTX
DirectX::XMMATRIX VECCALL MatrixF::XMMatrix()
{
	DirectX::XMMATRIX matrixResult;

	alignas(32) float pArray[16];
	part1.store(pArray);
	part2.store(pArray + 8);

	//DirectX::XMMatrixLoad(pArray, matrixResult);

	return matrixResult;
}
#endif

// getters and setters
float VECCALL MatrixF::get(char  ind) const
{
	return 0;
}
void VECCALL MatrixF::set(char ind, float value)
{

}
int VECCALL MatrixF::getInt(char ind) const
{
	return 0;
}
void VECCALL MatrixF::setInt(char ind, int value)
{

}


// base operations
MatrixF VECCALL MatrixF::operator+(MatrixF matrix) const
{
	MatrixF matrixResult;

	return matrixResult;
}
MatrixF VECCALL MatrixF::operator-(MatrixF matrix) const
{
	MatrixF matrixResult;

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

	return matrixResult;
}
MatrixF VECCALL MatrixF::operator/(float scale) const
{
	MatrixF matrixResult;

	return matrixResult;
}
MatrixF& VECCALL MatrixF::operator+=(MatrixF matrix)
{
	MatrixF matrixResult;

	return matrixResult;
}
MatrixF& VECCALL MatrixF::operator-=(MatrixF matrix)
{
	MatrixF matrixResult;

	return matrixResult;
}
MatrixF& VECCALL MatrixF::operator*=(MatrixF matrix)
{
	MatrixF matrixResult;

	return matrixResult;
}
MatrixF& VECCALL MatrixF::operator*=(float scale)
{
	MatrixF matrixResult;

	return matrixResult;
}
MatrixF& VECCALL MatrixF::operator/=(float scale)
{
	MatrixF matrixResult;

	return matrixResult;
}
MatrixF VECCALL MatrixF::operator-() const
{
	MatrixF matrixResult;

	return matrixResult;
}

// additional operations
MatrixF VECCALL M3DM::operator*(float scale, MatrixF matrix)
{
	MatrixF matrixResult;

	return matrixResult;
}
MatrixF VECCALL M3DM::operator/(float scale, MatrixF matrix)
{
	MatrixF matrixResult;

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