#include "MathTests.h"

using namespace M3DM;

bool Vector2Tester::testAll()
{
	bool result;
	std::cout << "------VECTOR 2 TEST------" << std::endl;
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

	return true;
}

bool Vector2Tester::testEqual()
{
	Vector2 v1(1.5, 2.5);
	Vector2 v2(1.5, 2.5);
	bool result;

	std::cout << "((1.5, 2.5) == (1.5, 2.5)) == true" << std::endl;
	result = v1 == v2;
	if (!result)
		return false;

	std::cout << "((1.5, 2.5) == (2.5, 2.5)) == false" << std::endl;
	v2.x = 2.5;
	result = !(v1 == v2);
	if (!result)
		return false;

	std::cout << "(1.5, 2.5).isEqualPrec((2.5, 2.5), 0) == false" << std::endl;
	result = !v1.isEqualPrec(v2);
	if (!result)
		return false;

	std::cout << "(1.5, 2.5).isEqualPrec((1.5, 2.5), 0) == true" << std::endl;
	v2.x = 1.5;
	result = v1.isEqualPrec(v2);
	if (!result)
		return false;

	std::cout << "(1.5, 2.5).isEqualPrec((1.500005, 2.5), 0.00001) == true" << std::endl;
	v2.x = 1.500005;
	result = v1.isEqualPrec(v2, 0.00001);
	if (!result)
		return false;

	std::cout << "(1.5, 2.5).isEqualPrec((1.500005, 2.50002), 0.00001) == false" << std::endl;
	v2.y = 2.50002;
	result = !v1.isEqualPrec(v2, 0.00001);
	if (!result)
		return false;

	std::cout << "(1.5, 2.5).isEqualPrec((1.500005, 2.50002), (0.00001, 0.0001)) == true" << std::endl;
	Vector2 v3(0.00001, 0.0001);
	result = v1.isEqualPrec(v2,v3);
	if (!result)
		return false;

	std::cout << "(1.5, 2.5).isEqualPrec((1.500005, 2.50002), (-0.00001, 0.00002)) == false" << std::endl;
	v3.x = -0.00001;
	result = !v1.isEqualPrec(v2,v3);
	if (!result)
		return false;

	std::cout << "(1.5, 2.5).isEqualVec((1.500005, 2.5)) == (0,1)" << std::endl;
	v2.y = 2.5;
	result = v1.isEqualVec(v2) == Vector2(0, 1);
	if (!result)
		return false;

	std::cout << "(1.5, 2.5).isEqualVec((1.5, 2.5)) == (1,1)" << std::endl;
	v2 = v1;
	result = v1.isEqualVec(v2) == Vector2(1, 1);
	if (!result)
		return false;

	std::cout << "(1.6, 2.6).isEqualVec((1.5, 2.5)) == (0,0)" << std::endl;
	v1 = Vector2(1.6, 2.6);
	result = v1.isEqualVec(v2) == Vector2(0, 0);
	if (!result)
		return false;

	std::cout << "(1.6, 2.6).isEqualVecPrec((1.60001, 2.60002), (0.00001, 0.00001)) == (1,0)" << std::endl;
	v2 = Vector2(1.600005, 2.60002);
	v3 = Vector2(0.00001, 0.00001);
	result = v1.isEqualPrecVec(v2, v3) == Vector2(1, 0);
	if (!result)
		return false;

	return true;
}

bool Vector2Tester::testCmp()
{
	Vector2 v1, v2;
	bool result;

	std::cout << "(1.5, 2.5) < (1.5, 2.5) == false" << std::endl;
	v1 = Vector2(1.5, 2.5);
	v2 = Vector2(1.5, 2.5);
	result = v1 < v2 == false;
	if (!result)
		return false;

	std::cout << "(1.5, 2.5) < (1.6, 2.6) == true" << std::endl;
	v1 = Vector2(1.5, 2.5);
	v2 = Vector2(1.6, 2.6);
	result = v1 < v2 == true;
	if (!result)
		return false;

	std::cout << "(1.5, 2.5) > (1.5, 2.5) == false" << std::endl;
	v1 = Vector2(1.5, 2.5);
	v2 = Vector2(1.5, 2.5);
	result = v1 > v2 == false;
	if (!result)
		return false;

	std::cout << "(1.6, 2.6) > (1.5, 2.5) == true" << std::endl;
	v1 = Vector2(1.6, 2.6);
	v2 = Vector2(1.5, 2.5);
	result = v1 > v2 == true;
	if (!result)
		return false;

	std::cout << "(1.5, 2.5) <= (1.5, 2.5) == true" << std::endl;
	v1 = Vector2(1.5, 2.5);
	v2 = Vector2(1.5, 2.5);
	result = v1 <= v2 == true;
	if (!result)
		return false;

	std::cout << "(1.5, 2.5) <= (1.5, 2.5) == true" << std::endl;
	v1 = Vector2(1.5, 2.5);
	v2 = Vector2(1.5, 2.5);
	result = v1 <= v2 == true;
	if (!result)
		return false;

	std::cout << "(1.4, 2.4) >= (1.5, 2.5) == false" << std::endl;
	v1 = Vector2(1.4, 2.4);
	v2 = Vector2(1.5, 2.5);
	result = v1 >= v2 == false;
	if (!result)
		return false;

	std::cout << "(1.4, 2.4) <= (1.3, 2.5) == false" << std::endl;
	v1 = Vector2(1.4, 2.4);
	v2 = Vector2(1.3, 2.5);
	result = v1 <= v2 == false;
	if (!result)
		return false;

	std::cout << "(1.4, 2.4) >= (1.3, 2.3) == true" << std::endl;
	v1 = Vector2(1.4, 2.4);
	v2 = Vector2(1.3, 2.3);
	result = v1 >= v2 == true;
	if (!result)
		return false;

	return true;
}

bool Vector2Tester::testConversions()
{
	Vector2 v1;
	bool result;

	std::cout << "Vector2({1,2}) == (1,2)" << std::endl;
	float pArray[2] = { 1, 2 };
	v1 = Vector2(pArray);
	result = v1 == Vector2(1, 2);
	if (!result)
		return false;

	std::cout << "Vector2((1,2,3)) == (1,2)" << std::endl;
	Vector3 v2 = Vector3(1, 2, 3);
	v1 = Vector2(v2);
	result = v1 == Vector2(1, 2);
	if (!result)
		return false;

	std::cout << "Vector2((1,2,3,4)) == (1,2)" << std::endl;
	Vector4 v3 = Vector4(1, 2, 3, 4);
	v1 = Vector2(v3);
	result = v1 == Vector2(1, 2);
	if (!result)
		return false;

	std::cout << "float((1,2)) = pArray, pArray[1] == 1, pArray[2] == 2" << std::endl;
	float* pArray2 = v1;
	result = pArray[0] == 1 && pArray[1] == 2;
	if (!result)
		return false;

	return true;
}

bool Vector2Tester::testAdd()
{
	Vector2 v1(1, 2);
	Vector2 v2(2, 3);
	bool result;

	std::cout << "(1,2) + (2,3) == (3,5)" << std::endl;
	result = v1 + v2 == Vector2(3, 5);
	if (!result)
		return false;

	std::cout << "(1,2) += (2,3) == (3,5)" << std::endl;
	v1 += v2;
	result = v1 == Vector2(3, 5);
	if (!result)
		return false;

	return true;
}

bool Vector2Tester::testSub()
{
	Vector2 v1(1, 2);
	Vector2 v2(2, 3);
	bool result;

	std::cout << "(1,2) - (2,3) == (-1,-1)" << std::endl;
	result = v1 - v2 == Vector2(-1, -1);
	if (!result)
		return false;

	std::cout << "(1,2) -= (2,3) == (-1,-1)" << std::endl;
	v1 -= v2;
	result = v1 == Vector2(-1, -1);
	if (!result)
		return false;

	return true;
}

bool Vector2Tester::testMul()
{
	Vector2 v1(1, 2);
	Vector2 v2(2, 3);
	bool result;

	std::cout << "(1,2) * (2,3) == (2,6)" << std::endl;
	result = v1 * v2 == Vector2(2, 6);
	if (!result)
		return false;

	std::cout << "(1,2) *= (2,3) == (2,6)" << std::endl;
	v1 *= v2;
	result = v1 == Vector2(2, 6);
	if (!result)
		return false;

	return true;
}

bool Vector2Tester::testDiv()
{
	Vector2 v1(1, 2);
	Vector2 v2(2, 3);
	bool result;

	std::cout << "(1,2) / (2,3) == (0.5,0.66666) precision = 0.0001" << std::endl;
	result = (v1 / v2).isEqualPrec(Vector2(0.5, 0.66666), 0.0001);
	if (!result)
		return false;

	std::cout << "(1,2) /= (2,3) == (0.5,0.66666) precision = 0.0001" << std::endl;
	v1 /= v2;
	result = v1.isEqualPrec(Vector2(0.5, 0.66666), 0.0001);
	if (!result)
		return false;

	return true;
}




