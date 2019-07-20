#include "MathTests.h"
#include <cmath>
using namespace M3DM;

bool MatrixFFunctionsTester::testAll()
{
	bool result;
	std::cout << "------MATRIX FUNCTIONS SIMD TEST------" << std::endl;

	std::cout << "--Test scale--" << std::endl;
	result = testScale();
	if (!result)
		return false;

	std::cout << "--Test rotation--" << std::endl;
	result = testRotation();
	if (!result)
		return false;

	std::cout << "--Test translation--" << std::endl;
	result = testTranslation();
	if (!result)
		return false;

	std::cout << "--Test transform--" << std::endl;
	result = testTransform();
	if (!result)
		return false;

	std::cout << "--Test special LH--" << std::endl;
	result = testSpecialLH();
	if (!result)
		return false;

	std::cout << "--Test special RH--" << std::endl;
	result = testSpecialRH();
	if (!result)
		return false;

	return true;
}

bool MatrixFFunctionsTester::testScale()
{
	return true;
}

bool MatrixFFunctionsTester::testRotation()
{
	return true;
}

bool MatrixFFunctionsTester::testTranslation()
{
	return true;
}

bool MatrixFFunctionsTester::testTransform()
{
	return true;
}

bool MatrixFFunctionsTester::testSpecialLH()
{
	return true;
}

bool MatrixFFunctionsTester::testSpecialRH()
{
	return true;
}
