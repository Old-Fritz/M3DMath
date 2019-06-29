#include "MathTests.h"
#include <cmath>
using namespace M3DM;

bool MatrixScalarTester::testAll()
{
	bool result;
	std::cout << "------MATRIX SCALAR TEST------" << std::endl;
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

bool MatrixScalarTester::testEqual()
{
	MatrixScalar m1, m2, matrixPrecision, matrixResult, matrixPrediction;
	float precision;
	bool result, boolPrediciton;
	
	// TEST #1
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	std::cout << "TEST #1: (" << m1 << " == " << m2 << ") == " << boolPrediciton << std::endl;
	result = (m1 == m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #2
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #2: (" << m1 << " == " << m2 << ") == " << boolPrediciton << std::endl;
	result = (m1 == m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #3
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 11, 12, 14, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #3: (" << m1 << " == " << m2 << ") == " << boolPrediciton << std::endl;
	result = (m1 == m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #4
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10.000001f, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #4: (" << m1 << " == " << m2 << ") == " << boolPrediciton << std::endl;
	result = (m1 == m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #5
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	std::cout << "TEST #5: " << m1 << ".isEqualPrec(" << m2 << ") == " << boolPrediciton << std::endl;
	result = m1.isEqualPrec(m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #6
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10.0001f, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #6: " << m1 << ".isEqualPrec(" << m2 << ") == " << boolPrediciton << std::endl;
	result = m1.isEqualPrec(m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #7
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 7.99999f, 9, 10.0003f, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	precision = 0.001f;
	std::cout << "TEST #7: " << m1 << ".isEqualPrec(" << m2 << ", " << precision << ") == " << boolPrediciton << std::endl;
	result = m1.isEqualPrec(m2, precision) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #8
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 7.99999f, 9, 10.0003f, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	precision = 0.0000001f;
	std::cout << "TEST #8: " << m1 << ".isEqualPrec(" << m2 << ", " << precision << ") == " << boolPrediciton << std::endl;
	result = m1.isEqualPrec(m2, precision) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #9
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 7.99999f, 9, 10.0003f, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	matrixPrecision = MatrixScalar(0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f);
	std::cout << "TEST #9: " << m1 << ".isEqualPrec(" << m2 << ", " << matrixPrecision << ") == " << boolPrediciton << std::endl;
	result = m1.isEqualPrec(m2, matrixPrecision) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #10
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 7.99999f, 9, 10.0003f, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	matrixPrecision = MatrixScalar(0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.0001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f);
	std::cout << "TEST #9: " << m1 << ".isEqualPrec(" << m2 << ", " << matrixPrecision << ") == " << boolPrediciton << std::endl;
	result = m1.isEqualPrec(m2, matrixPrecision) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	return true;
}

bool MatrixScalarTester::testCmp()
{
	return true;
}

bool MatrixScalarTester::testConversions()
{
	return true;
}

bool MatrixScalarTester::testAdd()
{
	return true;
}

bool MatrixScalarTester::testSub()
{
	return true;
}

bool MatrixScalarTester::testMul()
{
	return true;
}

bool MatrixScalarTester::testDiv()
{
	return true;
}

bool MatrixScalarTester::testFunctions()
{
	return true;
}
