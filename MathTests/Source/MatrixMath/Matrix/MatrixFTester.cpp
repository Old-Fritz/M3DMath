#include "MathTests.h"
#include <cmath>
using namespace M3DM;

bool MatrixFTester::testAll()
{
	bool result;
	std::cout << "------MATRIX SIMD TEST------" << std::endl;
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

	std::cout << "--Test store--" << std::endl;
	result = testStore();
	if (!result)
		return false;

	std::cout << "--Test get and set--" << std::endl;
	result = testGetSet();
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


bool MatrixFTester::testEqual()
{
	return true;
}

bool MatrixFTester::testCmp()
{
	return true;
}

bool MatrixFTester::testStore()
{
	return true;
}

bool MatrixFTester::testGetSet()
{
	return true;
}

bool MatrixFTester::testConversions()
{
	return true;
}

bool MatrixFTester::testAdd()
{
	return true;
}

bool MatrixFTester::testSub()
{
	return true;
}

bool MatrixFTester::testMul()
{
	return true;
}

bool MatrixFTester::testDiv()
{
	return true;
}

bool MatrixFTester::testFunctions()
{
	
	MatrixF matrix, matrixPrediction, matrixResult;
	float valueResult, valuePrediction;
	bool result;

	// TEST #1
	matrixPrediction = MatrixF(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	std::cout << "TEST #1: matrixScalarIdentity()" << " == " << matrixPrediction << std::endl;
	matrixResult = matrixFIdentity();
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	matrixPrediction = MatrixF(INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY);
	std::cout << "TEST #2: matrixScalarInfinity()" << " == " << matrixPrediction << std::endl;
	matrixResult = matrixFInfinity();
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #3
	matrix = MatrixF(1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16);
	matrixPrediction = MatrixF(1, 5, 9, 13,
		2, 6, 10, 14,
		3, 7, 11, 15,
		4, 8, 12, 16);
	std::cout << "TEST #3: " << matrix << ".transpose()" << " == " << matrixPrediction << std::endl;
	matrixResult = matrix.transpose();
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}
	
	return true;
}
