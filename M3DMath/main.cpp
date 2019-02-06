/// Flobal defines and tests

#define DIRECTX12MATH

#ifdef DIRECTX12MATH

#pragma comment(lib,"d3dcompiler.lib") 
#pragma comment(lib, "D3D12.lib") 
#pragma comment(lib, "dxgi.lib") 

#endif

#include "M3DMAth.h"

using namespace M3DMath;

int main()
{
	Vector4 a;
	Vector2 b;

	Vector4 c = b+a;

}