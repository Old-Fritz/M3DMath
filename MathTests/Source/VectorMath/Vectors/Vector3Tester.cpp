#include "MathTests.h"
#include <cmath>
using namespace M3DM;



Bool Vector3Tester::testAll()
{
	Bool result;
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

	std::cout << "--Test functions--" << std::endl;
	result = testFunctions();
	if (!result)
		return false;

	return true;
}

Bool Vector3Tester::testEqual()
{
	Vector3 v1, v2, vecPrecision, resultVec, prediction;
	Float precision;
	Bool result, resultPrediciton;

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

Bool Vector3Tester::testCmp()
{
	Vector3 v1, v2;
	Bool result, resultPrediciton;

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

Bool Vector3Tester::testConversions()
{
	Float pArray[3], pArrayPrediction[3];
	Float* pArrayRes;
	Float value;
	Vector2 vec2;
	Vector4 vec4;
	Vector3 resultVec;
	Vector3 prediction;
	Bool result;

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
	std::cout << "TEST #4: Float*(" << resultVec << ") == {" << pArrayPrediction[0] << ", " << pArrayPrediction[1] << ", " << pArrayPrediction[2] << "}" << std::endl;
	pArrayRes = resultVec;
	result = pArrayRes[0] == pArrayPrediction[0] && pArrayRes[1] == pArrayPrediction[1] && pArrayRes[2] == pArrayPrediction[2];
	if (!result)
	{
		std::cout << "Failed. Computed value: {" << pArrayRes[0] << ", " << pArrayRes[1] << ", " << pArrayRes[2] << "}" << std::endl;
		return false;
	}

	// TEST #5
	value = 3;
	prediction = Vector3(3, 3, 3);
	std::cout << "TEST #5: Vector3(" << value << ") == " << prediction << std::endl;
	resultVec = Vector3(value);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	return true;
}

Bool Vector3Tester::testAdd()
{
	Vector3 arg1, arg2, prediction, resultVec;
	Bool result;

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

Bool Vector3Tester::testSub()
{
	Vector3 arg1, arg2, prediction, resultVec;
	Bool result;

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

	// TEST #3
	arg1 = Vector3(1, 2, 3);
	prediction = Vector3(-1, -2, -3);
	std::cout << "TEST #3: " << " -" << arg1 << " == " << prediction << std::endl;
	resultVec = -arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	return true;
}

Bool Vector3Tester::testMul()
{
	Vector3 arg1, arg2, prediction, resultVec;
	Float scale;
	Bool result;

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

	// TEST #3
	arg1 = Vector3(1, 2, 3);
	scale = 2;
	prediction = Vector3(2, 4, 6);
	std::cout << "TEST #3: " << arg1 << " * " << scale << " == " << prediction << std::endl;
	resultVec = arg1 * scale;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	return true;
}

Bool Vector3Tester::testDiv()
{
	Vector3 arg1, arg2, prediction, resultVec;
	Float scale;
	Bool result;

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

	// TEST #3
	arg1 = Vector3(1, 2, 3);
	scale = 2;
	prediction = Vector3(0.5, 1, 1.5);
	std::cout << "TEST #3: " << arg1 << " / " << scale << " == " << prediction << std::endl;
	resultVec = arg1 / scale;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	return true;
}

Bool Vector3Tester::testFunctions()
{
	Vector3 vec, vecPrediction, vecPrediction2, vecResult, vecResult2;
	Float value, valueResult, valuePrediction;
	Bool result;

	// TEST #1
	vec = Vector3(1, 2, 3);
	valuePrediction = 3.7416573867f;
	std::cout << "TEST #1: " << vec << ".length()" << " == " << valuePrediction << std::endl;
	valueResult = vec.length();
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #2
	vec = Vector3(1, 2, 3);
	valuePrediction = 14;
	std::cout << "TEST #2: " << vec << ".sqrLength()" << " == " << valuePrediction << std::endl;
	valueResult = vec.sqrLength();
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #3
	vec = Vector3(1, 2, 3);
	vecPrediction = Vector3(1 / 3.7416573867f, 2 / 3.7416573867f, 3 / 3.7416573867f);
	std::cout << "TEST #3: " << vec << ".normalized()" << " == " << vecPrediction << std::endl;
	vecResult = vec.normalized();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #4
	vec = Vector3(-3, 4, -5);
	vecPrediction = Vector3(3, 4, 5);
	std::cout << "TEST #4: " << vec << ".abs()" << " == " << vecPrediction << std::endl;
	vecResult = vec.abs();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #5
	vec = Vector3(3.1, 4.7, 5.2);
	vecPrediction = Vector3(3, 4, 5);
	std::cout << "TEST #5: " << vec << ".floor()" << " == " << vecPrediction << std::endl;
	vecResult = vec.floor();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #6
	vec = Vector3(3.7, 4.1, 5.6);
	vecPrediction = Vector3(3, 4, 5);
	std::cout << "TEST #6: " << vec << ".floor()" << " == " << vecPrediction << std::endl;
	vecResult = vec.floor();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #7
	vec = Vector3(3.1, 4.7, 5.2);
	vecPrediction = Vector3(4, 5, 6);
	std::cout << "TEST #7: " << vec << ".ceil()" << " == " << vecPrediction << std::endl;
	vecResult = vec.ceil();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #8
	vec = Vector3(3.7, 4.1, 5.6);
	vecPrediction = Vector3(4, 5, 6);
	std::cout << "TEST #8: " << vec << ".ceil()" << " == " << vecPrediction << std::endl;
	vecResult = vec.ceil();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #9
	vec = Vector3(3.1, 4.7, 5.2);
	vecPrediction = Vector3(3, 5, 5);
	std::cout << "TEST #9: " << vec << ".round()" << " == " << vecPrediction << std::endl;
	vecResult = vec.round();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #10
	vec = Vector3(3.7, 4.1, 5.6);
	vecPrediction = Vector3(4, 4, 6);
	std::cout << "TEST #10: " << vec << ".round()" << " == " << vecPrediction << std::endl;
	vecResult = vec.round();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #11
	vec = Vector3(2, 4, 8);
	vecPrediction = Vector3(0.5, 0.25, 0.125);
	std::cout << "TEST #11: " << vec << ".reciprocal()" << " == " << vecPrediction << std::endl;
	vecResult = vec.reciprocal();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #12
	vec = Vector3(0.4, 6, 3);
	vecPrediction = Vector3(0.4, 1, 1);
	std::cout << "TEST #12: " << vec << ".saturate()" << " == " << vecPrediction << std::endl;
	vecResult = vec.saturate();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #13
	vec = Vector3(-5, 0.7, 0.3);
	vecPrediction = Vector3(0, 0.7, 0.3);
	std::cout << "TEST #13: " << vec << ".saturate()" << " == " << vecPrediction << std::endl;
	vecResult = vec.saturate();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #14
	vec = Vector3(4, 9, 16);
	vecPrediction = Vector3(2, 3, 4);
	std::cout << "TEST #14: " << vec << ".sqrt()" << " == " << vecPrediction << std::endl;
	vecResult = vec.sqrt();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}


	// TEST #15
	vec = Vector3(4, -9, 34);
	vecPrediction = Vector3(sinf(4), sinf(-9), sinf(34));
	std::cout << "TEST #15: " << vec << ".sin()" << " == " << vecPrediction << std::endl;
	vecResult = vec.sin();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #16
	vec = Vector3(4, -9, 34);
	vecPrediction = Vector3(cosf(4), cosf(-9), cosf(34));
	std::cout << "TEST #16: " << vec << ".cos()" << " == " << vecPrediction << std::endl;
	vecResult = vec.cos();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #17
	vec = Vector3(4, -9, 34);
	vecPrediction = Vector3(tanf(4), tanf(-9), tanf(34));
	std::cout << "TEST #17: " << vec << ".tan()" << " == " << vecPrediction << std::endl;
	vecResult = vec.tan();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #18
	vec = Vector3(0.4, -0.6, 0.34);
	vecPrediction = Vector3(asinf(0.4), asinf(-0.6), asinf(0.34));
	std::cout << "TEST #18: " << vec << ".asin()" << " == " << vecPrediction << std::endl;
	vecResult = vec.asin();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #19
	vec = Vector3(0.4, -0.6, 0.34);
	vecPrediction = Vector3(acosf(0.4), acosf(-0.6), acosf(0.34));
	std::cout << "TEST #19: " << vec << ".acos()" << " == " << vecPrediction << std::endl;
	vecResult = vec.acos();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #20
	vec = Vector3(0.4, -0.6, 0.34);
	vecPrediction = Vector3(atanf(0.4), atanf(-0.6), atanf(0.34));
	std::cout << "TEST #20: " << vec << ".atan()" << " == " << vecPrediction << std::endl;
	vecResult = vec.atan();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #21
	vec = Vector3(1, 2, 3);
	vecPrediction = Vector3(exp2f(1), exp2f(2),exp2f(3));
	std::cout << "TEST #21: " << vec << ".exp2()" << " == " << vecPrediction << std::endl;
	vecResult = vec.exp2();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #22
	vec = Vector3(1, 2, 3);
	vecPrediction = Vector3(expf(1), expf(2), expf(3));
	std::cout << "TEST #22: " << vec << ".expE()" << " == " << vecPrediction << std::endl;
	vecResult = vec.expE();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #23
	vec = Vector3(1, 2, 3);
	vecPrediction = Vector3(log2f(1), log2f(2), log2f(3));
	std::cout << "TEST #23: " << vec << ".log2()" << " == " << vecPrediction << std::endl;
	vecResult = vec.log2();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #24
	vec = Vector3(1, 2, 3);
	vecPrediction = Vector3(logf(1), logf(2), logf(3));
	std::cout << "TEST #24: " << vec << ".logE()" << " == " << vecPrediction << std::endl;
	vecResult = vec.logE();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #25
	vec = Vector3(1, 2, 3);
	vecPrediction = Vector3(sinf(1), sinf(2), sinf(3));
	vecPrediction2 = Vector3(cosf(1), cosf(2), cosf(3));
	std::cout << "TEST #25: " << vec << ".sincos()" << " == " << vecPrediction << ", " << vecPrediction2 << std::endl;
	vec.sincos(vecResult, vecResult2);
	result = vecResult == vecPrediction && vecResult2 == vecPrediction2;
	if (!result)
	{
		std::cout << "Failed. Computed value: vecResult = " << vecResult << "; vecResult2 = " << vecResult2 << std::endl;
		return false;
	}

	// TEST #27
	vec = Vector3(1, -1, 0);
	vecPrediction = Vector3(1, 1, 1);
	std::cout << "TEST #27: " << vec << ".orthogonal()" << " == " << vecPrediction << std::endl;
	vecResult = vec.orthogonal();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	return true;
}