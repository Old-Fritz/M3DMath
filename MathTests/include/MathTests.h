#pragma once

#include "M3DMath.h"
#include <iostream>

using namespace M3DM;

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
	ALIGN(16) Float pArray[4];
	vectorF.store(pArray);
	stream << "[" << pArray[0] << ", " << pArray[1] << ", " << pArray[2] << ", " << pArray[3] << "]";
	return stream;
}

inline std::ostream& operator<<(std::ostream& stream, const M3DM::DoubleVectorF& dVectorF)
{
	ALIGN(32) Float pArray[8];
	dVectorF.store(pArray);
	stream << "[" << pArray[0] << ", " << pArray[1] << ", " << pArray[2] << ", " << pArray[3] << ", " << pArray[4] << ", " << pArray[5] << ", " << pArray[6] << ", " << pArray[7] << "]";
	return stream;
}

inline std::ostream& operator<<(std::ostream& stream, const M3DM::MatrixScalar& matrix)
{
	const Float* pArray = matrix;
	stream << std::endl;
	for (Int32 i = 0; i < 4; i++)
	{
		stream << "| ";
		for (Int32 j = 0; j < 4; j++)
		{
			stream << pArray[ i*4 + j] << "\t";
		}
		stream << " |" << std::endl;
	}
	return stream;
}

inline std::ostream& operator<<(std::ostream& stream, const M3DM::MatrixF& matrix)
{
	Float pArray[16];
	matrix.store(pArray);
	stream << std::endl;
	for (Int32 i = 0; i < 4; i++)
	{
		stream << "| ";
		for (Int32 j = 0; j < 4; j++)
		{
			stream << pArray[i * 4 + j] << "\t";
		}
		stream << " |" << std::endl;
	}
	return stream;
}

class Vector2Tester
{
public:
	Bool testAll();

	Bool testEqual();
	Bool testCmp();
	Bool testConversions();
	Bool testAdd();
	Bool testSub();
	Bool testMul();
	Bool testDiv();
	Bool testFunctions();
};

class Vector3Tester
{
public:
	Bool testAll();

	Bool testEqual();
	Bool testCmp();
	Bool testConversions();
	Bool testAdd();
	Bool testSub();
	Bool testMul();
	Bool testDiv();
	Bool testFunctions();
};

class Vector4Tester
{
public:
	Bool testAll();

	Bool testEqual();
	Bool testCmp();
	Bool testConversions();
	Bool testAdd();
	Bool testSub();
	Bool testMul();
	Bool testDiv();
	Bool testFunctions();
};

class VectorOperationsTester
{
public:
	Bool testAll();

	Bool testVector2And3();
	Bool testVector2And4();
	Bool testVector3And4();
	Bool testScalarOperations();
};

class VectorFTester
{
public:
	Bool testAll();

	Bool testEqual();
	Bool testCmp();
	Bool testConversions();
	Bool testAdd();
	Bool testSub();
	Bool testMul();
	Bool testDiv();
	Bool testStore();
	Bool testGetSet();
	Bool testFunctions();
};

class DoubleVectorFTester
{
public:
	Bool testAll();

	Bool testEqual();
	Bool testCmp();
	Bool testConversions();
	Bool testAdd();
	Bool testSub();
	Bool testMul();
	Bool testDiv();
	Bool testStore();
	Bool testGetSet();
	Bool testFunctions();
};

class VectorFunctionsTester
{
public:
	Bool testAll();

	Bool testVector2();
	Bool testVector3();
	Bool testVector4();
	Bool testVectorF2D();
	Bool testVectorF3D();
	Bool testVectorF4D();
	Bool testDoubleVectorF2D();
	Bool testDoubleVectorF3D();
	Bool testDoubleVectorF4D();
};

class MatrixScalarTester
{
public:
	Bool testAll();

	Bool testEqual();
	Bool testCmp();
	Bool testConversions();
	Bool testAdd();
	Bool testSub();
	Bool testMul();
	Bool testDiv();
	Bool testFunctions();
};

class MatrixFTester
{
public:
	Bool testAll();

	Bool testEqual();
	Bool testCmp();
	Bool testLoad();
	Bool testStore();
	Bool testGetSet();
	Bool testConversions();
	Bool testAdd();
	Bool testSub();
	Bool testMul();
	Bool testDiv();
	Bool testFunctions();
};

class MatrixScalarFunctionsTester
{
public:
	Bool testAll();

	Bool testScale();
	Bool testRotation();
	Bool testTranslation();
	Bool testTransform();
	Bool testSpecialLH();
	Bool testSpecialRH();
};

class MatrixFFunctionsTester
{
public:
	Bool testAll();

	Bool testScale();
	Bool testRotation();
	Bool testTranslation();
	Bool testTransform();
	Bool testSpecialLH();
	Bool testSpecialRH();
};