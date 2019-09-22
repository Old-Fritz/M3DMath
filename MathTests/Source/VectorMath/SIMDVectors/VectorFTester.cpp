#include "MathTests.h"
#include <cmath>

using namespace M3DM;

Bool VectorFTester::testAll()
{
	Bool result;
	std::cout << "------VECTOR SIMD TEST------" << std::endl;
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

	std::cout << "--Test store--" << std::endl;
	result = testStore();
	if (!result)
		return false;

	std::cout << "--Test get and set--" << std::endl;
	result = testGetSet();
	if (!result)
		return false;

	std::cout << "--Test functions--" << std::endl;
	result = testFunctions();
	if (!result)
		return false;

	return true;
}

Bool VectorFTester::testEqual()
{
	VectorF v1, v2, vecPrecision, resultVec, prediction;
	Float precision;
	Bool result, resultPrediciton;

	// ==
	// TEST #1
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1, 2, 3, 4);
	resultPrediciton = true;
	std::cout << "TEST #1: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #2
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(2, 2, 3, 4);
	resultPrediciton = false;
	std::cout << "TEST #2: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #3
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1, 3, 3, 4);
	resultPrediciton = false;
	std::cout << "TEST #3: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #4
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1, 2, 4, 4);
	resultPrediciton = false;
	std::cout << "TEST #4: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #5
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1, 2, 3, 5);
	resultPrediciton = false;
	std::cout << "TEST #5: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #6
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(2, 2, 3, 5);
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
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1, 2, 3, 4);
	resultPrediciton = true;
	std::cout << "TEST #7: " << v1 << ".isEqualPrec(" << v2 << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #8
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1, 2, 4, 4);
	resultPrediciton = false;
	std::cout << "TEST #8: " << v1 << ".isEqualPrec(" << v2 << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #9
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1, 2, 3, 4);
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
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1, 2, 3.0001, 4);
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
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1.000001, 2.000001, 3.000001, 4.000001);
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
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1.000001, 2.000001, 3.000001, 4.000001);
	vecPrecision = VectorF(0.0001, 0.0001, 0.0001, 0.0001);
	resultPrediciton = true;
	std::cout << "TEST #12: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #13
	v1 = VectorF(1.000001, 2.000001, 3.000001, 4.000001);
	v2 = VectorF(1, 2, 3, 4);
	vecPrecision = VectorF(0.0001, 0.0001, 0.0001, 0.0001);
	resultPrediciton = true;
	std::cout << "TEST #13: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #14
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1.000001, 2.000001, 3.000001, 4.001);
	vecPrecision = VectorF(0.0001, 0.0001, 0.0001, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #14: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #15
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1.001, 2.001, 3.001, 4.001);
	vecPrecision = VectorF(0.0001, 0.0001, 0.0001, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #15: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #16
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1.001, 2.001, 3.001, 4.001);
	vecPrecision = VectorF(0.005, 0.0001, 0.0001, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #16: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #17
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1.001, 2.001, 3.001, 4.001);
	vecPrecision = VectorF(0.01, 0.01, -0.01, 0.01);
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
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1, 2, 3, 4);
	prediction = VectorF(FNAN, FNAN, FNAN, FNAN);
	std::cout << "TEST #18: " << v1 << ".isEqualVec(" << v2 << ") == " << prediction << std::endl;
	resultVec = v1.isEqualVec(v2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #19
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1, 2, 3, 5);
	prediction = VectorF(FNAN, FNAN, FNAN, 0);
	std::cout << "TEST #19: " << v1 << ".isEqualVec(" << v2 << ") == " << prediction << std::endl;
	resultVec = v1.isEqualVec(v2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #20
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(2, 3, 4, 5);
	prediction = VectorF(0, 0, 0, 0);
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
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1, 2, 3, 4);
	vecPrecision = VectorF(0.0001, 0.0001, 0.0001, 0.0001);
	prediction = VectorF(FNAN, FNAN, FNAN, FNAN);
	resultPrediciton = true;
	std::cout << "TEST #21: " << v1 << ".isEqualPrecVec(" << v2 << ", " << vecPrecision << ") == " << prediction << std::endl;
	resultVec = v1.isEqualPrecVec(v2, vecPrecision);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}



	// TEST #22
	v1 = VectorF(1, 2, 3, 4);
	v2 = VectorF(1.0000001, 2.001, 2.99, 4);
	vecPrecision = VectorF(0.0001, 0.0001, 0.0001, 0.0001);
	prediction = VectorF(FNAN, 0, 0, FNAN);
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

Bool VectorFTester::testCmp()
{
	VectorF v1, v2;
	Bool result, resultPrediciton;

	// TEST #1
	v1 = VectorF(1.5, 2.5, 3.5, 4.5);
	v2 = VectorF(1.5, 2.5, 3.5, 4.5);
	resultPrediciton = false;
	std::cout << "TEST #1: " << v1 << " < " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 < v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #2
	v1 = VectorF(1.5, 2.5, 3.5, 4.5);
	v2 = VectorF(1.6, 2.6, 3.6, 4.6);
	resultPrediciton = true;
	std::cout << "TEST #2: " << v1 << " < " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 < v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #3
	v1 = VectorF(1.5, 2.5, 3.5, 4.5);
	v2 = VectorF(1.5, 2.5, 3.5, 4.5);
	resultPrediciton = false;
	std::cout << "TEST #3: " << v1 << " > " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 > v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #4
	v1 = VectorF(1.6, 2.6, 3.6, 4.6);
	v2 = VectorF(1.5, 2.5, 3.5, 4.5);
	resultPrediciton = true;
	std::cout << "TEST #4: " << v1 << " > " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 > v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #5
	v1 = VectorF(1.5, 2.5, 3.5, 4.5);
	v2 = VectorF(1.5, 2.5, 3.5, 4.5);
	resultPrediciton = true;
	std::cout << "TEST #5: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #6
	v1 = VectorF(1.5, 2.5, 3.5, 4.5);
	v2 = VectorF(1.5, 2.5, 3.5, 4.5);
	resultPrediciton = true;
	std::cout << "TEST #6: " << v1 << " <= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 <= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #7
	v1 = VectorF(1.4, 2.4, 3.4, 4.4);
	v2 = VectorF(1.5, 2.5, 3.5, 4.5);
	resultPrediciton = false;
	std::cout << "TEST #7: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #8
	v1 = VectorF(1.4, 2.4, 3.4, 4.4);
	v2 = VectorF(1.3, 2.5, 3.5, 4.5);
	resultPrediciton = false;
	std::cout << "TEST #8: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #9
	v1 = VectorF(1.4, 2.4, 3.4, 4.4);
	v2 = VectorF(1.3, 2.3, 3.3, 4.4);
	resultPrediciton = true;
	std::cout << "TEST #9: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #10
	v1 = VectorF(1.4, 2.4, 3.4, 4.4);
	v2 = VectorF(1.3, 2.3, 3.3, 4.3);
	resultPrediciton = false;
	std::cout << "TEST #10: " << v1 << " <= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 <= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #11
	v1 = VectorF(1.4, 2.4, 3.4, 4.4);
	v2 = VectorF(1.3, 2.5, 3.5, 4.5);
	resultPrediciton = false;
	std::cout << "TEST #11: " << v1 << " <= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 <= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #12
	v1 = VectorF(1.4, 2.4, 3.4, 4.4);
	v2 = VectorF(1.5, 2.5, 3.5, 4.5);
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

Bool VectorFTester::testConversions()
{
	ALIGN(16) Float pArray[4];
	ALIGN(16) Float* pArrayRes;
	Float value;
	Vector2 vec21, vec22;
	Vector3 vec3;
	Vector4 vec4;
	VectorF resultVec;
	VectorF prediction;
	Bool result;

	// TEST #1
	pArray[0] = 1;
	pArray[1] = 2;
	pArray[2] = 3;
	pArray[3] = 4;
	prediction = VectorF(1, 2, 3, 4);
	std::cout << "TEST #1: VectorF({" << pArray[0] << ", " << pArray[1] << ", " << pArray[2] << ", " << pArray[3] << "}) == " << prediction << std::endl;
	resultVec = VectorF(pArray);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	vec21 = Vector2(1, 2);
	prediction = VectorF(1, 2, 0, 0);
	std::cout << "TEST #2: VectorF(" << vec21 << ") == " << prediction << std::endl;
	resultVec = VectorF(vec21);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #3
	vec3 = Vector3(1, 2, 3);
	prediction = VectorF(1, 2, 3, 0);
	std::cout << "TEST #3: VectorF(" << vec3 << ") == " << prediction << std::endl;
	resultVec = VectorF(vec3);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #4
	vec4 = Vector4(1, 2, 3, 4);
	prediction = VectorF(1, 2, 3, 4);
	std::cout << "TEST #4: VectorF(" << vec4 << ") == " << prediction << std::endl;
	resultVec = VectorF(vec4);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #5
	vec21 = Vector2(1, 2);
	vec22 = Vector2(3, 4);
	prediction = VectorF(1, 2, 3, 4);
	std::cout << "TEST #5: VectorF(" << vec21 << ", " << vec22 <<  ") == " << prediction << std::endl;
	resultVec = VectorF(vec21, vec22);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #6
	value = 3;
	prediction = VectorF(3,3,3,3);
	std::cout << "TEST #6: VectorF(" << value << ") == " << prediction << std::endl;
	resultVec = VectorF(value);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}


	return true;
}

Bool VectorFTester::testAdd()
{
	VectorF arg1, arg2, prediction, resultVec;
	Bool result;

	// TEST #1
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(2, 3, 4, 5);
	prediction = VectorF(3, 5, 7, 9);
	std::cout << "TEST #1: " << arg1 << " + " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 + arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(2, 3, 4, 5);
	prediction = VectorF(3, 5, 7, 9);
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

Bool VectorFTester::testSub()
{
	VectorF arg1, arg2, prediction, resultVec;
	Bool result;

	// TEST #1
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(2, 3, 4, 5);
	prediction = VectorF(-1, -1, -1, -1);
	std::cout << "TEST #1: " << arg1 << " - " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 - arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(2, 3, 4, 5);
	prediction = VectorF(-1, -1, -1, -1);
	std::cout << "TEST #2: " << arg1 << " -= " << arg2 << " == " << prediction << std::endl;
	arg1 -= arg2;
	result = arg1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << arg1 << std::endl;
		return false;
	}

	// TEST #3
	arg1 = VectorF(1, 2, 3, 4);
	prediction = VectorF(-1, -2, -3, -4);
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

Bool VectorFTester::testMul()
{
	VectorF arg1, arg2, prediction, resultVec;
	Float scale;
	Bool result;

	// TEST #1
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(2, 3, 4, 5);
	prediction = VectorF(2, 6, 12, 20);
	std::cout << "TEST #1: " << arg1 << " * " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 * arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(2, 3, 4, 5);
	prediction = VectorF(2, 6, 12, 20);
	std::cout << "TEST #2: " << arg1 << " *= " << arg2 << " == " << prediction << std::endl;
	arg1 *= arg2;
	result = arg1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << arg1 << std::endl;
		return false;
	}

	// TEST #3
	arg1 = VectorF(1, 2, 3, 4);
	scale = 2;
	prediction = VectorF(2, 4, 6, 8);
	std::cout << "TEST #3: " << arg1 << " * " << scale << " == " << prediction << std::endl;
	resultVec = arg1 * scale;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #4
	arg1 = VectorF(1, 2, 3, 4);
	scale = 2;
	prediction = VectorF(2, 4, 6, 8);
	std::cout << "TEST #4: " << scale << " * " << arg1 << " == " << prediction << std::endl;
	resultVec = scale * arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	return true;
}

Bool VectorFTester::testDiv()
{
	VectorF arg1, arg2, prediction, resultVec;
	Float scale;
	Bool result;

	// TEST #1
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(2, 3, 4, 5);
	prediction = VectorF(0.5, 0.666666666, 0.75, 0.8);
	std::cout << "TEST #1: " << arg1 << " / " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 / arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = VectorF(1, 2, 3, 4);
	arg2 = VectorF(2, 3, 4, 5);
	prediction = VectorF(0.5, 0.666666666, 0.75, 0.8);
	std::cout << "TEST #2: " << arg1 << " /= " << arg2 << " == " << prediction << std::endl;
	arg1 /= arg2;
	result = arg1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << arg1 << std::endl;
		return false;
	}

	// TEST #3
	arg1 = VectorF(1, 2, 3, 4);
	scale = 2;
	prediction = VectorF(0.5, 1, 1.5, 2);
	std::cout << "TEST #3: " << arg1 << " / " << scale << " == " << prediction << std::endl;
	resultVec = arg1 / scale;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}


	// TEST #4
	arg1 = VectorF(1, 2, 3, 4);
	scale = 2;
	prediction = VectorF(2, 1, 2.0 / 3, 2.0 / 4);
	std::cout << "TEST #4: " << scale << " / " << arg1 << " == " << prediction << std::endl;
	resultVec = scale / arg1;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	return true;
}

Bool VectorFTester::testStore()
{
	Float x, y, z, w, xPrediction, yPrediction, zPrediction, wPrediction;
	ALIGN(16) Float pArray[4];
	ALIGN(16) Float pArrayPrediction[4];
	Vector2 vec21, vec22, vec21Prediction, vec22Prediction;
	Vector3 vec3, vec3Prediction;
	Vector4 vec4, vec4Prediction;
	VectorF vec;
	Bool result;

	// TEST #1
	vec = VectorF(1, 2, 3, 4);
	xPrediction = 1;
	yPrediction = 2;
	zPrediction = 3;
	wPrediction = 4;
	std::cout << "TEST #1: " << vec << ".store(x,y,z,w); x == " << xPrediction << "; y == " << yPrediction <<
		"; z == " << zPrediction << "; w == " << wPrediction << std::endl;
	vec.store(x, y, z, w);
	result = x == xPrediction && y == yPrediction && z == zPrediction && w == wPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: x = " << x << ", y = " << y << ", z = " << z << ", w = " << w << std::endl;
		return false;
	}

	// TEST #2
	vec = VectorF(1, 2, 3, 4);
	pArrayPrediction[0] = 1;
	pArrayPrediction[1] = 2;
	pArrayPrediction[2] = 3;
	pArrayPrediction[3] = 4;
	std::cout << "TEST #2: " << vec << ".store(pArray); pArray = {" << pArrayPrediction[0] << ", " << pArrayPrediction[1] <<
		", " << pArrayPrediction[2] << ", " << pArrayPrediction[3] << "}" << std::endl;
	vec.store(pArray);
	result = pArray[0] == pArrayPrediction[0] && pArray[1] == pArrayPrediction[1] && pArray[2] == pArrayPrediction[2] && pArray[3] == pArrayPrediction[3];
	if (!result)
	{
		std::cout << "Failed. Computed value: { " << pArray[0] << ", " << pArray[1] << ", " << pArray[2] << ", " << pArray[3] << "}" << std::endl;
		return false;
	}

	// TEST #3
	vec = VectorF(1, 2, 3, 4);
	vec21Prediction = Vector2(1, 2);
	std::cout << "TEST #3: " << vec << ".store(vec2); vec2 = " << vec21Prediction << std::endl;
	vec.store(vec21);
	result = vec21 == vec21Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vec21 << std::endl;
		return false;
	}

	// TEST #4
	vec = VectorF(1, 2, 3, 4);
	vec3Prediction = Vector3(1, 2, 3);
	std::cout << "TEST #4: " << vec << ".store(vec3); vec3 = " << vec3Prediction << std::endl;
	vec.store(vec3);
	result = vec3 == vec3Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vec3 << std::endl;
		return false;
	}

	// TEST #5
	vec = VectorF(1, 2, 3, 4);
	vec4Prediction = Vector4(1, 2, 3, 4);
	std::cout << "TEST #5: " << vec << ".store(vec4); vec4 = " << vec4Prediction << std::endl;
	vec.store(vec4);
	result = vec4 == vec4Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vec4 << std::endl;
		return false;
	}

	// TEST #6
	vec = VectorF(1, 2, 3, 4);
	vec21Prediction = Vector2(1, 2);
	vec22Prediction = Vector2(3, 4);
	std::cout << "TEST #6: " << vec << ".store(vec21, vec22); vec21 = " << vec21Prediction << "; vec22 = " << vec22Prediction << std::endl;
	vec.store(vec21, vec22);
	result = vec21 == vec21Prediction && vec22 == vec22Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: vec21 = " << vec21 << "; vec22 = " << vec22 << std::endl;
		return false;
	}

	return true;
}

Bool VectorFTester::testGetSet()
{
	VectorF vec, vecPrediction;
	Float valuef, valuefResult, valuefPrediction;
	Int32 ind, valuei, valueiResult, valueiPrediction;
	Bool result;

	// TEST #1
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(1, 2, 3, 5);
	valuef = 5;
	ind = 3;
	std::cout << "TEST #1: " << vec << ".set(" << ind << ", " << valuef << ") == " << vecPrediction << std::endl;
	vec.set(ind, valuef);
	result = vec == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vec << std::endl;
		return false;
	}

	// TEST #2
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(5, 2, 3, 4);
	valuef = 5;
	ind = 0;
	std::cout << "TEST #2: " << vec << ".set(" << ind << ", " << valuef << ") == " << vecPrediction << std::endl;
	vec.set(ind, valuef);
	result = vec == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vec << std::endl;
		return false;
	}

	// TEST #3
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(1, 2, 3, int2Float(5));
	valuei = 5;
	ind = 3;
	std::cout << "TEST #3: " << vec << ".setInt(" << ind << ", " << valuei << ") == " << vecPrediction << std::endl;
	vec.setInt(ind, valuei);
	result = vec == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vec << std::endl;
		return false;
	}

	// TEST #4
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(int2Float(5), 2, 3, 4);
	valuei = 5;
	ind = 0;
	std::cout << "TEST #4: " << vec << ".setInt(" << ind << ", " << valuei << ") == " << vecPrediction << std::endl;
	vec.setInt(ind, valuei);
	result = vec == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vec << std::endl;
		return false;
	}

	// TEST #5
	vec = VectorF(1, 2, 3, 4);
	valuefPrediction = 4;
	ind = 3;
	std::cout << "TEST #5: " << vec << ".get(" << ind << ") == " << valuefPrediction << std::endl;
	valuefResult = vec.get(ind);
	result = valuefPrediction == valuefResult;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valuefResult << std::endl;
		return false;
	}

	// TEST #6
	vec = VectorF(1, 2, 3, 4);
	valuefPrediction = 1;
	ind = 0;
	std::cout << "TEST #6: " << vec << ".get(" << ind << ") == " << valuefPrediction << std::endl;
	valuefResult = vec.get(ind);
	result = valuefPrediction == valuefResult;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valuefResult << std::endl;
		return false;
	}

	// TEST #7
	vec = VectorF(1, 2, 3, 4);
	valueiPrediction = float2Int(4);
	ind = 3;
	std::cout << "TEST #7: " << vec << ".getInt(" << ind << ") == " << valueiPrediction << std::endl;
	valueiResult = vec.getInt(ind);
	result = valueiPrediction == valueiResult;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueiResult << std::endl;
		return false;
	}

	// TEST #8
	vec = VectorF(1, 2, 3, 4);
	valueiPrediction = float2Int(1);
	ind = 0;
	std::cout << "TEST #8: " << vec << ".getInt(" << ind << ") == " << valueiPrediction << std::endl;
	valueiResult = vec.getInt(ind);
	result = valueiPrediction == valueiResult;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueiResult << std::endl;
		return false;
	}


	return true;
}

Bool VectorFTester::testFunctions()
{
	VectorF vec, vecPrediction, vecPrediction2, vecResult, vecResult2;
	Float value, valueResult, valuePrediction;
	Bool result;

	// TEST #1
	vec = VectorF(1, 2, 3, 4);
	valuePrediction = 5.477225575051f;
	std::cout << "TEST #1: " << vec << ".length4D()" << " == " << valuePrediction << std::endl;
	valueResult = vec.length4D();
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #2
	vec = VectorF(1, 2, 3, 4);
	valuePrediction = 30;
	std::cout << "TEST #2: " << vec << ".sqrLength4D()" << " == " << valuePrediction << std::endl;
	valueResult = vec.sqrLength4D();
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #4
	vec = VectorF(-3, 4, -5, 6);
	vecPrediction = VectorF(3, 4, 5, 6);
	std::cout << "TEST #4: " << vec << ".abs()" << " == " << vecPrediction << std::endl;
	vecResult = vec.abs();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #5
	vec = VectorF(3.1, 4.7, 5.2, 6.8);
	vecPrediction = VectorF(3, 4, 5, 6);
	std::cout << "TEST #5: " << vec << ".floor()" << " == " << vecPrediction << std::endl;
	vecResult = vec.floor();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #6
	vec = VectorF(3.7, 4.1, 5.6, 6.3);
	vecPrediction = VectorF(3, 4, 5, 6);
	std::cout << "TEST #6: " << vec << ".floor()" << " == " << vecPrediction << std::endl;
	vecResult = vec.floor();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #7
	vec = VectorF(3.1, 4.7, 5.2, 6.8);
	vecPrediction = VectorF(4, 5, 6, 7);
	std::cout << "TEST #7: " << vec << ".ceil()" << " == " << vecPrediction << std::endl;
	vecResult = vec.ceil();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #8
	vec = VectorF(3.7, 4.1, 5.6, 6.3);
	vecPrediction = VectorF(4, 5, 6, 7);
	std::cout << "TEST #8: " << vec << ".ceil()" << " == " << vecPrediction << std::endl;
	vecResult = vec.ceil();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #9
	vec = VectorF(3.1, 4.7, 5.2, 6.8);
	vecPrediction = VectorF(3, 5, 5, 7);
	std::cout << "TEST #9: " << vec << ".round()" << " == " << vecPrediction << std::endl;
	vecResult = vec.round();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #10
	vec = VectorF(3.7, 4.1, 5.6, 6.3);
	vecPrediction = VectorF(4, 4, 6, 6);
	std::cout << "TEST #10: " << vec << ".round()" << " == " << vecPrediction << std::endl;
	vecResult = vec.round();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #11
	vec = VectorF(2, 4, 8, 5);
	vecPrediction = VectorF(0.5, 0.25, 0.125, 0.2);
	std::cout << "TEST #11: " << vec << ".reciprocal()" << " == " << vecPrediction << std::endl;
	vecResult = vec.reciprocal();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #12
	vec = VectorF(0.4, 6, 3, 0);
	vecPrediction = VectorF(0.4, 1, 1, 0);
	std::cout << "TEST #12: " << vec << ".saturate()" << " == " << vecPrediction << std::endl;
	vecResult = vec.saturate();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #13
	vec = VectorF(-5, 0.7, 0.3, 0.9999999);
	vecPrediction = VectorF(0, 0.7, 0.3, 0.9999999);
	std::cout << "TEST #13: " << vec << ".saturate()" << " == " << vecPrediction << std::endl;
	vecResult = vec.saturate();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #14
	vec = VectorF(4, 9, 16, 25);
	vecPrediction = VectorF(2, 3, 4, 5);
	std::cout << "TEST #14: " << vec << ".sqrt()" << " == " << vecPrediction << std::endl;
	vecResult = vec.sqrt();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}


	// TEST #15
	vec = VectorF(4, -9, 34, 21);
	vecPrediction = VectorF(sinf(4), sinf(-9), sinf(34), sinf(21));
	std::cout << "TEST #15: " << vec << ".sin()" << " == " << vecPrediction << std::endl;
	vecResult = vec.sin();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #16
	vec = VectorF(4, -9, 34, 21);
	vecPrediction = VectorF(cosf(4), cosf(-9), cosf(34), cosf(21));
	std::cout << "TEST #16: " << vec << ".cos()" << " == " << vecPrediction << std::endl;
	vecResult = vec.cos();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #17
	vec = VectorF(4, -9, 34, 21);
	vecPrediction = VectorF(tanf(4), tanf(-9), tanf(34), tanf(21));
	std::cout << "TEST #17: " << vec << ".tan()" << " == " << vecPrediction << std::endl;
	vecResult = vec.tan();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #18
	vec = VectorF(0.4, -0.6, 0.34, 0.21);
	vecPrediction = VectorF(asinf(0.4), asinf(-0.6), asinf(0.34), asinf(0.21));
	std::cout << "TEST #18: " << vec << ".asin()" << " == " << vecPrediction << std::endl;
	vecResult = vec.asin();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #19
	vec = VectorF(0.4, -0.6, 0.34, 0.21);
	vecPrediction = VectorF(acosf(0.4), acosf(-0.6), acosf(0.34), acosf(0.21));
	std::cout << "TEST #19: " << vec << ".acos()" << " == " << vecPrediction << std::endl;
	vecResult = vec.acos();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #20
	vec = VectorF(0.4, -0.6, 0.34, 0.21);
	vecPrediction = VectorF(atanf(0.4), atanf(-0.6), atanf(0.34), atanf(0.21));
	std::cout << "TEST #20: " << vec << ".atan()" << " == " << vecPrediction << std::endl;
	vecResult = vec.atan();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #21
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(exp2f(1), exp2f(2), exp2f(3), exp2f(4));
	std::cout << "TEST #21: " << vec << ".exp2()" << " == " << vecPrediction << std::endl;
	vecResult = vec.exp2();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #22
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(expf(1), expf(2), expf(3), expf(4));
	std::cout << "TEST #22: " << vec << ".expE()" << " == " << vecPrediction << std::endl;
	vecResult = vec.expE();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #23
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(log2f(1), log2f(2), log2f(3), log2f(4));
	std::cout << "TEST #23: " << vec << ".log2()" << " == " << vecPrediction << std::endl;
	vecResult = vec.log2();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #24
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(logf(1), logf(2), logf(3), logf(4));
	std::cout << "TEST #24: " << vec << ".logE()" << " == " << vecPrediction << std::endl;
	vecResult = vec.logE();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #25
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(sinf(1), sinf(2), sinf(3), sinf(4));
	vecPrediction2 = VectorF(cosf(1), cosf(2), cosf(3), cosf(4));
	std::cout << "TEST #25: " << vec << ".sincos()" << " == " << vecPrediction << ", " << vecPrediction2 << std::endl;
	vec.sincos(vecResult, vecResult2);
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f)) && vecResult2.isEqualPrec(vecPrediction2, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: vecResult = " << vecResult << "; vecResult2 = " << vecResult2 << std::endl;
		return false;
	}

	// TEST #26
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(1 / 5.477225575051f, 2 / 5.477225575051f, 3 / 5.477225575051f, 4 / 5.477225575051f);
	std::cout << "TEST #26: " << vec << ".normalized4D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.normalized4D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #27
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(5.477225575051f);
	std::cout << "TEST #27: " << vec << ".lengthVec4D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.lengthVec4D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #28
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(30);
	std::cout << "TEST #28: " << vec << ".sqrLengthVec4D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.sqrLengthVec4D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #29
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(1/ 5.477225f, 2 / 5.477225f, 3 / 5.477225f, 4 / 5.477225f);
	std::cout << "TEST #29: " << vec << ".normalizedFast4D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.normalizedFast4D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #30
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(1, 0.5, 0.333333, 0.25);
	std::cout << "TEST #30: " << vec << ".reciprocalFast()" << " == " << vecPrediction << std::endl;
	vecResult = vec.reciprocalFast();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #31
	vec = VectorF(1, 4, 9, 16);
	vecPrediction = VectorF(1, 2, 3, 4);
	std::cout << "TEST #31: " << vec << ".sqrtFast()" << " == " << vecPrediction << std::endl;
	vecResult = vec.sqrtFast();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #32
	vec = VectorF(1, -1, 0, 2);
	vecPrediction = VectorF(1, 1, 1, 2);
	std::cout << "TEST #32: " << vec << ".orthogonal3D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.orthogonal3D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #33
	vec = VectorF(1, -1, 0, 2);
	vecPrediction = VectorF(0, 2, -1, 1);
	std::cout << "TEST #33: " << vec << ".orthogonal4D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.orthogonal4D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #34
	vec = VectorF(1, 2, 3, 4);
	valuePrediction = 3.7416573867f;
	std::cout << "TEST #34: " << vec << ".length3D()" << " == " << valuePrediction << std::endl;
	valueResult = vec.length3D();
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #35
	vec = VectorF(1, 2, 3, 4);
	valuePrediction = 14;
	std::cout << "TEST #35: " << vec << ".sqrLength3D()" << " == " << valuePrediction << std::endl;
	valueResult = vec.sqrLength3D();
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #36
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(1 / 3.7416573867f, 2 / 3.7416573867f, 3 / 3.7416573867f, 1.06904495);
	std::cout << "TEST #36: " << vec << ".normalized3D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.normalized3D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #37
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(3.7416573867f);
	std::cout << "TEST #37: " << vec << ".lengthVec3D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.lengthVec3D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #38
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(14);
	std::cout << "TEST #38: " << vec << ".sqrLengthVec3D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.sqrLengthVec3D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.01f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #39
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(1 / 3.7416573867f, 2 / 3.7416573867f, 3 / 3.7416573867f, 1.06904495);
	std::cout << "TEST #39: " << vec << ".normalizedFast3D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.normalizedFast3D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.01f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #40
	vec = VectorF(1, 2, 3, 4);
	valuePrediction = sqrtf(5);
	std::cout << "TEST #40: " << vec << ".length2D()" << " == " << valuePrediction << std::endl;
	valueResult = vec.length2D();
	result = valuePrediction == valueResult;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #41
	vec = VectorF(1, 2, 3, 4);
	valuePrediction = 5;
	std::cout << "TEST #41: " << vec << ".sqrLength2D()" << " == " << valuePrediction << std::endl;
	valueResult = vec.sqrLength2D();
	result = valuePrediction == valueResult;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #42
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(1/sqrtf(5), 2/sqrtf(5), 3/sqrtf(5), 4/sqrtf(5));
	std::cout << "TEST #42: " << vec << ".normalized2D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.normalized2D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #43
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(-2, 1, 1, 1);
	std::cout << "TEST #43: " << vec << ".orthogonal2D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.orthogonal2D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #44
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(sqrtf(5));
	std::cout << "TEST #44: " << vec << ".lengthVec2D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.lengthVec2D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #45
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(5);
	std::cout << "TEST #45: " << vec << ".sqrLengthVec2D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.sqrLengthVec2D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #46
	vec = VectorF(1, 2, 3, 4);
	vecPrediction = VectorF(1 / sqrtf(5), 2 / sqrtf(5), 3 / sqrtf(5), 4 / sqrtf(5));
	std::cout << "TEST #46: " << vec << ".normalizedFast2D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.normalizedFast2D();
	result = vecResult.isEqualPrec(vecPrediction, VectorF(0.01f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	return true;
}