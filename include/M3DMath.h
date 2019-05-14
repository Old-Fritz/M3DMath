#pragma once

#define VECCALL
#define M128 __m128
#define M256 __m256

#ifdef WIN32
#include <DirectXMath.h>
#define VECCALL __vectorcall
#endif

// x86_64 platform
#if defined(__x86_64__) || defined(__i386__) || defined(WIN32)
# define _AVX_
# include <xmmintrin.h>
# include <emmintrin.h>
# include <pmmintrin.h>
# include <smmintrin.h>
# include <immintrin.h>


#endif
// arm_platform
#ifdef __ARM_NEON
#define __ARM_FEATURE_FP16_VECTOR_ARITHMETIC 1
#include <arm_neon.h>
#define M128 float64x1x2_t
#define M256 float64x2x2_t
#define NO_ALIGNS
#define ALIGN(N) 
# define M128 
# define M256
#endif

#ifndef NO_ALIGNS
#define ALIGN(N) alignas((N))
#endif



namespace M3DM
{
	/// Scalar structs

	union intFloat
	{
		int i;
		float f;
	};

	/// Constants

	const float FNAN = intFloat{ -1 }.f;

	/// Base vector structs
	struct Vector2;
	struct Vector3;
	struct Vector4;

	struct Vector2
	{
		float x, y;

		// Constructors
		Vector2(const Vector2& vector) = default;
		Vector2(const float x = 0, const float y = 0) : x(x), y(y) {}
		Vector2& operator=(const Vector2& vector) = default;

		// Conversions
		explicit Vector2(const float* pArray) : x(pArray[0]), y(pArray[1]) {}
		explicit Vector2(const Vector3& vector);
		explicit Vector2(const Vector4& vector);
		operator float* ();
		operator float const* () const;

		// Base operations
		Vector2 operator+(const Vector2& vector) const;
		Vector2 operator-(const Vector2& vector) const;
		Vector2 operator*(const Vector2& vector) const;
		Vector2 operator/(const Vector2& vector) const;
		Vector2 operator*(float scale) const;
		Vector2 operator/(float scale) const;
		Vector2& operator+=(const Vector2& vector);
		Vector2& operator-=(const Vector2& vector);
		Vector2& operator*=(const Vector2& vector);
		Vector2& operator/=(const Vector2& vector);
		Vector2& operator*=(float scale);
		Vector2& operator/=(float scale);
		Vector2 operator-();
		

		// Compare 
		bool operator==(const Vector2& vector) const;
		bool operator<(const Vector2& vector) const;
		bool operator>(const Vector2& vector) const;
		bool operator<=(const Vector2& vector) const;
		bool operator>=(const Vector2& vector) const;
		bool isEqualPrec(const Vector2& vector, float precision = 0) const;
		bool isEqualPrec(const Vector2& vector, const Vector2& precision) const;
		Vector2 isEqualVec(const Vector2& vector) const;
		Vector2 isEqualPrecVec(const Vector2& vector, const Vector2& precision) const;

		// Functions
		float length();
		float sqrlength();
		Vector2 normalized();
		Vector2 abs();
		Vector2 floor();
		Vector2 ceil();
		Vector2 round();
		Vector2 reciprocal();
		Vector2 saturate();
		Vector2 sqrt();
		Vector2 cos();
		Vector2 sin();
		Vector2 tan();
		Vector2 acos();
		Vector2 asin();
		Vector2 atan();
		Vector2 exp2();
		Vector2 expE();
		Vector2 log2();
		Vector2 logE();
		void sincos(Vector2& sin, Vector2& cos);
		void replicate(float value);
		
	};

	struct Vector3
	{
		float x, y, z;

		// Constructors
		Vector3(const Vector3& vector) = default;
		Vector3(const float x = 0, const float y = 0, const float z = 0) : x(x), y(y), z(z) {}
		Vector3& operator=(const Vector3& vector) = default;

		// Conversions
		explicit Vector3(const float* pArray) : x(pArray[0]), y(pArray[1]), z(pArray[2]) {}
		explicit Vector3(const Vector2& vector) : x(vector.x), y(vector.y), z(0) {}
		explicit Vector3(const Vector4& vector);
		operator float* ();
		operator float const* () const;

		// Base operations
		Vector3 operator+(const Vector3& vector) const;
		Vector3 operator-(const Vector3& vector) const;
		Vector3 operator*(const Vector3& vector) const;
		Vector3 operator/(const Vector3& vector) const;
		Vector3 operator*(float scale) const;
		Vector3 operator/(float scale) const;
		Vector3& operator+=(const Vector3& vector);
		Vector3& operator-=(const Vector3& vector);
		Vector3& operator*=(const Vector3& vector);
		Vector3& operator/=(const Vector3& vector);
		Vector3& operator*=(float scale);
		Vector3& operator/=(float scale);
		Vector3 operator-();

		// Compare functions
		bool operator==(const Vector3& vector) const;
		bool operator<(const Vector3& vector) const;
		bool operator>(const Vector3& vector) const;
		bool operator<=(const Vector3& vector) const;
		bool operator>=(const Vector3& vector) const;
		bool isEqualPrec(const Vector3& vector, float precision = 0) const;
		bool isEqualPrec(const Vector3& vector, const Vector3& precision) const;
		Vector3 isEqualVec(const Vector3& vector) const;
		Vector3 isEqualPrecVec(const Vector3& vector, const Vector3& precision) const;

		// Functions
		float length();
		float sqrlength();
		Vector3 normalized();
		Vector3 abs();
		Vector3 floor();
		Vector3 ceil();
		Vector3 round();
		Vector3 reciprocal();
		Vector3 saturate();
		Vector3 sqrt();
		Vector3 cos();
		Vector3 sin();
		Vector3 tan();
		Vector3 acos();
		Vector3 asin();
		Vector3 atan();
		Vector3 exp2();
		Vector3 expE();
		Vector3 log2();
		Vector3 logE();
		void sincos(Vector3& sin, Vector3& cos);
		void replicate(float value);
	};
	
	struct ALIGN(16) Vector4
	{
		float x, y, z, w;

		// Constructors
		Vector4(const Vector4& vector) = default;
		Vector4(const float x = 0, const float y = 0, const float z = 0, const float w = 0) : x(x), y(y), z(z), w(w) {}
		Vector4& operator=(const Vector4& vector) = default;

		// Conversions
		explicit Vector4(const float* pArray) : x(pArray[0]), y(pArray[1]), z(pArray[2]), w(pArray[3]) {}
		explicit Vector4(const Vector2& vector) : x(vector.x), y(vector.y), z(0), w(0) {}
		explicit Vector4(const Vector3& vector) : x(vector.x), y(vector.y), z(vector.z), w(0) {}
		explicit Vector4(const Vector2& vector1, const Vector2& vector2) : x(vector1.x), y(vector1.y), z(vector2.x), w(vector2.y) {}
		operator float*();
		operator float const * () const;

		// Base operations
		Vector4 operator+(const Vector4& vector) const;
		Vector4 operator-(const Vector4& vector) const;
		Vector4 operator*(const Vector4& vector) const;
		Vector4 operator/(const Vector4& vector) const;
		Vector4 operator*(float scale) const;
		Vector4 operator/(float scale) const;
		Vector4& operator+=(const Vector4& vector);
		Vector4& operator-=(const Vector4& vector);
		Vector4& operator*=(const Vector4& vector);
		Vector4& operator/=(const Vector4& vector);
		Vector4& operator*=(float scale);
		Vector4& operator/=(float scale);
		Vector4 operator-();

		// Compare functions
		bool operator==(const Vector4& vector) const;
		bool operator<(const Vector4& vector) const;
		bool operator>(const Vector4& vector) const;
		bool operator<=(const Vector4& vector) const;
		bool operator>=(const Vector4& vector) const;
		bool isEqualPrec(const Vector4& vector, float precision = 0) const;
		bool isEqualPrec(const Vector4& vector, const Vector4& precision) const;
		Vector4 isEqualVec(const Vector4& vector) const;
		Vector4 isEqualPrecVec(const Vector4& vector, const Vector4& precision) const;

		// Functions
		float length();
		float sqrlength();
		Vector4 normalized();
		Vector4 abs();
		Vector4 floor();
		Vector4 ceil();
		Vector4 round();
		Vector4 reciprocal();
		Vector4 saturate();
		Vector4 sqrt();
		Vector4 cos();
		Vector4 sin();
		Vector4 tan();
		Vector4 acos();
		Vector4 asin();
		Vector4 atan();
		Vector4 exp2();
		Vector4 expE();
		Vector4 log2();
		Vector4 logE();
		void sincos(Vector4& sin, Vector4& cos);
		void replicate(float value);
	};

	/// Different operator combinations
#pragma region 
	// Vector2 and Vector3
	Vector3 operator*(const Vector3& vector1, const Vector2& vector2);
	Vector3 operator*(const Vector2& vector1, const Vector3& vector2);
	Vector3 operator/(const Vector3& vector1, const Vector2& vector2);
	Vector3 operator/(const Vector2& vector1, const Vector3& vector2);
	Vector3 operator+(const Vector3& vector1, const Vector2& vector2);
	Vector3 operator+(const Vector2& vector1, const Vector3& vector2);
	Vector3 operator-(const Vector3& vector1, const Vector2& vector2);
	Vector3 operator-(const Vector2& vector1, const Vector3& vector2);

	// Vector2 and Vector4
	Vector4 operator*(const Vector4& vector1, const Vector2& vector2);
	Vector4 operator*(const Vector2& vector1, const Vector4& vector2);
	Vector4 operator/(const Vector4& vector1, const Vector2& vector2);
	Vector4 operator/(const Vector2& vector1, const Vector4& vector2);
	Vector4 operator+(const Vector4& vector1, const Vector2& vector2);
	Vector4 operator+(const Vector2& vector1, const Vector4& vector2);
	Vector4 operator-(const Vector4& vector1, const Vector2& vector2);
	Vector4 operator-(const Vector2& vector1, const Vector4& vector2);

	// Vector3 and Vector4
	Vector4 operator*(const Vector4& vector1, const Vector3& vector2);
	Vector4 operator*(const Vector3& vector1, const Vector4& vector2);
	Vector4 operator/(const Vector4& vector1, const Vector3& vector2);
	Vector4 operator/(const Vector3& vector1, const Vector4& vector2);
	Vector4 operator+(const Vector4& vector1, const Vector3& vector2);
	Vector4 operator+(const Vector3& vector1, const Vector4& vector2);
	Vector4 operator-(const Vector4& vector1, const Vector3& vector2);
	Vector4 operator-(const Vector3& vector1, const Vector4& vector2);

	// Scalar operations
	Vector2 operator*(float scale, const Vector2& vector);
	Vector3 operator*(float scale, const Vector3& vector);
	Vector4 operator*(float scale, const Vector4& vector);
	Vector2 operator/(float scale, const Vector2& vector);
	Vector3 operator/(float scale, const Vector3& vector);
	Vector4 operator/(float scale, const Vector4& vector);
#pragma endregion operators
	
	/// SSE vector
	class ALIGN(16) VectorF
	{
	public:
		// Constructors
		VectorF() : m_data() {}
		VectorF(const VectorF& vector) = default;
		VectorF(M128 data) : m_data(data) {}
		VectorF& VECCALL operator=(const VectorF& vector) = default;
		
		// Conversions
		explicit VectorF(float x, float y = 0, float z = 0, float w = 0);
		explicit VectorF(float* pArray);
		explicit VectorF(const Vector2& vector);
		explicit VectorF(const Vector3& vector);
		explicit VectorF(const Vector4& vector);
		explicit VectorF(const Vector2& vector1, const Vector2& vector2);
		operator M128() const;

		// getters and setters
		float get(int ind);
		void set(int ind, float value);
		int getInt(int ind);
		void setInt(int ind, int value);

		// Base operations
		VectorF VECCALL operator+(VectorF vector) const;
		VectorF VECCALL operator-(VectorF vector) const;
		VectorF VECCALL operator*(VectorF vector) const;
		VectorF VECCALL operator/(VectorF vector) const;
		VectorF VECCALL operator*(float scale) const;
		VectorF VECCALL operator/(float scale) const;
		VectorF& VECCALL operator+=(VectorF vector);
		VectorF& VECCALL operator-=(VectorF vector);
		VectorF& VECCALL operator*=(VectorF vector);
		VectorF& VECCALL operator/=(VectorF vector);
		VectorF& VECCALL operator*=(float scale);
		VectorF& VECCALL operator/=(float scale);
		VectorF VECCALL operator-();

		// Compare functions
		bool VECCALL operator==(VectorF vector) const;
		bool VECCALL operator<(VectorF vector) const;
		bool VECCALL operator>(VectorF vector) const;
		bool VECCALL operator<=(VectorF vector) const;
		bool VECCALL operator>=(VectorF vector) const;
		bool VECCALL isEqualPrec(VectorF vector, float precision = 0) const;
		bool VECCALL isEqualPrec(VectorF vector, VectorF precision) const;
		VectorF VECCALL isEqualVec(VectorF vector) const;
		VectorF VECCALL isEqualPrecVec(VectorF vector, VectorF precision) const;

		// load/store
		void VECCALL load(float x = 0, float y = 0, float z = 0, float w = 0);
		void VECCALL load(const float* pArray);
		void VECCALL load(const Vector2& vector);
		void VECCALL load(const Vector3& vector);
		void VECCALL load(const Vector4& vector);
		void VECCALL load(const Vector2& vector1, const Vector2& vector2);

		void VECCALL store(float& x, float& y, float& z, float& w) const;
		void VECCALL store(float* pArray) const;
		void VECCALL store(Vector2& vector) const;
		void VECCALL store(Vector3& vector) const;
		void VECCALL store(Vector4& vector) const;
		void VECCALL store(Vector2& vector1, Vector2& vector2) const;

		// Functions
		float length();
		float sqrlength();
		VectorF VECCALL normalized();
		VectorF VECCALL abs();
		VectorF VECCALL floor();
		VectorF VECCALL ceil();
		VectorF VECCALL round();
		VectorF VECCALL reciprocal();
		VectorF VECCALL saturate();
		VectorF VECCALL sqrt();
		VectorF VECCALL cos();
		VectorF VECCALL sin();
		VectorF VECCALL tan();
		VectorF VECCALL acos();
		VectorF VECCALL asin();
		VectorF VECCALL atan();
		VectorF VECCALL exp2();
		VectorF VECCALL expE();
		VectorF VECCALL log2();
		VectorF VECCALL logE();
		void sincos(VectorF& sin, VectorF& cos);
		void replicate(float value);

	private:
		M128 m_data{};
	};

	/// AVX vector
	class ALIGN(32) DoubleVectorF
	{
	public:
		// Constructors
		DoubleVectorF() : m_data() {}
		DoubleVectorF(const DoubleVectorF& vector) = default;
		DoubleVectorF(M256 data) : m_data(data) {}
		DoubleVectorF& VECCALL operator=(const DoubleVectorF& vector) = default;

		// Conversions
		explicit DoubleVectorF(float x1, float y1 = 0, float z1 = 0, float w1 = 0, float x2 = 0, float y2 = 0, float z2 = 0, float w2 = 0);
		explicit DoubleVectorF(float* pArray);
		explicit DoubleVectorF(const Vector2& vector);
		explicit DoubleVectorF(const Vector3& vector);
		explicit DoubleVectorF(const Vector4& vector);
		explicit DoubleVectorF(const Vector2& vector1, const Vector2& vector2);
		explicit DoubleVectorF(const Vector3& vector1, const Vector3& vector2);
		explicit DoubleVectorF(const Vector4& vector1, const Vector4& vector2);
		explicit DoubleVectorF(const Vector2& vector1, const Vector2& vector2, const Vector2& vector3, const Vector2& vector4);
		explicit DoubleVectorF(VectorF vector);
		explicit DoubleVectorF(VectorF vector1, VectorF vector2);
		VECCALL operator M256() const;

		// getters and setters
		float get(int ind);
		void set(int ind, float value);
		int getInt(int ind);
		void setInt(int ind, int value);

		// Base operations
		DoubleVectorF VECCALL operator+(DoubleVectorF vector) const;
		DoubleVectorF VECCALL operator-(DoubleVectorF vector) const;
		DoubleVectorF VECCALL operator*(DoubleVectorF vector) const;
		DoubleVectorF VECCALL operator/(DoubleVectorF vector) const;
		DoubleVectorF VECCALL operator*(float scale) const;
		DoubleVectorF VECCALL operator/(float scale) const;
		DoubleVectorF& VECCALL operator+=(DoubleVectorF vector);
		DoubleVectorF& VECCALL operator-=(DoubleVectorF vector);
		DoubleVectorF& VECCALL operator*=(DoubleVectorF vector);
		DoubleVectorF& VECCALL operator/=(DoubleVectorF vector);
		DoubleVectorF& VECCALL operator*=(float scale);
		DoubleVectorF& VECCALL operator/=(float scale);
		VectorF VECCALL operator-();

		// Compare functions
		bool VECCALL operator==(DoubleVectorF vector) const;
		bool VECCALL operator<(DoubleVectorF vector) const;
		bool VECCALL operator>(DoubleVectorF vector) const;
		bool VECCALL operator<=(DoubleVectorF vector) const;
		bool VECCALL operator>=(DoubleVectorF vector) const;
		bool VECCALL isEqualPrec(DoubleVectorF vector, float precision = 0) const;
		bool VECCALL isEqualPrec(DoubleVectorF vector, DoubleVectorF precision) const;
		DoubleVectorF VECCALL isEqualVec(DoubleVectorF vector) const;
		DoubleVectorF VECCALL isEqualPrecVec(DoubleVectorF vector, DoubleVectorF precision) const;

		// load/store
		void VECCALL load(float x1 = 0, float y1 = 0, float z1 = 0, float w1 = 0, float x2 = 0, float y2 = 0, float z2 = 0, float w2 = 0);
		void VECCALL load(const float* pArray);
		void VECCALL load(const Vector2& vector);
		void VECCALL load(const Vector3& vector);
		void VECCALL load(const Vector4& vector);
		void VECCALL load(const Vector2& vector1, const Vector2& vector2);
		void VECCALL load(const Vector3& vector1, const Vector3& vector2);
		void VECCALL load(const Vector4& vector1, const Vector4& vector2);
		void VECCALL load(const Vector2& vector1, const Vector2& vector2, const Vector2& vector3, const Vector2& vector4);
		void VECCALL load(VectorF vector);
		void VECCALL load(VectorF vector1, VectorF vector2);

		void VECCALL store(float& x1, float& y1, float& z1, float& w1, float& x2, float& y2, float& z2, float& w2) const;
		void VECCALL store(float* pArray) const;
		void VECCALL store(Vector2& vector) const;
		void VECCALL store(Vector3& vector) const;
		void VECCALL store(Vector4& vector) const;
		void VECCALL store(Vector2& vector1, Vector2& vector2) const;
		void VECCALL store(Vector3& vector1, Vector3& vector2) const;
		void VECCALL store(Vector4& vector1, Vector4& vector2) const;
		void VECCALL store(Vector2& vector1, Vector2& vector2, Vector2& vector3, Vector2& vector4) const;
		void VECCALL store(VectorF& vector) const;
		void VECCALL store(VectorF& vector1, VectorF& vector2) const;

		// Functions
		float length();
		float sqrlength();
		DoubleVectorF VECCALL normalized();
		DoubleVectorF VECCALL abs();
		DoubleVectorF VECCALL floor();
		DoubleVectorF VECCALL ceil();
		DoubleVectorF VECCALL round();
		DoubleVectorF VECCALL reciprocal();
		DoubleVectorF VECCALL saturate();
		DoubleVectorF VECCALL sqrt();
		DoubleVectorF VECCALL cos();
		DoubleVectorF VECCALL sin();
		DoubleVectorF VECCALL tan();
		DoubleVectorF VECCALL acos();
		DoubleVectorF VECCALL asin();
		DoubleVectorF VECCALL atan();
		DoubleVectorF VECCALL exp2();
		DoubleVectorF VECCALL expE();
		DoubleVectorF VECCALL log2();
		DoubleVectorF VECCALL logE();
		void sincos(DoubleVectorF& sin, DoubleVectorF& cos);
		void replicate(float value);
	private:
		M256 m_data{};
	};

	/// Vector functions
	// Vector2
	Vector2 vec2Distance(const Vector2& vec1, const Vector2& vec2);
	Vector2 vec2Lerp(const Vector2& vec1, const Vector2& vec2, float value);
	Vector2 vec2Max(const Vector2& vec1, const Vector2& vec2);
	Vector2 vec2Min(const Vector2& vec1, const Vector2& vec2);
	Vector2 vec2Project(const Vector2& vec1, const Vector2& vec2);
	Vector2 vec2IntersectLines(const Vector2& vec1, const Vector2& vec2);
	Vector2 vec2Reflect(const Vector2& vec, const Vector2& normal);
	Vector2 vec2Refract(const Vector2& vec, const Vector2& normal);
	Vector2 vec2Orthogonal(const Vector2& vec, const Vector2& normal);
	Vector2 vec2Pow(const Vector2& vec, const Vector2& pow);
	Vector2 vec2Pow(const Vector2& vec, float pow);
	float vec2Dot(const Vector2& vec1, const Vector2& vec2);
	float vec2LinePointDistance(const Vector2& line, const Vector2& point);
	float vec2AngleBetween(const Vector2& vec1, const Vector2& vec2);
	bool vec2InBound(const Vector2& vec, const Vector2& left, const Vector2& right);

	// Vector3
	Vector3 vec3Distance(const Vector3& vec1, const Vector3& vec2);
	Vector3 vec3Cross(const Vector3& vec1, const Vector3& vec2);
	Vector3 vec3Lerp(const Vector3& vec1, const Vector3& vec2, float value);
	Vector3 vec3Max(const Vector3& vec1, const Vector3& vec2);
	Vector3 vec3Min(const Vector3& vec1, const Vector3& vec2);
	Vector3 vec3Project(const Vector3& vec1, const Vector3& vec2);
	Vector3 vec3IntersectLines(const Vector3& vec1, const Vector3& vec2);
	Vector3 vec3Reflect(const Vector3& vec, const Vector3& normal);
	Vector3 vec3Refract(const Vector3& vec, const Vector3& normal);
	Vector3 vec3Orthogonal(const Vector3& vec, const Vector3& normal);
	Vector3 vec3Pow(const Vector3& vec, const Vector3& pow);
	Vector3 vec3Pow(const Vector3& vec, float pow);
	float vec3Dot(const Vector3& vec1, const Vector3& vec2);
	float vec3LinePointDistance(const Vector3& line, const Vector3& point);
	float vec3AngleBetween(const Vector3& vec1, const Vector3& vec2);
	bool vec3InBound(const Vector3& vec, const Vector3& left, const Vector3& right);

	// Vector4
	Vector4 vec4Distance(const Vector4& vec1, const Vector4& vec2);
	Vector4 vec4Lerp(const Vector4& vec1, const Vector4& vec2, float value);
	Vector4 vec4Max(const Vector4& vec1, const Vector4& vec2);
	Vector4 vec4Min(const Vector4& vec1, const Vector4& vec2);
	Vector4 vec4Project(const Vector4& vec1, const Vector4& vec2);
	Vector4 vec4IntersectLines(const Vector4& vec1, const Vector4& vec2);
	Vector4 vec4Reflect(const Vector4& vec, const Vector4& normal);
	Vector4 vec4Refract(const Vector4& vec, const Vector4& normal);
	Vector4 vec4Orthogonal(const Vector4& vec, const Vector4& normal);
	Vector4 vec4Pow(const Vector4& vec, const Vector4& pow);
	Vector4 vec4Pow(const Vector4& vec, float pow);
	float vec4Dot(const Vector4& vec1, const Vector4& vec2);
	float vec4LinePointDistance(const Vector4& line, const Vector4& point);
	float vec4AngleBetween(const Vector4& vec1, const Vector4& vec2);
	bool vec4InBound(const Vector4& vec, const Vector4& left, const Vector4& right);

	// VectorF
	VectorF VECCALL vecFDistance(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFCross(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFLerp(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFMax(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFMin(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFProject(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFIntersectLines(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFReflect(VectorF vec, VectorF normal);
	VectorF VECCALL vecFRefract(VectorF vec, VectorF normal);
	VectorF VECCALL vecFOrthogonal(VectorF vec, VectorF normal);
	VectorF VECCALL vecFDotVec(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFLinePointDistanceVec(VectorF line, VectorF point);
	VectorF VECCALL vecFAngleBetweenVec(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFInBoundVec(VectorF vec, VectorF left, VectorF right);
	VectorF VECCALL vecFPow(VectorF vec, VectorF pow);
	VectorF VECCALL vecFPow(VectorF vec, float pow);
	float VECCALL vecFDot(VectorF vec1, VectorF vec2);
	float VECCALL vecFLinePointDistance(VectorF line, VectorF point);
	float VECCALL vecFAngleBetween(VectorF vec1, VectorF vec2);
	bool VECCALL vecFinBound(VectorF vec, VectorF left, VectorF right);

	// DoubleDoubleVectorF
	DoubleVectorF VECCALL doubleVecFDistance(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFCross(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFLerp(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFMax(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFMin(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFProject(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFIntersectLines(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFReflect(DoubleVectorF vec, DoubleVectorF normal);
	DoubleVectorF VECCALL doubleVecFRefract(DoubleVectorF vec, DoubleVectorF normal);
	DoubleVectorF VECCALL doubleVecFOrthogonal(DoubleVectorF vec, DoubleVectorF normal);
	DoubleVectorF VECCALL doubleVecFDotVec(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFLinePointDistanceVec(DoubleVectorF line, DoubleVectorF point);
	DoubleVectorF VECCALL doubleVecFAngleBetweenVec(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFInBoundVec(DoubleVectorF vec, DoubleVectorF left, DoubleVectorF right);
	DoubleVectorF VECCALL doubleVecFPow(const DoubleVectorF& vec, const DoubleVectorF& pow);
	DoubleVectorF VECCALL doubleVecFPow(const DoubleVectorF& vec, float pow);
	float VECCALL doubleVecFDot(DoubleVectorF vec1, DoubleVectorF vec2);
	float VECCALL doubleVecFLinePointDistance(DoubleVectorF line, DoubleVectorF point);
	float VECCALL doubleVecFAngleBetween(DoubleVectorF vec1, DoubleVectorF vec2);
	bool VECCALL doubleVecFinBound(DoubleVectorF vec, DoubleVectorF left, DoubleVectorF right);

}
