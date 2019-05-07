#pragma once

#include "M3DMath.h"
#include<iostream>

class Vector2Tester
{
public:
	bool testAll();

	bool testEqual();
	bool testCmp();
	bool testConstructor();
	bool testConversions();
	bool testAdd();
	bool testSub();
	bool testMul();
	bool testDiv();
};