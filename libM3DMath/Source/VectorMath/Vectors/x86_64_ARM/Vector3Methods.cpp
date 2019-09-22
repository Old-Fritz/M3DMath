#include "M3DMath.h"
#include <cmath>

/// Implementation of Vector3 methods

using namespace M3DM;


Float Vector3::length() const
{
	return sqrtf(x * x + y * y + z * z);
}

Float Vector3::sqrLength() const
{
	return x * x + y * y + z * z;
}

Vector3 Vector3::normalized() const
{
	Vector3 resultVec;
	Float len = length();
	resultVec.x = x / len;
	resultVec.y = y / len;
	resultVec.z = z / len;

	return resultVec;
}

Vector3 Vector3::orthogonal() const
{
	Vector3 resultVec;

	resultVec = Vector3(z, z, -x-y);
	if (resultVec == Vector3()) //chech that result is not zero vector
		resultVec = Vector3(-y-z, x, x);

	return resultVec;
}

Vector3 Vector3::abs() const
{
	Vector3 resultVec;
	resultVec.x = fabs(x);
	resultVec.y = fabs(y);
	resultVec.z = fabs(z);

	return resultVec;
}

Vector3 Vector3::floor() const
{
	Vector3 resultVec;
	resultVec.x = floorf(x);
	resultVec.y = floorf(y);
	resultVec.z = floorf(z);

	return resultVec;
}

Vector3 Vector3::ceil() const
{
	Vector3 resultVec;
	resultVec.x = ceilf(x);
	resultVec.y = ceilf(y);
	resultVec.z = ceilf(z);

	return resultVec;
}

Vector3 Vector3::round() const
{
	Vector3 resultVec;
	resultVec.x = roundf(x);
	resultVec.y = roundf(y);
	resultVec.z = roundf(z);

	return resultVec;
}

Vector3 Vector3::reciprocal() const
{
	Vector3 resultVec;
	resultVec.x = 1 / x;
	resultVec.y = 1 / y;
	resultVec.z = 1 / z;

	return resultVec;
}

Vector3 Vector3::saturate() const
{
	Vector3 resultVec;
	resultVec.x = fmin(fmax(x, 0), 1);
	resultVec.y = fmin(fmax(y, 0), 1);
	resultVec.z = fmin(fmax(z, 0), 1);

	return resultVec;
}

Vector3 Vector3::sqrt() const
{
	Vector3 resultVec;
	resultVec.x = sqrtf(x);
	resultVec.y = sqrtf(y);
	resultVec.z = sqrtf(z);

	return resultVec;
}

Vector3 Vector3::cos() const
{
	Vector3 resultVec;
	resultVec.x = cosf(x);
	resultVec.y = cosf(y);
	resultVec.z = cosf(z);

	return resultVec;
}

Vector3 Vector3::sin() const
{
	Vector3 resultVec;
	resultVec.x = sinf(x);
	resultVec.y = sinf(y);
	resultVec.z = sinf(z);

	return resultVec;
}

Vector3 Vector3::tan() const
{
	Vector3 resultVec;
	resultVec.x = tanf(x);
	resultVec.y = tanf(y);
	resultVec.z = tanf(z);

	return resultVec;
}

Vector3 Vector3::acos() const
{
	Vector3 resultVec;
	resultVec.x = acosf(x);
	resultVec.y = acosf(y);
	resultVec.z = acosf(z);

	return resultVec;
}

Vector3 Vector3::asin() const
{
	Vector3 resultVec;
	resultVec.x = asinf(x);
	resultVec.y = asinf(y);
	resultVec.z = asinf(z);

	return resultVec;
}

Vector3 Vector3::atan() const
{
	Vector3 resultVec;
	resultVec.x = atanf(x);
	resultVec.y = atanf(y);
	resultVec.z = atanf(z);

	return resultVec;
}

Vector3 Vector3::exp2() const
{
	Vector3 resultVec;
	resultVec.x = exp2f(x);
	resultVec.y = exp2f(y);
	resultVec.z = exp2f(z);

	return resultVec;
}

Vector3 Vector3::expE() const
{
	Vector3 resultVec;
	resultVec.x = expf(x);
	resultVec.y = expf(y);
	resultVec.z = expf(z);

	return resultVec;
}

Vector3 Vector3::log2() const
{
	Vector3 resultVec;
	resultVec.x = log2f(x);
	resultVec.y = log2f(y);
	resultVec.z = log2f(z);

	return resultVec;
}

Vector3 Vector3::logE() const
{
	Vector3 resultVec;
	resultVec.x = logf(x);
	resultVec.y = logf(y);
	resultVec.z = logf(z);

	return resultVec;
}

void Vector3::sincos(Vector3 & sin, Vector3 & cos) const
{
	sin.x = sinf(x);
	sin.y = sinf(y);
	sin.z = sinf(z);
	cos.x = cosf(x);
	cos.y = cosf(y);
	cos.z = cosf(z);
}