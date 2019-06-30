#include "M3DMath.h"
#include <cmath>

/// Implementation of MatrixF

using namespace M3DM;

// convertions
#ifdef DIRECTX
DirectX::XMMATRIX VECCALL MatrixF::XMMatrix()
{
	
}
#endif

// getters and setters
float VECCALL MatrixF::get(char  ind) const
{

}
void VECCALL MatrixF::set(char ind, float value)
{

}
int VECCALL MatrixF::getInt(char ind) const
{

}
void VECCALL MatrixF::setInt(char ind, int value)
{

}


// base operations
MatrixF VECCALL MatrixF::operator+(MatrixF matrix) const
{

}
MatrixF VECCALL MatrixF::operator-(MatrixF matrix) const
{

}
MatrixF VECCALL MatrixF::operator*(MatrixF matrix) const
{

}
MatrixF VECCALL MatrixF::operator*(float scale) const
{

}
MatrixF VECCALL MatrixF::operator/(float scale) const
{

}
MatrixF& VECCALL MatrixF::operator+=(MatrixF matrix)
{

}
MatrixF& VECCALL MatrixF::operator-=(MatrixF matrix)
{

}
MatrixF& VECCALL MatrixF::operator*=(MatrixF matrix)
{

}
MatrixF& VECCALL MatrixF::operator*=(float scale)
{

}
MatrixF& VECCALL MatrixF::operator/=(float scale)
{

}
MatrixF VECCALL MatrixF::operator-() const
{

}

// additional operations
MatrixF VECCALL M3DM::operator*(float scale, MatrixF matrix)
{

}
MatrixF VECCALL M3DM::operator/(float scale, MatrixF matrix)
{

}

// compare
bool VECCALL MatrixF::operator==(MatrixF matrix) const
{

}
bool VECCALL MatrixF::operator<(MatrixF matrix) const
{

}
bool VECCALL MatrixF::operator>(MatrixF matrix) const
{

}
bool VECCALL MatrixF::operator<=(MatrixF matrix) const
{

}
bool VECCALL MatrixF::operator>=(MatrixF matrix) const
{

}
bool VECCALL MatrixF::isEqualPrec(MatrixF matrix, float precision) const
{

}
bool VECCALL MatrixF::isEqualPrec(MatrixF matrix, MatrixF precision) const
{

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

}
MatrixF VECCALL MatrixF::inverse() const
{

}
VectorF VECCALL MatrixF::determinantVec() const
{

}
float VECCALL MatrixF::determinant() const
{

}

//functions
MatrixF VECCALL M3DM::matrixFIdentity()
{

}
MatrixF VECCALL M3DM::matrixFInfinity()
{
	
}