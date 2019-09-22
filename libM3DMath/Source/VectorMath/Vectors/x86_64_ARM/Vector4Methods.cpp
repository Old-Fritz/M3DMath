#include "M3DMath.h"
#include <cmath>

/// Implementation of Vector4 methods

using namespace M3DM;


Float Vector4::length() const
{
	return sqrtf(x * x + y * y + z * z + w * w);
}

Float Vector4::sqrLength() const
{
	return x * x + y * y + z * z + w * w;
}

Vector4 Vector4::normalized() const
{
	Vector4 resultVec;
	Float len = length();
	resultVec.x = x / len;
	resultVec.y = y / len;
	resultVec.z = z / len;
	resultVec.w = w / len;

	return resultVec;
}

Vector4 Vector4::orthogonal3D() const
{
	Vector4 resultVec;

	resultVec = Vector4(z, z, -x - y, w);
	if (resultVec == Vector4(0,0,0,w)) //chech that result is not zero vector
		resultVec = Vector4(-y - z, x, x, w);

	return resultVec;
}

Vector4 Vector4::orthogonal4D() const
{
	Vector4 resultVec;

	resultVec.x = z;
	resultVec.y = w;
	resultVec.z = -x;
	resultVec.w = -y;

	return resultVec;
}

Vector4 Vector4::abs() const
{
	Vector4 resultVec;
	resultVec.x = fabs(x);
	resultVec.y = fabs(y);
	resultVec.z = fabs(z);
	resultVec.w = fabs(w);

	return resultVec;
}

Vector4 Vector4::floor() const
{
	Vector4 resultVec;
	resultVec.x = floorf(x);
	resultVec.y = floorf(y);
	resultVec.z = floorf(z);
	resultVec.w = floorf(w);

	return resultVec;
}

Vector4 Vector4::ceil() const
{
	Vector4 resultVec;
	resultVec.x = ceilf(x);
	resultVec.y = ceilf(y);
	resultVec.z = ceilf(z);
	resultVec.w = ceilf(w);

	return resultVec;
}

Vector4 Vector4::round() const
{
	Vector4 resultVec;
	resultVec.x = roundf(x);
	resultVec.y = roundf(y);
	resultVec.z = roundf(z);
	resultVec.w = roundf(w);

	return resultVec;
}

Vector4 Vector4::reciprocal() const
{
	Vector4 resultVec;
	resultVec.x = 1 / x;
	resultVec.y = 1 / y;
	resultVec.z = 1 / z;
	resultVec.w = 1 / w;

	return resultVec;
}

Vector4 Vector4::saturate() const
{
	Vector4 resultVec;
	resultVec.x = fmin(fmax(x, 0), 1);
	resultVec.y = fmin(fmax(y, 0), 1);
	resultVec.z = fmin(fmax(z, 0), 1);
	resultVec.w = fmin(fmax(w, 0), 1);

	return resultVec;
}

Vector4 Vector4::sqrt() const
{
	Vector4 resultVec;
	resultVec.x = sqrtf(x);
	resultVec.y = sqrtf(y);
	resultVec.z = sqrtf(z);
	resultVec.w = sqrtf(w);

	return resultVec;
}

Vector4 Vector4::cos() const
{
	Vector4 resultVec;
	resultVec.x = cosf(x);
	resultVec.y = cosf(y);
	resultVec.z = cosf(z);
	resultVec.w = cosf(w);

	return resultVec;
}

Vector4 Vector4::sin() const
{
	Vector4 resultVec;
	resultVec.x = sinf(x);
	resultVec.y = sinf(y);
	resultVec.z = sinf(z);
	resultVec.w = sinf(w);

	return resultVec;
}

Vector4 Vector4::tan() const
{
	Vector4 resultVec;
	resultVec.x = tanf(x);
	resultVec.y = tanf(y);
	resultVec.z = tanf(z);
	resultVec.w = tanf(w);

	return resultVec;
}

Vector4 Vector4::acos() const
{
	Vector4 resultVec;
	resultVec.x = acosf(x);
	resultVec.y = acosf(y);
	resultVec.z = acosf(z);
	resultVec.w = acosf(w);

	return resultVec;
}

Vector4 Vector4::asin() const
{
	Vector4 resultVec;
	resultVec.x = asinf(x);
	resultVec.y = asinf(y);
	resultVec.z = asinf(z);
	resultVec.w = asinf(w);

	return resultVec;
}

Vector4 Vector4::atan() const
{
	Vector4 resultVec;
	resultVec.x = atanf(x);
	resultVec.y = atanf(y);
	resultVec.z = atanf(z);
	resultVec.w = atanf(w);

	return resultVec;
}

Vector4 Vector4::exp2() const
{
	Vector4 resultVec;
	resultVec.x = exp2f(x);
	resultVec.y = exp2f(y);
	resultVec.z = exp2f(z);
	resultVec.w = exp2f(w);

	return resultVec;
}

Vector4 Vector4::expE() const
{
	Vector4 resultVec;
	resultVec.x = expf(x);
	resultVec.y = expf(y);
	resultVec.z = expf(z);
	resultVec.w = expf(w);

	return resultVec;
}

Vector4 Vector4::log2() const
{
	Vector4 resultVec;
	resultVec.x = log2f(x);
	resultVec.y = log2f(y);
	resultVec.z = log2f(z);
	resultVec.w = log2f(w);

	return resultVec;
}

Vector4 Vector4::logE() const
{
	Vector4 resultVec;
	resultVec.x = logf(x);
	resultVec.y = logf(y);
	resultVec.z = logf(z);
	resultVec.w = logf(w);

	return resultVec;
}

void Vector4::sincos(Vector4 & sin, Vector4 & cos) const
{
	sin.x = sinf(x);
	sin.y = sinf(y);
	sin.z = sinf(z);
	sin.w = sinf(w);
	cos.x = cosf(x);
	cos.y = cosf(y);
	cos.z = cosf(z);
	cos.w = cosf(w);
}