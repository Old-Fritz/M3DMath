#include "M3DMath.h"
#include <cmath>

/// Implementation of MatrixScalar functions

using namespace M3DM;

// Transforms
MatrixScalar M3DM::matrixScalarScaling(float x, float y, float z)
{
	MatrixScalar matrixResult;

	matrixResult.m11 = x;
	matrixResult.m22 = y;
	matrixResult.m33 = z;
	matrixResult.m44 = 1;

	return matrixResult;
}
MatrixScalar M3DM::matrixScalarScaling(Vector3 scale)
{
	MatrixScalar matrixResult;

	matrixResult.m11 = scale.x;
	matrixResult.m22 = scale.y;
	matrixResult.m33 = scale.z;
	matrixResult.m44 = 1;

	return matrixResult;
}

MatrixScalar M3DM::matrixScalarRotationX(float angle)
{
	MatrixScalar matrixResult;

	float cos, sin;
	sin = sinf(-angle);
	cos = cosf(-angle);

	matrixResult = matrixScalarIdentity();

	matrixResult.m22 = cos;
	matrixResult.m23 = -sin;
	matrixResult.m32 = sin;
	matrixResult.m33 = cos;

	return matrixResult;
}
MatrixScalar M3DM::matrixScalarRotationY(float angle)
{
	MatrixScalar matrixResult;

	float cos, sin;
	sin = sinf(-angle);
	cos = cosf(-angle);

	matrixResult = matrixScalarIdentity();

	matrixResult.m11 = cos;
	matrixResult.m13 = sin;
	matrixResult.m31 = -sin;
	matrixResult.m33 = cos;

	return matrixResult;
}
MatrixScalar M3DM::matrixScalarRotationZ(float angle)
{
	MatrixScalar matrixResult;

	float cos, sin;
	sin = sinf(-angle);
	cos = cosf(-angle);

	matrixResult = matrixScalarIdentity();

	matrixResult.m11 = cos;
	matrixResult.m12 = -sin;
	matrixResult.m21 = sin;
	matrixResult.m22 = cos;

	return matrixResult;
}
MatrixScalar M3DM::matrixScalarRotationAxis(Vector3 axis, float angle)
{
	return matrixScalarRotationNormal(axis.normalized(),angle);
}
MatrixScalar M3DM::matrixScalarRotationNormal(Vector3 normal, float angle)
{
	MatrixScalar matrixResult;
	float cos, sin, x, y, z;

	x = normal.x;
	y = normal.y;
	z = normal.z;
	sin = sinf(-angle);
	cos = cosf(-angle);

	matrixResult = matrixScalarIdentity();

	matrixResult.m11 = cos + (1 - cos) * x * x;
	matrixResult.m12 = (1 - cos) * x * y - sin * z;
	matrixResult.m13 = (1 - cos) * x * z + sin * y;

	matrixResult.m21 = (1 - cos) * y * x + sin * z;
	matrixResult.m22 = cos + (1 - cos) * y * y;
	matrixResult.m23 = (1 - cos) * y * z - sin * x;

	matrixResult.m31 = (1 - cos) * z * x - sin * y;
	matrixResult.m32 = (1 - cos) * z * y + sin * x;
	matrixResult.m33 = cos + (1 - cos) * z * z;

	return matrixResult;
}
MatrixScalar M3DM::matrixScalarRotationYawPitchRoll(float yaw, float pitch, float roll)
{
	MatrixScalar matrixResult;
	MatrixScalar yawMatrix, pitchMatrix, rollMatrix;

	pitchMatrix = matrixScalarRotationX(pitch);
	yawMatrix = matrixScalarRotationY(yaw);
	rollMatrix = matrixScalarRotationZ(roll);

	matrixResult = rollMatrix * pitchMatrix * yawMatrix;

	return matrixResult;
}
MatrixScalar M3DM::matrixScalarRotationYawPitchRoll(Vector3 yawPitchRoll)
{
	return matrixScalarRotationYawPitchRoll(yawPitchRoll.x, yawPitchRoll.y, yawPitchRoll.z);
}

MatrixScalar M3DM::matrixScalarTranslation(float x, float y, float z)
{
	MatrixScalar matrixResult;

	matrixResult = matrixScalarIdentity();

	matrixResult.m41 = x;
	matrixResult.m42 = y;
	matrixResult.m43 = z;

	return matrixResult;
}
MatrixScalar M3DM::matrixScalarTranslation(Vector3 vector)
{
	return matrixScalarTranslation(vector.x, vector.y, vector.z);
}

Vector3 M3DM::matrixScalarTransformCoord3D(Vector3 vector, MatrixScalar matrix)
{
	Vector4 transVec = {vector.x, vector.y, vector.z, 1 };

	transVec = matrixScalarTransform(transVec, matrix);

	return static_cast<Vector3>(transVec);
}
Vector3 M3DM::matrixScalarTransformNormal3D(Vector3 vector, MatrixScalar matrix)
{
	Vector4 transVec = { vector.x, vector.y, vector.z, 0 };

	transVec = matrixScalarTransform(transVec, matrix);

	return static_cast<Vector3>(transVec);
}
Vector4 M3DM::matrixScalarTransform(Vector4 vector, MatrixScalar matrix)
{
	Vector4 resultVec;

	resultVec.x = vector.x * matrix.m11 + vector.y * matrix.m21 + vector.z * matrix.m31 + vector.w * matrix.m41;
	resultVec.y = vector.x * matrix.m12 + vector.y * matrix.m22 + vector.z * matrix.m32 + vector.w * matrix.m42;
	resultVec.z = vector.x * matrix.m13 + vector.y * matrix.m23 + vector.z * matrix.m33 + vector.w * matrix.m43;
	resultVec.w = vector.x * matrix.m14 + vector.y * matrix.m24 + vector.z * matrix.m34 + vector.w * matrix.m44;

	return resultVec;
}

// special matricies LH
MatrixScalar M3DM::matrixScalarOrthoLH(float width, float height, float minZ, float maxZ)
{
	MatrixScalar matrixResult;
	
	matrixResult = matrixScalarIdentity();

	matrixResult.m11 = 2 / width;
	matrixResult.m22 = 2 / height;
	matrixResult.m33 = 1 / (maxZ - minZ);
	matrixResult.m43 = -minZ / (maxZ - minZ);

	return matrixResult;
}
MatrixScalar M3DM::matrixScalarPerspectiveLH(float width, float height, float minZ, float maxZ)
{
	MatrixScalar matrixResult;

	matrixResult = matrixScalarIdentity();

	matrixResult.m11 = 2 * minZ / width;
	matrixResult.m22 = 2 * minZ / height;
	matrixResult.m33 = maxZ / (maxZ - minZ);
	matrixResult.m43 = minZ * maxZ / (minZ - maxZ);
	matrixResult.m44 = 0;
	matrixResult.m34 = 1;

	return matrixResult;
}
MatrixScalar M3DM::matrixScalarPerspectiveFovLH(float fov, float aspect, float minZ, float maxZ)
{
	float width, height;

	height = 2 * minZ * tanf(fov / 2);
	width = height * aspect;

	return matrixScalarPerspectiveLH(width, height, minZ, maxZ);
}
MatrixScalar M3DM::matrixScalarLookAtLH(Vector3 eye, Vector3 at, Vector3 up)
{
	Vector3 xAxis, yAxis, zAxis;
	MatrixScalar matrixResult;

	matrixResult = matrixScalarIdentity();

	zAxis = (at - eye).normalized();
	xAxis = vec3Cross(up, zAxis).normalized();
	yAxis = vec3Cross(zAxis, xAxis);

	matrixResult.m11 = xAxis.x;
	matrixResult.m12 = yAxis.x;
	matrixResult.m13 = zAxis.x;
	matrixResult.m21 = xAxis.y;
	matrixResult.m22 = yAxis.y;
	matrixResult.m23 = zAxis.y;
	matrixResult.m31 = xAxis.z;
	matrixResult.m32 = yAxis.z;
	matrixResult.m33 = zAxis.z;
	matrixResult.m41 = -vec3Dot(xAxis, eye);
	matrixResult.m42 = -vec3Dot(yAxis, eye);
	matrixResult.m43 = -vec3Dot(zAxis, eye);

	return matrixResult;
}