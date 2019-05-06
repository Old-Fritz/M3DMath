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


int main()
{
	Vector2 c(3, 5);
	Vector2 d;

	d = c + c;
	
	VectorF a(4, 2, 3, 4);
	VectorF b(c);
	VectorF e(7, 7, 3, 4);
	Vector4 a1, a2;
	DoubleVectorF g(a, e);
	DoubleVectorF h(a, VectorF(c));
	DoubleVectorF j = g * h;
	DoubleVectorF t(16, 4, 9, 16, 21, 35);
	j.store(a1, a2);

	std::cout << a1.x << " " << a1.y << " " << a1.z << " " << a1.w << " " << a2.x << " " << a2.y << " " << a2.z << " " << a2.w << std::endl << (t==j) << std::endl;

	std::cin.get();
}