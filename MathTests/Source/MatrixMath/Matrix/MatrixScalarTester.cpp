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
	MatrixScalar m1, m2;
	bool result, boolPrediciton;

	// TEST #1
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #1: " << m1 << " < " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 < m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #2
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	boolPrediciton = true;
	std::cout << "TEST #2: " << m1 << " < " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 < m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #3
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #3: " << m1 << " > " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 > m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #4
	m1 = MatrixScalar(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	std::cout << "TEST #4: " << m1 << " > " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 > m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #5
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	std::cout << "TEST #5: " << m1 << " <= " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 <= m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #6
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	boolPrediciton = true;
	std::cout << "TEST #6: " << m1 << " <= " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 <= m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #7
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #7: " << m1 << " <= " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 <= m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #8
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	std::cout << "TEST #8: " << m1 << " >= " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 >= m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #9
	m1 = MatrixScalar(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	std::cout << "TEST #9: " << m1 << " >= " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 >= m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #10
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #10: " << m1 << " >= " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 >= m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}


	return true;
}

bool MatrixScalarTester::testConversions()
{
	float pArray[16], pArrayPrediction[16];
	float* pArrayRes;
	MatrixScalar matrixResult;
	MatrixScalar matrixPrediction;
	bool result;

	// TEST #1
	for (int i = 0; i < 16; i++)
		pArray[i] = i+1;
	matrixPrediction = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	std::cout << "TEST #1: MatrixScalar({";
	for (int i = 0; i < 15; i++)
		std::cout << pArray[i] << ", ";
	std::cout << pArray[15];
	std::cout << "}) == " << matrixPrediction << std::endl;
	matrixResult = MatrixScalar(pArray);
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	matrixResult = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	for (int i = 0; i < 16; i++)
		pArrayPrediction[i] = i + 1;
	std::cout << "TEST #2: float*(" << matrixResult << ") == {";
	for (int i = 0; i < 15; i++)
		std::cout << pArrayPrediction[i] << ", ";
	std::cout << pArrayPrediction[15];
	std::cout << "}" << std::endl;
	pArrayRes = matrixResult;
	result = 1;
	for (int i = 0; i < 16; i++)
		result = result & (pArrayRes[i] == pArrayPrediction[i]);
	if (!result)
	{
		std::cout << "Failed. Computed value: {";
		for (int i = 0; i < 15; i++)
			std::cout << pArrayRes[i] << ", ";
		std::cout << pArrayRes[15];
		std::cout << "}" << std::endl;
		return false;
	}

	return true;
}

bool MatrixScalarTester::testAdd()
{
	MatrixScalar m1, m2, prediction, matrixResult;
	bool result;

	// TEST #1
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	prediction = MatrixScalar(3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33);
	std::cout << "TEST #1: " << m1 << " + " << m2 << " == " << prediction << std::endl;
	matrixResult = m1 + m2;
	result = matrixResult == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #1
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	prediction = MatrixScalar(3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33);
	std::cout << "TEST #1: " << m1 << " += " << m2 << " == " << prediction << std::endl;
	m1 += m2;
	result = m1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << m1 << std::endl;
		return false;
	}

	return true;
}

bool MatrixScalarTester::testSub()
{
	MatrixScalar m1, m2, prediction, matrixResult;
	bool result;

	// TEST #1
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	prediction = MatrixScalar(-1,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
	std::cout << "TEST #1: " << m1 << " - " << m2 << " == " << prediction << std::endl;
	matrixResult = m1 - m2;
	result = matrixResult == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #1
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	prediction = MatrixScalar(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
	std::cout << "TEST #2: " << m1 << " -= " << m2 << " == " << prediction << std::endl;
	m1 -= m2;
	result = m1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << m1 << std::endl;
		return false;
	}

	return true;
}

bool MatrixScalarTester::testMul()
{
	MatrixScalar m1, m2, prediction, matrixResult;
	float value;
	bool result;

	// TEST #1
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	value = 2;
	prediction = MatrixScalar(2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32);
	std::cout << "TEST #1: " << m1 << " * " << value << " == " << prediction << std::endl;
	matrixResult = m1 * value;
	result = matrixResult == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	value = 2;
	prediction = MatrixScalar(2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32);
	std::cout << "TEST #2: " << m1 << " *= " << value << " == " << prediction << std::endl;
	m1 *= value;
	result = m1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << m1 << std::endl;
		return false;
	}

	// TEST #3
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	value = 2;
	prediction = MatrixScalar(2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32);
	std::cout << "TEST #3: " << value << " * " << m1 << " == " << prediction << std::endl;
	matrixResult = value * m1;
	result = matrixResult == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #4
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	prediction = DirectX::XMMatrixMultiply(m1.XMMatrix(), m2.XMMatrix());
	std::cout << "TEST #4: " << m1 << " * " << m2 << " == " << prediction << std::endl;
	matrixResult = m1 * m2;
	result = matrixResult == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #5
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixScalar(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	prediction = DirectX::XMMatrixMultiply(m1.XMMatrix(), m2.XMMatrix());
	std::cout << "TEST #5: " << m1 << " *= " << m2 << " == " << prediction << std::endl;
	m1 *= m2;
	result = m1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << m1 << std::endl;
		return false;
	}

	return true;
}

bool MatrixScalarTester::testDiv()
{
	MatrixScalar m1, prediction, matrixResult;
	float value;
	bool result;

	// TEST #1
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	value = 2;
	prediction = MatrixScalar(0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8);
	std::cout << "TEST #1: " << m1 << " / " << value << " == " << prediction << std::endl;
	matrixResult = m1 / value;
	result = matrixResult == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	value = 2;
	prediction = MatrixScalar(0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8);
	std::cout << "TEST #2: " << m1 << " /= " << value << " == " << prediction << std::endl;
	m1 /= value;
	result = m1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << m1 << std::endl;
		return false;
	}

	// TEST #3
	m1 = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	value = 2;
	prediction = MatrixScalar(2, 1, 2.0 / 3, 2.0 / 4, 2.0 / 5, 2.0 / 6, 2.0 / 7, 2.0 / 8, 2.0 / 9, 2.0 / 10, 2.0 / 11, 2.0 / 12, 2.0 / 13, 2.0 / 14, 2.0 / 15, 2.0 / 16);
	std::cout << "TEST #3: " << m1 << " / " << value << " == " << prediction << std::endl;
	matrixResult = value / m1;
	result = matrixResult.isEqualPrec(prediction, 0.001f);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	return true;
}

bool MatrixScalarTester::testFunctions()
{
	MatrixScalar matrix, matrixPrediction, matrixResult;
	float valueResult, valuePrediction;
	bool result;

	// TEST #1
	matrixPrediction = MatrixScalar(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
	std::cout << "TEST #1: matrixScalarIdentity()" << " == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarIdentity();
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	matrixPrediction = MatrixScalar(INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY);
	std::cout << "TEST #2: matrixScalarInfinity()" << " == " << matrixPrediction << std::endl;
	matrixResult = matrixScalarInfinity();
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #3
	matrix = MatrixScalar(1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16);
	matrixPrediction = MatrixScalar(1,5,9,13,
		2,6,10,14,
		3,7,11,15,
		4,8,12,16);
	std::cout << "TEST #3: " << matrix << ".transpose()" << " == " << matrixPrediction << std::endl;
	matrixResult = matrix.transpose();
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #4
	matrix = MatrixScalar(2, 2, 3, 4,
		5, 7, 7, 8,
		9, 10, 12, 12,
		13, 14, 15, 17);
	valuePrediction = VectorF(DirectX::XMMatrixDeterminant(matrix.XMMatrix())).get(0);
	std::cout << "TEST #4: " << matrix << ".determinant()" << " == " << valuePrediction << std::endl;
	valueResult = matrix.determinant();
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #5
	matrix = MatrixScalar(2, 2, 3, 4,
		5, 7, 7, 8,
		9, 10, 12, 12,
		13, 14, 15, 17);
	matrixPrediction = DirectX::XMMatrixInverse(0, matrix.XMMatrix());
	std::cout << "TEST #5: " << matrix << ".inverse()" << " == " << matrixPrediction << std::endl;
	matrixResult = matrix.inverse();
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	return true;
}
