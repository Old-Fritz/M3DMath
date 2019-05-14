#include "MathTests.h"

using namespace M3DM; 



bool Vector3Tester::testAll()
{
	bool result;
	std::cout << "------VECTOR 3 TEST------" << std::endl;
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

bool Vector3Tester::testEqual()
{
	Vector3 v1, v2, vecPrecision, resultVec, prediction;
	float precision;
	bool result, resultPrediciton;

	// ==
	// TEST #1
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1, 2, 3);
	resultPrediciton = true;
	std::cout << "TEST #1: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #2
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(2, 2, 3);
	resultPrediciton = false;
	std::cout << "TEST #2: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #3
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1, 3, 3);
	resultPrediciton = false;
	std::cout << "TEST #3: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #4
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1, 2, 4);
	resultPrediciton = false;
	std::cout << "TEST #4: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #5
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(2, 2, 4);
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
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1, 2, 3);
	resultPrediciton = true;
	std::cout << "TEST #6: " << v1 << ".isEqualPrec(" << v2 << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #7
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1, 2, 4);
	resultPrediciton = false;
	std::cout << "TEST #7: " << v1 << ".isEqualPrec(" << v2 << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #8
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1, 2, 3);
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
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1, 2, 3.0001);
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
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1.000001, 2.000001, 3.000001);
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
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1.000001, 2.000001, 3.000001);
	vecPrecision = Vector3(0.0001, 0.0001, 0.0001);
	resultPrediciton = true;
	std::cout << "TEST #11: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #12
	v1 = Vector3(1.000001, 2.000001, 3.000001);
	v2 = Vector3(1, 2, 3);
	vecPrecision = Vector3(0.0001, 0.0001, 0.0001);
	resultPrediciton = true;
	std::cout << "TEST #12: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #13
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1.000001, 2.000001, 3.001);
	vecPrecision = Vector3(0.0001, 0.0001, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #13: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #14
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1.001, 2.001, 3.001);
	vecPrecision = Vector3(0.0001, 0.0001, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #14: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #15
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1.001, 2.001, 3.001);
	vecPrecision = Vector3(0.005, 0.0001, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #15: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #16
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1.001, 2.001, 3.001);
	vecPrecision = Vector3(0.01, 0.01, -0.01);
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
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1, 2, 3);
	prediction = Vector3(1, 1, 1);
	std::cout << "TEST #17: " << v1 << ".isEqualVec(" << v2 << ") == " << prediction << std::endl;
	resultVec = v1.isEqualVec(v2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #18
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1, 2, 4);
	prediction = Vector3(1, 1, 0);
	std::cout << "TEST #18: " << v1 << ".isEqualVec(" << v2 << ") == " << prediction << std::endl;
	resultVec = v1.isEqualVec(v2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #19
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(2, 3, 4);
	prediction = Vector3(0, 0, 0);
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
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1, 2, 3);
	vecPrecision = Vector3(0.0001, 0.0001, 0.0001);
	prediction = Vector3(1, 1, 1);
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
	v1 = Vector3(1, 2, 3);
	v2 = Vector3(1.0000001, 2.001, 2.99);
	vecPrecision = Vector3(0.0001, 0.0001, 0.0001);
	prediction = Vector3(1, 0, 0);
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

bool Vector3Tester::testCmp()
{
	Vector3 v1, v2;
	bool result, resultPrediciton;

	// TEST #1
	v1 = Vector3(1.5, 2.5, 3.5);
	v2 = Vector3(1.5, 2.5, 3.5);
	resultPrediciton = false;
	std::cout << "TEST #1: " << v1 << " < " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 < v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #2
	v1 = Vector3(1.5, 2.5, 3.5);
	v2 = Vector3(1.6, 2.6, 3.6);
	resultPrediciton = true;
	std::cout << "TEST #2: " << v1 << " < " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 < v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #3
	v1 = Vector3(1.5, 2.5, 3.5);
	v2 = Vector3(1.5, 2.5, 3.5);
	resultPrediciton = false;
	std::cout << "TEST #3: " << v1 << " > " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 > v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #4
	v1 = Vector3(1.6, 2.6, 3.6);
	v2 = Vector3(1.5, 2.5, 3.5);
	resultPrediciton = true;
	std::cout << "TEST #4: " << v1 << " > " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 > v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #5
	v1 = Vector3(1.5, 2.5, 3.5);
	v2 = Vector3(1.5, 2.5, 3.5);
	resultPrediciton = true;
	std::cout << "TEST #5: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #6
	v1 = Vector3(1.5, 2.5, 3.5);
	v2 = Vector3(1.5, 2.5, 3.5);
	resultPrediciton = true;
	std::cout << "TEST #6: " << v1 << " <= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 <= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #7
	v1 = Vector3(1.4, 2.4, 3.4);
	v2 = Vector3(1.5, 2.5, 3.5);
	resultPrediciton = false;
	std::cout << "TEST #7: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #8
	v1 = Vector3(1.4, 2.4, 3.4);
	v2 = Vector3(1.3, 2.5, 3.5);
	resultPrediciton = false;
	std::cout << "TEST #8: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #9
	v1 = Vector3(1.4, 2.4, 3.4);
	v2 = Vector3(1.3, 2.3, 3.3);
	resultPrediciton = true;
	std::cout << "TEST #9: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #10
	v1 = Vector3(1.4, 2.4, 3.4);
	v2 = Vector3(1.3, 2.3, 3.3);
	resultPrediciton = false;
	std::cout << "TEST #10: " << v1 << " <= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 <= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #11
	v1 = Vector3(1.4, 2.4, 3.4);
	v2 = Vector3(1.3, 2.5, 3.5);
	resultPrediciton = false;
	std::cout << "TEST #11: " << v1 << " <= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 <= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #12
	v1 = Vector3(1.4, 2.4, 3.4);
	v2 = Vector3(1.5, 2.5, 3.5);
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

bool Vector3Tester::testConversions()
{
	float pArray[3], pArrayPrediction[3];
	float* pArrayRes;
	Vector2 vec2;
	Vector4 vec4;
	Vector3 resultVec;
	Vector3 prediction;
	bool result;

	// TEST #1
	pArray[0] = 1;
	pArray[1] = 2;
	pArray[2] = 3;
	prediction = Vector3(1, 2, 3);
	std::cout << "TEST #1: Vector3({" << pArray[0] << ", " << pArray[1] << ", " << pArray[2] << "}) == " << prediction << std::endl;
	resultVec = Vector3(pArray);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	vec2 = Vector2(1, 2);
	prediction = Vector3(1, 2, 0);
	std::cout << "TEST #2: Vector3(" << vec2 << ") == " << prediction << std::endl;
	resultVec = Vector3(vec2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #3
	vec4 = Vector4(1, 2, 3,4);
	prediction = Vector3(1, 2, 3);
	std::cout << "TEST #3: Vector3(" << vec4 << ") == " << prediction << std::endl;
	resultVec = Vector3(vec4);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #4
	resultVec = Vector3(1, 2, 3);
	pArrayPrediction[0] = 1;
	pArrayPrediction[1] = 2;
	pArrayPrediction[2] = 3;
	std::cout << "TEST #4: float*(" << resultVec << ") == {" << pArrayPrediction[0] << ", " << pArrayPrediction[1] << ", " << pArrayPrediction[2] << "}" << std::endl;
	pArrayRes = resultVec;
	result = pArrayRes[0] == pArrayPrediction[0] && pArrayRes[1] == pArrayPrediction[1] && pArrayRes[2] == pArrayPrediction[2];
	if (!result)
	{
		std::cout << "Failed. Computed value: {" << pArrayRes[0] << ", " << pArrayRes[1] << ", " << pArrayRes[2] << "}" << std::endl;
		return false;
	}

	return true;
}

bool Vector3Tester::testAdd()
{
	Vector3 arg1, arg2, prediction, resultVec;
	bool result;

	// TEST #1
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector3(2, 3, 4);
	prediction = Vector3(3, 5, 7);
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
	arg2 = Vector3(2, 3, 4);
	prediction = Vector3(3, 5, 7);
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

bool Vector3Tester::testSub()
{
	Vector3 arg1, arg2, prediction, resultVec;
	bool result;

	// TEST #1
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector3(2, 3, 4);
	prediction = Vector3(-1, -1, -1);
	std::cout << "TEST #1: " << arg1 << " - " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 - arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector3(2, 3, 4);
	prediction = Vector3(-1,-1,-1);
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

bool Vector3Tester::testMul()
{
	Vector3 arg1, arg2, prediction, resultVec;
	bool result;

	// TEST #1
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector3(2, 3, 4);
	prediction = Vector3(2,6,12);
	std::cout << "TEST #1: " << arg1 << " * " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 * arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector3(2, 3, 4);
	prediction = Vector3(2,6,12);
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

bool Vector3Tester::testDiv()
{
	Vector3 arg1, arg2, prediction, resultVec;
	bool result;

	// TEST #1
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector3(2, 3, 4);
	prediction = Vector3(0.5, 0.66666666, 0.75);
	std::cout << "TEST #1: " << arg1 << " / " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 / arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = Vector3(1, 2, 3);
	arg2 = Vector3(2, 3, 4);
	prediction = Vector3(0.5, 0.66666666, 0.75);
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