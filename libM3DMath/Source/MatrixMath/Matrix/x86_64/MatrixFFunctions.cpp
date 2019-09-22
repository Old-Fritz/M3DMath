#include "M3DMath.h"
#include <cmath>

/// Implementation of MatrixF Functions

using namespace M3DM;

// Transforms
MatrixF M3DM::matrixFScaling(Float x, Float y, Float z)
{
	return matrixFScaling(VectorF(x,y,z,0));
}
MatrixF M3DM::matrixFScaling(VectorF scale)
{
	MatrixF matrixResult;
	__m128 data = scale.getData();
	
	matrixResult = matrixFIdentity();
	matrixResult.m_rows[0] = vecFShuffle(data, matrixResult.m_rows[0], 0, 1, 2, 3);
	matrixResult.m_rows[0] = vecFSwizzle(matrixResult.m_rows[0], 0, 3, 3, 3);
	matrixResult.m_rows[1] = vecFShuffle(data, matrixResult.m_rows[1], 0, 1, 2, 3);
	matrixResult.m_rows[1] = vecFSwizzle(matrixResult.m_rows[1], 3, 1, 3, 3);
	matrixResult.m_rows[2] = vecFShuffle(matrixResult.m_rows[2], data, 0, 1, 2, 3);
	matrixResult.m_rows[2] = vecFSwizzle(matrixResult.m_rows[2], 0, 0, 2, 0);

	return matrixResult;
}

MatrixF M3DM::matrixFRotationX(Float angle)
{
	return matrixFRotationX(VectorF(angle));
}
MatrixF M3DM::matrixFRotationX(VectorF angle)
{
	MatrixF matrixResult;

	VectorF cos, sin;
	(-angle).sincos(sin, cos);

	matrixResult = matrixFIdentity();
	__m128 mask = VectorF(0, FNAN, FNAN, 0).getData();

	matrixResult.m_rows[1] = vecFShuffle(cos.getData(), (-sin).getData(), 0, 1, 2, 3);
	matrixResult.m_rows[2] = vecFShuffle(sin.getData(), cos.getData(), 0, 1, 2, 3);
	matrixResult.m_rows[1] = _mm_and_ps(matrixResult.m_rows[1], mask);
	matrixResult.m_rows[2] = _mm_and_ps(matrixResult.m_rows[2], mask);

	return matrixResult;
}
MatrixF M3DM::matrixFRotationY(Float angle)
{
	return matrixFRotationY(VectorF(angle));
}
MatrixF M3DM::matrixFRotationY(VectorF angle)
{
	MatrixF matrixResult;

	VectorF cos, sin;
	(-angle).sincos(sin, cos);

	matrixResult = matrixFIdentity();
	__m128 mask = VectorF(FNAN, 0, FNAN, 0).getData();

	matrixResult.m_rows[0] = vecFShuffle(cos.getData(), sin.getData(), 0, 1, 2, 3);
	matrixResult.m_rows[2] = vecFShuffle((-sin).getData(), cos.getData(), 0, 1, 2, 3);
	matrixResult.m_rows[0] = _mm_and_ps(matrixResult.m_rows[0], mask);
	matrixResult.m_rows[2] = _mm_and_ps(matrixResult.m_rows[2], mask);

	return matrixResult;
}
MatrixF M3DM::matrixFRotationZ(Float angle)
{
	return matrixFRotationZ(VectorF(angle));
}
MatrixF M3DM::matrixFRotationZ(VectorF angle)
{
	MatrixF matrixResult;

	VectorF cos, sin;
	(-angle).sincos(sin, cos);

	matrixResult = matrixFIdentity();
	__m128 mask = VectorF(FNAN, FNAN, 0, 0).getData();

	matrixResult.m_rows[0] = vecFShuffle(cos.getData(), (-sin).getData(), 0, 1, 2, 3);
	matrixResult.m_rows[1] = vecFShuffle(sin.getData(), cos.getData(), 0, 1, 2, 3);
	matrixResult.m_rows[0] = vecFSwizzle(matrixResult.m_rows[0], 0, 2, 0, 0);
	matrixResult.m_rows[1] = vecFSwizzle(matrixResult.m_rows[1], 0, 2, 0, 0);
	matrixResult.m_rows[0] = _mm_and_ps(matrixResult.m_rows[0], mask);
	matrixResult.m_rows[1] = _mm_and_ps(matrixResult.m_rows[1], mask);

	return matrixResult;
}
MatrixF M3DM::matrixFRotationAxis(VectorF axis, Float angle)
{
	return matrixFRotationAxis(axis, VectorF(angle));
}
MatrixF M3DM::matrixFRotationAxis(VectorF axis, VectorF angle)
{
	return matrixFRotationNormal(axis.normalized3D(), angle);
}
MatrixF M3DM::matrixFRotationNormal(VectorF normal, Float angle)
{
	return matrixFRotationNormal(normal, VectorF(angle));
}
MatrixF M3DM::matrixFRotationNormal(VectorF normal, VectorF angle)
{
	MatrixF matrixResult;

	VectorF cos, minuscos, sin, x, y, z;
	(-angle).sincos(sin, cos);
	x = vecFSwizzle(normal.getData(), 0, 0, 0, 0);
	y = vecFSwizzle(normal.getData(), 1, 1, 1, 1);
	z = vecFSwizzle(normal.getData(), 2, 2, 2, 2);
	minuscos = VectorF(1) - cos;

	matrixResult = matrixFIdentity();
	__m128 mask = VectorF(FNAN, FNAN, FNAN, 0).getData();

	VectorF m1 = cos + minuscos * x * x;
	VectorF m2 = minuscos * x * y - sin * z;
	VectorF m3 = minuscos * x * z + sin * y;

	matrixResult.m_rows[0] = vecFShuffle(m1.getData(), m2.getData(), 0, 1, 2, 3);
	matrixResult.m_rows[0] = vecFSwizzle(matrixResult.m_rows[0], 0, 2, 0, 0);
	matrixResult.m_rows[0] = vecFShuffle(matrixResult.m_rows[0], m3.getData(), 0, 1, 2, 3);
	matrixResult.m_rows[0] = _mm_and_ps(matrixResult.m_rows[0], mask);

	m1 = minuscos * y * x + sin * z;
	m2 = cos + minuscos * y * y;
	m3 = minuscos * y * z - sin * x;

	matrixResult.m_rows[1] = vecFShuffle(m1.getData(), m2.getData(), 0, 1, 2, 3);
	matrixResult.m_rows[1] = vecFSwizzle(matrixResult.m_rows[1], 0, 2, 0, 0);
	matrixResult.m_rows[1] = vecFShuffle(matrixResult.m_rows[1], m3.getData(), 0, 1, 2, 3);
	matrixResult.m_rows[1] = _mm_and_ps(matrixResult.m_rows[1], mask);

	m1 = minuscos * z * x - sin * y;
	m2 = minuscos * z * y + sin * x;
	m3 = cos + minuscos * z * z;

	matrixResult.m_rows[2] = vecFShuffle(m1.getData(), m2.getData(), 0, 1, 2, 3);
	matrixResult.m_rows[2] = vecFSwizzle(matrixResult.m_rows[2], 0, 2, 0, 0);
	matrixResult.m_rows[2] = vecFShuffle(matrixResult.m_rows[2], m3.getData(), 0, 1, 2, 3);
	matrixResult.m_rows[2] = _mm_and_ps(matrixResult.m_rows[2], mask);

	return matrixResult;
}
MatrixF M3DM::matrixFRotationYawPitchRoll(Float yaw, Float pitch, Float roll)
{
	return matrixFRotationYawPitchRoll(VectorF(yaw, pitch, roll, 0));
}
MatrixF M3DM::matrixFRotationYawPitchRoll(VectorF yawPitchRoll)
{
	MatrixF matrixResult;
	MatrixF yawMatrix, pitchMatrix, rollMatrix;

	VectorF yaw, pitch, roll;

	yaw = vecFSwizzle(yawPitchRoll.getData(), 0, 0, 0, 0);
	pitch = vecFSwizzle(yawPitchRoll.getData(), 1, 1, 1, 1);
	roll = vecFSwizzle(yawPitchRoll.getData(), 2, 2, 2, 2);


	pitchMatrix = matrixFRotationX(pitch);
	yawMatrix = matrixFRotationY(yaw);
	rollMatrix = matrixFRotationZ(roll);

	matrixResult = rollMatrix * pitchMatrix * yawMatrix;

	return matrixResult;
}

MatrixF M3DM::matrixFTranslation(Float x, Float y, Float z)
{
	return matrixFTranslation(VectorF(x,y,z, 0));
}
MatrixF M3DM::matrixFTranslation(VectorF vector)
{
	MatrixF matrixResult;
	
	matrixResult = matrixFIdentity();

	matrixResult.m_rows[3] = _mm_add_ps(matrixResult.m_rows[3], _mm_and_ps(vector.getData(), VectorF(FNAN, FNAN, FNAN, 0).getData()));

	return matrixResult;
}

VectorF M3DM::matrixFTransformCoord3D(VectorF vector, MatrixF matrix)
{
	VectorF resultVec;

	__m128 data, x, y, z, w, temp1, temp2;

	data = vector.getData();
	data = _mm_insert_ps(data, _mm_set1_ps(1), 3 << 4);

	matrix = matrix.transpose();
	x = _mm_dp_ps(data, matrix.m_rows[0], 0b11111111);
	y = _mm_dp_ps(data, matrix.m_rows[1], 0b11111111);
	z = _mm_dp_ps(data, matrix.m_rows[2], 0b11111111);

	temp1 = vecFShuffle(x, y, 0, 1, 2, 3);
	temp1 = vecFSwizzle(temp1, 0, 2, 2, 3);
	temp2 = vecFShuffle(z, vector.getData(), 0, 1, 3, 3);
	temp2 = vecFSwizzle(temp2, 0, 2, 2, 3);

	resultVec = vecFShuffle_0101(temp1, temp2);

	return resultVec;
}
VectorF M3DM::matrixFTransformNormal3D(VectorF vector, MatrixF matrix)
{
	VectorF resultVec;

	__m128 data, x, y, z, w, temp1, temp2;

	data = vector.getData();
	data = _mm_insert_ps(data, _mm_set1_ps(0), 3 << 4);

	matrix = matrix.transpose();
	x = _mm_dp_ps(data, matrix.m_rows[0], 0b11111111);
	y = _mm_dp_ps(data, matrix.m_rows[1], 0b11111111);
	z = _mm_dp_ps(data, matrix.m_rows[2], 0b11111111);

	temp1 = vecFShuffle(x, y, 0, 1, 2, 3);
	temp1 = vecFSwizzle(temp1, 0, 2, 2, 3);
	temp2 = vecFShuffle(z, vector.getData(), 0, 1, 3, 3);
	temp2 = vecFSwizzle(temp2, 0, 2, 2, 3);

	resultVec = vecFShuffle_0101(temp1, temp2);

	return resultVec;
}
VectorF M3DM::matrixFTransform(VectorF vector, MatrixF matrix)
{
	VectorF resultVec;

	__m128 x, y, z, w, temp1, temp2;

	matrix = matrix.transpose();
	x = _mm_dp_ps(vector.getData(), matrix.m_rows[0], 0b11111111);
	y = _mm_dp_ps(vector.getData(), matrix.m_rows[1], 0b11111111);
	z = _mm_dp_ps(vector.getData(), matrix.m_rows[2], 0b11111111);
	w = _mm_dp_ps(vector.getData(), matrix.m_rows[3], 0b11111111);

	temp1 = vecFShuffle(x, y, 0, 1, 2, 3);
	temp1 = vecFSwizzle(temp1, 0, 2, 2, 3);
	temp2 = vecFShuffle(z, w, 0, 1, 2, 3);
	temp2 = vecFSwizzle(temp2, 0, 2, 2, 3);

	resultVec = vecFShuffle_0101(temp1, temp2);

	return resultVec;
}

// special matricies LH
MatrixF M3DM::matrixFOrthoLH(Float width, Float height, Float minZ, Float maxZ)
{
	return matrixFOrthoLH(VectorF(width), VectorF(height), VectorF(minZ), VectorF(maxZ));
}
MatrixF M3DM::matrixFPerspectiveLH(Float width, Float height, Float minZ, Float maxZ)
{
	return matrixFPerspectiveLH(VectorF(width), VectorF(height), VectorF(minZ), VectorF(maxZ));
}
MatrixF M3DM::matrixFPerspectiveFovLH(Float fov, Float aspect, Float minZ, Float maxZ)
{
	return matrixFPerspectiveFovLH(VectorF(fov), VectorF(aspect), VectorF(minZ), VectorF(maxZ));
}
MatrixF M3DM::matrixFOrthoLH(VectorF width, VectorF height, VectorF minZ, VectorF maxZ)
{
	MatrixF matrixResult;

	matrixResult = matrixFIdentity();


	matrixResult.m_rows[0] = _mm_insert_ps(matrixResult.m_rows[0], (VectorF(2) / width).getData(), 0 << 4);
	matrixResult.m_rows[1] = _mm_insert_ps(matrixResult.m_rows[1], (VectorF(2) / height).getData(), 1 << 4);

	VectorF deltaZ = maxZ - minZ;

	matrixResult.m_rows[2] = _mm_insert_ps(matrixResult.m_rows[2], deltaZ.reciprocal().getData(), 2 << 4);
	matrixResult.m_rows[3] = _mm_insert_ps(matrixResult.m_rows[3], (-minZ / deltaZ).getData(), 2 << 4);

	return matrixResult;
}
MatrixF M3DM::matrixFPerspectiveLH(VectorF width, VectorF height, VectorF minZ, VectorF maxZ)
{
	MatrixF matrixResult;

	VectorF two = VectorF(2);
	VectorF temp;

	temp = two * minZ;
	// 2 * minZ / width
	matrixResult.m_rows[0] = _mm_insert_ps(matrixResult.m_rows[0], (temp / width).getData(), 0 << 4);
	// 2 * minZ / height
	matrixResult.m_rows[1] = _mm_insert_ps(matrixResult.m_rows[1], (temp / height).getData(), 1 << 4);
	// maxZ / (maxZ - minZ)
	temp = maxZ / (maxZ - minZ);
	matrixResult.m_rows[2] = _mm_insert_ps(matrixResult.m_rows[2], temp.getData(), 2 << 4);
	// minZ * maxZ / (minZ - maxZ);
	matrixResult.m_rows[3] = _mm_insert_ps(matrixResult.m_rows[3], (-minZ*temp).getData(), 2 << 4);
	matrixResult.m_rows[2] = _mm_insert_ps(matrixResult.m_rows[2], VectorF(1).getData(), 3 << 4);

	return matrixResult;
}
MatrixF M3DM::matrixFPerspectiveFovLH(VectorF fov, VectorF aspect, VectorF minZ, VectorF maxZ)
{
	VectorF width, height, two;

	two = VectorF(2);

	height = two * minZ * (fov / two).tan();
	width = height * aspect;

	return matrixFPerspectiveLH(width, height, minZ, maxZ);
}
MatrixF M3DM::matrixFLookAtLH(VectorF eye, VectorF at, VectorF up)
{
	VectorF xAxis, yAxis, zAxis;
	MatrixF matrixResult;

	matrixResult = matrixFIdentity();

	zAxis = (at - eye).normalized3D();
	xAxis = vecFCross3D(up, zAxis).normalized3D();
	yAxis = vecFCross3D(zAxis, xAxis);

	matrixResult.m_rows[0] = xAxis.getData();
	matrixResult.m_rows[1] = yAxis.getData();
	matrixResult.m_rows[2] = zAxis.getData();

	matrixResult.m_rows[0] = _mm_insert_ps(matrixResult.m_rows[0], (-vecFDotVec3D(xAxis, eye)).getData(), 3 << 4);
	matrixResult.m_rows[1] = _mm_insert_ps(matrixResult.m_rows[1], (-vecFDotVec3D(yAxis, eye)).getData(), 3 << 4);
	matrixResult.m_rows[2] = _mm_insert_ps(matrixResult.m_rows[2], (-vecFDotVec3D(zAxis, eye)).getData(), 3 << 4);

	matrixResult = matrixResult.transpose();

	return matrixResult;
}