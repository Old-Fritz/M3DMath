#include "MathTests.h"

using namespace M3DM;

bool DoubleVectorFTester::testAll()
{
	bool result;
	std::cout << "------DOUBLE VECTOR SIMD TEST------" << std::endl;
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

	return true;
}

bool DoubleVectorFTester::testEqual()
{
	DoubleVectorF v1, v2, vecPrecision, resultVec, prediction;
	float precision;
	bool result, resultPrediciton;

	// ==
	// TEST #1
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	resultPrediciton = true;
	std::cout << "TEST #1: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #2
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(2, 2, 3, 4, 5, 6, 7, 8);
	resultPrediciton = false;
	std::cout << "TEST #2: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #3
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1, 2, 3, 4, 6, 6, 7, 8);
	resultPrediciton = false;
	std::cout << "TEST #3: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #4
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 9);
	resultPrediciton = false;
	std::cout << "TEST #4: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #5
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1, 2, 3, 5, 6, 6, 7, 8);
	resultPrediciton = false;
	std::cout << "TEST #5: (" << v1 << " == " << v2 << ") == " << resultPrediciton << std::endl;
	result = (v1 == v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #6
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(2, 2, 3, 5, 5, 8, 7, 9);
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
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	resultPrediciton = true;
	std::cout << "TEST #7: " << v1 << ".isEqualPrec(" << v2 << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #8
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1, 2, 4, 4, 5, 6, 7, 8);
	resultPrediciton = false;
	std::cout << "TEST #8: " << v1 << ".isEqualPrec(" << v2 << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #9
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
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
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1, 2, 3.0001, 4, 5, 6, 7, 8);
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
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1.000001, 2.000001, 3.000001, 4.000001, 5.000001, 6.000001, 7.000001, 8.000001);
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
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1.000001, 2.000001, 3.000001, 4.000001, 5.000001, 6.000001, 7.000001, 8.000001);
	vecPrecision = DoubleVectorF(0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001);
	resultPrediciton = true;
	std::cout << "TEST #12: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #13
	v1 = DoubleVectorF(1.000001, 2.000001, 3.000001, 4.000001, 5.000001, 6.000001, 7.000001, 8.000001);
	v2 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrecision = DoubleVectorF(0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001);
	resultPrediciton = true;
	std::cout << "TEST #13: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #14
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1.000001, 2.000001, 3.000001, 4.001, 5.000001, 6.000001, 7.000001, 8.000001);
	vecPrecision = DoubleVectorF(0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #14: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #15
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1.001, 2.001, 3.001, 4.001, 5.001, 6.001, 7.001, 8.001);
	vecPrecision = DoubleVectorF(0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #15: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #16
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1.001, 2.001, 3.001, 4.001, 5.001, 6.001, 7.001, 8.001);
	vecPrecision = DoubleVectorF(0.005, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001);
	resultPrediciton = false;
	std::cout << "TEST #16: " << v1 << ".isEqualPrec(" << v2 << ", " << vecPrecision << ") == " << resultPrediciton << std::endl;
	result = v1.isEqualPrec(v2, vecPrecision) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #17
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1.001, 2.001, 3.001, 4.001, 5.001, 6.001, 7.001, 8.001);
	vecPrecision = DoubleVectorF(0.01, 0.01, 0.01, 0.01, 0.0001, 0.01, -0.01, 0.01);
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
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	prediction = DoubleVectorF(FNAN, FNAN, FNAN, FNAN, FNAN, FNAN, FNAN, FNAN);
	std::cout << "TEST #18: " << v1 << ".isEqualVec(" << v2 << ") == " << prediction << std::endl;
	resultVec = v1.isEqualVec(v2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #19
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1, 2, 3, 5, 5, 6, 7, 9);
	prediction = DoubleVectorF(FNAN, FNAN, FNAN, 0, FNAN, FNAN, FNAN, 0);
	std::cout << "TEST #19: " << v1 << ".isEqualVec(" << v2 << ") == " << prediction << std::endl;
	resultVec = v1.isEqualVec(v2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #20
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(2, 3, 4, 5, 6, 7, 8, 9);
	prediction = DoubleVectorF(0, 0, 0, 0, 0, 0, 0, 0);
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
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	v2 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrecision = DoubleVectorF(0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001);
	prediction = DoubleVectorF(FNAN, FNAN, FNAN, FNAN, FNAN, FNAN, FNAN, FNAN);
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
	v1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 6.99999, 8);
	v2 = DoubleVectorF(1.0000001, 2.001, 2.99, 4, 6, 6, 7, 8.001);
	vecPrecision = DoubleVectorF(0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001);
	prediction = DoubleVectorF(FNAN, 0, 0, FNAN, 0, FNAN, FNAN, 0);
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

bool DoubleVectorFTester::testCmp()
{
	DoubleVectorF v1, v2;
	bool result, resultPrediciton;

	// TEST #1
	v1 = DoubleVectorF(1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5);
	v2 = DoubleVectorF(1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5);
	resultPrediciton = false;
	std::cout << "TEST #1: " << v1 << " < " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 < v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #2
	v1 = DoubleVectorF(1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5);
	v2 = DoubleVectorF(1.6, 2.6, 3.6, 4.6, 5.6, 6.6, 7.6, 8.6);
	resultPrediciton = true;
	std::cout << "TEST #2: " << v1 << " < " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 < v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #3
	v1 = DoubleVectorF(1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5);
	v2 = DoubleVectorF(1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5);
	resultPrediciton = false;
	std::cout << "TEST #3: " << v1 << " > " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 > v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #4
	v1 = DoubleVectorF(1.6, 2.6, 3.6, 4.6, 5.6, 6.6, 7.6, 8.6);
	v2 = DoubleVectorF(1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5);
	resultPrediciton = true;
	std::cout << "TEST #4: " << v1 << " > " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 > v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #5
	v1 = DoubleVectorF(1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5);
	v2 = DoubleVectorF(1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5);
	resultPrediciton = true;
	std::cout << "TEST #5: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #6
	v1 = DoubleVectorF(1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5);
	v2 = DoubleVectorF(1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5);
	resultPrediciton = true;
	std::cout << "TEST #6: " << v1 << " <= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 <= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #7
	v1 = DoubleVectorF(1.4, 2.4, 3.4, 4.4, 5.4, 6.4, 7.4, 8.4);
	v2 = DoubleVectorF(1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5);
	resultPrediciton = false;
	std::cout << "TEST #7: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #8
	v1 = DoubleVectorF(1.4, 2.4, 3.4, 4.4, 5.4, 6.4, 7.4, 8.4);
	v2 = DoubleVectorF(1.3, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5);
	resultPrediciton = false;
	std::cout << "TEST #8: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #9
	v1 = DoubleVectorF(1.4, 2.4, 3.4, 4.4, 5.4, 6.4, 7.4, 8.4);
	v2 = DoubleVectorF(1.3, 2.3, 3.3, 4.4, 5.3, 6.3, 7.3, 8.3);
	resultPrediciton = true;
	std::cout << "TEST #9: " << v1 << " >= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 >= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #10
	v1 = DoubleVectorF(1.4, 2.4, 3.4, 4.4, 5.5, 6.5, 7.5, 8.5);
	v2 = DoubleVectorF(1.3, 2.3, 3.3, 4.3, 5.3, 6.3, 7.3, 8.3);
	resultPrediciton = false;
	std::cout << "TEST #10: " << v1 << " <= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 <= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #11
	v1 = DoubleVectorF(1.4, 2.4, 3.4, 4.4, 5.4, 6.4, 7.4, 8.4);
	v2 = DoubleVectorF(1.3, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5);
	resultPrediciton = false;
	std::cout << "TEST #11: " << v1 << " <= " << v2 << " == " << resultPrediciton << std::endl;
	result = (v1 <= v2) == resultPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #12
	v1 = DoubleVectorF(1.4, 2.4, 3.4, 4.4, 5.4, 6.4, 7.4, 8.4);
	v2 = DoubleVectorF(1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5);
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

bool DoubleVectorFTester::testConversions()
{
	ALIGN(32) float pArray[8];
	ALIGN(32) float* pArrayRes;
	Vector2 vec21, vec22, vec23, vec24;
	Vector3 vec31, vec32;
	Vector4 vec41, vec42;
	VectorF vecF1, vecF2;
	DoubleVectorF resultVec;
	DoubleVectorF prediction;
	bool result;

	// TEST #1
	pArray[0] = 1;
	pArray[1] = 2;
	pArray[2] = 3;
	pArray[3] = 4;
	pArray[4] = 5;
	pArray[5] = 6;
	pArray[6] = 7;
	pArray[7] = 8;
	prediction = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	std::cout << "TEST #1: DoubleVectorF({" << pArray[0] << ", " << pArray[1] << ", " << pArray[2] << ", " << pArray[3]
		<< ", " << pArray[4] << ", " << pArray[5] << ", " << pArray[6] << ", " << pArray[7] << "}) == " << prediction << std::endl;
	resultVec = DoubleVectorF(pArray);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	vec21 = Vector2(1, 2);
	prediction = DoubleVectorF(1, 2);
	std::cout << "TEST #2: DoubleVectorF(" << vec21 << ") == " << prediction << std::endl;
	resultVec = DoubleVectorF(vec21);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #3
	vec31 = Vector3(1, 2, 3);
	prediction = DoubleVectorF(1, 2, 3);
	std::cout << "TEST #3: DoubleVectorF(" << vec31 << ") == " << prediction << std::endl;
	resultVec = DoubleVectorF(vec31);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #4
	vec41 = Vector4(1, 2, 3, 4);
	prediction = DoubleVectorF(1, 2, 3, 4);
	std::cout << "TEST #4: DoubleVectorF(" << vec41 << ") == " << prediction << std::endl;
	resultVec = DoubleVectorF(vec41);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #5
	vec21 = Vector2(1, 2);
	vec22 = Vector2(3, 4);
	prediction = DoubleVectorF(1, 2, 0, 0, 3, 4, 0, 0);
	std::cout << "TEST #5: DoubleVectorF(" << vec21 << ", " << vec22 <<  ") == " << prediction << std::endl;
	resultVec = DoubleVectorF(vec21, vec22);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #6
	vec31 = Vector3(1, 2, 3);
	vec32 = Vector3(4 ,5, 6);
	prediction = DoubleVectorF(1, 2, 3, 0, 4, 5, 6, 0);
	std::cout << "TEST #6: DoubleVectorF(" << vec31 << ", " << vec32 << ") == " << prediction << std::endl;
	resultVec = DoubleVectorF(vec31, vec32);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #7
	vec41 = Vector4(1, 2, 3, 4);
	vec42 = Vector4(5, 6, 7, 8);
	prediction = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	std::cout << "TEST #7: DoubleVectorF(" << vec41 << ", " << vec42 << ") == " << prediction << std::endl;
	resultVec = DoubleVectorF(vec41, vec42);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #8
	vec21 = Vector2(1, 2);
	vec22 = Vector2(3, 4);
	vec23 = Vector2(5, 6);
	vec24 = Vector2(7, 8);
	prediction = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	std::cout << "TEST #8: DoubleVectorF(" << vec21 << ", " << vec22 << ", " << vec23 << ", " << vec24 << ") == " << prediction << std::endl;
	resultVec = DoubleVectorF(vec21, vec22, vec23, vec24);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #9
	vecF1 = VectorF(1, 2, 3, 4);
	prediction = DoubleVectorF(1, 2, 3, 4);
	std::cout << "TEST #9: DoubleVectorF(" << vecF1 << ") == " << prediction << std::endl;
	resultVec = DoubleVectorF(vecF1);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #10
	vecF1 = VectorF(1, 2, 3, 4);
	vecF2 = VectorF(5, 6, 7, 8);
	prediction = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	std::cout << "TEST #10: DoubleVectorF(" << vecF1 << ", " << vecF2 << ") == " << prediction << std::endl;
	resultVec = DoubleVectorF(vecF1, vecF2);
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	return true;
}

bool DoubleVectorFTester::testAdd()
{
	DoubleVectorF arg1, arg2, prediction, resultVec;
	bool result;

	// TEST #1
	arg1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	arg2 = DoubleVectorF(2, 3, 4, 5, 6, 7, 8, 9);
	prediction = DoubleVectorF(3, 5, 7, 9, 11, 13, 15, 17);
	std::cout << "TEST #1: " << arg1 << " + " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 + arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	arg2 = DoubleVectorF(2, 3, 4, 5, 6, 7, 8, 9);
	prediction = DoubleVectorF(3, 5, 7, 9, 11, 13, 15, 17);
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

bool DoubleVectorFTester::testSub()
{
	DoubleVectorF arg1, arg2, prediction, resultVec;
	bool result;

	// TEST #1
	arg1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	arg2 = DoubleVectorF(2, 3, 4, 5, 6, 7, 8, 9);
	prediction = DoubleVectorF(-1, -1, -1, -1, -1, -1, -1, -1);
	std::cout << "TEST #1: " << arg1 << " - " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 - arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	arg2 = DoubleVectorF(2, 3, 4, 5, 6, 7, 8, 9);
	prediction = DoubleVectorF(-1, -1, -1, -1, -1, -1, -1, -1);
	std::cout << "TEST #2: " << arg1 << " -= " << arg2 << " == " << prediction << std::endl;
	arg1 -= arg2;
	result = arg1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << arg1 << std::endl;
		return false;
	}

	// TEST #3
	arg1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	prediction = DoubleVectorF(-1, -2, -3, -4, -5, -6, -7, -8);
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

bool DoubleVectorFTester::testMul()
{
	DoubleVectorF arg1, arg2, prediction, resultVec;
	float scale;
	bool result;

	// TEST #1
	arg1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	arg2 = DoubleVectorF(2, 3, 4, 5, 6, 7, 8, 9);
	prediction = DoubleVectorF(2, 6, 12, 20, 30, 42, 56, 72);
	std::cout << "TEST #1: " << arg1 << " * " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 * arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	arg2 = DoubleVectorF(2, 3, 4, 5, 6, 7, 8, 9);
	prediction = DoubleVectorF(2, 6, 12, 20, 30, 42, 56, 72);
	std::cout << "TEST #2: " << arg1 << " *= " << arg2 << " == " << prediction << std::endl;
	arg1 *= arg2;
	result = arg1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << arg1 << std::endl;
		return false;
	}

	// TEST #3
	arg1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	scale = 2;
	prediction = DoubleVectorF(2, 4, 6, 8, 10, 12, 14, 16);
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

bool DoubleVectorFTester::testDiv()
{
	DoubleVectorF arg1, arg2, prediction, resultVec;
	float scale;
	bool result;

	// TEST #1
	arg1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	arg2 = DoubleVectorF(2, 3, 4, 5, 6, 7, 8, 9);
	prediction = DoubleVectorF(0.5, 0.666666666, 0.75, 0.8, 0.833333333, 0.8571428571, 0.875, 0.888888888);
	std::cout << "TEST #1: " << arg1 << " / " << arg2 << " == " << prediction << std::endl;
	resultVec = arg1 / arg2;
	result = resultVec == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << resultVec << std::endl;
		return false;
	}

	// TEST #2
	arg1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	arg2 = DoubleVectorF(2, 3, 4, 5, 6, 7, 8, 9);
	prediction = DoubleVectorF(0.5, 0.666666666, 0.75, 0.8, 0.833333333, 0.8571428571, 0.875, 0.888888888);
	std::cout << "TEST #2: " << arg1 << " /= " << arg2 << " == " << prediction << std::endl;
	arg1 /= arg2;
	result = arg1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << arg1 << std::endl;
		return false;
	}

	// TEST #3
	arg1 = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	scale = 2;
	prediction = DoubleVectorF(0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4);
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

bool DoubleVectorFTester::testStore()
{
	float x1, y1, z1, w1, x2, y2, z2, w2,
	x1Prediction, y1Prediction, z1Prediction, w1Prediction, x2Prediction, y2Prediction, z2Prediction, w2Prediction;
	ALIGN(32) float pArray[8];
	ALIGN(32) float pArrayPrediction[8];
	Vector2 vec21, vec22, vec23, vec24,
	vec21Prediction, vec22Prediction, vec23Prediction, vec24Prediction;
	Vector3 vec31, vec32, vec31Prediction, vec32Prediction;
	Vector4 vec41, vec42, vec41Prediction, vec42Prediction;
	VectorF vecF1, vecF2, vecF1Prediction, vecF2Prediction;
	DoubleVectorF vec;
	bool result;

	// TEST #1
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	x1Prediction = 1;
	y1Prediction = 2;
	z1Prediction = 3;
	w1Prediction = 4;
	x2Prediction = 5;
	y2Prediction = 6;
	z2Prediction = 7;
	w2Prediction = 8;
	std::cout << "TEST #1: " << vec << ".store(x1,y1,z1,w1,x2,y2,z2,w2); x1 == " << x1Prediction << "; y1 == " << y1Prediction <<
		"; z1 == " << z1Prediction << "; w1 == " << w1Prediction << "; x2 == " << x2Prediction << "; y2 == " << y2Prediction <<
		"; z == " << z2Prediction << "; w == " << w2Prediction << std::endl;
	vec.store(x1, y1, z1, w1, x2, y2, z2, w2);
	result = x1 == x1Prediction && y1 == y1Prediction && z1 == z1Prediction && w1 == w1Prediction && x2 == x2Prediction && y2 == y2Prediction && z2 == z2Prediction && w2 == w2Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: x = " << x1 << ", y = " << y1 << ", z = " << z1 << ", w = " << w1 << ", x = " << x2 << ", y = " << y2 << ", z = " << z2 << ", w = " << w2 << std::endl;
		return false;
	}

	// TEST #2
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	pArrayPrediction[0] = 1;
	pArrayPrediction[1] = 2;
	pArrayPrediction[2] = 3;
	pArrayPrediction[3] = 4;
	pArrayPrediction[4] = 5;
	pArrayPrediction[5] = 6;
	pArrayPrediction[6] = 7;
	pArrayPrediction[7] = 8;
	std::cout << "TEST #2: " << vec << ".store(pArray); pArray = {" << pArrayPrediction[0] << ", " << pArrayPrediction[1] <<
		", " << pArrayPrediction[2] << ", " << pArrayPrediction[3] << ", " << pArrayPrediction[4] << ", " << pArrayPrediction[5] <<
		", " << pArrayPrediction[6] << ", " << pArrayPrediction[7] << "}" << std::endl;
	vec.store(pArray);
	result = pArray[0] == pArrayPrediction[0] && pArray[1] == pArrayPrediction[1] && pArray[2] == pArrayPrediction[2] && pArray[3] == pArrayPrediction[3] &&
		pArray[4] == pArrayPrediction[4] && pArray[5] == pArrayPrediction[5] && pArray[6] == pArrayPrediction[6] && pArray[7] == pArrayPrediction[7];
	if (!result)
	{
		std::cout << "Failed. Computed value: { " << pArray[0] << ", " << pArray[1] << ", " << pArray[2] << ", " << pArray[3] << ", "
		<< pArray[4] << ", " << pArray[5] << ", " << pArray[6] << ", " << pArray[7] << "}" << std::endl;
		return false;
	}

	// TEST #3
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
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
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vec31Prediction = Vector3(1, 2, 3);
	std::cout << "TEST #4: " << vec << ".store(vec3); vec3 = " << vec31Prediction << std::endl;
	vec.store(vec31);
	result = vec31 == vec31Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vec31 << std::endl;
		return false;
	}

	// TEST #5
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vec41Prediction = Vector4(1, 2, 3, 4);
	std::cout << "TEST #5: " << vec << ".store(vec4); vec4 = " << vec41Prediction << std::endl;
	vec.store(vec41);
	result = vec41 == vec41Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vec41 << std::endl;
		return false;
	}

	// TEST #6
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vec21Prediction = Vector2(1, 2);
	vec22Prediction = Vector2(5, 6);
	std::cout << "TEST #6: " << vec << ".store(vec21, vec22); vec21 = " << vec21Prediction << "; vec22 = " << vec22Prediction << std::endl;
	vec.store(vec21, vec22);
	result = vec21 == vec21Prediction && vec22 == vec22Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: vec21 = " << vec21 << "; vec22 = " << vec22 << std::endl;
		return false;
	}

	// TEST #7
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vec31Prediction = Vector3(1, 2, 3);
	vec32Prediction = Vector3(5, 6, 7);
	std::cout << "TEST #7: " << vec << ".store(vec31, vec32); vec31 = " << vec31Prediction << "; vec32 = " << vec32Prediction << std::endl;
	vec.store(vec31, vec32);
	result = vec31 == vec31Prediction && vec32 == vec32Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: vec31 = " << vec31 << "; vec32 = " << vec32 << std::endl;
		return false;
	}

	// TEST #8
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vec41Prediction = Vector4(1, 2, 3, 4);
	vec42Prediction = Vector4(5, 6, 7, 8);
	std::cout << "TEST #8: " << vec << ".store(vec41, vec42); vec41 = " << vec41Prediction << "; vec42 = " << vec42Prediction << std::endl;
	vec.store(vec41, vec42);
	result = vec41 == vec41Prediction && vec42 == vec42Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: vec41 = " << vec41 << "; vec42 = " << vec42 << std::endl;
		return false;
	}

	// TEST #9
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vec21Prediction = Vector2(1, 2);
	vec22Prediction = Vector2(3, 4);
	vec23Prediction = Vector2(5, 6);
	vec24Prediction = Vector2(7, 8);
	std::cout << "TEST #9: " << vec << ".store(vec21, vec22, vec23, vec24); vec21 = " << vec21Prediction <<
		"; vec22 = " << vec22Prediction << "; vec23 = " << vec23Prediction << "; vec24 = " << vec24Prediction << std::endl;
	vec.store(vec21, vec22, vec23, vec24);
	result = vec21 == vec21Prediction && vec22 == vec22Prediction && vec23 == vec23Prediction &&vec24 == vec24Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: vec21 = " << vec21 << "; vec22 = " << vec22 << "; vec23" << vec23 << "; vec24" << vec24 << std::endl;
		return false;
	}

	// TEST #10
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecF1Prediction = VectorF(1, 2, 3, 4);
	std::cout << "TEST #10: " << vec << ".store(vecF); vecF = " << vecF1Prediction << std::endl;
	vec.store(vecF1);
	result = vecF1 == vecF1Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecF1 << std::endl;
		return false;
	}

	// TEST #11
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecF1Prediction = VectorF(1, 2, 3, 4);
	vecF2Prediction = VectorF(5, 6, 7, 8);
	std::cout << "TEST #11: " << vec << ".store(vecF1, vecF2); vecF1 = " << vecF1Prediction << "; vecF2 = " << vecF2Prediction << std::endl;
	vec.store(vecF1, vecF2);
	result = vecF1 == vecF1Prediction && vecF2 == vecF2Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: vecF1 = " << vecF1 << "; vecF2 = " << vecF2 << std::endl;
		return false;
	}

	return true;
}

bool DoubleVectorFTester::testGetSet()
{
	DoubleVectorF vec, vecPrediction;
	float valuef, valuefResult, valuefPrediction;
	int ind, valuei, valueiResult, valueiPrediction;
	bool result;

	// TEST #1
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(1, 2, 4, 4, 5, 6, 7, 8);
	valuef = 4;
	ind = 2;
	std::cout << "TEST #1: " << vec << ".set(" << ind << ", " << valuef << ") == " << vecPrediction << std::endl;
	vec.set(ind, valuef);
	result = vec == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vec << std::endl;
		return false;
	}

	// TEST #2
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(1, 2, 3, 4, 5, 6, 12, 8);
	valuef = 12;
	ind = 6;
	std::cout << "TEST #2: " << vec << ".set(" << ind << ", " << valuef << ") == " << vecPrediction << std::endl;
	vec.set(ind, valuef);
	result = vec == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vec << std::endl;
		return false;
	}

	// TEST #3
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(1, int2Float(5), 3, 4, 5, 6, 7, 8);
	valuei = 5;
	ind = 1;
	std::cout << "TEST #3: " << vec << ".setInt(" << ind << ", " << valuei << ") == " << vecPrediction << std::endl;
	vec.setInt(ind, valuei);
	result = vec == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vec << std::endl;
		return false;
	}

	// TEST #4
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(1, 2, 3, 4, 5, int2Float(5), 7, 8);
	valuei = 5;
	ind = 5;
	std::cout << "TEST #4: " << vec << ".setInt(" << ind << ", " << valuei << ") == " << vecPrediction << std::endl;
	vec.setInt(ind, valuei);
	result = vec == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vec << std::endl;
		return false;
	}

	// TEST #5
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	valuefPrediction = 1;
	ind = 0;
	std::cout << "TEST #5: " << vec << ".get(" << ind << ") == " << valuefPrediction << std::endl;
	valuefResult = vec.get(ind);
	result = valuefPrediction == valuefResult;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valuefResult << std::endl;
		return false;
	}

	// TEST #6
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	valuefPrediction = 8;
	ind = 7;
	std::cout << "TEST #6: " << vec << ".get(" << ind << ") == " << valuefPrediction << std::endl;
	valuefResult = vec.get(ind);
	result = valuefPrediction == valuefResult;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valuefResult << std::endl;
		return false;
	}

	// TEST #7
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
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
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	valueiPrediction = float2Int(7);
	ind = 6;
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