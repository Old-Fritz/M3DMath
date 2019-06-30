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
	return true;
}
