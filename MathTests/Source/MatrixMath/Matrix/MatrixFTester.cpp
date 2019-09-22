#include "MathTests.h"
#include <cmath>
using namespace M3DM;

Bool MatrixFTester::testAll()
{
	Bool result;
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

	std::cout << "--Test load--" << std::endl;
	result = testLoad();
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


Bool MatrixFTester::testEqual()
{
	MatrixF m1, m2, matrixPrecision, matrixResult, matrixPrediction;
	Float precision;
	Bool result, boolPrediciton;

	// TEST #1
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	std::cout << "TEST #1: (" << m1 << " == " << m2 << ") == " << boolPrediciton << std::endl;
	result = (m1 == m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #2
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #2: (" << m1 << " == " << m2 << ") == " << boolPrediciton << std::endl;
	result = (m1 == m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #3
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 11, 12, 14, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #3: (" << m1 << " == " << m2 << ") == " << boolPrediciton << std::endl;
	result = (m1 == m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #4
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10.000001f, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #4: (" << m1 << " == " << m2 << ") == " << boolPrediciton << std::endl;
	result = (m1 == m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #5
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	std::cout << "TEST #5: " << m1 << ".isEqualPrec(" << m2 << ") == " << boolPrediciton << std::endl;
	result = m1.isEqualPrec(m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #6
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10.0001f, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #6: " << m1 << ".isEqualPrec(" << m2 << ") == " << boolPrediciton << std::endl;
	result = m1.isEqualPrec(m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #7
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 7.99999f, 9, 10.0003f, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
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
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 7.99999f, 9, 10.0003f, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
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
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 7.99999f, 9, 10.0003f, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	matrixPrecision = MatrixF(0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f);
	std::cout << "TEST #9: " << m1 << ".isEqualPrec(" << m2 << ", " << matrixPrecision << ") == " << boolPrediciton << std::endl;
	result = m1.isEqualPrec(m2, matrixPrecision) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	// TEST #10
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 7.99999f, 9, 10.0003f, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	matrixPrecision = MatrixF(0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.0001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f, 0.001f);
	std::cout << "TEST #9: " << m1 << ".isEqualPrec(" << m2 << ", " << matrixPrecision << ") == " << boolPrediciton << std::endl;
	result = m1.isEqualPrec(m2, matrixPrecision) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed." << std::endl;
		return false;
	}

	return true;
}

Bool MatrixFTester::testCmp()
{
	MatrixF m1, m2;
	Bool result, boolPrediciton;

	// TEST #1
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #1: " << m1 << " < " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 < m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #2
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	boolPrediciton = true;
	std::cout << "TEST #2: " << m1 << " < " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 < m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #3
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #3: " << m1 << " > " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 > m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #4
	m1 = MatrixF(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	std::cout << "TEST #4: " << m1 << " > " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 > m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #5
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	std::cout << "TEST #5: " << m1 << " <= " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 <= m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #6
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	boolPrediciton = true;
	std::cout << "TEST #6: " << m1 << " <= " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 <= m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #7
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = false;
	std::cout << "TEST #7: " << m1 << " <= " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 <= m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #8
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	std::cout << "TEST #8: " << m1 << " >= " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 >= m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #9
	m1 = MatrixF(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	boolPrediciton = true;
	std::cout << "TEST #9: " << m1 << " >= " << m2 << " == " << boolPrediciton << std::endl;
	result = (m1 >= m2) == boolPrediciton;
	if (!result)
	{
		std::cout << "Failed. " << std::endl;
		return false;
	}

	// TEST #10
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 14, 15, 16);
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

Bool MatrixFTester::testLoad()
{
	Float pArray[16];
	MatrixScalar matrixScalar;
	VectorF row1, row2, row3, row4;
	MatrixF matrixResult;
	MatrixF matrixPrediction;
	Bool result;

	// TEST #1
	for (Int32 i = 0; i < 16; i++)
		pArray[i] = i + 1;
	matrixPrediction = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	matrixResult = MatrixF();
	std::cout << "TEST #1: " << matrixResult << ".load(";
	for (Int32 i = 0; i < 15; i++)
		std::cout << pArray[i] << ", ";
	std::cout << pArray[15];
	std::cout << ") == " << matrixPrediction << std::endl;
	matrixResult.load(pArray[0], pArray[1], pArray[2], pArray[3],
		pArray[4], pArray[5], pArray[6], pArray[7],
		pArray[8], pArray[9], pArray[10], pArray[11],
		pArray[12], pArray[13], pArray[14], pArray[15]);
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	for (Int32 i = 0; i < 16; i++)
		pArray[i] = i + 1;
	matrixPrediction = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	matrixResult = MatrixF();
	std::cout << "TEST #2: " << matrixResult << ".load({";
	for (Int32 i = 0; i < 15; i++)
		std::cout << pArray[i] << ", ";
	std::cout << pArray[15];
	std::cout << "}) == " << matrixPrediction << std::endl;
	matrixResult.load(pArray);
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #3
	matrixScalar = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	matrixPrediction = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	matrixResult = MatrixF();
	std::cout << "TEST #3: " << matrixResult << ".load( " << matrixScalar << " ) == " << matrixPrediction << std::endl;
	matrixResult.load(matrixScalar);
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #4
	row1 = VectorF(1, 2, 3, 4);
	row2 = VectorF(5, 6, 7, 8);
	row3 = VectorF(9, 10, 11, 12);
	row4 = VectorF(13, 14, 15, 16);
	matrixPrediction = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	matrixResult = MatrixF();
	std::cout << "TEST #4: " << matrixResult << ".load( " << row1 << ", " << row2 << ", " << row3 << ", " << row4 << " ) == " << matrixPrediction << std::endl;
	matrixResult.load(row1, row2, row3, row4);
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	return true;
}

Bool MatrixFTester::testStore()
{
	Float pArrayResult[16], pArrayPrediction[16];
	MatrixScalar matrixScalarResult, matrixScalarPrediction;
	VectorF row1Result, row2Result, row3Result, row4Result, row1Prediction, row2Prediction, row3Prediction, row4Prediction;
	MatrixF matrix;
	Bool result;

	// TEST #1
	for (Int32 i = 0; i < 16; i++)
		pArrayPrediction[i] = i + 1;
	matrix = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	std::cout << "TEST #1: " << matrix << ".store(";
	for (Int32 i = 0; i < 15; i++)
		std::cout << pArrayResult[i] << ", ";
	std::cout << pArrayResult[15];
	std::cout << ") == ";
	for (Int32 i = 0; i < 15; i++)
		std::cout << pArrayPrediction[i] << ", ";
	std::cout << pArrayPrediction[15] << std::endl;

	matrix.store(pArrayResult[0], pArrayResult[1], pArrayResult[2], pArrayResult[3],
		pArrayResult[4], pArrayResult[5], pArrayResult[6], pArrayResult[7],
		pArrayResult[8], pArrayResult[9], pArrayResult[10], pArrayResult[11],
		pArrayResult[12], pArrayResult[13], pArrayResult[14], pArrayResult[15]);
	result = true;
	for(Int32 i = 0; i < 16; i++)
	result = result && (pArrayResult[i] == pArrayPrediction[i]);
	if (!result)
	{
		std::cout << "Failed. Computed value: ";
		for (Int32 i = 0; i < 15; i++)
			std::cout << pArrayPrediction[i] << ", ";
		std::cout << pArrayPrediction[15] << std::endl;
		return false;
	}

	// TEST #2
	for (Int32 i = 0; i < 16; i++)
		pArrayPrediction[i] = i + 1;
	matrix = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	std::cout << "TEST #2: " << matrix << ".store({";
	for (Int32 i = 0; i < 15; i++)
		std::cout << pArrayResult[i] << ", ";
	std::cout << pArrayResult[15];
	std::cout << "}) == {";
	for (Int32 i = 0; i < 15; i++)
		std::cout << pArrayPrediction[i] << ", ";
	std::cout << pArrayPrediction[15] << "}" << std::endl;

	matrix.store(pArrayResult);
	result = true;
	for (Int32 i = 0; i < 16; i++)
		result = result && (pArrayResult[i] == pArrayPrediction[i]);
	if (!result)
	{
		std::cout << "Failed. Computed value: {";
		for (Int32 i = 0; i < 15; i++)
			std::cout << pArrayPrediction[i] << ", ";
		std::cout << pArrayPrediction[15] << "}" << std::endl;
		return false;
	}

	// TEST #3
	matrix = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	matrixScalarPrediction = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	std::cout << "TEST #3: " << matrix << ".store( " << matrixScalarResult << " ) == " << matrixScalarPrediction << std::endl;
	matrix.store(matrixScalarResult);
	result = matrixScalarResult == matrixScalarPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixScalarResult << std::endl;
		return false;
	}

	// TEST #4
	matrix = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	row1Prediction = VectorF(1, 2, 3, 4);
	row2Prediction = VectorF(5, 6, 7, 8);
	row3Prediction = VectorF(9, 10, 11, 12);
	row4Prediction = VectorF(13, 14, 15, 16);
	std::cout << "TEST #4: " << matrix << ".store( " 
		<< row1Result << ", " << row2Result << ", " << row3Result << ", " << row4Result <<
		" ) == " 
		<< row1Prediction << ", " << row2Prediction << ", " << row3Prediction << ", " << row4Prediction <<  std::endl;
	matrix.store(row1Result, row2Result, row3Result, row4Result);
	result = (row1Result == row1Prediction) && (row2Result == row2Prediction) && (row3Result == row3Prediction) && (row4Result == row4Prediction);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << row1Result << ", " << row2Result << ", " << row3Result << ", " << row4Result << std::endl;
		return false;
	}

	return true;
}

Bool MatrixFTester::testGetSet()
{
	MatrixF matrix, matrixPrediction;
	Float valuef, valuefResult, valuefPrediction;
	Int32 ind, valuei, valueiResult, valueiPrediction;
	Bool result;

	// TEST #1
	matrix = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	matrixPrediction = MatrixF(1, 2, 3, 4, 5, 6, 5, 8, 9, 10, 11, 12, 13, 14, 15, 16);;
	valuef = 5;
	ind = 6;
	std::cout << "TEST #1: " << matrix << ".set(" << ind << ", " << valuef << ") == " << matrixPrediction << std::endl;
	matrix.set(ind, valuef);
	result = matrix == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrix << std::endl;
		return false;
	}

	// TEST #2
	matrix = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	matrixPrediction = MatrixF(5, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	valuef = 5;
	ind = 0;
	std::cout << "TEST #2: " << matrix << ".set(" << ind << ", " << valuef << ") == " << matrixPrediction << std::endl;
	matrix.set(ind, valuef);
	result = matrix == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrix << std::endl;
		return false;
	}

	// TEST #3
	matrix = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	matrixPrediction = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, int2Float(5), 11, 12, 13, 14, 15, 16);
	valuei = 5;
	ind = 9;
	std::cout << "TEST #3: " << matrix << ".setInt(" << ind << ", " << valuei << ") == " << matrixPrediction << std::endl;
	matrix.setInt(ind, valuei);
	result = matrix == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrix << std::endl;
		return false;
	}

	// TEST #4
	matrix = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	matrixPrediction = MatrixF(int2Float(5), 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	valuei = 5;
	ind = 0;
	std::cout << "TEST #4: " << matrix << ".setInt(" << ind << ", " << valuei << ") == " << matrixPrediction << std::endl;
	matrix.setInt(ind, valuei);
	result = matrix == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrix << std::endl;
		return false;
	}

	// TEST #5
	matrix = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	valuefPrediction = 13;
	ind = 12;
	std::cout << "TEST #5: " << matrix << ".get(" << ind << ") == " << valuefPrediction << std::endl;
	valuefResult = matrix.get(ind);
	result = valuefPrediction == valuefResult;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valuefResult << std::endl;
		return false;
	}

	// TEST #6
	matrix = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	valuefPrediction = 1;
	ind = 0;
	std::cout << "TEST #6: " << matrix << ".get(" << ind << ") == " << valuefPrediction << std::endl;
	valuefResult = matrix.get(ind);
	result = valuefPrediction == valuefResult;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valuefResult << std::endl;
		return false;
	}

	// TEST #7
	matrix = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	valueiPrediction = float2Int(16);
	ind = 15;
	std::cout << "TEST #7: " << matrix << ".getInt(" << ind << ") == " << valueiPrediction << std::endl;
	valueiResult = matrix.getInt(ind);
	result = valueiPrediction == valueiResult;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueiResult << std::endl;
		return false;
	}

	// TEST #8
	matrix = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	valueiPrediction = float2Int(1);
	ind = 0;
	std::cout << "TEST #8: " << matrix << ".getInt(" << ind << ") == " << valueiPrediction << std::endl;
	valueiResult = matrix.getInt(ind);
	result = valueiPrediction == valueiResult;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueiResult << std::endl;
		return false;
	}

	return true;
}

Bool MatrixFTester::testConversions()
{
	Float pArray[16];
	MatrixScalar matrixScalar;
	VectorF row1, row2, row3, row4;
	MatrixF matrixResult;
	MatrixF matrixPrediction;
	Bool result;

	// TEST #1
	for (Int32 i = 0; i < 16; i++)
		pArray[i] = i + 1;
	matrixPrediction = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	std::cout << "TEST #1: MatrixF({";
	for (Int32 i = 0; i < 15; i++)
		std::cout << pArray[i] << ", ";
	std::cout << pArray[15];
	std::cout << "}) == " << matrixPrediction << std::endl;
	matrixResult = MatrixF(pArray);
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	matrixScalar = MatrixScalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	matrixPrediction = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	std::cout << "TEST #2: MatrixF( " << matrixScalar << " ) == " << matrixPrediction << std::endl;
	matrixResult = MatrixF(matrixScalar);
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #3
	row1 = VectorF(1, 2, 3, 4);
	row2 = VectorF(5,6,7,8);
	row3 = VectorF(9,10,11,12);
	row4 = VectorF(13,14,15,16);
	matrixPrediction = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	std::cout << "TEST #3: MatrixF( " << row1 << ", " << row2 << ", " << row3 << ", " << row4 << " ) == " << matrixPrediction << std::endl;
	matrixResult = MatrixF(row1,row2,row3,row4);
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

#ifdef DIRECTX
	// TEST #4
	DirectX::XMFLOAT4X4 directxFloat4x4 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	DirectX::XMMATRIX directxMatrix = DirectX::XMLoadFloat4x4(&directxFloat4x4);
	matrixPrediction = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	std::cout << "TEST #4: MatrixF( directxMatrix ) == " << matrixPrediction << std::endl;
	matrixResult = MatrixF(directxMatrix);
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}
#endif
	return true;
}

Bool MatrixFTester::testAdd()
{
	MatrixF m1, m2, prediction, matrixResult;
	Bool result;

	// TEST #1
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	prediction = MatrixF(3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33);
	std::cout << "TEST #1: " << m1 << " + " << m2 << " == " << prediction << std::endl;
	matrixResult = m1 + m2;
	result = matrixResult == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #1
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	prediction = MatrixF(3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33);
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

Bool MatrixFTester::testSub()
{
	MatrixF m1, m2, prediction, matrixResult;
	Bool result;

	// TEST #1
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	prediction = MatrixF(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
	std::cout << "TEST #1: " << m1 << " - " << m2 << " == " << prediction << std::endl;
	matrixResult = m1 - m2;
	result = matrixResult == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #1
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	prediction = MatrixF(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
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

Bool MatrixFTester::testMul()
{
	MatrixF m1, m2, prediction, matrixResult;
	Float value;
	Bool result;

	// TEST #1
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	value = 2;
	prediction = MatrixF(2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32);
	std::cout << "TEST #1: " << m1 << " * " << value << " == " << prediction << std::endl;
	matrixResult = m1 * value;
	result = matrixResult == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	value = 2;
	prediction = MatrixF(2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32);
	std::cout << "TEST #2: " << m1 << " *= " << value << " == " << prediction << std::endl;
	m1 *= value;
	result = m1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << m1 << std::endl;
		return false;
	}

	// TEST #3
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	value = 2;
	prediction = MatrixF(2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32);
	std::cout << "TEST #3: " << value << " * " << m1 << " == " << prediction << std::endl;
	matrixResult = value * m1;
	result = matrixResult == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #4
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	prediction = MatrixF(100, 110, 120, 130,
		228, 254, 280, 306,
		356, 398, 440, 482,
		484, 542, 600, 658);
	std::cout << "TEST #4: " << m1 << " * " << m2 << " == " << prediction << std::endl;
	matrixResult = m1 * m2;
	result = matrixResult == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #5
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	//prediction = DirectX::XMMatrixMultiply(m1.XMMatrix(), m2.XMMatrix());
	prediction = MatrixF(100, 110, 120, 130,
		228, 254, 280, 306,
		356, 398, 440, 482,
		484, 542, 600, 658);
	std::cout << "TEST #5: " << m1 << " *= " << m2 << " == " << prediction << std::endl;
	m1 *= m2;
	result = m1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << m1 << std::endl;
		return false;
	}

#ifdef DIRECTX
	// TEST #6
	//MatrixF s1, s2, sPrediction;
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	m2 = MatrixF(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
	prediction = m1.XMMatrix() * m2.XMMatrix();
	//prediction = MatrixF(100, 110, 120, 130,
	//	228, 254, 280, 306,
	//	356, 398, 440, 482,
	//	484, 542, 600, 658);
	std::cout << "TEST #6: " << m1 << " * " << m2 << " == " << prediction << std::endl;
	m1 *= m2;
	result = m1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << m1 << std::endl;
		return false;
	}
#endif
	return true;
}

Bool MatrixFTester::testDiv()
{
	MatrixF m1, prediction, matrixResult;
	Float value;
	Bool result;

	// TEST #1
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	value = 2;
	prediction = MatrixF(0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8);
	std::cout << "TEST #1: " << m1 << " / " << value << " == " << prediction << std::endl;
	matrixResult = m1 / value;
	result = matrixResult == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	value = 2;
	prediction = MatrixF(0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8);
	std::cout << "TEST #2: " << m1 << " /= " << value << " == " << prediction << std::endl;
	m1 /= value;
	result = m1 == prediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << m1 << std::endl;
		return false;
	}

	// TEST #3
	m1 = MatrixF(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	value = 2;
	prediction = MatrixF(2, 1, 2.0 / 3, 2.0 / 4, 2.0 / 5, 2.0 / 6, 2.0 / 7, 2.0 / 8, 2.0 / 9, 2.0 / 10, 2.0 / 11, 2.0 / 12, 2.0 / 13, 2.0 / 14, 2.0 / 15, 2.0 / 16);
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

Bool MatrixFTester::testFunctions()
{
	
	MatrixF matrix, matrixPrediction, matrixResult;
	Float valueResult, valuePrediction;
	VectorF vecResult, vecPrediction;
	Bool result;

	// TEST #1
	matrixPrediction = MatrixF(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	std::cout << "TEST #1: MatrixFIdentity()" << " == " << matrixPrediction << std::endl;
	matrixResult = matrixFIdentity();
	result = matrixResult == matrixPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	// TEST #2
	matrixPrediction = MatrixF(INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY);
	std::cout << "TEST #2: MatrixFInfinity()" << " == " << matrixPrediction << std::endl;
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

	// TEST #4
	matrix = MatrixF(2, 2, 3, 4,
		5, 7, 7, 8,
		9, 10, 12, 12,
		13, 14, 15, 17);
	vecPrediction = VectorF(-45);
	std::cout << "TEST #4: " << matrix << ".determinantVec()" << " == " << vecPrediction << std::endl;
	vecResult = matrix.determinantVec();
	result = vecResult == vecPrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << vecResult << std::endl;
		return false;
	}

	// TEST #5
	matrix = MatrixF(2, 2, 3, 4,
		5, 7, 7, 8,
		9, 10, 12, 12,
		13, 14, 15, 17);
	valuePrediction = -45;
	std::cout << "TEST #5: " << matrix << ".determinant()" << " == " << valuePrediction << std::endl;
	valueResult = matrix.determinant();
	result = valueResult == valuePrediction;
	if (!result)
	{
		std::cout << "Failed. Computed value: " << valueResult << std::endl;
		return false;
	}

	// TEST #6
	matrix = MatrixF(2, 2, 3, 4,
		5, 7, 7, 8,
		9, 10, 12, 12,
		13, 14, 15, 17);
	matrixPrediction = MatrixF(-0.2222222, -0.6666666, -0.11111111, 0.4444444,
		-0.6, 0.6, -0.2, -0,
		0.0222222, -0.1333333, 0.711111, -0.4444444,
		0.6444444, 0.1333333, -0.3777777, 0.1111111);
	std::cout << "TEST #6: " << matrix << ".inverse()" << " == " << matrixPrediction << std::endl;
	matrixResult = matrix.inverse();
	result = matrixResult.isEqualPrec(matrixPrediction, 0.000001f);
	if (!result)
	{
		std::cout << "Failed. Computed value: " << matrixResult << std::endl;
		return false;
	}

	return true;
}
