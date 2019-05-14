#include "MathTests.h"

using namespace M3DM;

bool VectorFTester::testAll()
{
	bool result;
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

	return true;
}

bool VectorFTester::testEqual()
{
	VectorF v1, v2, vecPrecision, resultVec, prediction;
	float precision;
	bool result, resultPrediciton;

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

bool VectorFTester::testCmp()
{
	VectorF v1, v2;
	bool result, resultPrediciton;

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

bool VectorFTester::testConversions()
{
	ALIGN(16) float pArray[4];
	ALIGN(16) float* pArrayRes;
	Vector2 vec21, vec22;
	Vector3 vec3;
	Vector4 vec4;
	VectorF resultVec;
	VectorF prediction;
	bool result;

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

	return true;
}

bool VectorFTester::testAdd()
{
	VectorF arg1, arg2, prediction, resultVec;
	bool result;

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

bool VectorFTester::testSub()
{
	VectorF arg1, arg2, prediction, resultVec;
	bool result;

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

	return true;
}

bool VectorFTester::testMul()
{
	VectorF arg1, arg2, prediction, resultVec;
	bool result;

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

	return true;
}

bool VectorFTester::testDiv()
{
	VectorF arg1, arg2, prediction, resultVec;
	bool result;

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

	return true;
}

bool VectorFTester::testStore()
{
	float x, y, z, w, xPrediction, yPrediction, zPrediction, wPrediction;
	ALIGN(16) float pArray[4];
	ALIGN(16) float pArrayPrediction[4];
	Vector2 vec21, vec22, vec21Prediction, vec22Prediction;
	Vector3 vec3, vec3Prediction;
	Vector4 vec4, vec4Prediction;
	VectorF vec;
	bool result;

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