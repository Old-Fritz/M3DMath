#include "MathTests.h"
#include <cmath>
using namespace M3DM;

bool MatrixScalarFunctionsTester::testAll()
{
	bool result;
	std::cout << "------MATRIX FUNCTIONS SCALAR TEST------" << std::endl;

	std::cout << "--Test scale--" << std::endl;
	result = testScale();
	if (!result)
		return false;

	std::cout << "--Test rotation--" << std::endl;
	result = testRotation();
	if (!result)
		return false;

	std::cout << "--Test translation--" << std::endl;
	result = testTranslation();
	if (!result)
		return false;

	std::cout << "--Test transform--" << std::endl;
	result = testTransform();
	if (!result)
		return false;

	std::cout << "--Test special LH--" << std::endl;
	result = testSpecialLH();
	if (!result)
		return false;

	std::cout << "--Test special RH--" << std::endl;
	result = testSpecialRH();
	if (!result)
		return false;

	return true;
}

bool MatrixScalarFunctionsTester::testScale()
{
	MatrixScalar matrixResult, matrixPrediction;
	float x, y, z;
	Vector3 scale;
	bool result, boolPrediciton;

	// TEST #1
	x = 3;
	y = 5;
	z = 7;
	matrixPrediction = MatrixScalar(3, 0, 0, 0,
		0, 5, 0, 0,
		0, 0, 7, 0,
		0, 0, 0, 1);
	std::cout << "TEST #1: matrixScalarScaling(" << x << ", " << y << ", " << z << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarScaling(x, y, z);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	scale = Vector3(3, 5, 7);
	matrixPrediction = MatrixScalar(3, 0, 0, 0,
		0, 5, 0, 0,
		0, 0, 7, 0,
		0, 0, 0, 1);
	std::cout << "TEST #2: matrixScalarScaling(" << scale << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarScaling(scale);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	return true;
}

bool MatrixScalarFunctionsTester::testRotation()
{
	MatrixScalar matrixResult, matrixPrediction;
	float x, y, z, angle;
	Vector3 vector;
	bool result, boolPrediciton;

	// TEST #1
	angle = 50;
	matrixPrediction = MatrixScalar(1, 0, 0, 0,
		0, 0.964966, -0.262376, 0,
		0, 0.262376, 0.964966, 0,
		0, 0, 0, 1);
	std::cout << "TEST #1: matrixScalarRotationX(" << angle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarRotationX(angle);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	angle = 50;
	matrixPrediction = MatrixScalar(0.964966, 0, 0.262376, 0,
		0, 1, 0, 0,
		-0.262376, 0, 0.964966, 0,
		0, 0, 0, 1);
	std::cout << "TEST #2: matrixScalarRotationY(" << angle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarRotationY(angle);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #3
	angle = 50;
	matrixPrediction = MatrixScalar(0.964966, -0.262376, 0, 0,
		0.262376, 0.964966, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	std::cout << "TEST #3: matrixScalarRotationZ(" << angle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarRotationZ(angle);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #4
	angle = 50;
	vector = Vector3(1, 2, 3);
	matrixPrediction = MatrixScalar(0.967468, -0.205364, 0.147753, 0,
		0.215374, 0.974975, -0.0551083, 0,
		-0.132739, 0.0851377, 0.987488, 0,
		0, 0, 0, 1);
	std::cout << "TEST #4: matrixScalarRotationAxis(" << vector << ", " << angle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarRotationAxis(vector, angle);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #5
	angle = 50;
	vector = Vector3(1, 2, 3).normalized();
	matrixPrediction = MatrixScalar(0.967468, -0.205364, 0.147753, 0,
		0.215374, 0.974975, -0.0551083, 0,
		-0.132739, 0.0851377, 0.987488, 0,
		0, 0, 0, 1);
	std::cout << "TEST #5: matrixScalarRotationNormal(" << vector << ", " << angle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarRotationNormal(vector, angle);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #6
	x = 10;
	y = 20;
	z = 30;
	matrixPrediction = MatrixScalar(0.36129, -0.403198, 0.840774, 0,
		-0.90564, 0.062947, 0.41935, 0,
		-0.222005, -0.912945, -0.34241, 0,
		0, 0, 0, 1);
	std::cout << "TEST #6: matrixScalarRotationYawPitchRoll(" << x << ", " << y << ", " << z << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarRotationYawPitchRoll(x,y,z);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #7
	vector = Vector3(10, 20, 30);
	matrixPrediction = MatrixScalar(0.36129, -0.403198, 0.840774, 0,
		-0.90564, 0.062947, 0.41935, 0,
		-0.222005, -0.912945, -0.34241, 0,
		0, 0, 0, 1);
	std::cout << "TEST #7: matrixScalarRotationYawPitchRoll(" << vector << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarRotationYawPitchRoll(vector);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	return true;
}

bool MatrixScalarFunctionsTester::testTranslation()
{
	MatrixScalar matrixResult, matrixPrediction;
	float x, y, z;
	Vector3 vector;
	bool result, boolPrediciton;

	// TEST #1
	x = 3;
	y = 5;
	z = 7;
	matrixPrediction = MatrixScalar(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		3, 5, 7, 1);
	std::cout << "TEST #1: matrixScalarTranslation(" << x << ", " << y << ", " << z << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarTranslation(x, y, z);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	vector = Vector3(3, 5, 7);
	matrixPrediction = MatrixScalar(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		3, 5, 7, 1);
	std::cout << "TEST #2: matrixScalarTranslation(" << vector << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarTranslation(vector);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	return true;
}

bool MatrixScalarFunctionsTester::testTransform()
{
	MatrixScalar matrix;
	Vector3 vector3, vector3Result, vector3Prediction;
	Vector4 vector4, vector4Result, vector4Prediction;
	bool result, boolPrediciton;

	// TEST #1
	vector3 = Vector3(1, 2, 3);
	matrix = MatrixScalar(1, 0, 0, 0,
		0, -0.989992, 0.14112, 0,
		0, -0.14112, -0.989992, 0,
		1, -2.40335, -2.68774, 1);
	vector3Prediction = Vector3(2, -4.80669, -5.37547);
	std::cout << "TEST #1: matrixScalarTransformCoord3D(" << vector3 << ", " << matrix << ") == " << vector3Prediction << std::endl;
	vector3Result = matrixScalarTransformCoord3D(vector3, matrix);
	result = vector3Result.isEqualPrec(vector3Prediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << vector3Result << std::endl;
		return false;
	}

	// TEST #2
	vector3 = Vector3(1, 2, 3);
	matrix = MatrixScalar(1, 0, 0, 0,
		0, -0.989992, 0.14112, 0,
		0, -0.14112, -0.989992, 0,
		1, -2.40335, -2.68774, 1);
	vector3Prediction = Vector3(1, -2.40335, -2.68774);
	std::cout << "TEST #2: matrixScalarTransformNormal3D(" << vector3 << ", " << matrix << ") == " << vector3Prediction << std::endl;
	vector3Result = matrixScalarTransformNormal3D(vector3, matrix);
	result = vector3Result.isEqualPrec(vector3Prediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << vector3Result << std::endl;
		return false;
	}

	// TEST #3
	vector4 = Vector4(1, 2, 3, 1);
	matrix = MatrixScalar(1, 0, 0, 0,
		0, -0.989992, 0.14112, 0,
		0, -0.14112, -0.989992, 0,
		1, -2.40335, -2.68774, 1);
	vector4Prediction = Vector4(2, -4.80669, -5.37547, 1);
	std::cout << "TEST #3: matrixScalarTransform(" << vector4 << ", " << matrix << ") == " << vector4Prediction << std::endl;
	vector4Result = matrixScalarTransform(vector4, matrix);
	result = vector4Result.isEqualPrec(vector4Prediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << vector3Result << std::endl;
		return false;
	}

	// TEST #4
	vector4 = Vector4(1, 2, 3, 0);
	matrix = MatrixScalar(1, 0, 0, 0,
		0, -0.989992, 0.14112, 0,
		0, -0.14112, -0.989992, 0,
		1, -2.40335, -2.68774, 1);
	vector4Prediction = Vector4(1, -2.40335, -2.68774, 0);
	std::cout << "TEST #4: matrixScalarTransform(" << vector4 << ", " << matrix << ") == " << vector4Prediction << std::endl;
	vector4Result = matrixScalarTransform(vector4, matrix);
	result = vector4Result.isEqualPrec(vector4Prediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << vector3Result << std::endl;
		return false;
	}

	return true;
}

bool MatrixScalarFunctionsTester::testSpecialLH()
{
	MatrixScalar matrixResult, matrixPrediction;
	float height, width, fov, aspect, minZ, maxZ;
	Vector3 eye, at, up;
	bool result, boolPrediciton;

	// TEST #1
	height = 1080;
	width = 920;
	minZ = 1;
	maxZ = 1000;
	matrixPrediction = MatrixScalar(0.00217391, 0, 0, 0,
		0, 0.00185185, 0, 0,
		0, 0, 0.001001, 0,
		0, 0, -0.001001, 1);
	std::cout << "TEST #1: matrixScalarOrthoLH(" << width << ", " << height << ", " << minZ << ", " << maxZ << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarOrthoLH(width, height, minZ, maxZ);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	height = 1080;
	width = 920;
	minZ = 1;
	maxZ = 1000;
	matrixPrediction = MatrixScalar(0.00217391, 0, 0, 0,
		0, 0.00185185, 0, 0,
		0, 0, 1.001, 1,
		0, 0, -1.001, 0);
	std::cout << "TEST #2: matrixScalarPerspectiveLH(" << width << ", " << height << ", " << minZ << ", " << maxZ << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarPerspectiveLH(width, height, minZ, maxZ);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #3
	fov = 90;
	aspect = 1.6;
	minZ = 1;
	maxZ = 1000;
	matrixPrediction = MatrixScalar(0.385858, 0, 0, 0,
		0, 0.617373, 0, 0,
		0, 0, 1.001, 1,
		0, 0, -1.001, 0);
	std::cout << "TEST #3: matrixScalarPerspectiveFovLH(" << fov << ", " << aspect << ", " << minZ << ", " << maxZ << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarPerspectiveFovLH(fov, aspect, minZ, maxZ);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #4
	eye = Vector3(1, 2, 3);
	at = Vector3(2, 3, 4);
	up = Vector3(0, 0, 1);
	matrixPrediction = MatrixScalar(-0.707107, -0.408248, 0.57735, 0,
		0.707107, -0.408248, 0.57735, 0,
		0, 0.816497, 0.57735, 0,
		-0.707107, -1.22474, -3.4641, 1);
	std::cout << "TEST #4: matrixScalarLookAtLH(" << eye << ", " << at << ", " << up << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarLookAtLH(eye, at, up);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	return true;
}

bool MatrixScalarFunctionsTester::testSpecialRH()
{
	return true;
}
