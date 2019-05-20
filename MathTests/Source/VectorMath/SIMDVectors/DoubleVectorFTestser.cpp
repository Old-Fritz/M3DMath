#include "MathTests.h"
#include <cmath>

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

	std::cout << "--Test functions--" << std::endl;
	result = testFunctions();
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
	float value;
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
	prediction = DoubleVectorF(1, 2, 0, 0, 0, 0, 0, 0);
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
	prediction = DoubleVectorF(1, 2, 3, 0, 0, 0, 0, 0);
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
	prediction = DoubleVectorF(1, 2, 3, 4, 0, 0, 0, 0);
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
	prediction = DoubleVectorF(1, 2, 3, 4, 0, 0, 0, 0);
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

	// TEST #11
	value = 3;
	prediction = DoubleVectorF(3, 3, 3, 3, 3, 3, 3, 3);
	std::cout << "TEST #11: DoubleVectorF(" << value << ") == " << prediction << std::endl;
	resultVec = DoubleVectorF(value);
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

bool DoubleVectorFTester::testFunctions()
{
	DoubleVectorF vec, vecPrediction, vecPrediction2, vecResult, vecResult2;
	float value, valueResult, value2Result, valuePrediction, value2Prediction;
	bool result;

	// TEST #1
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	valuePrediction = 5.477225575f;
	value2Prediction = 13.19090596f;
	std::cout << "TEST #1: " << vec << ".length4D(); " << " lenth1 == " << valuePrediction << ", length2 ==" << value2Prediction << std::endl;
	vec.length4D(valueResult, value2Result);
	result = valueResult == valuePrediction && value2Result == value2Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: lenth1 == " << valueResult << ", length2 ==" << value2Result << std::endl;
		return false;
	}

	// TEST #2
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	valuePrediction = 30;
	value2Prediction = 174;
	std::cout << "TEST #2: " << vec << ".sqrLength4D(); " << " lenth1 == " << valuePrediction << ", length2 ==" << value2Prediction << std::endl;
	vec.sqrLength4D(valueResult, value2Result);
	result = valueResult == valuePrediction && value2Result == value2Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: lenth1 == " << valueResult << ", length2 ==" << value2Result << std::endl;
		return false;
	}

	// TEST #4
	vec = DoubleVectorF(-3, 4, -5, 6, 7, -8, -9, 10);
	vecPrediction = DoubleVectorF(3, 4, 5, 6, 7, 8, 9, 10);
	std::cout << "TEST #4: " << vec << ".abs()" << " == " << vecPrediction << std::endl;
	vecResult = vec.abs();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #5
	vec = DoubleVectorF(3.1, 4.7, 5.2, 6.8, 7.2, 8.3, 9.5, 10.8);
	vecPrediction = DoubleVectorF(3, 4, 5, 6, 7, 8, 9, 10);
	std::cout << "TEST #5: " << vec << ".floor()" << " == " << vecPrediction << std::endl;
	vecResult = vec.floor();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #6
	vec = DoubleVectorF(3.7, 4.1, 5.6, 6.3, 7.9, 8.6, 9.2, 10.3);
	vecPrediction = DoubleVectorF(3, 4, 5, 6, 7, 8, 9, 10);
	std::cout << "TEST #6: " << vec << ".floor()" << " == " << vecPrediction << std::endl;
	vecResult = vec.floor();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #7
	vec = DoubleVectorF(3.1, 4.7, 5.2, 6.8, 7.2, 8.3, 9.5, 10.8);
	vecPrediction = DoubleVectorF(4, 5, 6, 7, 8, 9, 10, 11);
	std::cout << "TEST #7: " << vec << ".ceil()" << " == " << vecPrediction << std::endl;
	vecResult = vec.ceil();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #8
	vec = DoubleVectorF(3.7, 4.1, 5.6, 6.3, 7.9, 8.6, 9.2, 10.3);
	vecPrediction = DoubleVectorF(4, 5, 6, 7, 8, 9, 10, 11);
	std::cout << "TEST #8: " << vec << ".ceil()" << " == " << vecPrediction << std::endl;
	vecResult = vec.ceil();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #9
	vec = DoubleVectorF(3.1, 4.7, 5.2, 6.8, 7.2, 8.3, 9.5, 10.8);
	vecPrediction = DoubleVectorF(3, 5, 5, 7, 7, 8, 10, 11);
	std::cout << "TEST #9: " << vec << ".round()" << " == " << vecPrediction << std::endl;
	vecResult = vec.round();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #10
	vec = DoubleVectorF(3.7, 4.1, 5.6, 6.3, 7.9, 8.6, 9.2, 10.3);
	vecPrediction = DoubleVectorF(4, 4, 6, 6, 8, 9, 9, 10);
	std::cout << "TEST #10: " << vec << ".round()" << " == " << vecPrediction << std::endl;
	vecResult = vec.round();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #11
	vec = DoubleVectorF(2, 4, 8, 5, 10, 20, 100, 1);
	vecPrediction = DoubleVectorF(0.5, 0.25, 0.125, 0.2, 0.1, 0.05, 0.01, 1);
	std::cout << "TEST #11: " << vec << ".reciprocal()" << " == " << vecPrediction << std::endl;
	vecResult = vec.reciprocal();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #12
	vec = DoubleVectorF(0.4, 6, 3, 0, 0.3, 2, -4, 4);
	vecPrediction = DoubleVectorF(0.4, 1, 1, 0, 0.3, 1, 0, 1);
	std::cout << "TEST #12: " << vec << ".saturate()" << " == " << vecPrediction << std::endl;
	vecResult = vec.saturate();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #13
	vec = DoubleVectorF(-5, 0.7, 0.3, 0.9999999, 0.00000001, 5, 0.6, 1);
	vecPrediction = DoubleVectorF(0, 0.7, 0.3, 0.9999999, 0.00000001, 1, 0.6, 1);
	std::cout << "TEST #13: " << vec << ".saturate()" << " == " << vecPrediction << std::endl;
	vecResult = vec.saturate();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #14
	vec = DoubleVectorF(4, 9, 16, 25, 36, 49, 64, 81);
	vecPrediction = DoubleVectorF(2, 3, 4, 5, 6, 7, 8, 9);
	std::cout << "TEST #14: " << vec << ".sqrt()" << " == " << vecPrediction << std::endl;
	vecResult = vec.sqrt();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}


	// TEST #15
	vec = DoubleVectorF(4, -9, 34, 21, 65, 521, 42, -17);
	vecPrediction = DoubleVectorF(sinf(4), sinf(-9), sinf(34), sinf(21), sinf(65), sinf(521), sinf(42), sinf(-17));
	std::cout << "TEST #15: " << vec << ".sin()" << " == " << vecPrediction << std::endl;
	vecResult = vec.sin();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #16
	vec = DoubleVectorF(4, -9, 34, 21, 65, 521, 42, -17);
	vecPrediction = DoubleVectorF(cosf(4), cosf(-9), cosf(34), cosf(21), cosf(65), cosf(521), cosf(42), cosf(-17));
	std::cout << "TEST #16: " << vec << ".cos()" << " == " << vecPrediction << std::endl;
	vecResult = vec.cos();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #17
	vec = DoubleVectorF(4, -9, 34, 21, 65, 521, 42, -17);
	vecPrediction = DoubleVectorF(tanf(4), tanf(-9), tanf(34), tanf(21), tanf(65), tanf(521), tanf(42), tanf(-17));
	std::cout << "TEST #17: " << vec << ".tan()" << " == " << vecPrediction << std::endl;
	vecResult = vec.tan();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #18
	vec = DoubleVectorF(0.4, -0.6, 0.34, 0.21, 0.5, 0.9999999, 0, -0.9999999);
	vecPrediction = DoubleVectorF(asinf(0.4), asinf(-0.6), asinf(0.34), asinf(0.21), asinf(0.5), asinf(0.9999999), asinf(0), asinf(-0.9999999));
	std::cout << "TEST #18: " << vec << ".asin()" << " == " << vecPrediction << std::endl;
	vecResult = vec.asin();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #19
	vec = DoubleVectorF(0.4, -0.6, 0.34, 0.21, 0.5, 0.9999999, 0, -0.9999999);
	vecPrediction = DoubleVectorF(acosf(0.4), acosf(-0.6), acosf(0.34), acosf(0.21), acosf(0.5), acosf(0.9999999), acosf(0), acosf(-0.9999999));
	std::cout << "TEST #19: " << vec << ".acos()" << " == " << vecPrediction << std::endl;
	vecResult = vec.acos();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #20
	vec = DoubleVectorF(0.4, -0.6, 0.34, 0.21, 0.5, 0.9999999, 0, -0.9999999);
	vecPrediction = DoubleVectorF(atanf(0.4), atanf(-0.6), atanf(0.34), atanf(0.21), atanf(0.5), atanf(0.9999999), atanf(0), atanf(-0.9999999));
	std::cout << "TEST #20: " << vec << ".atan()" << " == " << vecPrediction << std::endl;
	vecResult = vec.atan();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #21
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(exp2f(1), exp2f(2), exp2f(3), exp2f(4), exp2f(5), exp2f(6), exp2f(7), exp2f(8));
	std::cout << "TEST #21: " << vec << ".exp2()" << " == " << vecPrediction << std::endl;
	vecResult = vec.exp2();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #22
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(expf(1), expf(2), expf(3), expf(4), expf(5), expf(6), expf(7), expf(8));
	std::cout << "TEST #22: " << vec << ".expE()" << " == " << vecPrediction << std::endl;
	vecResult = vec.expE();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #23
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(log2f(1), log2f(2), log2f(3), log2f(4), log2f(5), log2f(6), log2f(7), log2f(8));
	std::cout << "TEST #23: " << vec << ".log2()" << " == " << vecPrediction << std::endl;
	vecResult = vec.log2();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #24
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(logf(1), logf(2), logf(3), logf(4), logf(5), logf(6), logf(7), logf(8));
	std::cout << "TEST #24: " << vec << ".logE()" << " == " << vecPrediction << std::endl;
	vecResult = vec.logE();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #25
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(sinf(1), sinf(2), sinf(3), sinf(4), sinf(5), sinf(6), sinf(7), sinf(8));
	vecPrediction2 = DoubleVectorF(cosf(1), cosf(2), cosf(3), cosf(4), cosf(5), cosf(6), cosf(7), cosf(8));
	std::cout << "TEST #25: " << vec << ".sincos()" << " == " << vecPrediction << ", " << vecPrediction2 << std::endl;
	vec.sincos(vecResult, vecResult2);
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f)) && vecResult2.isEqualPrec(vecPrediction2, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: vecResult = " << vecResult << "; vecResult2 = " << vecResult2 << std::endl;
		return false;
	}

	// TEST #26
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(1 / 5.477225575051f, 2 / 5.477225575051f, 3 / 5.477225575051f, 4 / 5.477225575051f, 5 / 13.19090596f, 6 / 13.19090596f, 7 / 13.19090596f, 8 / 13.19090596f);
	std::cout << "TEST #26: " << vec << ".normalized4D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.normalized4D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #27
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(VectorF(5.477225575051f), VectorF(13.19090596f));
	std::cout << "TEST #27: " << vec << ".lengthVec4D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.lengthVec4D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #28
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(VectorF(30), VectorF(174));
	std::cout << "TEST #28: " << vec << ".sqrLengthVec4D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.sqrLengthVec4D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #29
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(1 / 5.477225f, 2 / 5.477225f, 3 / 5.477225f, 4 / 5.477225f, 5 / 13.19090596f, 6 / 13.19090596f, 7 / 13.19090596f, 8 / 13.19090596f);
	std::cout << "TEST #29: " << vec << ".normalizedFast4D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.normalizedFast4D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #30
	vec = DoubleVectorF(1, 2, 3, 0.01, 10, 20, 100, 1);
	vecPrediction = DoubleVectorF(1, 0.5, 0.333333, 100, 0.1, 0.05, 0.01, 1);
	std::cout << "TEST #30: " << vec << ".reciprocalFast()" << " == " << vecPrediction << std::endl;
	vecResult = vec.reciprocalFast();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.01f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #31
	vec = DoubleVectorF(1, 4, 9, 16, 25, 36, 49, 64);
	vecPrediction = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	std::cout << "TEST #31: " << vec << ".sqrtFast()" << " == " << vecPrediction << std::endl;
	vecResult = vec.sqrtFast();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.01f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #32
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(3, 4, -1, -2, 7, 8, -5, -6);
	std::cout << "TEST #43: " << vec << ".orthogonal4D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.orthogonal4D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #33
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	valuePrediction = sqrtf(14);
	value2Prediction = sqrtf(110);
	std::cout << "TEST #33: " << vec << ".length3D()" << " == " << valuePrediction << ", " << value2Prediction << std::endl;
	vec.length3D(valueResult, value2Result);
	result = valuePrediction == valueResult && value2Result == value2Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << ", " << value2Result << std::endl;
		return false;
	}

	// TEST #34
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	valuePrediction = 14;
	value2Prediction = 110;
	std::cout << "TEST #34: " << vec << ".sqrLength3D()" << " == " << valuePrediction << ", " << value2Prediction << std::endl;
	vec.sqrLength3D(valueResult, value2Result);
	result = valuePrediction == valueResult && value2Result == value2Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << ", " << value2Result << std::endl;
		return false;
	}

	// TEST #35
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(1 / sqrtf(14), 2 / sqrtf(14), 3 / sqrtf(14), 4 / sqrtf(14), 5 / sqrtf(110), 6 / sqrtf(110), 7 / sqrtf(110), 8 / sqrtf(110));
	std::cout << "TEST #35: " << vec << ".normalized3D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.normalized3D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #36
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(3, 3, -3, 4, 7, 7, -11, 8);
	std::cout << "TEST #36: " << vec << ".orthogonal3D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.orthogonal3D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #37
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(VectorF(sqrtf(14)), VectorF(sqrtf(110)));
	std::cout << "TEST #37: " << vec << ".lengthVec3D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.lengthVec3D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #38
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(VectorF(14), VectorF(110));
	std::cout << "TEST #38: " << vec << ".sqrLengthVec3D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.sqrLengthVec3D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #39
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(1 / sqrtf(14), 2 / sqrtf(14), 3 / sqrtf(14), 4 / sqrtf(14), 5 / sqrtf(110), 6 / sqrtf(110), 7 / sqrtf(110), 8 / sqrtf(110));
	std::cout << "TEST #39: " << vec << ".normalizedFast3D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.normalizedFast3D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.01f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #40
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	valuePrediction = sqrtf(5);
	value2Prediction = sqrtf(61);
	std::cout << "TEST #40: " << vec << ".length2D()" << " == " << valuePrediction << ", " << value2Prediction << std::endl;
	vec.length2D(valueResult, value2Result);
	result = valuePrediction == valueResult && value2Result == value2Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << ", " << value2Result << std::endl;
		return false;
	}

	// TEST #41
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	valuePrediction = 5;
	value2Prediction = 61;
	std::cout << "TEST #41: " << vec << ".sqrLength2D()" << " == " << valuePrediction << ", " << value2Prediction << std::endl;
	vec.sqrLength2D(valueResult, value2Result);
	result = valuePrediction == valueResult && value2Result == value2Prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << ", " << value2Result << std::endl;
		return false;
	}

	// TEST #42
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(1 / sqrtf(5), 2 / sqrtf(5), 3 / sqrtf(5), 4 / sqrtf(5), 5 / sqrtf(61), 6 / sqrtf(61), 7 / sqrtf(61), 8 / sqrtf(61));
	std::cout << "TEST #42: " << vec << ".normalized2D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.normalized2D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #43
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(-2, 1, 1, 1, -6, 5, 5, 5);
	std::cout << "TEST #43: " << vec << ".orthogonal2D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.orthogonal2D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #44
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(VectorF(sqrtf(5)), VectorF(sqrtf(61)));
	std::cout << "TEST #44: " << vec << ".lengthVec2D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.lengthVec2D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #45
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(VectorF(5), VectorF(61));
	std::cout << "TEST #45: " << vec << ".sqrLengthVec2D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.sqrLengthVec2D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.0001f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #46
	vec = DoubleVectorF(1, 2, 3, 4, 5, 6, 7, 8);
	vecPrediction = DoubleVectorF(1 / sqrtf(5), 2 / sqrtf(5), 3 / sqrtf(5), 4 / sqrtf(5), 5 / sqrtf(61), 6 / sqrtf(61), 7 / sqrtf(61), 8 / sqrtf(61));
	std::cout << "TEST #46: " << vec << ".normalizedFast2D()" << " == " << vecPrediction << std::endl;
	vecResult = vec.normalizedFast2D();
	result = vecResult.isEqualPrec(vecPrediction, DoubleVectorF(0.01f));
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	return true;
}