/// Flobal defines and tests
#define DIRECTX12MATH

#ifdef DIRECTX12MATH

#pragma comment(lib,"d3dcompiler.lib") 
#pragma comment(lib, "D3D12.lib") 
#pragma comment(lib, "dxgi.lib") 

#endif

#include <iostream>
#include "MathTests.h"

using namespace M3DM;

bool makeTests()
{
	Vector2Tester vector2Tester;
	Vector3Tester vector3Tester;
	Vector4Tester vector4Tester;
	VectorOperationsTester vectorOperatinosTester;

	bool result;

	result = vector2Tester.testAll();
	if (!result)
		return false;

	result = vector3Tester.testAll();
	if (!result)
		return false;


	result = vector4Tester.testAll();
	if (!result)
		return false;

	result = vectorOperatinosTester.testAll();
	if (!result)
		return false;

	return true;
}

int main()
{
	bool result = makeTests();
	if (result)
		std::cout << "----------ALL TESTS PASSED----------" << std::endl;
	else
		std::cout << "----------!!!!SOME TESTS NOT PASSED!!!!!----------" << std::endl;

	std::cin.get();
}