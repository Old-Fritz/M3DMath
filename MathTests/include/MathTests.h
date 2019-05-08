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
};