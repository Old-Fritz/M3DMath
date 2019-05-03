/// Flobal defines and tests
#include <ctime>
#define DIRECTX12MATH

#ifdef DIRECTX12MATH

#pragma comment(lib,"d3dcompiler.lib") 
#pragma comment(lib, "D3D12.lib") 
#pragma comment(lib, "dxgi.lib") 

#endif

#include "M3DMAth.h"
#include "DirectXMath.h"
#include <iostream>

using namespace M3DM;


int main()
{
	Vector2 c(3, 5);
	Vector2 d;
	VectorF a(4, 2, 3, 4);
	VectorF b(c);

	a += b;
	a.store(c, d);

	std::cout << c.x << " " << c.y << " " << d.x << " " << d.y;
}