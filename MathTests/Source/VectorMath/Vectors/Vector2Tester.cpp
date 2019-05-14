#include "MathTests.h"

using namespace M3DM;

bool Vector2Tester::testAll()
{
	bool result;
	std::cout << "------VECTOR 2 TEST------" << std::endl;
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

bool Vector2Tester::testEqual()
{
	Vector2 v1, v2, vecPrecision, resultVec, prediction;
	float precision;
	bool result, resultPrediciton;

	// ==
	// TEST #1
	v1 = Vector2(1, 2);
	v2 = Vector2(1, 2);
	resultPrediciton = true;
	std::cout << "TEST #1: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #2
	v1 = Vector2(1, 2);
	v2 = Vector2(2, 2);
	resultPrediciton = false;
	std::cout << "TEST #2: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #3
	v1 = Vector2(1, 2);
	v2 = Vector2(1, 3);
	resultPrediciton = false;
	std::cout << "TEST #3: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #4
	v1 = Vector2(1, 2);
	v2 = Vector2(2, 3);
	resultPrediciton = false;
	std::cout << "TEST #4: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #5
	v1 = Vector2(1, 2);
	v2 = Vector2(1.0001f, 2);
	resultPrediciton = false;
	std::cout << "TEST #5: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// isEqualPrec

	// TEST #6
	v1 = Vector2(1, 2);
	v2 = Vector2(1, 2);
	resultPrediciton = true;
	std::cout << "TEST #6: " << v1 << ".isEqualPrec(" << v2 << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #7
	v1 = Vector2(1, 2);
	v2 = Vector2(1, 3);
	resultPrediciton = false;
	std::cout << "TEST #7: " << v1 << ".isEqualPrec(" << v2 << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #8
	v1 = Vector2(1, 2);
	v2 = Vector2(1, 2);
	precision = 0.00001;
	resultPrediciton = true;
	std::cout << "TEST #8: " << v1 << ".isEqualPrec(" << v2 << ", " << precision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, precision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #9
	v1 = Vector2(1, 2);
	v2 = Vector2(1, 2.0001);
	precision = 0.00001;
	resultPrediciton = false;
	std::cout << "TEST #9: " << v1 << ".isEqualPrec(" << v2 << ", " << precision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, precision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #10
	v1 = Vector2(1, 2);
	v2 = Vector2(1.000001, 2.000001);
	precision = 0.00001;
	resultPrediciton = true;
	std::cout << "TEST #10: " << v1 << ".isEqualPrec(" << v2 << ", " << precision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, precision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// isEqualPrec (vec)

	// TEST #11
	v1 = Vector2(1, 2);
	v2 = Vector2(1.000001, 2.000001);
	vecPrecision = Vector2(0.0001, 0.0001);
	resultPrediciton = true;
	std::cout << "TEST #11: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #12
	v1 = Vector2(1.000001, 2.000001);
	v2 = Vector2(1, 2);
	vecPrecision = Vector2(0.0001, 0.0001);
	resultPrediciton = true;
	std::cout << "TEST #12: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #13
	v1 = Vector2(1, 2);
	v2 = Vector2(1.000001, 2.001);
	vecPrecision = Vector2(0.0001, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #13: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #14
	v1 = Vector2(1, 2);
	v2 = Vector2(1.001, 2.001);
	vecPrecision = Vector2(0.0001, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #14: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #15
	v1 = Vector2(1, 2);
	v2 = Vector2(1.001, 2.001);
	vecPrecision = Vector2(0.005, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #15: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #16
	v1 = Vector2(1, 2);
	v2 = Vector2(1.001, 2.001);
	vecPrecision = Vector2(0.01, -0.01);
	resultPrediciton = false;
	std::cout << "TEST #16: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}


	// isEqualVec

	// TEST #17
	v1 = Vector2(1, 2);
	v2 = Vector2(1, 2);
	prediction = Vector2(1, 1);
	std::cout << "TEST #17: " << v1 << ".isEqualVec(" << v2 << ") == " << prediction << std::endl;
	resultVec = v1.isEqualVec(v2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #18
	v1 = Vector2(1, 2);
	v2 = Vector2(1, 3);
	prediction = Vector2(1, 0);
	std::cout << "TEST #18: " << v1 << ".isEqualVec(" << v2 << ") == " << prediction << std::endl;
	resultVec = v1.isEqualVec(v2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #19
	v1 = Vector2(1, 2);
	v2 = Vector2(2, 3);
	prediction = Vector2(0, 0);
	std::cout << "TEST #19: " << v1 << ".isEqualVec(" << v2 << ") == " << prediction << std::endl;
	resultVec = v1.isEqualVec(v2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// isEqualPrecVec

	// TEST #20
	v1 = Vector2(1, 2);
	v2 = Vector2(1, 2);
	vecPrecision = Vector2(0.0001, 0.0001);
	prediction = Vector2(1, 1);
	resultPrediciton = true;
	std::cout << "TEST #20: " << v1 << ".isEqualPrecVec(" << v2 << ", " << vecPrecision << ") == " << prediction << std::endl;
	resultVec = v1.isEqualPrecVec(v2, vecPrecision);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}



	// TEST #21
	v1 = Vector2(1, 2);
	v2 = Vector2(1.0000001, 2.001);
	vecPrecision = Vector2(0.0001, 0.0001);
	prediction = Vector2(1, 0);
	resultPrediciton = true;
	std::cout << "TEST #21: " << v1 << ".isEqualPrecVec(" << v2 << ", " << vecPrecision << ") == " << prediction << std::endl;
	resultVec = v1.isEqualPrecVec(v2, vecPrecision);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	return true;
}

bool Vector2Tester::testCmp()
{
	Vector2 v1, v2;
	bool result, resultPrediciton;

	// TEST #1
	v1 = Vector2(1.5, 2.5);
	v2 = Vector2(1.5, 2.5);
	resultPrediciton = false;
	std::cout << "TEST #1: " << v1 << " < " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 < v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #2
	v1 = Vector2(1.5, 2.5);
	v2 = Vector2(1.6, 2.6);
	resultPrediciton = true;
	std::cout << "TEST #2: " << v1 << " < " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 < v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #3
	v1 = Vector2(1.5, 2.5);
	v2 = Vector2(1.5, 2.5);
	resultPrediciton = false;
	std::cout << "TEST #3: " << v1 << " > " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 > v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #4
	v1 = Vector2(1.6, 2.6);
	v2 = Vector2(1.5, 2.5);
	resultPrediciton = true;
	std::cout << "TEST #4: " << v1 << " > " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 > v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #5
	v1 = Vector2(1.5, 2.5);
	v2 = Vector2(1.5, 2.5);
	resultPrediciton = true;
	std::cout << "TEST #5: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #6
	v1 = Vector2(1.5, 2.5);
	v2 = Vector2(1.5, 2.5);
	resultPrediciton = true;
	std::cout << "TEST #6: " << v1 << " <= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 <= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #7
	v1 = Vector2(1.4, 2.4);
	v2 = Vector2(1.5, 2.5);
	resultPrediciton = false;
	std::cout << "TEST #7: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #8
	v1 = Vector2(1.4, 2.4);
	v2 = Vector2(1.3, 2.5);
	resultPrediciton = false;
	std::cout << "TEST #8: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #9
	v1 = Vector2(1.4, 2.4);
	v2 = Vector2(1.3, 2.3);
	resultPrediciton = true;
	std::cout << "TEST #9: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #10
	v1 = Vector2(1.4, 2.4);
	v2 = Vector2(1.3, 2.3);
	resultPrediciton = false;
	std::cout << "TEST #10: " << v1 << " <= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 <= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #11
	v1 = Vector2(1.4, 2.4);
	v2 = Vector2(1.3, 2.5);
	resultPrediciton = false;
	std::cout << "TEST #11: " << v1 << " <= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 <= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #12
	v1 = Vector2(1.4, 2.4);
	v2 = Vector2(1.5, 2.5);
	resultPrediciton = true;
	std::cout << "TEST #12: " << v1 << " <= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 <= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	return true;
}

bool Vector2Tester::testConversions()
{
	float pArray[2], pArrayPrediction[2];
	float* pArrayRes;
	Vector3 vec3;
	Vector4 vec4;
	Vector2 resultVec;
	Vector2 prediction;
	bool result;

	// TEST #1
	pArray[0] = 1;
	pArray[1] = 2;
	prediction = Vector2(1, 2);
	std::cout << "TEST #1: Vector2({" << pArray[0] << ", " << pArray[1] << "}) == " << prediction << std::endl;
	resultVec = Vector2(pArray);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	vec3 = Vector3(1, 2, 3);
	prediction = Vector2(1, 2);
	std::cout << "TEST #2: Vector2(" << vec3 << ") == " << prediction << std::endl;
	resultVec = Vector2(vec3);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #3
	vec4 = Vector4(1, 2, 3, 4);
	prediction = Vector2(1, 2);
	std::cout << "TEST #3: Vector2(" << vec4 << ") == " << prediction << std::endl;
	resultVec = Vector2(vec4);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #4
	resultVec = Vector2(1, 2);
	pArrayPrediction[0] = 1;
	pArrayPrediction[1] = 2;
	std::cout << "TEST #4: float*(" << resultVec << ") == {" << pArrayPrediction[0] << ", " << pArrayPrediction[1] << "}" << std::endl;
	pArrayRes = resultVec;
	result = pArrayRes[0] == pArrayPrediction[0] && pArrayRes[1] == pArrayPrediction[1];
	if (!result)
	{
		std::cout << "Failed. Computed value: {" << pArrayRes[0] << ", " << pArrayRes[1] << "}" << std::endl;
		return false;
	}

	return true;
}

bool Vector2Tester::testAdd()
{
	Vector2 arg1, arg2, prediction, resultVec;
	bool result;

	// TEST #1
	arg1 = Vector2(1, 2);
	arg2 = Vector2(2, 3);
	prediction = Vector2(3, 5);
	std::cout << "TEST #1: " << arg1 << " + " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 + arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector2(1, 2);
	arg2 = Vector2(2, 3);
	prediction = Vector2(3, 5);
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

bool Vector2Tester::testSub()
{
	Vector2 arg1, arg2, prediction, resultVec;
	bool result;

	// TEST #1
	arg1 = Vector2(1, 2);
	arg2 = Vector2(2, 3);
	prediction = Vector2(-1, -1);
	std::cout << "TEST #1: " << arg1 << " - " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 - arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector2(1, 2);
	arg2 = Vector2(2, 3);
	prediction = Vector2(-1, -1);
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

bool Vector2Tester::testMul()
{
	Vector2 arg1, arg2, prediction, resultVec;
	bool result;

	// TEST #1
	arg1 = Vector2(1, 2);
	arg2 = Vector2(2, 3);
	prediction = Vector2(2, 6);
	std::cout << "TEST #1: " << arg1 << " * " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 * arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector2(1, 2);
	arg2 = Vector2(2, 3);
	prediction = Vector2(2, 6);
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

bool Vector2Tester::testDiv()
{
	Vector2 arg1, arg2, prediction, resultVec;
	bool result;

	// TEST #1
	arg1 = Vector2(1, 2);
	arg2 = Vector2(2, 3);
	prediction = Vector2(0.5, 0.66666666);
	std::cout << "TEST #1: " << arg1 << " / " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 / arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector2(1, 2);
	arg2 = Vector2(2, 3);
	prediction = Vector2(0.5, 0.66666666);
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








