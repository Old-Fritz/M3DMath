#include "MathTests.h"
#include <cmath>
using namespace M3DM;

bool MatrixFFunctionsTester::testAll()
{
	bool result;
	std::cout << "------MATRIX FUNCTIONS SIMD TEST------" << std::endl;

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

bool MatrixFFunctionsTester::testScale()
{
	MatrixF matrixResult, matrixPrediction;
	float x, y, z;
	VectorF scale;
	bool result, boolPrediciton;

	// TEST #1
	x = 3;
	y = 5;
	z = 7;
	matrixPrediction = MatrixF(3, 0, 0, 0,
		0, 5, 0, 0,
		0, 0, 7, 0,
		0, 0, 0, 1);
	std::cout << "TEST #1: matrixFScaling(" << x << ", " << y << ", " << z << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFScaling(x, y, z);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	scale = VectorF(3, 5, 7, 6);
	matrixPrediction = MatrixF(3, 0, 0, 0,
		0, 5, 0, 0,
		0, 0, 7, 0,
		0, 0, 0, 1);
	std::cout << "TEST #2: matrixFScaling(" << scale << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFScaling(scale);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	return true;
}

bool MatrixFFunctionsTester::testRotation()
{
	MatrixF matrixResult, matrixPrediction;
	float x, y, z, angle;
	VectorF vector, vectorAngle;
	bool result, boolPrediciton;

	// TEST #1
	angle = 50;
	matrixPrediction = MatrixF(1, 0, 0, 0,
		0, 0.964966, -0.262376, 0,
		0, 0.262376, 0.964966, 0,
		0, 0, 0, 1);
	std::cout << "TEST #1: matrixFRotationX(" << angle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFRotationX(angle);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	angle = 50;
	matrixPrediction = MatrixF(0.964966, 0, 0.262376, 0,
		0, 1, 0, 0,
		-0.262376, 0, 0.964966, 0,
		0, 0, 0, 1);
	std::cout << "TEST #2: matrixFRotationY(" << angle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFRotationY(angle);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #3
	angle = 50;
	matrixPrediction = MatrixF(0.964966, -0.262376, 0, 0,
		0.262376, 0.964966, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	std::cout << "TEST #3: matrixFRotationZ(" << angle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFRotationZ(angle);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #4
	angle = 50;
	vector = VectorF(1, 2, 3, 4);
	matrixPrediction = MatrixF(0.967468, -0.205364, 0.147753, 0,
		0.215374, 0.974975, -0.0551083, 0,
		-0.132739, 0.0851377, 0.987488, 0,
		0, 0, 0, 1);
	std::cout << "TEST #4: matrixFRotationAxis(" << vector << ", " << angle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFRotationAxis(vector, angle);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #5
	angle = 50;
	vector = VectorF(1, 2, 3, 1).normalized3D();
	matrixPrediction = MatrixF(0.967468, -0.205364, 0.147753, 0,
		0.215374, 0.974975, -0.0551083, 0,
		-0.132739, 0.0851377, 0.987488, 0,
		0, 0, 0, 1);
	std::cout << "TEST #5: matrixFRotationNormal(" << vector << ", " << angle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFRotationNormal(vector, angle);
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
	matrixPrediction = MatrixF(0.36129, -0.403198, 0.840774, 0,
		-0.90564, 0.062947, 0.41935, 0,
		-0.222005, -0.912945, -0.34241, 0,
		0, 0, 0, 1);
	std::cout << "TEST #6: matrixFRotationYawPitchRoll(" << x << ", " << y << ", " << z << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFRotationYawPitchRoll(x, y, z);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #7
	vector = VectorF(10, 20, 30, 4);
	matrixPrediction = MatrixF(0.36129, -0.403198, 0.840774, 0,
		-0.90564, 0.062947, 0.41935, 0,
		-0.222005, -0.912945, -0.34241, 0,
		0, 0, 0, 1);
	std::cout << "TEST #7: matrixFRotationYawPitchRoll(" << vector << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFRotationYawPitchRoll(vector);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}


	// TEST #8
	vectorAngle = VectorF(50);
	matrixPrediction = MatrixF(1, 0, 0, 0,
		0, 0.964966, -0.262376, 0,
		0, 0.262376, 0.964966, 0,
		0, 0, 0, 1);
	std::cout << "TEST #8: matrixFRotationX(" << vectorAngle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFRotationX(vectorAngle);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #9
	vectorAngle = VectorF(50);
	matrixPrediction = MatrixF(0.964966, 0, 0.262376, 0,
		0, 1, 0, 0,
		-0.262376, 0, 0.964966, 0,
		0, 0, 0, 1);
	std::cout << "TEST #9: matrixFRotationY(" << vectorAngle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFRotationY(vectorAngle);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #10
	vectorAngle = VectorF(50);
	matrixPrediction = MatrixF(0.964966, -0.262376, 0, 0,
		0.262376, 0.964966, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	std::cout << "TEST #10: matrixFRotationZ(" << vectorAngle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFRotationZ(vectorAngle);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #11
	vectorAngle = VectorF(50);
	vector = VectorF(1, 2, 3, 4);
	matrixPrediction = MatrixF(0.967468, -0.205364, 0.147753, 0,
		0.215374, 0.974975, -0.0551083, 0,
		-0.132739, 0.0851377, 0.987488, 0,
		0, 0, 0, 1);
	std::cout << "TEST #11: matrixFRotationAxis(" << vector << ", " << vectorAngle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFRotationAxis(vector, vectorAngle);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #12
	vectorAngle = VectorF(50);
	vector = VectorF(1, 2, 3, 4).normalized3D();
	matrixPrediction = MatrixF(0.967468, -0.205364, 0.147753, 0,
		0.215374, 0.974975, -0.0551083, 0,
		-0.132739, 0.0851377, 0.987488, 0,
		0, 0, 0, 1);
	std::cout << "TEST #12: matrixFRotationNormal(" << vector << ", " << vectorAngle << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFRotationNormal(vector, vectorAngle);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	return true;
}

bool MatrixFFunctionsTester::testTranslation()
{
	MatrixF matrixResult, matrixPrediction;
	float x, y, z;
	VectorF vector;
	bool result, boolPrediciton;

	// TEST #1
	x = 3;
	y = 5;
	z = 7;
	matrixPrediction = MatrixF(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		3, 5, 7, 1);
	std::cout << "TEST #1: matrixFTranslation(" << x << ", " << y << ", " << z << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFTranslation(x, y, z);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	vector = VectorF(3, 5, 7, 12);
	matrixPrediction = MatrixF(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		3, 5, 7, 1);
	std::cout << "TEST #2: matrixFTranslation(" << vector << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFTranslation(vector);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	return true;
}

bool MatrixFFunctionsTester::testTransform()
{
	MatrixF matrix;
	VectorF vector, vectorResult, vectorPrediction;
	bool result, boolPrediciton;

	// TEST #1
	vector = VectorF(1, 2, 3, 1);
	matrix = MatrixF(1, 0, 0, 0,
		0, -0.989992, 0.14112, 0,
		0, -0.14112, -0.989992, 0,
		1, -2.40335, -2.68774, 1);
	vectorPrediction = VectorF(2, -4.80669, -5.37547, 1);
	std::cout << "TEST #1: matrixFTransformCoord3D(" << vector << ", " << matrix << ") == " << vectorPrediction << std::endl;
	vectorResult = matrixFTransformCoord3D(vector, matrix);
	result = vectorResult.isEqualPrec(vectorPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << vectorResult << std::endl;
		return false;
	}

	// TEST #2
	vector = VectorF(1, 2, 3, 1);
	matrix = MatrixF(1, 0, 0, 0,
		0, -0.989992, 0.14112, 0,
		0, -0.14112, -0.989992, 0,
		1, -2.40335, -2.68774, 1);
	vectorPrediction = VectorF(1, -2.40335, -2.68774, 1);
	std::cout << "TEST #2: matrixFTransformNormal3D(" << vector << ", " << matrix << ") == " << vectorPrediction << std::endl;
	vectorResult = matrixFTransformNormal3D(vector, matrix);
	result = vectorResult.isEqualPrec(vectorPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << vectorResult << std::endl;
		return false;
	}

	// TEST #3
	vector = VectorF(1, 2, 3, 1);
	matrix = MatrixF(1, 0, 0, 0,
		0, -0.989992, 0.14112, 0,
		0, -0.14112, -0.989992, 0,
		1, -2.40335, -2.68774, 1);
	vectorPrediction = VectorF(2, -4.80669, -5.37547, 1);
	std::cout << "TEST #3: matrixFTransform(" << vector << ", " << matrix << ") == " << vectorPrediction << std::endl;
	vectorResult = matrixFTransform(vector, matrix);
	result = vectorResult.isEqualPrec(vectorPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << vectorResult << std::endl;
		return false;
	}

	// TEST #4
	vector = VectorF(1, 2, 3, 0);
	matrix = MatrixF(1, 0, 0, 0,
		0, -0.989992, 0.14112, 0,
		0, -0.14112, -0.989992, 0,
		1, -2.40335, -2.68774, 1);
	vectorPrediction = VectorF(1, -2.40335, -2.68774, 0);
	std::cout << "TEST #4: matrixFTransform(" << vector << ", " << matrix << ") == " << vectorPrediction << std::endl;
	vectorResult = matrixFTransform(vector, matrix);
	result = vectorResult.isEqualPrec(vectorPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << vectorResult << std::endl;
		return false;
	}

	return true;
}

bool MatrixFFunctionsTester::testSpecialLH()
{
	MatrixF matrixResult, matrixPrediction;
	float height, width, fov, aspect, minZ, maxZ;
	VectorF heightVector, widthVector, fovVector, aspectVector, minZVector, maxZVector;
	VectorF eye, at, up;
	bool result, boolPrediciton;

	// TEST #1
	height = 1080;
	width = 920;
	minZ = 1;
	maxZ = 1000;
	matrixPrediction = MatrixF(0.00217391, 0, 0, 0,
		0, 0.00185185, 0, 0,
		0, 0, 0.001001, 0,
		0, 0, -0.001001, 1);
	std::cout << "TEST #1: matrixFOrthoLH(" << width << ", " << height << ", " << minZ << ", " << maxZ << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFOrthoLH(width, height, minZ, maxZ);
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
	matrixPrediction = MatrixF(0.00217391, 0, 0, 0,
		0, 0.00185185, 0, 0,
		0, 0, 1.001, 1,
		0, 0, -1.001, 0);
	std::cout << "TEST #2: matrixFPerspectiveLH(" << width << ", " << height << ", " << minZ << ", " << maxZ << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFPerspectiveLH(width, height, minZ, maxZ);
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
	matrixPrediction = MatrixF(0.385858, 0, 0, 0,
		0, 0.617373, 0, 0,
		0, 0, 1.001, 1,
		0, 0, -1.001, 0);
	std::cout << "TEST #3: matrixFPerspectiveFovLH(" << fov << ", " << aspect << ", " << minZ << ", " << maxZ << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFPerspectiveFovLH(fov, aspect, minZ, maxZ);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #4
	eye = VectorF(1, 2, 3, 3);
	at = VectorF(2, 3, 4, 5);
	up = VectorF(0, 0, 1, 0);
	matrixPrediction = MatrixF(-0.707107, -0.408248, 0.57735, 0,
		0.707107, -0.408248, 0.57735, 0,
		0, 0.816497, 0.57735, 0,
		-0.707107, -1.22474, -3.4641, 1);
	std::cout << "TEST #4: matrixFLookAtLH(" << eye << ", " << at << ", " << up << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFLookAtLH(eye, at, up);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #5
	heightVector = VectorF(1080);
	widthVector = VectorF(920);
	minZVector = VectorF(1);
	maxZVector = VectorF(1000);
	matrixPrediction = MatrixF(0.00217391, 0, 0, 0,
		0, 0.00185185, 0, 0,
		0, 0, 0.001001, 0,
		0, 0, -0.001001, 1);
	std::cout << "TEST #1: matrixFOrthoLH(" << widthVector << ", " << heightVector << ", " << minZVector << ", " << maxZVector << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFOrthoLH(widthVector, heightVector, minZVector, maxZVector);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #6
	heightVector = VectorF(1080);
	widthVector = VectorF(920);
	minZVector = VectorF(1);
	maxZVector = VectorF(1000);
	matrixPrediction = MatrixF(0.00217391, 0, 0, 0,
		0, 0.00185185, 0, 0,
		0, 0, 1.001, 1,
		0, 0, -1.001, 0);
	std::cout << "TEST #2: matrixFPerspectiveLH(" << widthVector << ", " << heightVector << ", " << minZVector << ", " << maxZVector << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFPerspectiveLH(widthVector, heightVector, minZVector, maxZVector);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	// TEST #7
	fovVector = VectorF(90);
	aspectVector = VectorF(1.6);
	minZVector = VectorF(1);
	maxZVector = VectorF(1000);
	matrixPrediction = MatrixF(0.385858, 0, 0, 0,
		0, 0.617373, 0, 0,
		0, 0, 1.001, 1,
		0, 0, -1.001, 0);
	std::cout << "TEST #3: matrixFPerspectiveFovLH(" << fovVector << ", " << aspectVector << ", " << minZVector << ", " << maxZVector << ") == " << matrixPrediction << std::endl;
	matrixResult = matrixFPerspectiveFovLH(fovVector, aspectVector, minZVector, maxZVector);
	result = matrixResult.isEqualPrec(matrixPrediction, 0.0001f);
	if (!result)
	{
		std::cout << "Failed. Result is " << matrixResult << std::endl;
		return false;
	}

	return true;
}

bool MatrixFFunctionsTester::testSpecialRH()
{
	return true;
}
