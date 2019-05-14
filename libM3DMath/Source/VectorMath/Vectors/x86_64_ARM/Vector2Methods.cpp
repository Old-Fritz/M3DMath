#include "M3DMath.h"
#include <cmath>

/// Implementation of Vector2 methods

using namespace M3DM;


float Vector2::length()
{
	return sqrtf(x * x + y * y);
}

float Vector2::sqrlength()
{
	return x * x + y * y;
}

Vector2 Vector2::normalized()
{
	Vector2 resultVec;
	float len = length();
	resultVec.x = x / len;
	resultVec.y = y / len;

	return resultVec;
}

Vector2 Vector2::abs()
{
	Vector2 resultVec;
	resultVec.x = fabs(x);
	resultVec.y = fabs(y);

	return resultVec;
}

Vector2 Vector2::floor()
{
	Vector2 resultVec;
	resultVec.x = floorf(x);
	resultVec.y = floorf(y);

	return resultVec;
}

Vector2 Vector2::ceil()
{
	Vector2 resultVec;
	resultVec.x = ceilf(x);
	resultVec.y = ceilf(y);

	return resultVec;
}

Vector2 Vector2::round()
{
	Vector2 resultVec;
	resultVec.x = roundf(x);
	resultVec.y = roundf(y);

	return resultVec;
}

Vector2 Vector2::reciprocal()
{
	Vector2 resultVec;
	resultVec.x = 1/x;
	resultVec.y = 1/y;

	return resultVec;
}

Vector2 Vector2::saturate()
{
	Vector2 resultVec;
	resultVec.x = fmin(fmax(x,0),1);
	resultVec.y = fmin(fmax(y, 0), 1);

	return resultVec;
}

Vector2 Vector2::sqrt()
{
	Vector2 resultVec;
	resultVec.x = sqrtf(x);
	resultVec.y = sqrtf(y);

	return resultVec;
}

Vector2 Vector2::cos()
{
	Vector2 resultVec;
	resultVec.x = cosf(x);
	resultVec.y = cosf(y);

	return resultVec;
}

Vector2 Vector2::sin()
{
	Vector2 resultVec;
	resultVec.x =sinf(x);
	resultVec.y =sinf(y);

	return resultVec;
}

Vector2 Vector2::tan()
{
	Vector2 resultVec;
	resultVec.x = tanf(x);
	resultVec.y = tanf(y);

	return resultVec;
}

Vector2 Vector2::acos()
{
	Vector2 resultVec;
	resultVec.x = acosf(x);
	resultVec.y = acosf(y);

	return resultVec;
}

Vector2 Vector2::asin()
{
	Vector2 resultVec;
	resultVec.x = asinf(x);
	resultVec.y = asinf(y);

	return resultVec;
}

Vector2 Vector2::atan()
{
	Vector2 resultVec;
	resultVec.x = atanf(x);
	resultVec.y = atanf(y);

	return resultVec;
}

Vector2 Vector2::exp2()
{
	Vector2 resultVec;
	resultVec.x = exp2f(x);
	resultVec.y = exp2f(y);

	return resultVec;
}

Vector2 Vector2::expE()
{
	Vector2 resultVec;
	resultVec.x = expf(x);
	resultVec.y = expf(y);

	return resultVec;
}

Vector2 Vector2::log2()
{
	Vector2 resultVec;
	resultVec.x = log2f(x);
	resultVec.y = log2f(y);

	return resultVec;
}

Vector2 Vector2::logE()
{
	Vector2 resultVec;
	resultVec.x = logf(x);
	resultVec.y = logf(y);

	return resultVec;
}

void Vector2::sincos(Vector2& sin, Vector2& cos)
{
	sin.x = sinf(x);
	sin.y = sinf(y);
	cos.x = cosf(x);
	cos.y = cosf(y);

}

void Vector2::replicate(float value)
{
	x = value;
	y = value;
}