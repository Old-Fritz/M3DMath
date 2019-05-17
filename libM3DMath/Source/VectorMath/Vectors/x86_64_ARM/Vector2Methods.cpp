#include "M3DMath.h"
#include <cmath>

/// Implementation of Vector2 methods

using namespace M3DM;


float Vector2::length() const
{
	return sqrtf(x * x + y * y);
}

float Vector2::sqrLength() const
{
	return x * x + y * y;
}

Vector2 Vector2::normalized() const
{
	Vector2 resultVec;
	float len = length();
	resultVec.x = x / len;
	resultVec.y = y / len;

	return resultVec;
}

Vector2 Vector2::abs() const
{
	Vector2 resultVec;
	resultVec.x = fabs(x);
	resultVec.y = fabs(y);

	return resultVec;
}

Vector2 Vector2::floor() const
{
	Vector2 resultVec;
	resultVec.x = floorf(x);
	resultVec.y = floorf(y);

	return resultVec;
}

Vector2 Vector2::ceil() const
{
	Vector2 resultVec;
	resultVec.x = ceilf(x);
	resultVec.y = ceilf(y);

	return resultVec;
}

Vector2 Vector2::round() const
{
	Vector2 resultVec;
	resultVec.x = roundf(x);
	resultVec.y = roundf(y);

	return resultVec;
}

Vector2 Vector2::reciprocal() const
{
	Vector2 resultVec;
	resultVec.x = 1/x;
	resultVec.y = 1/y;

	return resultVec;
}

Vector2 Vector2::saturate() const
{
	Vector2 resultVec;
	resultVec.x = fmin(fmax(x,0),1);
	resultVec.y = fmin(fmax(y, 0), 1);

	return resultVec;
}

Vector2 Vector2::sqrt() const
{
	Vector2 resultVec;
	resultVec.x = sqrtf(x);
	resultVec.y = sqrtf(y);

	return resultVec;
}

Vector2 Vector2::cos() const
{
	Vector2 resultVec;
	resultVec.x = cosf(x);
	resultVec.y = cosf(y);

	return resultVec;
}

Vector2 Vector2::sin() const
{
	Vector2 resultVec;
	resultVec.x =sinf(x);
	resultVec.y =sinf(y);

	return resultVec;
}

Vector2 Vector2::tan() const
{
	Vector2 resultVec;
	resultVec.x = tanf(x);
	resultVec.y = tanf(y);

	return resultVec;
}

Vector2 Vector2::acos() const
{
	Vector2 resultVec;
	resultVec.x = acosf(x);
	resultVec.y = acosf(y);

	return resultVec;
}

Vector2 Vector2::asin() const
{
	Vector2 resultVec;
	resultVec.x = asinf(x);
	resultVec.y = asinf(y);

	return resultVec;
}

Vector2 Vector2::atan() const
{
	Vector2 resultVec;
	resultVec.x = atanf(x);
	resultVec.y = atanf(y);

	return resultVec;
}

Vector2 Vector2::exp2() const
{
	Vector2 resultVec;
	resultVec.x = exp2f(x);
	resultVec.y = exp2f(y);

	return resultVec;
}

Vector2 Vector2::expE() const
{
	Vector2 resultVec;
	resultVec.x = expf(x);
	resultVec.y = expf(y);

	return resultVec;
}

Vector2 Vector2::log2() const
{
	Vector2 resultVec;
	resultVec.x = log2f(x);
	resultVec.y = log2f(y);

	return resultVec;
}

Vector2 Vector2::logE() const
{
	Vector2 resultVec;
	resultVec.x = logf(x);
	resultVec.y = logf(y);

	return resultVec;
}

void Vector2::sincos(Vector2& sin, Vector2& cos) const
{
	sin.x = sinf(x);
	sin.y = sinf(y);
	cos.x = cosf(x);
	cos.y = cosf(y);

}

Vector2& Vector2::replicate(float value)
{
	x = value;
	y = value;

	return *this;
}

Vector2 Vector2::orthogonal() const
{
	Vector2 resultVec;
	resultVec.x = -y;
	resultVec.y = x;

	return resultVec;
}