/// Flobal defines and tests
#include <ctime>
#define DIRECTX12MATH

#ifdef DIRECTX12MATH

#pragma comment(lib,"d3dcompiler.lib") 
#pragma comment(lib, "D3D12.lib") 
#pragma comment(lib, "dxgi.lib") 

#endif

#include "M3DMAth.h"

using namespace M3DM;


int main()
{
	Vector2 a = {1, 4};
	Vector3 b = {5, 4,1};

	a = static_cast<Vector2>(a + b)/7;
}