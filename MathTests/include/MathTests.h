#pragma once

#include "M3DMath.h"

class Vector2Tester
{
public:
	bool testAll();

	bool testEqual();
	bool testConstructor();
	bool testConversions();
	bool testAdd();
	bool testSub();
	bool testMul();
	bool testDiv();
};