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

Bool makeMatrixTests()
{
	MatrixScalarTester matrixScalarTester;
	MatrixFTester matrixFTester;
	MatrixScalarFunctionsTester matrixScalarFunctionsTester;
	MatrixFFunctionsTester matrixFFunctionsTester;

	Bool result;

	result = matrixScalarTester.testAll();
	if (!result)
		return false;

	result = matrixFTester.testAll();
	if (!result)
		return false;

	result = matrixScalarFunctionsTester.testAll();
	if (!result)
		return false;

	result = matrixFFunctionsTester.testAll();
	if (!result)
		return false;

	return true;
}

Bool makeVectorTests()
{
	Vector2Tester vector2Tester;
	Vector3Tester vector3Tester;
	Vector4Tester vector4Tester;
	VectorOperationsTester vectorOperatinosTester;
	VectorFTester vectorFTester;
	DoubleVectorFTester doubleVectorFTester;
	VectorFunctionsTester vectorFunctionsTester;

	Bool result;

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

	result = vectorFTester.testAll();
	if (!result)
		return false;

	result = doubleVectorFTester.testAll();
	if (!result)
		return false;

	result = vectorFunctionsTester.testAll();
	if (!result)
		return false;

	return true;
}

Bool makeTests()
{
	Bool result;

	//result = makeVectorTests();
	//if (!result)
	//	return false;

	result = makeMatrixTests();
	if (!result)
		return false;

	return true;
}

Int32 main()
{
	Bool result = makeTests();
	if (result)
		std::cout << "----------ALL TESTS PASSED----------" << std::endl;
	else
		std::cout << "----------!!!!SOME TESTS NOT PASSED!!!!!----------" << std::endl;

	std::cin.get();
}