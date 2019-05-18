#pragma once

#include "M3DMath.h"
#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const M3DM::Vector2& vector2)
{
	stream << "(" << vector2.x << ", " << vector2.y << ")";
	return stream;
}

inline std::ostream& operator<<(std::ostream& stream, const M3DM::Vector3& vector3)
{
	stream << "(" << vector3.x << ", " << vector3.y << ", " << vector3.z << ")";
	return stream;
}

inline std::ostream& operator<<(std::ostream& stream, const M3DM::Vector4& vector4)
{
	stream << "(" << vector4.x << ", " << vector4.y << ", " << vector4.z << ", " << vector4.w << ")";
	return stream;
}

inline std::ostream& operator<<(std::ostream& stream, const M3DM::VectorF& vectorF)
{
	ALIGN(16) float pArray[4];
	vectorF.store(pArray);
	stream << "[" << pArray[0] << ", " << pArray[1] << ", " << pArray[2] << ", " << pArray[3] << "]";
	return stream;
}

inline std::ostream& operator<<(std::ostream& stream, const M3DM::DoubleVectorF& dVectorF)
{
	ALIGN(32) float pArray[8];
	dVectorF.store(pArray);
	stream << "[" << pArray[0] << ", " << pArray[1] << ", " << pArray[2] << ", " << pArray[3] << ", " << pArray[4] << ", " << pArray[5] << ", " << pArray[6] << ", " << pArray[7] << "]";
	return stream;
}


class Vector2Tester
{
public:
	bool testAll();

	bool testEqual();
	bool testCmp();
	bool testConversions();
	bool testAdd();
	bool testSub();
	bool testMul();
	bool testDiv();
	bool testFunctions();
};

class Vector3Tester
{
public:
	bool testAll();

	bool testEqual();
	bool testCmp();
	bool testConversions();
	bool testAdd();
	bool testSub();
	bool testMul();
	bool testDiv();
	bool testFunctions();
};

class Vector4Tester
{
public:
	bool testAll();

	bool testEqual();
	bool testCmp();
	bool testConversions();
	bool testAdd();
	bool testSub();
	bool testMul();
	bool testDiv();
	bool testFunctions();
};

class VectorOperationsTester
{
public:
	bool testAll();

	bool testVector2And3();
	bool testVector2And4();
	bool testVector3And4();
	bool testScalarOperations();
};

class VectorFTester
{
public:
	bool testAll();

	bool testEqual();
	bool testCmp();
	bool testConversions();
	bool testAdd();
	bool testSub();
	bool testMul();
	bool testDiv();
	bool testStore();
	bool testGetSet();
	bool testFunctions();
};

class DoubleVectorFTester
{
public:
	bool testAll();

	bool testEqual();
	bool testCmp();
	bool testConversions();
	bool testAdd();
	bool testSub();
	bool testMul();
	bool testDiv();
	bool testStore();
	bool testGetSet();
	bool testFunctions();
};

class VectorFunctionsTester
{
public:
	bool testAll();

	bool testVector2();
	bool testVector3();
	bool testVector4();
	bool testVectorF();
	bool testDoubleVectorF();
};