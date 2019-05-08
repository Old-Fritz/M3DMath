#include "MathTests.h"

using namespace M3DM;

bool Vector4Tester::testAll()
{
	bool result;
	std::cout << "------VECTOR 4 TEST------" << std::endl;
	std::cout << "--Test equal--" << std::endl;
	result = testEqual();
	if (!result)
		return false;

	std::cout << "--Test compare--" << std::endl;
	result = testCmp();
	if (!result)
		return false;

	std::cout << "--Test conversions--" << std::endl;
	result = testConversions();
	if (!result)
		return false;

	std::cout << "--Test add--" << std::endl;
	result = testAdd();
	if (!result)
		return false;

	std::cout << "--Test sub--" << std::endl;
	result = testSub();
	if (!result)
		return false;

	std::cout << "--Test mul--" << std::endl;
	result = testMul();
	if (!result)
		return false;

	std::cout << "--Test div--" << std::endl;
	result = testDiv();
	if (!result)
		return false;

	return true;
}

bool Vector4Tester::testEqual()
{
	Vector4 v1, v2, vecPrecision, resultVec, prediction;
	float precision;
	bool result, resultPrediciton;

	// ==
	// TEST #1
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1, 2, 3, 4);
	resultPrediciton = true;
	std::cout << "TEST #1: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #2
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(2, 2, 3, 4);
	resultPrediciton = false;
	std::cout << "TEST #2: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #3
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1, 3, 3, 4);
	resultPrediciton = false;
	std::cout << "TEST #3: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #4
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1, 2, 4, 4);
	resultPrediciton = false;
	std::cout << "TEST #4: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #5
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1, 2, 3, 5);
	resultPrediciton = false;
	std::cout << "TEST #5: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #6
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(2, 2, 3, 5);
	resultPrediciton = false;
	std::cout << "TEST #6: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// isEqualPrec

	// TEST #7
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1, 2, 3, 4);
	resultPrediciton = true;
	std::cout << "TEST #7: " << v1 << ".isEqualPrec(" << v2 << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #8
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1, 2, 4, 4);
	resultPrediciton = false;
	std::cout << "TEST #8: " << v1 << ".isEqualPrec(" << v2 << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #9
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1, 2, 3, 4);
	precision = 0.00001;
	resultPrediciton = true;
	std::cout << "TEST #9: " << v1 << ".isEqualPrec(" << v2 << ", " << precision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, precision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #10
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1, 2, 3.0001, 4);
	precision = 0.00001;
	resultPrediciton = false;
	std::cout << "TEST #10: " << v1 << ".isEqualPrec(" << v2 << ", " << precision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, precision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #11
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1.000001, 2.000001, 3.000001, 4.000001);
	precision = 0.00001;
	resultPrediciton = true;
	std::cout << "TEST #11: " << v1 << ".isEqualPrec(" << v2 << ", " << precision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, precision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// isEqualPrec (vec)

	// TEST #12
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1.000001, 2.000001, 3.000001, 4.000001);
	vecPrecision = Vector4(0.0001, 0.0001, 0.0001, 0.0001);
	resultPrediciton = true;
	std::cout << "TEST #12: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #13
	v1 = Vector4(1.000001, 2.000001, 3.000001, 4.000001);
	v2 = Vector4(1, 2, 3, 4);
	vecPrecision = Vector4(0.0001, 0.0001, 0.0001, 0.0001);
	resultPrediciton = true;
	std::cout << "TEST #13: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #14
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1.000001, 2.000001, 3.000001, 4.001);
	vecPrecision = Vector4(0.0001, 0.0001, 0.0001, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #14: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #15
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1.001, 2.001, 3.001, 4.001);
	vecPrecision = Vector4(0.0001, 0.0001, 0.0001, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #15: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #16
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1.001, 2.001, 3.001, 4.001);
	vecPrecision = Vector4(0.005, 0.0001, 0.0001, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #16: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #17
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1.001, 2.001, 3.001, 4.001);
	vecPrecision = Vector4(0.01, 0.01, -0.01, 0.01);
	resultPrediciton = false;
	std::cout << "TEST #17: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}


	// isEqualVec

	// TEST #18
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1, 2, 3, 4);
	prediction = Vector4(1, 1, 1, 1);
	std::cout << "TEST #18: " << v1 << ".isEqualVec(" << v2 << ") == " << prediction << std::endl;
	resultVec = v1.isEqualVec(v2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #19
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1, 2, 3, 5);
	prediction = Vector4(1, 1, 1, 0);
	std::cout << "TEST #19: " << v1 << ".isEqualVec(" << v2 << ") == " << prediction << std::endl;
	resultVec = v1.isEqualVec(v2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #20
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(2, 3, 4, 5);
	prediction = Vector4(0, 0, 0, 0);
	std::cout << "TEST #20: " << v1 << ".isEqualVec(" << v2 << ") == " << prediction << std::endl;
	resultVec = v1.isEqualVec(v2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// isEqualPrecVec

	// TEST #21
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1, 2, 3, 4);
	vecPrecision = Vector4(0.0001, 0.0001, 0.0001, 0.0001);
	prediction = Vector4(1, 1, 1, 1);
	resultPrediciton = true;
	std::cout << "TEST #21: " << v1 << ".isEqualPrecVec(" << v2 << ", " << vecPrecision <<  ") == " << prediction << std::endl;
	resultVec = v1.isEqualPrecVec(v2, vecPrecision);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}



	// TEST #22
	v1 = Vector4(1, 2, 3, 4);
	v2 = Vector4(1.0000001, 2.001, 2.99, 4);
	vecPrecision = Vector4(0.0001, 0.0001, 0.0001, 0.0001);
	prediction = Vector4(1, 0, 0, 1);
	resultPrediciton = true;
	std::cout << "TEST #22: " << v1 << ".isEqualPrecVec(" << v2 << ", " << vecPrecision << ") == " << prediction << std::endl;
	resultVec = v1.isEqualPrecVec(v2, vecPrecision);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	return true;
}

bool Vector4Tester::testCmp()
{
	// TODO: make this tests
	return true;
}

bool Vector4Tester::testConversions()
{
	float pArray[4], pArrayPrediction[4];
	float* pArrayRes;
	Vector2 vec2;
	Vector3 vec3;
	Vector4 resultVec;
	Vector4 prediction;
	bool result;

	// TEST #1
	pArray[0] = 1;
	pArray[1] = 2;
	pArray[2] = 3;
	pArray[3] = 4;
	prediction = Vector4(1, 2, 3, 4);
	std::cout << "TEST #1: Vector4({" << pArray[0] << ", " << pArray[1] << ", " << pArray[2] << ", " << pArray[3] << "}) == " << prediction << std::endl;
	resultVec = Vector4(pArray);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	vec2 = Vector2(1, 2);
	prediction = Vector4(1, 2, 0, 0);
	std::cout << "TEST #2: Vector4(" << vec2 << ") == " << prediction << std::endl;
	resultVec = Vector4(vec2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #3
	vec3 = Vector3(1, 2, 3);
	prediction = Vector4(1, 2, 3, 0);
	std::cout << "TEST #3: Vector4(" << vec3 << ") == " << prediction << std::endl;
	resultVec = Vector4(vec3);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #4
	resultVec = Vector4(1, 2, 3, 4);
	pArrayPrediction[0] = 1;
	pArrayPrediction[1] = 2;
	pArrayPrediction[2] = 3;
	pArrayPrediction[3] = 4;
	std::cout << "TEST #4: float*(" << resultVec << ") == {" << pArrayPrediction[0] << ", " << pArrayPrediction[1] << ", " << pArrayPrediction[2] << ", " << pArrayPrediction[3] << "}" << std::endl;
	pArrayRes = resultVec;
	result = pArrayRes[0] == pArrayPrediction[0] && pArrayRes[1] == pArrayPrediction[1] && pArrayRes[2] == pArrayPrediction[2] && pArrayRes[3] == pArrayPrediction[3];
	if (!result)
	{
		std::cout << "Failed. Computed value: {" << pArrayRes[0] << ", " << pArrayRes[1] << ", " << pArrayRes[2] << ", " << pArrayRes[3] << "}" << std::endl;
		return false;
	}

	return true;
}

bool Vector4Tester::testAdd()
{
	Vector4 arg1, arg2, prediction, resultVec;
	bool result;

	// TEST #1
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector4(2, 3, 4, 5);
	prediction = Vector4(3, 5, 7, 9);
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
	arg2 = Vector4(2, 3, 4, 5);
	prediction = Vector4(3, 5, 7, 9);
	std::cout << "TEST #2: " << arg1 << " += " << arg2 << " == " << prediction << std::endl;
	arg1 += arg2;
	result = arg1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << arg1 << std::endl;
		return false;
	}

	return true;
}

bool Vector4Tester::testSub()
{
	Vector4 arg1, arg2, prediction, resultVec;
	bool result;

	// TEST #1
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector4(2, 3, 4, 5);
	prediction = Vector4(-1, -1, -1, -1);
	std::cout << "TEST #1: " << arg1 << " - " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 - arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector4(2, 3, 4, 5);
	prediction = Vector4(-1, -1, -1, -1);
	std::cout << "TEST #2: " << arg1 << " -= " << arg2 << " == " << prediction << std::endl;
	arg1 -= arg2;
	result = arg1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << arg1 << std::endl;
		return false;
	}

	return true;
}

bool Vector4Tester::testMul()
{
	Vector4 arg1, arg2, prediction, resultVec;
	bool result;

	// TEST #1
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector4(2, 3, 4, 5);
	prediction = Vector4(2, 6, 12, 20);
	std::cout << "TEST #1: " << arg1 << " * " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 * arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector4(2, 3, 4, 5);
	prediction = Vector4(2, 6, 12, 20);
	std::cout << "TEST #2: " << arg1 << " *= " << arg2 << " == " << prediction << std::endl;
	arg1 *= arg2;
	result = arg1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << arg1 << std::endl;
		return false;
	}

	return true;
}

bool Vector4Tester::testDiv()
{
	Vector4 arg1, arg2, prediction, resultVec;
	bool result;

	// TEST #1
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector4(2, 3, 4, 5);
	prediction = Vector4(0.5, 0.666666666, 0.75, 0.8);
	std::cout << "TEST #1: " << arg1 << " / " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 / arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector4(1, 2, 3, 4);
	arg2 = Vector4(2, 3, 4, 5);
	prediction = Vector4(0.5, 0.666666666, 0.75, 0.8);
	std::cout << "TEST #2: " << arg1 << " /= " << arg2 << " == " << prediction << std::endl;
	arg1 /= arg2;
	result = arg1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << arg1 << std::endl;
		return false;
	}

	return true;
}