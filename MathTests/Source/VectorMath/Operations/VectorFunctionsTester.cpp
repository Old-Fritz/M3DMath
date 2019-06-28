#include "MathTests.h"
#include <math.h>
//#include "DirectXMath.h"
//using namespace DirectX;

using namespace M3DM;

bool VectorFunctionsTester::testAll()
{
	bool result;
	std::cout << "------VECTOR FUNCTIONS TEST------" << std::endl;
	std::cout << "--Test Vector2--" << std::endl;
	result = testVector2();
	if (!result)
		return false;

	std::cout << "--Test Vector3--" << std::endl;
	result = testVector3();
	if (!result)
		return false;

	std::cout << "--Test Vector4--" << std::endl;
	result = testVector4();
	if (!result)
		return false;

	std::cout << "--Test VectorF 2D--" << std::endl;
	result = testVectorF2D();
	if (!result)
		return false;

	std::cout << "--Test VectorF 3D--" << std::endl;
	result = testVectorF3D();
	if (!result)
		return false;

	std::cout << "--Test VectorF 4D--" << std::endl;
	result = testVectorF4D();
	if (!result)
		return false;

	std::cout << "--Test DoubleVectorF 2D--" << std::endl;
	result = testDoubleVectorF2D();
	if (!result)
		return false;

	std::cout << "--Test DoubleVectorF 3D--" << std::endl;
	result = testDoubleVectorF3D();
	if (!result)
		return false;

	std::cout << "--Test DoubleVectorF 4D--" << std::endl;
	result = testDoubleVectorF4D();
	if (!result)
		return false;

	//std::cout << "--Test VectorF--" << std::endl;
	//result = testVectorF();
	//if (!result)
	//	return false;

	return true;
}

bool VectorFunctionsTester::testVector2()
{
	Vector2 arg1, arg2, arg3, arg4, vecResult,  vecPrediction;
	float value, valueResult, valuePrediction;
	bool boolResult, boolPrediction;
	bool result;

	// TEST #1
	arg1 = Vector2(1, 2);
	arg2 = Vector2(1, 3);
	valuePrediction = 7;
	std::cout << "TEST #1: vec2Dot(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec2Dot(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector2(1, 2);
	arg2 = Vector2(1, 3);
	valuePrediction = 1;
	std::cout << "TEST #2: vec2Cross(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec2Cross(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #3
	arg1 = Vector2(0, 0);
	arg2 = Vector2(2, 2);
	arg3 = Vector2(0, 2);
	arg4 = Vector2(2, 0);
	vecPrediction = Vector2(1,1);
	std::cout << "TEST #3: vec2IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec2IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #4
	arg1 = Vector2(0, 2);
	arg2 = Vector2(2, 0);
	arg3 = Vector2(0, 0);
	arg4 = Vector2(2, 2);
	vecPrediction = Vector2(1, 1);
	std::cout << "TEST #4: vec2IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec2IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #5
	arg1 = Vector2(0, 0);
	arg2 = Vector2(2, 2);
	arg3 = Vector2(3, 2);
	arg4 = Vector2(5, 0);
	vecPrediction = Vector2(2.5, 2.5);
	std::cout << "TEST #5: vec2IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec2IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #6
	arg1 = Vector2(0, 0);
	arg2 = Vector2(2, 2);
	arg3 = Vector2(-3, 2);
	arg4 = Vector2(-1, 0);
	vecPrediction = Vector2(-0.5, -0.5);
	std::cout << "TEST #6: vec2IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec2IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #7
	arg1 = Vector2(0, 0);
	arg2 = Vector2(2, 2);
	arg3 = Vector2(1, 0);
	arg4 = Vector2(3, 2);
	vecPrediction = Vector2(-INFINITY, -INFINITY);
	std::cout << "TEST #7: vec2IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec2IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #8
	arg1 = Vector2(0, 0);
	arg2 = Vector2(2, 2);
	arg3 = Vector2(0, 0);
	arg4 = Vector2(2, 2);
	vecPrediction = Vector2(NAN, NAN);
	std::cout << "TEST #8: vec2IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec2IntersectLines(arg1, arg2, arg3, arg4);
	result = isnan(vecResult.x) && isnan(vecResult.y);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #9
	arg1 = Vector2(1, 2);
	arg2 = Vector2(2, 1);
	vecPrediction = Vector2(1.6, 0.8);
	std::cout << "TEST #9: vec2Project(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec2Project(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #10
	arg1 = Vector2(1, 2);
	arg2 = Vector2(2, 3);
	valuePrediction = sqrtf(2);
	std::cout << "TEST #10: vec2Distance(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec2Distance(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #11
	arg1 = Vector2(1, 2);
	arg2 = Vector2(2, 1);
	vecPrediction = Vector2(1, 1);
	std::cout << "TEST #11: vec2Min(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec2Min(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #12
	arg1 = Vector2(1, 2);
	arg2 = Vector2(2, 1);
	vecPrediction = Vector2(2, 2);
	std::cout << "TEST #12: vec2Max(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec2Max(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #13
	arg1 = Vector2(1, -2);
	arg2 = Vector2(0, 1);
	vecPrediction = Vector2(1, 2);
	std::cout << "TEST #13: vec2Reflect(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec2Reflect(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #14
	arg1 = Vector2(1, -2);
	arg2 = Vector2(0, 1);
	value = 1;
	vecPrediction = Vector2(1, -2);
	std::cout << "TEST #14: vec2Refract(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vec2Refract(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #15
	arg1 = Vector2(1, -2);
	arg2 = Vector2(0, 1);
	value = 0.5;
	vecPrediction = Vector2(0.5, -1.32287562);
	std::cout << "TEST #15: vec2Refract(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vec2Refract(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #16
	arg1 = Vector2(2, 3);
	arg2 = Vector2(2, 3);
	vecPrediction = Vector2(4, 27);
	std::cout << "TEST #16: vec2Pow(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec2Pow(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #17
	arg1 = Vector2(2, 3);
	value = 4;
	vecPrediction = Vector2(16, 81);
	std::cout << "TEST #17: vec2Pow(" << arg1 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vec2Pow(arg1, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #18
	arg1 = Vector2(100, 20);
	arg2 = Vector2(20, 200);
	value = 0.7;
	vecPrediction = Vector2(76, 74);
	std::cout << "TEST #18: vec2Lerp(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vec2Lerp(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #19
	arg1 = Vector2(100, 20);
	arg2 = Vector2(20, 200);
	value = 0.7;
	vecPrediction = Vector2(76, 74);
	std::cout << "TEST #19: vec2Lerp(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vec2Lerp(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #20
	arg1 = Vector2(1, 2);
	arg2 = Vector2(-2, 1);
	valuePrediction = 3.1415926535897/2;
	std::cout << "TEST #20: vec2AngleBetween(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec2AngleBetween(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #21
	arg1 = Vector2(1, 2);
	arg2 = Vector2(2, -1);
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #21: vec2AngleBetween(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec2AngleBetween(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #22
	arg1 = Vector2(2, 0);
	arg2 = Vector2(0, 0);
	arg3 = Vector2(1, 2);
	valuePrediction = 2;
	std::cout << "TEST #22: vec2LinePointDistance(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << valuePrediction << std::endl;
	valueResult = vec2LinePointDistance(arg1, arg2, arg3);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #23
	arg1 = Vector2(0, 0);
	arg2 = Vector2(2, 2);
	arg3 = Vector2(0, 2);
	valuePrediction = sqrtf(2);
	std::cout << "TEST #23: vec2LinePointDistance(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << valuePrediction << std::endl;
	valueResult = vec2LinePointDistance(arg1, arg2, arg3);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #24
	arg1 = Vector2(2, 2);
	arg2 = Vector2(0, 0);
	arg3 = Vector2(3, 3);
	boolPrediction = true;
	std::cout << "TEST #24: vec2InBound(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << std::endl;
	boolResult = vec2InBound(arg1, arg2, arg3);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #25
	arg1 = Vector2(2, 2);
	arg2 = Vector2(3, 0);
	arg3 = Vector2(3, 3);
	boolPrediction = false;
	std::cout << "TEST #25: vec2InBound(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << std::endl;
	boolResult = vec2InBound(arg1, arg2, arg3);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #26
	arg1 = Vector2(1, 2).normalized();
	arg2 = Vector2(-2, 1).normalized();
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #26: vec2AngleBetweenNormals(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec2AngleBetweenNormals(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	return true;
}

bool VectorFunctionsTester::testVector3()
{
	Vector3 arg1, arg2, arg3, arg4, vecResult, vecPrediction;
	float value, valueResult, valuePrediction;
	bool boolResult, boolPrediction;
	bool result;

	// TEST #1
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector3(1, 3, -7);
	valuePrediction = -14;
	std::cout << "TEST #1: vec3Dot(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec3Dot(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector3(1, 3, 5);
	vecPrediction = Vector3(1, -2, 1);
	std::cout << "TEST #2: vec3Cross(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec3Cross(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #3
	arg1 = Vector3(0, 0, 0);
	arg2 = Vector3(2, 2, 0);
	arg3 = Vector3(0, 2, 0);
	arg4 = Vector3(2, 0, 0);
	vecPrediction = Vector3(1, 1, 0);
	std::cout << "TEST #3: vec3IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec3IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #4
	arg1 = Vector3(0, 2, 0);
	arg2 = Vector3(2, 0, 0);
	arg3 = Vector3(0, 0, 0);
	arg4 = Vector3(2, 2, 0);
	vecPrediction = Vector3(1, 1, 0);
	std::cout << "TEST #4: vec3IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec3IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #5
	arg1 = Vector3(0, 0, 0);
	arg2 = Vector3(2, 2, 0);
	arg3 = Vector3(3, 2, 0);
	arg4 = Vector3(5, 0, 0);
	vecPrediction = Vector3(2.5, 2.5, 0);
	std::cout << "TEST #5: vec3IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec3IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #6
	arg1 = Vector3(0, 0, 0);
	arg2 = Vector3(2, 2, 0);
	arg3 = Vector3(-3, 2, 0);
	arg4 = Vector3(-1, 0, 0);
	vecPrediction = Vector3(-0.5, -0.5, 0);
	std::cout << "TEST #6: vec3IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec3IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #7
	arg1 = Vector3(0, 0, 0);
	arg2 = Vector3(2, 2, 0);
	arg3 = Vector3(1, 0, 0);
	arg4 = Vector3(3, 2, 0);
	vecPrediction = Vector3(INFINITY, INFINITY, INFINITY);
	std::cout << "TEST #7: vec3IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec3IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #8
	arg1 = Vector3(0, 0, 0);
	arg2 = Vector3(2, 2, 0);
	arg3 = Vector3(0, 0, 0);
	arg4 = Vector3(2, 2, 0);
	vecPrediction = Vector3(INFINITY, INFINITY, INFINITY);
	std::cout << "TEST #8: vec3IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec3IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #9
	arg1 = Vector3(1, 2, 1);
	arg2 = Vector3(2, 1, 2);
	vecPrediction = Vector3(1.33333333, 0.66666666, 1.33333333);
	std::cout << "TEST #9: vec3Project(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec3Project(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #10
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector3(2, 3, 7);
	valuePrediction = sqrtf(18);
	std::cout << "TEST #10: vec3Distance(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec3Distance(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #11
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector3(2, 1, 0);
	vecPrediction = Vector3(1, 1, 0);
	std::cout << "TEST #11: vec3Min(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec3Min(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #12
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector3(2, 1, 0);
	vecPrediction = Vector3(2, 2, 3);
	std::cout << "TEST #12: vec3Max(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec3Max(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #13
	arg1 = Vector3(1, -2, 5);
	arg2 = Vector3(0, 1, 2);
	vecPrediction = Vector3(1, -18, -27);
	std::cout << "TEST #13: vec3Reflect(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec3Reflect(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #14
	arg1 = Vector3(1, -2, 53);
	arg2 = Vector3(0, 1, 53);
	value = 1;
	vecPrediction = Vector3(1, -5616, -297489);
	vecResult = vec3Refract(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #15
	arg1 = Vector3(1, -2, 53);
	arg2 = Vector3(0, 1, 53);
	value = 0.5;
	vecPrediction = Vector3(0.5, -2808.00024, -148744.516);
	std::cout << "TEST #15: vec3Refract(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vec3Refract(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #16
	arg1 = Vector3(2, 3, 4);
	arg2 = Vector3(2, 3, 4);
	vecPrediction = Vector3(4, 27, 256);
	std::cout << "TEST #16: vec3Pow(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec3Pow(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #17
	arg1 = Vector3(2, 3, 4);
	value = 4;
	vecPrediction = Vector3(16, 81, 256);
	std::cout << "TEST #17: vec3Pow(" << arg1 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vec3Pow(arg1, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #18
	arg1 = Vector3(100, 20, 500);
	arg2 = Vector3(20, 200, 0);
	value = 0.7;
	vecPrediction = Vector3(76, 74, 350);
	std::cout << "TEST #18: vec3Lerp(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vec3Lerp(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #19
	arg1 = Vector3(100, 20, 0);
	arg2 = Vector3(20, 200, 0);
	value = 0.7;
	vecPrediction = Vector3(76, 74, 0);
	std::cout << "TEST #18: vec3Lerp(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vec3Lerp(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #20
	arg1 = Vector3(1, 2, 0);
	arg2 = Vector3(-2, 1, 0);
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #20: vec3AngleBetween(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec3AngleBetween(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #21
	arg1 = Vector3(1, 2, 0);
	arg2 = Vector3(2, -1, 0);
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #21: vec3AngleBetween(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec3AngleBetween(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #22
	arg1 = Vector3(2, 0, 1);
	arg2 = Vector3(0, 0, 0);
	arg3 = Vector3(1, 2, 1);
	valuePrediction = 2.04939015319192;
	std::cout << "TEST #22: vec3LinePointDistance(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << valuePrediction << std::endl;
	valueResult = vec3LinePointDistance(arg1, arg2, arg3);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #23
	arg1 = Vector3(0, 0, 0);
	arg2 = Vector3(2, 2, 2);
	arg3 = Vector3(0, 1, 1);
	valuePrediction = 0.81649658092772;
	std::cout << "TEST #23: vec3LinePointDistance(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << valuePrediction << std::endl;
	valueResult = vec3LinePointDistance(arg1, arg2, arg3);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #24
	arg1 = Vector3(2, 2, 2);
	arg2 = Vector3(0, 0, 0);
	arg3 = Vector3(3, 3, 3);
	boolPrediction = true;
	std::cout << "TEST #24: vec3InBound(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << std::endl;
	boolResult = vec3InBound(arg1, arg2, arg3);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #25
	arg1 = Vector3(2, 2, 2);
	arg2 = Vector3(0, 0, 4);
	arg3 = Vector3(3, 3, 3);
	boolPrediction = false;
	std::cout << "TEST #25: vec3InBound(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << std::endl;
	boolResult = vec3InBound(arg1, arg2, arg3);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #26
	arg1 = Vector3(1, 2, 0).normalized();
	arg2 = Vector3(-2, 1, 0).normalized();
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #26: vec3AngleBetweenNormals(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec3AngleBetweenNormals(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	return true;
}

bool VectorFunctionsTester::testVector4()
{
	Vector4 arg1, arg2, arg3, arg4, vecResult, vecPrediction;
	float value, valueResult, valuePrediction;
	bool boolResult, boolPrediction;
	bool result;

	// TEST #1
	arg1 = Vector4(1, 2, 3, 14);
	arg2 = Vector4(1, 3, -7, 1);
	valuePrediction = 0;
	std::cout << "TEST #1: vec4Dot(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec4Dot(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector4(1, 3, 5, 4);
	vecPrediction = Vector4(1, -2, 1, 0);
	//XMStoreFloat3((XMFLOAT3*)static_cast<const float*>(vecPrediction),
	//	XMVector4Cross(XMLoadFloat3((XMFLOAT3*)static_cast<const float*>(arg1)),
	//		XMLoadFloat3((XMFLOAT3*)static_cast<const float*>(arg2))));
	std::cout << "TEST #2: vec4Cross(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec4Cross3D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #3
	arg1 = Vector4(0, 0, 0, 0);
	arg2 = Vector4(2, 2, 0, 0);
	arg3 = Vector4(0, 2, 0, 0);
	arg4 = Vector4(2, 0, 0, 0);
	vecPrediction = Vector4(1, 1, 0, 0);
	std::cout << "TEST #3: vec4IntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec4IntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #4
	arg1 = Vector4(0, 2, 0, 0);
	arg2 = Vector4(2, 0, 0, 0);
	arg3 = Vector4(0, 0, 0, 0);
	arg4 = Vector4(2, 2, 0, 0);
	vecPrediction = Vector4(1, 1, 0, 0);
	std::cout << "TEST #4: vec4IntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec4IntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #5
	arg1 = Vector4(0, 0, 0, 0);
	arg2 = Vector4(2, 2, 0, 0);
	arg3 = Vector4(3, 2, 0, 0);
	arg4 = Vector4(5, 0, 0, 0);
	vecPrediction = Vector4(2.5, 2.5, 0, 0);
	std::cout << "TEST #5: vec4IntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec4IntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #6
	arg1 = Vector4(0, 0, 0, 0);
	arg2 = Vector4(2, 2, 0, 0);
	arg3 = Vector4(-3, 2, 0, 0);
	arg4 = Vector4(-1, 0, 0, 0);
	vecPrediction = Vector4(-0.5, -0.5, 0, 0);
	std::cout << "TEST #6: vec4IntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec4IntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #7
	arg1 = Vector4(0, 0, 0, 0);
	arg2 = Vector4(2, 2, 0, 0);
	arg3 = Vector4(1, 0, 0, 0);
	arg4 = Vector4(3, 2, 0, 0);
	vecPrediction = Vector4(INFINITY, INFINITY, INFINITY, 0);
	std::cout << "TEST #7: vec4IntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec4IntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #8
	arg1 = Vector4(0, 0, 0, 0);
	arg2 = Vector4(2, 2, 0, 0);
	arg3 = Vector4(0, 0, 0, 0);
	arg4 = Vector4(2, 2, 0, 0);
	vecPrediction = Vector4(INFINITY, INFINITY, INFINITY, 0);
	std::cout << "TEST #8: vec4IntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec4IntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #9
	arg1 = Vector4(1, 2, 1, 3);
	arg2 = Vector4(0, 0, 0, 3);
	vecPrediction = Vector4(0, 0, 0, 3);
	std::cout << "TEST #9: vec4Project(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec4Project(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #10
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector4(2, 3, 7, 5);
	valuePrediction = sqrtf(19);
	std::cout << "TEST #10: vec4Distance(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec4Distance(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #11
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector4(2, 1, 0, 8);
	vecPrediction = Vector4(1, 1, 0, 4);
	std::cout << "TEST #11: vec4Min(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec4Min(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #12
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector4(2, 1, 0, 8);
	vecPrediction = Vector4(2, 2, 3, 8);
	std::cout << "TEST #12: vec4Max(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec4Max(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #13
	arg1 = Vector4(1, -2, 5, 7);
	arg2 = Vector4(0, 1, 2, 9);
	vecPrediction = Vector4(1, -144, -279, - 1271);
	//XMStoreFloat4((XMFLOAT4*)static_cast<const float*>(vecPrediction),
	//	XMVector4Reflect(XMLoadFloat4((XMFLOAT4*)static_cast<const float*>(arg1)),
	//		XMLoadFloat4((XMFLOAT4*)static_cast<const float*>(arg2))));
	std::cout << "TEST #13: vec4Reflect(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec4Reflect(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #14
	arg1 = Vector4(1, -2, 3, 13);
	arg2 = Vector4(0, 1, 5, 6);
	value = 1;
	vecPrediction = Vector4(1, -184, -907, -1079);
	vecResult = vec4Refract(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #15
	arg1 = Vector4(1, -2, 3, 13);
	arg2 = Vector4(0, 1, 5, 6);
	value = 0.5;
	vecPrediction = Vector4(0.5, -92.0082397, -453.541199, -539.549438);
	std::cout << "TEST #15: vec4Refract(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vec4Refract(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #16
	arg1 = Vector4(2, 3, 4, 5);
	arg2 = Vector4(2, 3, 4, 2);
	vecPrediction = Vector4(4, 27, 256, 25);
	std::cout << "TEST #16: vec4Pow(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec4Pow(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #17
	arg1 = Vector4(2, 3, 4, 1);
	value = 4;
	vecPrediction = Vector4(16, 81, 256, 1);
	std::cout << "TEST #17: vec4Pow(" << arg1 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vec4Pow(arg1, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #18
	arg1 = Vector4(100, 20, 500, 1);
	arg2 = Vector4(20, 200, 0, 1);
	value = 0.7;
	vecPrediction = Vector4(76, 74, 350, 1);
	std::cout << "TEST #18: vec4Lerp(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vec4Lerp(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #19
	arg1 = Vector4(100, 20, 0, 3);
	arg2 = Vector4(20, 200, 0, 5);
	value = 0.7;
	vecPrediction = Vector4(76, 74, 0, 3.6);
	std::cout << "TEST #19: vec4Lerp(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vec4Lerp(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #20
	arg1 = Vector4(1, 2, 0, 0);
	arg2 = Vector4(-2, 1, 0, 0);
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #20: vec4AngleBetween(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec4AngleBetween(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #21
	arg1 = Vector4(1, 2, 0, 0);
	arg2 = Vector4(2, -1, 0, 0);
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #21: vec4AngleBetween(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec4AngleBetween(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #22
	arg1 = Vector4(2, 0, 1, 2);
	arg2 = Vector4(0, 0, 0, 3);
	arg3 = Vector4(1, 2, 1, 4);
	valuePrediction = 2.04939015319192;
	std::cout << "TEST #22: vec4LinePointDistance3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << valuePrediction << std::endl;
	valueResult = vec4LinePointDistance3D(arg1, arg2, arg3);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #23
	arg1 = Vector4(0, 0, 0, 2);
	arg2 = Vector4(2, 2, 2, 3);
	arg3 = Vector4(0, 1, 1, 4);
	valuePrediction = 0.81649658092772;
	std::cout << "TEST #23: vec4LinePointDistance3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << valuePrediction << std::endl;
	valueResult = vec4LinePointDistance3D(arg1, arg2, arg3);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #24
	arg1 = Vector4(2, 2, 2, 2);
	arg2 = Vector4(0, 0, 0, 0);
	arg3 = Vector4(3, 3, 3, 3);
	boolPrediction = true;
	std::cout << "TEST #24: vec4InBound(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << std::endl;
	boolResult = vec4InBound(arg1, arg2, arg3);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #25
	arg1 = Vector4(2, 2, 2, 3);
	arg2 = Vector4(0, 0, 0, 4);
	arg3 = Vector4(3, 3, 3, 3);
	boolPrediction = false;
	std::cout << "TEST #25: vec4InBound(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << std::endl;
	boolResult = vec4InBound(arg1, arg2, arg3);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #26
	arg1 = Vector4(1, 2, 0, 0).normalized();
	arg2 = Vector4(-2, 1, 0, 0).normalized();
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #26: vec4AngleBetweenNormals(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vec4AngleBetweenNormals(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	return true;
}

bool VectorFunctionsTester::testVectorF2D()
{
	VectorF arg1, arg2, arg3, arg4, vecResult, vecPrediction;
	float value, valueResult, valuePrediction;
	bool boolResult, boolPrediction;
	bool result;

	// TEST #1
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(1, 3, 3, 4);
	boolPrediction = false;
	std::cout << "TEST #1: vecFCmp2D(" << arg1 << ", " << arg2 << ") == " << boolPrediction << std::endl;
	boolResult = vecFCmp2D(arg1, arg2, CMP_EQ);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #2
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(1, 2, 5, 7);
	boolPrediction = true;
	std::cout << "TEST #2: vecFCmp2D(" << arg1 << ", " << arg2 << ") == " << boolPrediction << std::endl;
	boolResult = vecFCmp2D(arg1, arg2, CMP_EQ);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #3
	arg1 = VectorF(1, 2, 5, 3);
	arg2 = VectorF(1, 3, -7, 1);
	vecPrediction = VectorF(1);
	std::cout << "TEST #3: vecFCross2D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFCross2D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #4
	arg1 = VectorF(1, 2, 5, 3);
	arg2 = VectorF(1, 3, -7, 1);
	vecPrediction = VectorF(7);
	std::cout << "TEST #3: vecFDotVec2D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFDotVec2D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #5
	arg1 = VectorF(1, -2, 3, 4);
	arg2 = VectorF(0, 1, 3, 4);
	vecPrediction = VectorF(1, 2, FNAN, FNAN);
	std::cout << "TEST #5: vecFReflect2D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFReflect2D(arg1, arg2);
	result = vecFCmp2D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #6
	arg1 = VectorF(1, -2, 3, 4);
	arg2 = VectorF(0, 1, 5, 6);
	value = 1;
	vecPrediction = VectorF(1, -2, FNAN, FNAN);
	std::cout << "TEST #6: vecFRefract2D(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vecFRefract2D(arg1, arg2, value);
	result = vecFCmp2D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #7
	arg1 = VectorF(1, -2, 3 ,4);
	arg2 = VectorF(0, 1, 7, 8);
	value = 0.5;
	vecPrediction = VectorF(0.5, -1.32287562, FNAN, FNAN);
	std::cout << "TEST #7: vecFRefract2D(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vecFRefract2D(arg1, arg2, value);
	result = vecFCmp2D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #8
	arg1 = VectorF(0, 0, 3, 4);
	arg2 = VectorF(2, 2, 3, 4);
	arg3 = VectorF(0, 2, 3, 4);
	arg4 = VectorF(2, 0, 3, 4);
	vecPrediction = VectorF(1, 1, FNAN, FNAN);
	std::cout << "TEST #8: vecFIntersectLines2D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines2D(arg1, arg2, arg3, arg4);
	result = vecFCmp2D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #9
	arg1 = VectorF(0, 2, 3, 4);
	arg2 = VectorF(2, 0, 3, 4);
	arg3 = VectorF(0, 0, 3, 4);
	arg4 = VectorF(2, 2, 3, 4);
	vecPrediction = VectorF(1, 1, FNAN, FNAN);
	std::cout << "TEST #9: vecFIntersectLines2D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines2D(arg1, arg2, arg3, arg4);
	result = vecFCmp2D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #10
	arg1 = VectorF(0, 0, 3, 4);
	arg2 = VectorF(2, 2, 3, 4);
	arg3 = VectorF(3, 2, 3, 4);
	arg4 = VectorF(5, 0, 3, 4);
	vecPrediction = VectorF(2.5, 2.5, FNAN, FNAN);
	std::cout << "TEST #10: vecFIntersectLines2D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines2D(arg1, arg2, arg3, arg4);
	result = vecFCmp2D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #11
	arg1 = VectorF(0, 0, 3, 4);
	arg2 = VectorF(2, 2, 3, 4);
	arg3 = VectorF(-3, 2, 3, 4);
	arg4 = VectorF(-1, 0, 3, 4);
	vecPrediction = VectorF(-0.5, -0.5, FNAN, FNAN);
	std::cout << "TEST #11: vecFIntersectLines2D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines2D(arg1, arg2, arg3, arg4);
	result = vecFCmp2D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #12
	arg1 = VectorF(0, 0, 3, 4);
	arg2 = VectorF(2, 2, 3, 4);
	arg3 = VectorF(1, 0, 3, 4);
	arg4 = VectorF(3, 2, 3, 4);
	vecPrediction = VectorF(INFINITY, INFINITY, FNAN, FNAN);
	std::cout << "TEST #12: vecFIntersectLines2D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines2D(arg1, arg2, arg3, arg4);
	result = vecFCmp2D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #13
	arg1 = VectorF(0, 0, 3, 4);
	arg2 = VectorF(2, 2, 3, 4);
	arg3 = VectorF(0, 0, 3, 4);
	arg4 = VectorF(2, 2, 3, 4);
	vecPrediction = VectorF(INFINITY, INFINITY, FNAN, FNAN);
	std::cout << "TEST #13: vecFIntersectLines2D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines2D(arg1, arg2, arg3, arg4);
	result = vecFCmp2D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #14
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(3, 4, 5, 6);
	vecPrediction = VectorF(sqrtf(8));
	std::cout << "TEST #14: vecFDistanceVec2D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFDistanceVec2D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #15
	arg1 = VectorF(1, -2, 3, 4);
	arg2 = VectorF(0, 1, 7, 8);
	arg3 = VectorF(0.5);
	vecPrediction = VectorF(0.5, -1.32287562, FNAN, FNAN);
	std::cout << "TEST #15: vecFRefractVec2D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = vecFRefractVec2D(arg1, arg2, arg3);
	result = vecFCmp2D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #16
	arg1 = VectorF(2, 0, 3, 4);
	arg2 = VectorF(0, 0, 7, 8);
	arg3 = VectorF(1, 2, 8, 9);
	vecPrediction = VectorF(2);
	std::cout << "TEST #16: vecFLinePointDistanceVec2D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = vecFLinePointDistanceVec2D(arg1, arg2, arg3);
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #17
	arg1 = VectorF(0, 0, 3, 4);
	arg2 = VectorF(2, 2, 7, 8);
	arg3 = VectorF(0, 2, 8, 9);
	vecPrediction = VectorF(sqrtf(2));
	std::cout << "TEST #17: vecFLinePointDistanceVec2D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = vecFLinePointDistanceVec2D(arg1, arg2, arg3);
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #18
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(-2, 1, 7, 8);
	vecPrediction = VectorF(3.1415926535897 / 2);
	std::cout << "TEST #18: vecFAngleBetweenVec2D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFAngleBetweenVec2D(arg1, arg2);
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #19
	arg1 = VectorF(1, 2, 3, 4).normalized2D();
	arg2 = VectorF(2, -1, 7, 8).normalized2D();
	vecPrediction = VectorF(3.1415926535897 / 2);
	std::cout << "TEST #19: vecFAngleBetweenNormalsVec2D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFAngleBetweenNormalsVec2D(arg1, arg2);
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #20
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(3, 4, 5, 6);
	valuePrediction = sqrtf(8);
	std::cout << "TEST #20: vecFDistance2D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFDistance2D(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #21
	arg1 = VectorF(1, 2, 5, 3);
	arg2 = VectorF(1, 3, -7, 1);
	valuePrediction = 7;
	std::cout << "TEST #21: vecFDot2D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFDot2D(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #22
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(-2, 1, 7, 8);
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #22: vecFAngleBetween2D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFAngleBetween2D(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #23
	arg1 = VectorF(1, 2, 3, 4).normalized2D();
	arg2 = VectorF(2, -1, 7, 8).normalized2D();
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #23: vecFAngleBetweenNormals2D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFAngleBetweenNormals2D(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #24
	arg1 = VectorF(0, 0, 3, 4);
	arg2 = VectorF(2, 2, 7, 8);
	arg3 = VectorF(0, 2, 8, 9);
	valuePrediction = sqrtf(2);
	std::cout << "TEST #24: vecFLinePointDistance2D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << valuePrediction << std::endl;
	valueResult = vecFLinePointDistance2D(arg1, arg2, arg3);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #24
	arg1 = VectorF(3, 3, 3, 4);
	arg2 = VectorF(2, 2, 7, 8);
	arg3 = VectorF(4, 4, 8, 9);
	boolPrediction = true;
	std::cout << "TEST #24: vecFInBound2D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << std::endl;
	boolResult = vecFInBound2D(arg1, arg2, arg3);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #25
	arg1 = VectorF(3, 5, 3, 4);
	arg2 = VectorF(2, 2, 7, 8);
	arg3 = VectorF(4, 4, 8, 9);
	boolPrediction = false;
	std::cout << "TEST #25: vecFInBound2D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << std::endl;
	boolResult = vecFInBound2D(arg1, arg2, arg3);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #26
	arg1 = VectorF(1, 2, 1, 4);
	arg2 = VectorF(2, 1, 2, 8);
	vecPrediction = VectorF(1.6, 0.8, FNAN, FNAN);
	std::cout << "TEST #26: vecFProject2D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFProject2D(arg1, arg2);
	result = vecFCmp2D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	return true;
}

bool VectorFunctionsTester::testVectorF3D()
{
	VectorF arg1, arg2, arg3, arg4, vecResult, vecPrediction;
	float value, valueResult, valuePrediction;
	bool boolResult, boolPrediction;
	bool result;

	// TEST #1
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(1, 3, 3, 4);
	boolPrediction = false;
	std::cout << "TEST #1: vecFCmp3D(" << arg1 << ", " << arg2 << ") == " << boolPrediction << std::endl;
	boolResult = vecFCmp3D(arg1, arg2, CMP_EQ);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #2
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(1, 2, 3, 7);
	boolPrediction = true;
	std::cout << "TEST #2: vecFCmp3D(" << arg1 << ", " << arg2 << ") == " << boolPrediction << std::endl;
	boolResult = vecFCmp3D(arg1, arg2, CMP_EQ);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #3
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(1, 3, 5, 4);
	vecPrediction = VectorF(1, -2, 1, FNAN);
	std::cout << "TEST #3: vecFCross3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFCross3D(arg1, arg2);
	result = vecFCmp3D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #4
	arg1 = VectorF(1, 2, 3, 14);
	arg2 = VectorF(1, 3, -7, 1);
	vecPrediction = VectorF(-14);
	std::cout << "TEST #3: vecFDotVec3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFDotVec3D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #5
	arg1 = VectorF(1, -2, 5, 4);
	arg2 = VectorF(0, 1, 2, 4);
	vecPrediction = VectorF(1, -18, -27, FNAN);
	std::cout << "TEST #5: vecFReflect3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFReflect3D(arg1, arg2);
	result = vecFCmp3D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #6
	arg1 = VectorF(1, -2, 53, 4);
	arg2 = VectorF(0, 1, 53, 6);
	value = 1;
	vecPrediction = VectorF(1, -5616, -297489, FNAN);
	std::cout << "TEST #6: vecFRefract3D(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vecFRefract3D(arg1, arg2, value);
	result = vecFCmp3D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #7
	arg1 = VectorF(1, -2, 53, 4);
	arg2 = VectorF(0, 1, 53, 8);
	value = 0.5;
	vecPrediction = VectorF(0.5, -2808.00024, -148744.516, FNAN);
	std::cout << "TEST #7: vecFRefract3D(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vecFRefract3D(arg1, arg2, value);
	result = vecFCmp3D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #8
	arg1 = VectorF(0, 0, 0, 4);
	arg2 = VectorF(2, 2, 0, 4);
	arg3 = VectorF(0, 2, 0, 4);
	arg4 = VectorF(2, 0, 0, 4);
	vecPrediction = VectorF(1, 1, 0, FNAN);
	std::cout << "TEST #8: vecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecFCmp3D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #9
	arg1 = VectorF(0, 2, 0, 4);
	arg2 = VectorF(2, 0, 0, 4);
	arg3 = VectorF(0, 0, 0, 4);
	arg4 = VectorF(2, 2, 0, 4);
	vecPrediction = VectorF(1, 1, 0, FNAN);
	std::cout << "TEST #9: vecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecFCmp3D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #10
	arg1 = VectorF(0, 0, 0, 4);
	arg2 = VectorF(2, 2, 0, 4);
	arg3 = VectorF(3, 2, 0, 4);
	arg4 = VectorF(5, 0, 0, 4);
	vecPrediction = VectorF(2.5, 2.5, 0, FNAN);
	std::cout << "TEST #10: vecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecFCmp3D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #11
	arg1 = VectorF(0, 0, 0, 4);
	arg2 = VectorF(2, 2, 0, 4);
	arg3 = VectorF(-3, 2, 0, 4);
	arg4 = VectorF(-1, 0, 0, 4);
	vecPrediction = VectorF(-0.5, -0.5, 0, FNAN);
	std::cout << "TEST #11: vecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecFCmp3D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #12
	arg1 = VectorF(0, 0, 0, 4);
	arg2 = VectorF(2, 2, 0, 4);
	arg3 = VectorF(1, 0, 0, 4);
	arg4 = VectorF(3, 2, 0, 4);
	vecPrediction = VectorF(INFINITY, INFINITY, INFINITY, FNAN);
	std::cout << "TEST #12: vecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecFCmp3D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #13
	arg1 = VectorF(0, 0, 0, 4);
	arg2 = VectorF(2, 2, 0, 4);
	arg3 = VectorF(0, 0, 0, 4);
	arg4 = VectorF(2, 2, 0, 4);
	vecPrediction = VectorF(INFINITY, INFINITY, INFINITY, FNAN);
	std::cout << "TEST #13: vecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecFCmp3D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #14
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(3, 4, 5, 6);
	vecPrediction = VectorF(sqrtf(12));
	std::cout << "TEST #14: vecFDistanceVec3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFDistanceVec3D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #15
	arg1 = VectorF(1, -2, 53, 4);
	arg2 = VectorF(0, 1, 53, 8);
	arg3 = VectorF(0.5);
	vecPrediction = VectorF(0.5, -2808.00024, -148744.516, FNAN);
	std::cout << "TEST #15: vecFRefractVec3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = vecFRefractVec3D(arg1, arg2, arg3);
	result = vecFCmp3D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #16
	arg1 = VectorF(2, 0, 1, 4);
	arg2 = VectorF(0, 0, 0, 8);
	arg3 = VectorF(1, 2, 1, 9);
	vecPrediction = VectorF(2.04939015319192);
	std::cout << "TEST #16: vecFLinePointDistance3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = vecFLinePointDistanceVec3D(arg1, arg2, arg3);
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #17
	arg1 = VectorF(0, 0, 0, 4);
	arg2 = VectorF(2, 2, 2, 8);
	arg3 = VectorF(0, 1, 1, 9);
	vecPrediction = VectorF(0.81649658092772);
	std::cout << "TEST #17: vecFLinePointDistanceVec3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = vecFLinePointDistanceVec3D(arg1, arg2, arg3);
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #18
	arg1 = VectorF(1, 2, 0, 4);
	arg2 = VectorF(-2, 1, 0, 8);
	vecPrediction = VectorF(3.1415926535897 / 2);
	std::cout << "TEST #18: vecFAngleBetweenVec3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFAngleBetweenVec3D(arg1, arg2);
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #19
	arg1 = VectorF(1, 2, 0, 4).normalized3D();
	arg2 = VectorF(2, -1, 0, 8).normalized3D();
	vecPrediction = VectorF(3.1415926535897 / 2);
	std::cout << "TEST #19: vecFAngleBetweenNormalsVec3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFAngleBetweenNormalsVec3D(arg1, arg2);
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #20
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(3, 4, 5, 6);
	valuePrediction = sqrtf(12);
	std::cout << "TEST #20: vecFDistance3D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFDistance3D(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #21
	arg1 = VectorF(1, 2, 5, 3);
	arg2 = VectorF(1, 3, -7, 1);
	valuePrediction = -28;
	std::cout << "TEST #21: vecFDot3D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFDot3D(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #22
	arg1 = VectorF(1, 2, 0, 4);
	arg2 = VectorF(-2, 1, 0, 8);
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #22: vecFAngleBetween3D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFAngleBetween3D(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #23
	arg1 = VectorF(1, 2, 0, 4).normalized3D();
	arg2 = VectorF(2, -1, 0, 8).normalized3D();
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #23: vecFAngleBetweenNormals3D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFAngleBetweenNormals3D(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #24
	arg1 = VectorF(0, 0, 0, 4);
	arg2 = VectorF(2, 2, 2, 8);
	arg3 = VectorF(0, 1, 1, 9);
	valuePrediction = 0.81649658092772;
	std::cout << "TEST #24: vecFLinePointDistance3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << valuePrediction << std::endl;
	valueResult = vecFLinePointDistance3D(arg1, arg2, arg3);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #24
	arg1 = VectorF(3, 3, 3, 4);
	arg2 = VectorF(2, 2, 2, 8);
	arg3 = VectorF(4, 4, 4, 9);
	boolPrediction = true;
	std::cout << "TEST #24: vecFInBound3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << std::endl;
	boolResult = vecFInBound3D(arg1, arg2, arg3);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #25
	arg1 = VectorF(3, 5, 3, 4);
	arg2 = VectorF(2, 2, 2, 8);
	arg3 = VectorF(4, 4, 4, 9);
	boolPrediction = false;
	std::cout << "TEST #25: vecFInBound3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << std::endl;
	boolResult = vecFInBound3D(arg1, arg2, arg3);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #26
	arg1 = VectorF(1, 2, 1, 4);
	arg2 = VectorF(2, 1, 2, 8);
	vecPrediction = VectorF(1.33333333, 0.66666666, 1.33333333, FNAN);
	std::cout << "TEST #26: vecFProject3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFProject3D(arg1, arg2);
	result = vecFCmp3D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	return true;
}

bool VectorFunctionsTester::testVectorF4D()
{
	VectorF arg1, arg2, arg3, arg4, vecResult, vecPrediction;
	float value, valueResult, valuePrediction;
	bool boolResult, boolPrediction;
	bool result;

	// TEST #1
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(1, 3, 3, 4);
	boolPrediction = false;
	std::cout << "TEST #1: vecFCmp4D(" << arg1 << ", " << arg2 << ") == " << boolPrediction << std::endl;
	boolResult = vecFCmp4D(arg1, arg2, CMP_EQ);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #2
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(1, 2, 3, 4);
	boolPrediction = true;
	std::cout << "TEST #2: vecFCmp4D(" << arg1 << ", " << arg2 << ") == " << boolPrediction << std::endl;
	boolResult = vecFCmp4D(arg1, arg2, CMP_EQ);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #4
	arg1 = VectorF(1, 2, 3, 14);
	arg2 = VectorF(1, 3, -7, 1);
	vecPrediction = VectorF();
	std::cout << "TEST #3: vecFDotVec4D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFDotVec4D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #5
	arg1 = VectorF(1, -2, 5, 7);
	arg2 = VectorF(0, 1, 2, 9);
	vecPrediction = VectorF(1, -144, -279, -1271);
	std::cout << "TEST #5: vecFReflect4D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFReflect4D(arg1, arg2);
	result = vecFCmp4D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #6
	arg1 = VectorF(1, -2, 3, 13);
	arg2 = VectorF(0, 1, 5, 6);
	value = 1;
	vecPrediction = VectorF(1, -184, -907, -1079);
	std::cout << "TEST #6: vecFRefract4D(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vecFRefract4D(arg1, arg2, value);
	result = vecFCmp4D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #7
	arg1 = VectorF(1, -2, 3, 13);
	arg2 = VectorF(0, 1, 5, 6);
	value = 0.5;
	vecPrediction = VectorF(0.5, -92.0082397, -453.541199, -539.549438);
	std::cout << "TEST #7: vecFRefract4D(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vecFRefract4D(arg1, arg2, value);
	result = vecFCmp4D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #8
	arg1 = VectorF(1, 2, 3, 14);
	arg2 = VectorF(1, 3, -7, 1);
	vecPrediction = VectorF(1, 3, 3, 14);
	std::cout << "TEST #8: vecFMax(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFMax(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #9
	arg1 = VectorF(1, 2, 3, 14);
	arg2 = VectorF(1, 3, -7, 1);
	vecPrediction = VectorF(1, 2, -7, 1);
	std::cout << "TEST #9: vecFMin(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFMin(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #10
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(4, 3, 2, 1);
	vecPrediction = VectorF(1, 8, 9, 4);
	std::cout << "TEST #10: vecFPow(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFPow(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #11
	arg1 = VectorF(1, 2, 3, 4);
	value = 3;
	vecPrediction = VectorF(1, 8, 27, 64);
	std::cout << "TEST #11: vecFPow(" << arg1 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vecFPow(arg1, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #12
	arg1 = VectorF(1, 0, 3, 4);
	arg2 = VectorF(4, 3, 3, 1);
	value = 0.7;
	vecPrediction = VectorF(1.9, 0.9, 3, 3.1);
	std::cout << "TEST #12: vecFLerp(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vecFLerp(arg1, arg2, value);
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.00001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #14
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(3, 4, 5, 6);
	vecPrediction = VectorF(4);
	std::cout << "TEST #14: vecFDistanceVec4D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFDistanceVec4D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #15
	arg1 = VectorF(1, -2, 3, 13);
	arg2 = VectorF(0, 1, 5, 6);
	arg3 = VectorF(0.5);
	vecPrediction = VectorF(0.5, -92.0082397, -453.541199, -539.549438);
	std::cout << "TEST #15: vecFRefractVec4D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = vecFRefractVec4D(arg1, arg2, arg3);
	result = vecFCmp4D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #18
	arg1 = VectorF(1, 2, 0, 0);
	arg2 = VectorF(-2, 1, 0, 0);
	vecPrediction = VectorF(3.1415926535897 / 2);
	std::cout << "TEST #18: vecFAngleBetweenVec4D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFAngleBetweenVec4D(arg1, arg2);
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #19
	arg1 = VectorF(1, 2, 0, 0).normalized4D();
	arg2 = VectorF(2, -1, 0, 0).normalized4D();
	vecPrediction = VectorF(3.1415926535897 / 2);
	std::cout << "TEST #19: vecFAngleBetweenNormalsVec4D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFAngleBetweenNormalsVec4D(arg1, arg2);
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #20
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(3, 4, 5, 6);
	valuePrediction = 4;
	std::cout << "TEST #20: vecFDistance4D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFDistance4D(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #21
	arg1 = VectorF(1, 2, 5, 3);
	arg2 = VectorF(1, 3, -7, 1);
	valuePrediction = -25;
	std::cout << "TEST #21: vecFDot4D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFDot4D(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #22
	arg1 = VectorF(1, 2, 0, 0);
	arg2 = VectorF(-2, 1, 0, 0);
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #22: vecFAngleBetween4D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFAngleBetween4D(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #23
	arg1 = VectorF(1, 2, 0, 0).normalized4D();
	arg2 = VectorF(2, -1, 0, 0).normalized4D();
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #23: vecFAngleBetweenNormals4D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFAngleBetweenNormals4D(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #24
	arg1 = VectorF(3, 3, 3, 3);
	arg2 = VectorF(2, 2, 2, 2);
	arg3 = VectorF(4, 4, 4, 4);
	boolPrediction = true;
	std::cout << "TEST #24: vecFInBound4D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << std::endl;
	boolResult = vecFInBound4D(arg1, arg2, arg3);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #25
	arg1 = VectorF(3, 5, 3, 3);
	arg2 = VectorF(2, 2, 2, 2);
	arg3 = VectorF(4, 4, 4, 4);
	boolPrediction = false;
	std::cout << "TEST #25: vecFInBound4D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << std::endl;
	boolResult = vecFInBound4D(arg1, arg2, arg3);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #26
	arg1 = VectorF(1, 2, 1, 3);
	arg2 = VectorF(0, 0, 0, 3);
	vecPrediction = VectorF(0, 0, 0, 3);
	std::cout << "TEST #26: vecFProject4D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFProject4D(arg1, arg2);
	result = vecFCmp4D(vecResult, vecPrediction, CMP_EQ);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}


	return true;
}

bool VectorFunctionsTester::testDoubleVectorF2D()
{
	DoubleVectorF arg1, arg2, arg3, arg4, vecResult, vecPrediction;
	float value, valueResult, valueResult2, valuePrediction, valuePrediction2;
	bool boolResult, boolResult2, boolPrediction, boolPrediction2;
	bool result;

	// TEST #1
	arg1 = DoubleVectorF(1, 2, 3, 4, 1, 2, 3, 4);
	arg2 = DoubleVectorF(1, 3, 3, 4, 1, 2, 3, 4);
	boolPrediction = false;
	boolPrediction2 = true;
	std::cout << "TEST #1: doubleVecFCmp2D(" << arg1 << ", " << arg2 << ", CMP_EQ) == " << boolPrediction << ", " << boolPrediction2 << std::endl;
	doubleVecFCmp2D(arg1, arg2, CMP_EQ, boolResult, boolResult2);
	result = boolResult == boolPrediction && boolResult2 == boolPrediction2;
	if (!result)
	{
		std::cout << "Failed.  Computed value: boolResult1 = " << boolResult << ", boolResult2 = " << boolResult2 << std::endl;
		return false;
	}

	// TEST #2
	arg1 = DoubleVectorF(1, 2, 3, 4, 1, 2, 3, 4);
	arg2 = DoubleVectorF(1, 2, 5, 7, 1, 3, 5, 7);
	boolPrediction = true;
	boolPrediction2 = false;
	std::cout << "TEST #2: doubleVecFCmp2D(" << arg1 << ", " << arg2 << ", CMP_EQ) == " << boolPrediction << ", " << boolPrediction2 << std::endl;
	doubleVecFCmp2D(arg1, arg2, CMP_EQ, boolResult, boolResult2);
	result = boolResult == boolPrediction && boolResult2 == boolPrediction2;
	if (!result)
	{
		std::cout << "Failed.  Computed value: boolResult1 = " << boolResult << ", boolResult2 = " << boolResult2 << std::endl;
		return false;
	}

	// TEST #3
	arg1 = DoubleVectorF(1, 2, 5, 3, 1, 2, 5, 3);
	arg2 = DoubleVectorF(1, 3, -7, 1, 1, 3, -7, 1);
	vecPrediction = DoubleVectorF(1);
	std::cout << "TEST #3: doubleVecFCross2D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFCross2D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #4
	arg1 = DoubleVectorF(1, 2, 5, 3, 1, 2, 5, 3);
	arg2 = DoubleVectorF(1, 3, -7, 1, 1, 3, -7, 1);
	vecPrediction = DoubleVectorF(7);
	std::cout << "TEST #3: doubleVecFDotVec2D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFDotVec2D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #5
	arg1 = DoubleVectorF(1, -2, 3, 4, 1, -2, 3, 4);
	arg2 = DoubleVectorF(0, 1, 3, 4, 0, 1, 3, 4);
	vecPrediction = DoubleVectorF(1, 2, FNAN, FNAN, 1, 2, FNAN, FNAN);
	std::cout << "TEST #5: doubleVecFReflect2D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFReflect2D(arg1, arg2);
	doubleVecFCmp2D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #6
	arg1 = DoubleVectorF(1, -2, 3, 4, 1, -2, 3, 4);
	arg2 = DoubleVectorF(0, 1, 5, 6, 0, 1, 5, 6);
	value = 1;
	vecPrediction = DoubleVectorF(1, -2, FNAN, FNAN, 1, -2, FNAN, FNAN);
	std::cout << "TEST #6: doubleVecFRefract2D(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFRefract2D(arg1, arg2, value);
	doubleVecFCmp2D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #7
	arg1 = DoubleVectorF(1, -2, 3, 4, 1, -2, 3, 4);
	arg2 = DoubleVectorF(0, 1, 7, 8, 0, 1, 7, 8);
	value = 0.5;
	vecPrediction = DoubleVectorF(0.5, -1.32287562, FNAN, FNAN, 0.5, -1.32287562, FNAN, FNAN);
	std::cout << "TEST #7: doubleVecFRefract2D(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFRefract2D(arg1, arg2, value);
	doubleVecFCmp2D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #8
	arg1 = DoubleVectorF(0, 0, 3, 4, 0, 0, 3, 4);
	arg2 = DoubleVectorF(2, 2, 3, 4, 2, 2, 3, 4);
	arg3 = DoubleVectorF(0, 2, 3, 4, 0, 2, 3, 4);
	arg4 = DoubleVectorF(2, 0, 3, 4, 2, 0, 3, 4);
	vecPrediction = DoubleVectorF(1, 1, FNAN, FNAN, 1, 1, FNAN, FNAN);
	std::cout << "TEST #8: doubleVecFIntersectLines2D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFIntersectLines2D(arg1, arg2, arg3, arg4);
	doubleVecFCmp2D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #9
	arg1 = DoubleVectorF(0, 2, 3, 4, 0, 2, 3, 4);
	arg2 = DoubleVectorF(2, 0, 3, 4, 2, 0, 3, 4);
	arg3 = DoubleVectorF(0, 0, 3, 4, 0, 0, 3, 4);
	arg4 = DoubleVectorF(2, 2, 3, 4, 2, 2, 3, 4);
	vecPrediction = DoubleVectorF(1, 1, FNAN, FNAN, 1, 1, FNAN, FNAN);
	std::cout << "TEST #9: doubleVecFIntersectLines2D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFIntersectLines2D(arg1, arg2, arg3, arg4);
	doubleVecFCmp2D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #10
	arg1 = DoubleVectorF(0, 0, 3, 4, 0, 0, 3, 4);
	arg2 = DoubleVectorF(2, 2, 3, 4, 2, 2, 3, 4);
	arg3 = DoubleVectorF(3, 2, 3, 4, 3, 2, 3, 4);
	arg4 = DoubleVectorF(5, 0, 3, 4, 5, 0, 3, 4);
	vecPrediction = DoubleVectorF(2.5, 2.5, FNAN, FNAN, 2.5, 2.5, FNAN, FNAN);
	std::cout << "TEST #10: doubleVecFIntersectLines2D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFIntersectLines2D(arg1, arg2, arg3, arg4);
	doubleVecFCmp2D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #11
	arg1 = DoubleVectorF(0, 0, 3, 4, 0, 0, 3, 4);
	arg2 = DoubleVectorF(2, 2, 3, 4, 2, 2, 3, 4);
	arg3 = DoubleVectorF(-3, 2, 3, 4, -3, 2, 3, 4);
	arg4 = DoubleVectorF(-1, 0, 3, 4, -1, 0, 3, 4);
	vecPrediction = DoubleVectorF(-0.5, -0.5, FNAN, FNAN, -0.5, -0.5, FNAN, FNAN);
	std::cout << "TEST #11: doubleVecFIntersectLines2D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFIntersectLines2D(arg1, arg2, arg3, arg4);
	doubleVecFCmp2D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #12
	arg1 = DoubleVectorF(0, 0, 3, 4, 0, 0, 3, 4);
	arg2 = DoubleVectorF(2, 2, 3, 4, 2, 2, 3, 4);
	arg3 = DoubleVectorF(1, 0, 3, 4, 1, 0, 3, 4);
	arg4 = DoubleVectorF(3, 2, 3, 4, 3, 2, 3, 4);
	vecPrediction = DoubleVectorF(INFINITY, INFINITY, FNAN, FNAN, INFINITY, INFINITY, FNAN, FNAN);
	std::cout << "TEST #12: doubleVecFIntersectLines2D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFIntersectLines2D(arg1, arg2, arg3, arg4);
	doubleVecFCmp2D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #13
	arg1 = DoubleVectorF(0, 0, 3, 4, 0, 0, 3, 4);
	arg2 = DoubleVectorF(2, 2, 3, 4, 2, 2, 3, 4);
	arg3 = DoubleVectorF(0, 0, 3, 4, 0, 0, 3, 4);
	arg4 = DoubleVectorF(2, 2, 3, 4, 2, 2, 3, 4);
	vecPrediction = DoubleVectorF(INFINITY, INFINITY, FNAN, FNAN, INFINITY, INFINITY, FNAN, FNAN);
	std::cout << "TEST #13: doubleVecFIntersectLines2D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFIntersectLines2D(arg1, arg2, arg3, arg4);
	doubleVecFCmp2D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #14
	arg1 = DoubleVectorF(1, 2, 3, 4, 1, 2, 3, 4);
	arg2 = DoubleVectorF(3, 4, 5, 6, 3, 4, 5, 6);
	vecPrediction = DoubleVectorF(sqrtf(8));
	std::cout << "TEST #14: doubleVecFDistanceVec2D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFDistanceVec2D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #15
	arg1 = DoubleVectorF(1, -2, 3, 4, 1, -2, 3, 4);
	arg2 = DoubleVectorF(0, 1, 7, 8, 0, 1, 7, 8);
	arg3 = DoubleVectorF(0.5);
	vecPrediction = DoubleVectorF(0.5, -1.32287562, FNAN, FNAN, 0.5, -1.32287562, FNAN, FNAN);
	std::cout << "TEST #15: doubleVecFRefractVec2D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFRefractVec2D(arg1, arg2, arg3);
	doubleVecFCmp2D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #16
	arg1 = DoubleVectorF(2, 0, 3, 4, 2, 0, 3, 4);
	arg2 = DoubleVectorF(0, 0, 7, 8, 0, 0, 7, 8);
	arg3 = DoubleVectorF(1, 2, 8, 9, 1, 2, 8, 9);
	vecPrediction = DoubleVectorF(2);
	std::cout << "TEST #16: doubleVecFLinePointDistanceVec2D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFLinePointDistanceVec2D(arg1, arg2, arg3);
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #17
	arg1 = DoubleVectorF(0, 0, 3, 4, 0, 0, 3, 4);
	arg2 = DoubleVectorF(2, 2, 7, 8, 2, 2, 7, 8);
	arg3 = DoubleVectorF(0, 2, 8, 9, 0, 2, 8, 9);
	vecPrediction = DoubleVectorF(sqrtf(2));
	std::cout << "TEST #17: doubleVecFLinePointDistanceVec2D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFLinePointDistanceVec2D(arg1, arg2, arg3);
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #18
	arg1 = DoubleVectorF(1, 2, 3, 4, 1, 2, 3, 4);
	arg2 = DoubleVectorF(-2, 1, 7, 8, -2, 1, 7, 8);
	vecPrediction = DoubleVectorF(3.1415926535897 / 2);
	std::cout << "TEST #18: doubleVecFAngleBetweenVec2D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFAngleBetweenVec2D(arg1, arg2);
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #19
	arg1 = DoubleVectorF(1, 2, 3, 4, 1, 2, 3, 4).normalized2D();
	arg2 = DoubleVectorF(2, -1, 7, 8, 2, -1, 7, 8).normalized2D();
	vecPrediction = DoubleVectorF(3.1415926535897 / 2);
	std::cout << "TEST #19: doubleVecFAngleBetweenNormalsVec2D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFAngleBetweenNormalsVec2D(arg1, arg2);
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #20
	arg1 = DoubleVectorF(1, 2, 3, 4, 1, 2, 3, 4);
	arg2 = DoubleVectorF(3, 4, 5, 6, 3, 4, 5, 6);
	valuePrediction = sqrtf(8);
	valuePrediction2 = sqrtf(8);
	std::cout << "TEST #20: doubleVecFDistance2D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << ", " << valuePrediction2  << std::endl;
	doubleVecFDistance2D(arg1, arg2, valueResult, valueResult2);
	result = (valueResult == valuePrediction) && (valueResult2 == valuePrediction2);
	if (!result)
	{
		std::cout << "Failed. Computed value: valueResult1 = " << valueResult << ", valueResult2 = " << valueResult2 << std::endl;
		return false;
	}

	// TEST #21
	arg1 = DoubleVectorF(1, 2, 5, 3, 1, 2, 5, 3);
	arg2 = DoubleVectorF(1, 3, -7, 1, 1, 3, -7, 1);
	valuePrediction = 7;
	valuePrediction2 = 7;
	std::cout << "TEST #21: doubleVecFDot2D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << ", " << valuePrediction2 << std::endl;
	doubleVecFDot2D(arg1, arg2, valueResult, valueResult2);
	result = (valueResult == valuePrediction) && (valueResult2 == valuePrediction2);
	if (!result)
	{
		std::cout << "Failed. Computed value: valueResult1 = " << valueResult << ", valueResult2 = " << valueResult2 << std::endl;
		return false;
	}

	// TEST #22
	arg1 = DoubleVectorF(1, 2, 3, 4, 1, 2, 3, 4);
	arg2 = DoubleVectorF(-2, 1, 7, 8, -2, 1, 7, 8);
	valuePrediction = 3.1415926535897 / 2;
	valuePrediction2 = 3.1415926535897 / 2;
	std::cout << "TEST #22: doubleVecFAngleBetween2D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << ", " << valuePrediction2 << std::endl;
	doubleVecFAngleBetween2D(arg1, arg2, valueResult, valueResult2);
	result = (valueResult == valuePrediction) && (valueResult2 == valuePrediction2);
	if (!result)
	{
		std::cout << "Failed. Computed value: valueResult1 = " << valueResult << ", valueResult2 = " << valueResult2 << std::endl;
		return false;
	}

	// TEST #23
	arg1 = DoubleVectorF(1, 2, 3, 4, 1, 2, 3, 4).normalized2D();
	arg2 = DoubleVectorF(2, -1, 7, 8, 2, -1, 7, 8).normalized2D();
	valuePrediction = 3.1415926535897 / 2;
	valuePrediction2 = 3.1415926535897 / 2;
	std::cout << "TEST #23: doubleVecFAngleBetweenNormals2D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << ", " << valuePrediction2 << std::endl;
	doubleVecFAngleBetweenNormals2D(arg1, arg2, valueResult, valueResult2);
	result = (valueResult == valuePrediction) && (valueResult2 == valuePrediction2);
	if (!result)
	{
		std::cout << "Failed. Computed value: valueResult1 = " << valueResult << ", valueResult2 = " << valueResult2 << std::endl;
		return false;
	}

	// TEST #24
	arg1 = DoubleVectorF(0, 0, 3, 4, 0, 0, 3, 4);
	arg2 = DoubleVectorF(2, 2, 7, 8, 2, 2, 7, 8);
	arg3 = DoubleVectorF(0, 2, 8, 9, 0, 2, 8, 9);
	valuePrediction = sqrtf(2);
	valuePrediction2 = sqrtf(2);
	std::cout << "TEST #24: doubleVecFLinePointDistance2D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << valuePrediction << ", " << valuePrediction2 << std::endl;
	doubleVecFLinePointDistance2D(arg1, arg2, arg3, valueResult, valueResult2);
	result = (valueResult == valuePrediction) && (valueResult2 == valuePrediction2);
	if (!result)
	{
		std::cout << "Failed. Computed value: valueResult1 = " << valueResult << ", valueResult2 = " << valueResult2 << std::endl;
		return false;
	}

	// TEST #24
	arg1 = DoubleVectorF(3, 3, 3, 4, 3, 3, 3, 4);
	arg2 = DoubleVectorF(2, 2, 7, 8, 2, 2, 7, 8);
	arg3 = DoubleVectorF(4, 4, 8, 9, 4, 4, 8, 9);
	boolPrediction = true;
	boolPrediction2 = true;
	std::cout << "TEST #24: doubleVecFInBound2D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << ", " << boolPrediction2 << std::endl;
	doubleVecFInBound2D(arg1, arg2, arg3, boolResult, boolResult2);
	result = (boolResult == boolPrediction) && (boolResult2 == boolPrediction2);
	if (!result)
	{
		std::cout << "Failed. boolResult1 = " << boolResult << ", boolResult2 = " << boolResult2 << std::endl;
		return false;
	}

	// TEST #25
	arg1 = DoubleVectorF(3, 5, 3, 4, 3, 5, 3, 4);
	arg2 = DoubleVectorF(2, 2, 7, 8, 2, 2, 7, 8);
	arg3 = DoubleVectorF(4, 4, 8, 9, 4, 4, 8, 9);
	boolPrediction = false;
	boolPrediction2 = false;
	std::cout << "TEST #25: doubleVecFInBound2D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << ", " << boolPrediction2 << std::endl;
	doubleVecFInBound2D(arg1, arg2, arg3, boolResult, boolResult2);
	result = (boolResult == boolPrediction) && (boolResult2 == boolPrediction2);
	if (!result)
	{
		std::cout << "Failed. boolResult1 = " << boolResult << ", boolResult2 = " << boolResult2 << std::endl;
		return false;
	}

	// TEST #26
	arg1 = DoubleVectorF(1, 2, 1, 4, 1, 2, 1, 4);
	arg2 = DoubleVectorF(2, 1, 2, 8, 2, 1, 2, 8);
	vecPrediction = DoubleVectorF(1.6, 0.8, FNAN, FNAN, 1.6, 0.8, FNAN, FNAN);
	std::cout << "TEST #26: doubleVecFProject2D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFProject2D(arg1, arg2);
	doubleVecFCmp2D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	return true;
}

bool VectorFunctionsTester::testDoubleVectorF3D()
{
	DoubleVectorF arg1, arg2, arg3, arg4, vecResult, vecPrediction;
	float value, valueResult, valueResult2, valuePrediction, valuePrediction2;
	bool boolResult, boolResult2, boolPrediction, boolPrediction2;
	bool result;

	// TEST #1
	arg1 = DoubleVectorF(1, 2, 3, 4, 1, 2, 3, 4);
	arg2 = DoubleVectorF(1, 3, 3, 4, 1, 2, 3, 4);
	boolPrediction = false;
	boolPrediction2 = true;
	std::cout << "TEST #1: doubleVecFCmp3D(" << arg1 << ", " << arg2 << ", CMP_EQ) == " << boolPrediction << ", " << boolPrediction2 << std::endl;
	doubleVecFCmp3D(arg1, arg2, CMP_EQ, boolResult, boolResult2);
	result = boolResult == boolPrediction && boolResult2 == boolPrediction2;
	if (!result)
	{
		std::cout << "Failed.  Computed value: boolResult1 = " << boolResult << ", boolResult2 = " << boolResult2 << std::endl;
		return false;
	}

	// TEST #2
	arg1 = DoubleVectorF(1, 2, 3, 4, 1, 2, 3, 4);
	arg2 = DoubleVectorF(1, 2, 3, 7, 1, 2, 4, 7);
	boolPrediction = true;
	boolPrediction2 = false;
	std::cout << "TEST #2: doubleVecFCmp3D(" << arg1 << ", " << arg2 << ", CMP_EQ) == " << boolPrediction << ", " << boolPrediction2 << std::endl;
	doubleVecFCmp3D(arg1, arg2, CMP_EQ, boolResult, boolResult2);
	result = boolResult == boolPrediction && boolResult2 == boolPrediction2;
	if (!result)
	{
		std::cout << "Failed. boolResult1 = " << boolResult << ", boolResult2 = " << boolResult2 << std::endl;
		return false;
	}

	// TEST #3
	arg1 = DoubleVectorF(1, 2, 3, 4, 1, 2, 3, 4);
	arg2 = DoubleVectorF(1, 3, 5, 4, 1, 3, 5, 4);
	vecPrediction = DoubleVectorF(1, -2, 1, FNAN, 1, -2, 1, FNAN);
	std::cout << "TEST #3: doubleVecFCross3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFCross3D(arg1, arg2);
	doubleVecFCmp3D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #4
	arg1 = DoubleVectorF(1, 2, 3, 14, 1, 2, 3, 14);
	arg2 = DoubleVectorF(1, 3, -7, 1, 1, 3, -7, 1);
	vecPrediction = DoubleVectorF(-14);
	std::cout << "TEST #3: doubleVecFDotVec3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFDotVec3D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #5
	arg1 = DoubleVectorF(1, -2, 5, 4, 1, -2, 5, 4);
	arg2 = DoubleVectorF(0, 1, 2, 4, 0, 1, 2, 4);
	vecPrediction = DoubleVectorF(1, -18, -27, FNAN, 1, -18, -27, FNAN);
	std::cout << "TEST #5: doubleVecFReflect3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFReflect3D(arg1, arg2);
	doubleVecFCmp3D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #6
	arg1 = DoubleVectorF(1, -2, 53, 4, 1, -2, 53, 4);
	arg2 = DoubleVectorF(0, 1, 53, 6, 0, 1, 53, 6);
	value = 1;
	vecPrediction = DoubleVectorF(1, -5616, -297489, FNAN, 1, -5616, -297489, FNAN);
	std::cout << "TEST #6: doubleVecFRefract3D(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFRefract3D(arg1, arg2, value);
	doubleVecFCmp3D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #7
	arg1 = DoubleVectorF(1, -2, 53, 4, 1, -2, 53, 4);
	arg2 = DoubleVectorF(0, 1, 53, 8, 0, 1, 53, 8);
	value = 0.5;
	vecPrediction = DoubleVectorF(0.5, -2808.00024, -148744.516, FNAN, 0.5, -2808.00024, -148744.516, FNAN);
	std::cout << "TEST #7: doubleVecFRefract3D(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFRefract3D(arg1, arg2, value);
	doubleVecFCmp3D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #8
	arg1 = DoubleVectorF(0, 0, 0, 4, 0, 0, 0, 4);
	arg2 = DoubleVectorF(2, 2, 0, 4, 2, 2, 0, 4);
	arg3 = DoubleVectorF(0, 2, 0, 4, 0, 2, 0, 4);
	arg4 = DoubleVectorF(2, 0, 0, 4, 2, 0, 0, 4);
	vecPrediction = DoubleVectorF(1, 1, 0, FNAN, 1, 1, 0, FNAN);
	std::cout << "TEST #8: doubleVecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFIntersectLines3D(arg1, arg2, arg3, arg4);
	doubleVecFCmp3D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #9
	arg1 = DoubleVectorF(0, 2, 0, 4, 0, 2, 0, 4);
	arg2 = DoubleVectorF(2, 0, 0, 4, 2, 0, 0, 4);
	arg3 = DoubleVectorF(0, 0, 0, 4, 0, 0, 0, 4);
	arg4 = DoubleVectorF(2, 2, 0, 4, 2, 2, 0, 4);
	vecPrediction = DoubleVectorF(1, 1, 0, FNAN, 1, 1, 0, FNAN);
	std::cout << "TEST #9: doubleVecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFIntersectLines3D(arg1, arg2, arg3, arg4);
	doubleVecFCmp3D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #10
	arg1 = DoubleVectorF(0, 0, 0, 4, 0, 0, 0, 4);
	arg2 = DoubleVectorF(2, 2, 0, 4, 2, 2, 0, 4);
	arg3 = DoubleVectorF(3, 2, 0, 4, 3, 2, 0, 4);
	arg4 = DoubleVectorF(5, 0, 0, 4, 5, 0, 0, 4);
	vecPrediction = DoubleVectorF(2.5, 2.5, 0, FNAN, 2.5, 2.5, 0, FNAN);
	std::cout << "TEST #10: doubleVecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFIntersectLines3D(arg1, arg2, arg3, arg4);
	doubleVecFCmp3D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #11
	arg1 = DoubleVectorF(0, 0, 0, 4, 0, 0, 0, 4);
	arg2 = DoubleVectorF(2, 2, 0, 4, 2, 2, 0, 4);
	arg3 = DoubleVectorF(-3, 2, 0, 4, -3, 2, 0, 4);
	arg4 = DoubleVectorF(-1, 0, 0, 4, -1, 0, 0, 4);
	vecPrediction = DoubleVectorF(-0.5, -0.5, 0, FNAN, -0.5, -0.5, 0, FNAN);
	std::cout << "TEST #11: doubleVecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFIntersectLines3D(arg1, arg2, arg3, arg4);
	doubleVecFCmp3D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #12
	arg1 = DoubleVectorF(0, 0, 0, 4, 0, 0, 0, 4);
	arg2 = DoubleVectorF(2, 2, 0, 4, 2, 2, 0, 4);
	arg3 = DoubleVectorF(1, 0, 0, 4, 1, 0, 0, 4);
	arg4 = DoubleVectorF(3, 2, 0, 4, 3, 2, 0, 4);
	vecPrediction = DoubleVectorF(INFINITY, INFINITY, INFINITY, FNAN, INFINITY, INFINITY, INFINITY, FNAN);
	std::cout << "TEST #12: doubleVecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFIntersectLines3D(arg1, arg2, arg3, arg4);
	doubleVecFCmp3D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #13
	arg1 = DoubleVectorF(0, 0, 0, 4, 0, 0, 0, 4);
	arg2 = DoubleVectorF(2, 2, 0, 4, 2, 2, 0, 4);
	arg3 = DoubleVectorF(0, 0, 0, 4, 0, 0, 0, 4);
	arg4 = DoubleVectorF(2, 2, 0, 4, 2, 2, 0, 4);
	vecPrediction = DoubleVectorF(INFINITY, INFINITY, INFINITY, FNAN, INFINITY, INFINITY, INFINITY, FNAN);
	std::cout << "TEST #13: doubleVecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFIntersectLines3D(arg1, arg2, arg3, arg4);
	doubleVecFCmp3D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #14
	arg1 = DoubleVectorF(1, 2, 3, 4, 1, 2, 3, 4);
	arg2 = DoubleVectorF(3, 4, 5, 6, 3, 4, 5, 6);
	vecPrediction = DoubleVectorF(sqrtf(12));
	std::cout << "TEST #14: doubleVecFDistanceVec3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFDistanceVec3D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #15
	arg1 = DoubleVectorF(1, -2, 53, 4, 1, -2, 53, 4);
	arg2 = DoubleVectorF(0, 1, 53, 8, 0, 1, 53, 8);
	arg3 = DoubleVectorF(0.5);
	vecPrediction = DoubleVectorF(0.5, -2808.00024, -148744.516, FNAN, 0.5, -2808.00024, -148744.516, FNAN);
	std::cout << "TEST #15: doubleVecFRefractVec3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFRefractVec3D(arg1, arg2, arg3);
	doubleVecFCmp3D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #16
	arg1 = DoubleVectorF(2, 0, 1, 4, 2, 0, 1, 4);
	arg2 = DoubleVectorF(0, 0, 0, 8, 0, 0, 0, 8);
	arg3 = DoubleVectorF(1, 2, 1, 9, 1, 2, 1, 9);
	vecPrediction = DoubleVectorF(2.04939015319192);
	std::cout << "TEST #16: doubleVecFLinePointDistance3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFLinePointDistanceVec3D(arg1, arg2, arg3);
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #17
	arg1 = DoubleVectorF(0, 0, 0, 4, 0, 0, 0, 4);
	arg2 = DoubleVectorF(2, 2, 2, 8, 2, 2, 2, 8);
	arg3 = DoubleVectorF(0, 1, 1, 9, 0, 1, 1, 9);
	vecPrediction = DoubleVectorF(0.81649658092772);
	std::cout << "TEST #17: doubleVecFLinePointDistanceVec3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFLinePointDistanceVec3D(arg1, arg2, arg3);
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #18
	arg1 = DoubleVectorF(1, 2, 0, 4, 1, 2, 0, 4);
	arg2 = DoubleVectorF(-2, 1, 0, 8, -2, 1, 0, 8);
	vecPrediction = DoubleVectorF(3.1415926535897 / 2);
	std::cout << "TEST #18: doubleVecFAngleBetweenVec3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFAngleBetweenVec3D(arg1, arg2);
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #19
	arg1 = DoubleVectorF(1, 2, 0, 4, 1, 2, 0, 4).normalized3D();
	arg2 = DoubleVectorF(2, -1, 0, 8, 2, -1, 0, 8).normalized3D();
	vecPrediction = DoubleVectorF(3.1415926535897 / 2);
	std::cout << "TEST #19: doubleVecFAngleBetweenNormalsVec3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFAngleBetweenNormalsVec3D(arg1, arg2);
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #20
	arg1 = DoubleVectorF(1, 2, 3, 4, 1, 2, 3, 4);
	arg2 = DoubleVectorF(3, 4, 5, 6, 3, 4, 5, 6);
	valuePrediction = sqrtf(12);
	valuePrediction2 = sqrtf(12);
	std::cout << "TEST #20: doubleVecFDistance3D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << ", " << valuePrediction2 << std::endl;
	doubleVecFDistance3D(arg1, arg2, valueResult, valueResult2);
	result = (valueResult == valuePrediction) && (valueResult2 == valuePrediction2);
	if (!result)
	{
		std::cout << "Failed. Computed value: valueResult1 = " << valueResult << ", valueResult2 = " << valueResult2 << std::endl;
		return false;
	}

	// TEST #21
	arg1 = DoubleVectorF(1, 2, 5, 3, 1, 2, 5, 3);
	arg2 = DoubleVectorF(1, 3, -7, 1, 1, 3, -7, 1);
	valuePrediction = -28;
	valuePrediction2 = -28;
	std::cout << "TEST #21: doubleVecFDot3D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << ", " << valuePrediction2 << std::endl;
	doubleVecFDot3D(arg1, arg2, valueResult, valueResult2);
	result = (valueResult == valuePrediction) && (valueResult2 == valuePrediction2);
	if (!result)
	{
		std::cout << "Failed. Computed value: valueResult1 = " << valueResult << ", valueResult2 = " << valueResult2 << std::endl;
		return false;
	}

	// TEST #22
	arg1 = DoubleVectorF(1, 2, 0, 4, 1, 2, 0, 4);
	arg2 = DoubleVectorF(-2, 1, 0, 8, -2, 1, 0, 8);
	valuePrediction = 3.1415926535897 / 2;
	valuePrediction2 = 3.1415926535897 / 2;
	std::cout << "TEST #22: doubleVecFAngleBetween3D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << ", " << valuePrediction2 << std::endl;
	doubleVecFAngleBetween3D(arg1, arg2, valueResult, valueResult2);
	result = (valueResult == valuePrediction) && (valueResult2 == valuePrediction2);
	if (!result)
	{
		std::cout << "Failed. Computed value: valueResult1 = " << valueResult << ", valueResult2 = " << valueResult2 << std::endl;
		return false;
	}

	// TEST #23
	arg1 = DoubleVectorF(1, 2, 0, 4, 1, 2, 0, 4).normalized3D();
	arg2 = DoubleVectorF(2, -1, 0, 8, 2, -1, 0, 8).normalized3D();
	valuePrediction = 3.1415926535897 / 2;
	valuePrediction2 = 3.1415926535897 / 2;
	std::cout << "TEST #23: doubleVecFAngleBetweenNormals3D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << ", " << valuePrediction2 << std::endl;
	doubleVecFAngleBetweenNormals3D(arg1, arg2, valueResult, valueResult2);
	result = (valueResult == valuePrediction) && (valueResult2 == valuePrediction2);
	if (!result)
	{
		std::cout << "Failed. Computed value: valueResult1 = " << valueResult << ", valueResult2 = " << valueResult2 << std::endl;
		return false;
	}

	// TEST #24
	arg1 = DoubleVectorF(0, 0, 0, 4, 0, 0, 0, 4);
	arg2 = DoubleVectorF(2, 2, 2, 8, 2, 2, 2, 8);
	arg3 = DoubleVectorF(0, 1, 1, 9, 0, 1, 1, 9);
	valuePrediction = 0.81649658092772;
	valuePrediction2 = 0.81649658092772;
	std::cout << "TEST #24: doubleVecFLinePointDistance3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << valuePrediction << ", " << valuePrediction2 << std::endl;
	doubleVecFLinePointDistance3D(arg1, arg2, arg3, valueResult, valueResult2);
	result = (valueResult == valuePrediction) && (valueResult2 == valuePrediction2);
	if (!result)
	{
		std::cout << "Failed. Computed value: valueResult1 = " << valueResult << ", valueResult2 = " << valueResult2 << std::endl;
		return false;
	}

	// TEST #24
	arg1 = DoubleVectorF(3, 3, 3, 4, 3, 3, 3, 4);
	arg2 = DoubleVectorF(2, 2, 2, 8, 2, 2, 2, 8);
	arg3 = DoubleVectorF(4, 4, 4, 9, 4, 4, 4, 9);
	boolPrediction = true;
	boolPrediction2 = true;
	std::cout << "TEST #24: doubleVecFInBound3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << ", " << boolPrediction2 << std::endl;
	doubleVecFInBound3D(arg1, arg2, arg3, boolResult, boolResult2);
	result = (boolResult == boolPrediction) && (boolResult2 == boolPrediction2);
	if (!result)
	{
		std::cout << "Failed. boolResult1 = " << boolResult << ", boolResult2 = " << boolResult2 << std::endl;
		return false;
	}

	// TEST #25
	arg1 = DoubleVectorF(3, 5, 3, 4, 3, 5, 3, 4);
	arg2 = DoubleVectorF(2, 2, 2, 8, 2, 2, 2, 8);
	arg3 = DoubleVectorF(4, 4, 4, 9, 4, 4, 4, 9);
	boolPrediction = false;
	boolPrediction2 = false;
	std::cout << "TEST #25: doubleVecFInBound3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << ", " << boolPrediction2 << std::endl;
	doubleVecFInBound3D(arg1, arg2, arg3, boolResult, boolResult2);
	result = (boolResult == boolPrediction) && (boolResult2 == boolPrediction2);
	if (!result)
	{
		std::cout << "Failed. boolResult1 = " << boolResult << ", boolResult2 = " << boolResult2 << std::endl;
		return false;
	}

	// TEST #26
	arg1 = DoubleVectorF(1, 2, 1, 4, 1, 2, 1, 4);
	arg2 = DoubleVectorF(2, 1, 2, 8, 2, 1, 2, 8);
	vecPrediction = DoubleVectorF(1.33333333, 0.66666666, 1.33333333, FNAN, 1.33333333, 0.66666666, 1.33333333, FNAN);
	std::cout << "TEST #26: doubleVecFProject3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = doubleVecFProject3D(arg1, arg2);
	doubleVecFCmp3D(vecResult, vecPrediction, CMP_EQ, boolResult, boolResult2);
	result = boolResult && boolResult2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	return true;
}

bool VectorFunctionsTester::testDoubleVectorF4D()
{
	return true;
}

/*
bool VectorFunctionsTester::testVectorF()
{
	VectorF arg1, arg2, arg3, arg4, vecResult, vecPrediction;
	float value, valueResult, valuePrediction;
	bool boolResult, boolPrediction;
	bool result;

	// TEST #1
	arg1 = VectorF(1, 2, 3, 14);
	arg2 = VectorF(1, 3, -7, 1);
	valuePrediction = 0;
	std::cout << "TEST #1: vecFDot(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFDot(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #2
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(1, 3, 5, 4);
	vecPrediction = VectorF(1, -2, 1, 0);
	std::cout << "TEST #2: vecFCross3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFCross3D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #3
	arg1 = VectorF(0, 0, 0, 0);
	arg2 = VectorF(2, 2, 0, 0);
	arg3 = VectorF(0, 2, 0, 0);
	arg4 = VectorF(2, 0, 0, 0);
	vecPrediction = VectorF(1, 1, 0, 0);
	std::cout << "TEST #3: vecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #4
	arg1 = VectorF(0, 2, 0, 0);
	arg2 = VectorF(2, 0, 0, 0);
	arg3 = VectorF(0, 0, 0, 0);
	arg4 = VectorF(2, 2, 0, 0);
	vecPrediction = VectorF(1, 1, 0, 0);
	std::cout << "TEST #4: vecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #5
	arg1 = VectorF(0, 0, 0, 0);
	arg2 = VectorF(2, 2, 0, 0);
	arg3 = VectorF(3, 2, 0, 0);
	arg4 = VectorF(5, 0, 0, 0);
	vecPrediction = VectorF(2.5, 2.5, 0, 0);
	std::cout << "TEST #5: vecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #6
	arg1 = VectorF(0, 0, 0, 0);
	arg2 = VectorF(2, 2, 0, 0);
	arg3 = VectorF(-3, 2, 0, 0);
	arg4 = VectorF(-1, 0, 0, 0);
	vecPrediction = VectorF(-0.5, -0.5, 0, 0);
	std::cout << "TEST #6: vecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #7
	arg1 = VectorF(0, 0, 0, 0);
	arg2 = VectorF(2, 2, 0, 0);
	arg3 = VectorF(1, 0, 0, 0);
	arg4 = VectorF(3, 2, 0, 0);
	vecPrediction = VectorF(INFINITY, INFINITY, INFINITY, 0);
	std::cout << "TEST #7: vecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #8
	arg1 = VectorF(0, 0, 0, 0);
	arg2 = VectorF(2, 2, 0, 0);
	arg3 = VectorF(0, 0, 0, 0);
	arg4 = VectorF(2, 2, 0, 0);
	vecPrediction = VectorF(INFINITY, INFINITY, INFINITY, 0);
	std::cout << "TEST #8: vecFIntersectLines3D(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vecFIntersectLines3D(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #9
	arg1 = VectorF(1, 2, 1, 3);
	arg2 = VectorF(0, 0, 0, 3);
	vecPrediction = VectorF(0, 0, 0, 3);
	std::cout << "TEST #9: vecFProject(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFProject(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #10
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(2, 3, 7, 5);
	valuePrediction = sqrtf(19);
	std::cout << "TEST #10: vecFDistance(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFDistance(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #11
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(2, 1, 0, 8);
	vecPrediction = VectorF(1, 1, 0, 4);
	std::cout << "TEST #11: vecFMin(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFMin(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #12
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(2, 1, 0, 8);
	vecPrediction = VectorF(2, 2, 3, 8);
	std::cout << "TEST #12: vecFMax(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFMax(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #13
	arg1 = VectorF(1, -2, 5, 7);
	arg2 = VectorF(0, 1, 2, 9);
	vecPrediction = VectorF(1, -144, -279, -1271);
	std::cout << "TEST #13: vecFReflect(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFReflect(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #14
	arg1 = VectorF(1, -2, 3, 13);
	arg2 = VectorF(0, 1, 5, 6);
	value = 1;
	vecPrediction = VectorF(1, -184, -907, -1079);
	vecResult = vecFRefract(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #15
	arg1 = VectorF(1, -2, 3, 13);
	arg2 = VectorF(0, 1, 5, 6);
	value = 0.5;
	vecPrediction = VectorF(0.5, -92.0082397, -453.541199, -539.549438);
	std::cout << "TEST #15: vecFRefract(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vecFRefract(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #16
	arg1 = VectorF(2, 3, 4, 5);
	arg2 = VectorF(2, 3, 4, 2);
	vecPrediction = VectorF(4, 27, 256, 25);
	std::cout << "TEST #16: vecFPow(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFPow(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #17
	arg1 = VectorF(2, 3, 4, 1);
	value = 4;
	vecPrediction = VectorF(16, 81, 256, 1);
	std::cout << "TEST #17: vecFPow(" << arg1 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vecFPow(arg1, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #18
	arg1 = VectorF(100, 20, 500, 1);
	arg2 = VectorF(20, 200, 0, 1);
	value = 0.7;
	vecPrediction = VectorF(76, 74, 350, 1);
	std::cout << "TEST #18: vecFLerp(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vecFLerp(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #19
	arg1 = VectorF(100, 20, 0, 3);
	arg2 = VectorF(20, 200, 0, 5);
	value = 0.7;
	vecPrediction = VectorF(76, 74, 0, 3.6);
	std::cout << "TEST #19: vecFLerp(" << arg1 << ", " << arg2 << ", " << value << ") == " << vecPrediction << std::endl;
	vecResult = vecFLerp(arg1, arg2, value);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #20
	arg1 = VectorF(1, 2, 0, 0);
	arg2 = VectorF(-2, 1, 0, 0);
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #20: vecFAngleBetween(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFAngleBetween(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #21
	arg1 = VectorF(1, 2, 0, 0);
	arg2 = VectorF(2, -1, 0, 0);
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #21: vecFAngleBetween(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFAngleBetween(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #22
	arg1 = VectorF(2, 0, 1, 2);
	arg2 = VectorF(0, 0, 0, 3);
	arg3 = VectorF(1, 2, 1, 4);
	valuePrediction = 2.04939015319192;
	std::cout << "TEST #22: vecFLinePointDistance3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << valuePrediction << std::endl;
	valueResult = vecFLinePointDistance3D(arg1, arg2, arg3);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #23
	arg1 = VectorF(0, 0, 0, 2);
	arg2 = VectorF(2, 2, 2, 3);
	arg3 = VectorF(0, 1, 1, 4);
	valuePrediction = 0.81649658092772;
	std::cout << "TEST #23: vecFLinePointDistance3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << valuePrediction << std::endl;
	valueResult = vecFLinePointDistance3D(arg1, arg2, arg3);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #24
	arg1 = VectorF(2, 2, 2, 2);
	arg2 = VectorF(0, 0, 0, 0);
	arg3 = VectorF(3, 3, 3, 3);
	boolPrediction = true;
	std::cout << "TEST #24: vecFInBound(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << std::endl;
	boolResult = vecFInBound(arg1, arg2, arg3);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #25
	arg1 = VectorF(2, 2, 2, 3);
	arg2 = VectorF(0, 0, 0, 4);
	arg3 = VectorF(3, 3, 3, 3);
	boolPrediction = false;
	std::cout << "TEST #25: vecFInBound(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << boolPrediction << std::endl;
	boolResult = vecFInBound(arg1, arg2, arg3);
	result = boolResult == boolPrediction;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #26
	arg1 = VectorF(1, 2, 0, 0).normalized();
	arg2 = VectorF(-2, 1, 0, 0).normalized();
	valuePrediction = 3.1415926535897 / 2;
	std::cout << "TEST #26: vecFAngleBetweenNormals(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFAngleBetweenNormals(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #27
	arg1 = VectorF(1, -2, 3, 13);
	arg2 = VectorF(0, 1, 5, 6);
	arg3 = VectorF(0.5);
	vecPrediction = VectorF(0.5, -92.0082397, -453.541199, -539.549438);
	std::cout << "TEST #27: vecFRefractVec(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = vecFRefractVec(arg1, arg2, arg3);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #28
	arg1 = VectorF(100, 20, 0, 3);
	arg2 = VectorF(20, 200, 0, 5);
	arg3 = VectorF(0.7);
	vecPrediction = VectorF(76, 74, 0, 3.6);
	std::cout << "TEST #28: vecFLerpVec(" << arg1 << ", " << arg2 << ", " << arg3  << ") == " << vecPrediction << std::endl;
	vecResult = vecFLerpVec(arg1, arg2, arg3);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #29
	arg1 = VectorF(1, 2, 3, 12);
	arg2 = VectorF(1, 3, -7, 1);
	vecPrediction = VectorF(-2);
	std::cout << "TEST #29: vecFDotVec(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFDotVec(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #30
	arg1 = VectorF(2, 0, 1, 2);
	arg2 = VectorF(0, 0, 0, 3);
	arg3 = VectorF(1, 2, 1, 4);
	vecPrediction = VectorF(2.04939015319192);
	std::cout << "TEST #30: vecFLinePointDistanceVec3D(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << vecPrediction << std::endl;
	vecResult = vecFLinePointDistanceVec3D(arg1, arg2, arg3);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #31
	arg1 = VectorF(1, 2, 0, 0);
	arg2 = VectorF(2, -1, 0, 0);
	vecPrediction = VectorF(3.1415926535897 / 2);
	std::cout << "TEST #31: vecFAngleBetweenVec(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFAngleBetweenVec(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #32
	arg1 = VectorF(1, 2, 0, 0).normalized();
	arg2 = VectorF(-2, 1, 0, 0).normalized();
	vecPrediction = VectorF(3.1415926535897 / 2);
	std::cout << "TEST #32: vecFAngleBetweenNormalsVec(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFAngleBetweenNormalsVec(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #33
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(2, 3, 7, 5);
	vecPrediction = VectorF(sqrtf(19));
	std::cout << "TEST #33: vecFDistanceVec(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFDistanceVec(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #34
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(2, 3, 7, 5);
	vecPrediction = VectorF(29);
	std::cout << "TEST #34: vecFDotVec3D(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vecFDotVec3D(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #35
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(2, 3, 7, 5);
	valuePrediction = 29;
	std::cout << "TEST #35: vecFDot3D(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
	valueResult = vecFDot3D(arg1, arg2);
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	return true;
}
*/
