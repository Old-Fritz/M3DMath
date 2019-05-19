#include "MathTests.h"
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
	std::cout << "TEST #16: vec3Pow(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
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
	std::cout << "TEST #16: vec3Pow(" << arg1 << ", " << value << ") == " << vecPrediction << std::endl;
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
	vecPrediction = Vector2(76, 74);
	std::cout << "TEST #18: vec2Lerp(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
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
	std::cout << "TEST #22: vec3LinePointDistance(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << valuePrediction << std::endl;
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
	std::cout << "TEST #23: vec3LinePointDistance(" << arg1 << ", " << arg2 << ", " << arg3 << ") == " << valuePrediction << std::endl;
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
	std::cout << "TEST #1: vec2Dot(" << arg1 << ", " << arg2 << ") == " << valuePrediction << std::endl;
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
	//XMStoreFloat3((XMFLOAT3*)static_cast<const float*>(vecPrediction),
	//	XMVector3Cross(XMLoadFloat3((XMFLOAT3*)static_cast<const float*>(arg1)),
	//		XMLoadFloat3((XMFLOAT3*)static_cast<const float*>(arg2))));
	std::cout << "TEST #2: vec3Cross(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
	vecResult = vec3Cross(arg1, arg2);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #3
	arg1 = Vector3(0, 0);
	arg2 = Vector3(2, 2);
	arg3 = Vector3(0, 2);
	arg4 = Vector3(2, 0);
	vecPrediction = Vector3(1, 1);
	std::cout << "TEST #3: vec3IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec3IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #4
	arg1 = Vector3(0, 2);
	arg2 = Vector3(2, 0);
	arg3 = Vector3(0, 0);
	arg4 = Vector3(2, 2);
	vecPrediction = Vector3(1, 1);
	std::cout << "TEST #4: vec3IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec3IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #5
	arg1 = Vector3(0, 0);
	arg2 = Vector3(2, 2);
	arg3 = Vector3(3, 2);
	arg4 = Vector3(5, 0);
	vecPrediction = Vector3(2.5, 2.5);
	std::cout << "TEST #5: vec3IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec3IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #6
	arg1 = Vector3(0, 0);
	arg2 = Vector3(2, 2);
	arg3 = Vector3(-3, 2);
	arg4 = Vector3(-1, 0);
	vecPrediction = Vector3(-0.5, -0.5);
	std::cout << "TEST #6: vec3IntersectLines(" << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ") == " << vecPrediction << std::endl;
	vecResult = vec3IntersectLines(arg1, arg2, arg3, arg4);
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #7
	arg1 = Vector3(0, 0);
	arg2 = Vector3(2, 2);
	arg3 = Vector3(1, 0);
	arg4 = Vector3(3, 2);
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
	arg1 = Vector3(0, 0);
	arg2 = Vector3(2, 2);
	arg3 = Vector3(0, 0);
	arg4 = Vector3(2, 2);
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
	std::cout << "TEST #16: vec3Pow(" << arg1 << ", " << value << ") == " << vecPrediction << std::endl;
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
	vecPrediction = Vector3(76, 74, 0);
	std::cout << "TEST #18: vec3Lerp(" << arg1 << ", " << arg2 << ") == " << vecPrediction << std::endl;
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