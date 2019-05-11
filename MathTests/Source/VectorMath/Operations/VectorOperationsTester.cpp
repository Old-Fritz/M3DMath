#include "MathTests.h"

using namespace M3DM;

bool VectorOperationsTester::testAll()
{
	bool result;
	std::cout << "------VECTOR OPERATIONS TEST------" << std::endl;
	std::cout << "--Test Vector2 and Vector3--" << std::endl;
	result = testVector2And3();
	if (!result)
		return false;

	std::cout << "--Test Vector2 and Vector4--" << std::endl;
	result = testVector2And4();
	if (!result)
		return false;

	std::cout << "--Test Vector3 and Vector4--" << std::endl;
	result = testVector3And4();
	if (!result)
		return false;

	std::cout << "--Test Scalar operations--" << std::endl;
	result = testScalarOperations();
	if (!result)
		return false;


	return true;
}

bool VectorOperationsTester::testVector2And3()
{
	Vector3 arg1, prediction, resultVec;
	Vector2 arg2;
	bool result;

	// TEST #1
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector2(4, 5);
	prediction = Vector3(5, 7, 3);
	std::cout << "TEST #1: " << arg1 << " + " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 + arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector2(4, 5);
	prediction = Vector3(5, 7, 3);
	std::cout << "TEST #2: " << arg2 << " + " << arg1 << " == " << prediction << std::endl;
	resultVec = arg2 + arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #3
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector2(4, 5);
	prediction = Vector3(-3, -3, 3);
	std::cout << "TEST #3: " << arg1 << " - " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 - arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #4
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector2(4, 5);
	prediction = Vector3(3, 3,-3);
	std::cout << "TEST #4: " << arg2 << " - " << arg1 << " == " << prediction << std::endl;
	resultVec = arg2 - arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #5
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector2(4, 5);
	prediction = Vector3(4, 10, 3);
	std::cout << "TEST #5: " << arg1 << " * " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 * arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #6
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector2(4, 5);
	prediction = Vector3(4, 10, 3);
	std::cout << "TEST #6: " << arg2 << " * " << arg1 << " == " << prediction << std::endl;
	resultVec = arg2 * arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #7
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector2(4, 5);
	prediction = Vector3(0.25, 0.4, 3);
	std::cout << "TEST #7: " << arg1 << " / " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 / arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #8
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector2(4, 5);
	prediction = Vector3(4, 2.5, 3);
	std::cout << "TEST #8: " << arg2 << " / " << arg1 << " == " << prediction << std::endl;
	resultVec = arg2 / arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	return true;
}

bool VectorOperationsTester::testVector2And4()
{
	Vector4 arg1, prediction, resultVec;
	Vector2 arg2;
	bool result;

	// TEST #1
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector2(5, 6);
	prediction = Vector4(6, 8, 3, 4);
	std::cout << "TEST #1: " << arg1 << " + " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 + arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector2(5, 6);
	prediction = Vector4(6, 8, 3, 4);
	std::cout << "TEST #2: " << arg2 << " + " << arg1 << " == " << prediction << std::endl;
	resultVec = arg2 + arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #3
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector2(5, 6);
	prediction = Vector4(-4, -4, 3, 4);
	std::cout << "TEST #3: " << arg1 << " - " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 - arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #4
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector2(5, 6);
	prediction = Vector4(4, 4, -3, -4);
	std::cout << "TEST #4: " << arg2 << " - " << arg1 << " == " << prediction << std::endl;
	resultVec = arg2 - arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #5
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector2(5, 6);
	prediction = Vector4(5, 12, 3, 4);
	std::cout << "TEST #5: " << arg1 << " * " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 * arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #6
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector2(5, 6);
	prediction = Vector4(5, 12, 3, 4);
	std::cout << "TEST #6: " << arg2 << " * " << arg1 << " == " << prediction << std::endl;
	resultVec = arg2 * arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #7
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector2(5, 6);
	prediction = Vector4(0.2, 0.3333333333, 3, 4);
	std::cout << "TEST #7: " << arg1 << " / " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 / arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #8
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector2(5, 6);
	prediction = Vector4(5, 3, 3, 4);
	std::cout << "TEST #8: " << arg2 << " / " << arg1 << " == " << prediction << std::endl;
	resultVec = arg2 / arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	return true;
}

bool VectorOperationsTester::testVector3And4()
{
	Vector4 arg1, prediction, resultVec;
	Vector3 arg2;
	bool result;

	// TEST #1
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector3(5, 6, 7);
	prediction = Vector4(6, 8, 10, 4);
	std::cout << "TEST #1: " << arg1 << " + " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 + arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector3(5, 6, 7);
	prediction = Vector4(6, 8, 10, 4);
	std::cout << "TEST #2: " << arg2 << " + " << arg1 << " == " << prediction << std::endl;
	resultVec = arg2 + arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #3
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector3(5, 6, 7);
	prediction = Vector4(-4, -4, -4, 4);
	std::cout << "TEST #3: " << arg1 << " - " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 - arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #4
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector3(5, 6, 7);
	prediction = Vector4(4, 4, 4, -4);
	std::cout << "TEST #4: " << arg2 << " - " << arg1 << " == " << prediction << std::endl;
	resultVec = arg2 - arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #5
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector3(5, 6, 7);
	prediction = Vector4(5, 12, 21, 4);
	std::cout << "TEST #5: " << arg1 << " * " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 * arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #6
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector3(5, 6, 7);
	prediction = Vector4(5, 12, 21, 4);
	std::cout << "TEST #6: " << arg2 << " * " << arg1 << " == " << prediction << std::endl;
	resultVec = arg2 * arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #7
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector3(5, 6, 7);
	prediction = Vector4(0.2, 0.3333333333, 0.428571429, 4);
	std::cout << "TEST #7: " << arg1 << " / " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 / arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #8
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector3(5, 6, 7);
	prediction = Vector4(5, 3, 2.333333333, 4);
	std::cout << "TEST #8: " << arg2 << " / " << arg1 << " == " << prediction << std::endl;
	resultVec = arg2 / arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	return true;
}

bool VectorOperationsTester::testScalarOperations()
{
	Vector2 vec2, predictionVec2, resultVec2;
	Vector3 vec3, predictionVec3, resultVec3;
	Vector4 vec4, predictionVec4, resultVec4;
	float scalar;
	bool result;

	// TEST #1
	vec2 = Vector2(1, 2);
	predictionVec2 = Vector2(10, 20);
	scalar = 10;
	std::cout << "TEST #1: " << scalar << " * " << vec2 << " == " << predictionVec2 << std::endl;
	resultVec2 = scalar * vec2;
	result = resultVec2 == predictionVec2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec2 << std::endl;
		return false;
	}

	// TEST #2
	vec3 = Vector3(1, 2, 3);
	predictionVec3 = Vector3(10, 20, 30);
	scalar = 10;
	std::cout << "TEST #2: " << scalar << " * " << vec3 << " == " << predictionVec3 << std::endl;
	resultVec3 = scalar * vec3;
	result = resultVec3 == predictionVec3;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec3 << std::endl;
		return false;
	}

	// TEST #3
	vec4 = Vector4(1, 2, 3, 4);
	predictionVec4 = Vector4(10, 20, 30, 40);
	scalar = 10;
	std::cout << "TEST #3: " << scalar << " * " << vec4 << " == " << predictionVec4 << std::endl;
	resultVec4 = scalar * vec4;
	result = resultVec4 == predictionVec4;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec4 << std::endl;
		return false;
	}

	// TEST #4
	vec2 = Vector2(1, 2);
	predictionVec2 = Vector2(10, 5);
	scalar = 10;
	std::cout << "TEST #4: " << scalar << " / " << vec2 << " == " << predictionVec2 << std::endl;
	resultVec2 = scalar / vec2;
	result = resultVec2 == predictionVec2;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec2 << std::endl;
		return false;
	}

	// TEST #5
	vec3 = Vector3(1, 2, 3);
	predictionVec3 = Vector3(10, 5, 3.3333333);
	scalar = 10;
	std::cout << "TEST #5: " << scalar << " / " << vec3 << " == " << predictionVec3 << std::endl;
	resultVec3 = scalar / vec3;
	result = resultVec3 == predictionVec3;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec3 << std::endl;
		return false;
	}

	// TEST #6
	vec4 = Vector4(1, 2, 3, 4);
	predictionVec4 = Vector4(10, 5, 3.33333333, 2.5);
	scalar = 10;
	std::cout << "TEST #6: " << scalar << " / " << vec4 << " == " << predictionVec4 << std::endl;
	resultVec4 = scalar / vec4;
	result = resultVec4 == predictionVec4;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec4 << std::endl;
		return false;
	}



	return true;
}

