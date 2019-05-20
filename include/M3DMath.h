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

	union IntFloat
	{
		int i;
		float f;
	};

	union FloatInt
	{
		float f;
		int i;
	};

	inline float int2Float(int value)
	{
		return IntFloat{ value }.f;
	}
	inline int float2Int(float value)
	{
		return FloatInt{ value }.i;
	}

	/// Constants

	const float FNAN = int2Float(-1);

	/// Base vector structs
	struct Vector2;
	struct Vector3;
	struct Vector4;

	struct Vector2
	{
		float x, y;

		// Constructors
		Vector2() : x(0), y(0) {}
		Vector2(const Vector2& vector) = default;
		explicit Vector2(float value) : x(value), y(value) {}
		Vector2(float x, float y) : x(x), y(y) {}
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
		Vector2 operator-() const;
		

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
		float length() const;
		float sqrLength() const;
		Vector2 normalized() const;
		Vector2 orthogonal() const;
		Vector2 abs() const;
		Vector2 floor() const;
		Vector2 ceil() const;
		Vector2 round() const;
		Vector2 reciprocal() const;
		Vector2 saturate() const;
		Vector2 sqrt() const;
		Vector2 cos() const;
		Vector2 sin() const;
		Vector2 tan() const;
		Vector2 acos() const;
		Vector2 asin() const;
		Vector2 atan() const;
		Vector2 exp2() const;
		Vector2 expE() const;
		Vector2 log2() const;
		Vector2 logE() const;
		void sincos(Vector2& sin, Vector2& cos) const;		
	};

	struct Vector3
	{
		float x, y, z;

		// Constructors
		Vector3() : x(0), y(0), z(0) {}
		Vector3(const Vector3& vector) = default;
		explicit Vector3(float value) : x(value), y(value), z(value) {}
		Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
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
		Vector3 operator-() const;

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
		float length() const;
		float sqrLength() const;
		Vector3 normalized() const;
		Vector3 orthogonal() const;
		Vector3 abs() const;
		Vector3 floor() const;
		Vector3 ceil() const;
		Vector3 round() const;
		Vector3 reciprocal() const;
		Vector3 saturate() const;
		Vector3 sqrt() const;
		Vector3 cos() const;
		Vector3 sin() const;
		Vector3 tan() const;
		Vector3 acos() const;
		Vector3 asin() const;
		Vector3 atan() const;
		Vector3 exp2() const;
		Vector3 expE() const;
		Vector3 log2() const;
		Vector3 logE() const;
		void sincos(Vector3& sin, Vector3& cos) const;
	};
	
	struct ALIGN(16) Vector4
	{
		float x, y, z, w;

		// Constructors
		Vector4() : x(0), y(0), z(0), w(0) {}
		Vector4(const Vector4& vector) = default;
		Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
		explicit Vector4(float value) : x(value), y(value), z(value), w(value) {}
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
		Vector4 operator-() const;

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
		float length() const;
		float sqrLength() const;
		Vector4 normalized() const;
		Vector4 orthogonal3D() const;
		Vector4 orthogonal4D() const;
		Vector4 abs() const;
		Vector4 floor() const;
		Vector4 ceil() const;
		Vector4 round() const;
		Vector4 reciprocal() const;
		Vector4 saturate() const;
		Vector4 sqrt() const;
		Vector4 cos() const;
		Vector4 sin() const;
		Vector4 tan() const;
		Vector4 acos() const;
		Vector4 asin() const;
		Vector4 atan() const;
		Vector4 exp2() const;
		Vector4 expE() const;
		Vector4 log2() const;
		Vector4 logE() const;
		void sincos(Vector4& sin, Vector4& cos) const;
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
		explicit VectorF(float value);
		explicit VectorF(float x, float y, float z, float w);
		explicit VectorF(float* pArray);
		explicit VectorF(const Vector2& vector);
		explicit VectorF(const Vector3& vector);
		explicit VectorF(const Vector4& vector);
		explicit VectorF(const Vector2& vector1, const Vector2& vector2);
		operator M128&();

		// getters and setters
		float get(char  ind) const;
		void set(char ind, float value);
		int getInt(char ind) const;
		void setInt(char ind, int value);

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
		VectorF VECCALL operator-() const;

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
		void VECCALL load(float value);
		void VECCALL load(float x, float y, float z, float w);
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

		// Functions common
		VectorF VECCALL abs() const;
		VectorF VECCALL floor() const;
		VectorF VECCALL ceil() const;
		VectorF VECCALL round() const;
		VectorF VECCALL reciprocal() const;
		VectorF VECCALL saturate() const;
		VectorF VECCALL sqrt() const;
		VectorF VECCALL cos() const;
		VectorF VECCALL sin() const;
		VectorF VECCALL tan() const;
		VectorF VECCALL acos() const;
		VectorF VECCALL asin() const;
		VectorF VECCALL atan() const;
		VectorF VECCALL exp2() const;
		VectorF VECCALL expE() const;
		VectorF VECCALL log2() const;
		VectorF VECCALL logE() const;
		VectorF VECCALL sqrtFast() const;
		void sincos(VectorF& sin, VectorF& cos) const;
		VectorF VECCALL reciprocalFast() const;

		// functions 2d
		float length2D() const;
		float sqrLength2D() const;
		VectorF VECCALL normalized2D() const;
		VectorF VECCALL orthogonal2D() const;
		VectorF VECCALL lengthVec2D() const;
		VectorF VECCALL sqrLengthVec2D() const;
		VectorF VECCALL normalizedFast2D() const;

		// functions 3d
		float length3D() const;
		float sqrLength3D() const;
		VectorF VECCALL normalized3D() const;
		VectorF VECCALL orthogonal3D() const;
		VectorF VECCALL lengthVec3D() const;
		VectorF VECCALL sqrLengthVec3D() const;
		VectorF VECCALL normalizedFast3D() const;

		// functions 4d
		float length4D() const;
		float sqrLength4D() const;
		VectorF VECCALL normalized4D() const;
		VectorF VECCALL orthogonal4D() const;
		VectorF VECCALL lengthVec4D() const;
		VectorF VECCALL sqrLengthVec4D() const;
		VectorF VECCALL normalizedFast4D() const;
		
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
		explicit DoubleVectorF(float value);
		explicit DoubleVectorF(float x1, float y1, float z1, float w1, float x2, float y2, float z2, float w2);
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
		VECCALL operator M256&();

		// getters and setters
		float get(char ind) const;
		void set(char ind, float value);
		int getInt(char ind) const;
		void setInt(char ind, int value);

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
		DoubleVectorF VECCALL operator-() const;

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
		void VECCALL load(float value);
		void VECCALL load(float x1, float y1, float z1, float w1, float x2, float y2, float z2, float w2);
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

		// Functions common
		DoubleVectorF VECCALL abs() const;
		DoubleVectorF VECCALL floor() const;
		DoubleVectorF VECCALL ceil() const;
		DoubleVectorF VECCALL round() const;
		DoubleVectorF VECCALL reciprocal() const;
		DoubleVectorF VECCALL saturate() const;
		DoubleVectorF VECCALL sqrt() const;
		DoubleVectorF VECCALL cos() const;
		DoubleVectorF VECCALL sin() const;
		DoubleVectorF VECCALL tan() const;
		DoubleVectorF VECCALL acos() const;
		DoubleVectorF VECCALL asin() const;
		DoubleVectorF VECCALL atan() const;
		DoubleVectorF VECCALL exp2() const;
		DoubleVectorF VECCALL expE() const;
		DoubleVectorF VECCALL log2() const;
		DoubleVectorF VECCALL logE() const;
		DoubleVectorF VECCALL sqrtFast() const;
		DoubleVectorF VECCALL reciprocalFast() const;
		void sincos(DoubleVectorF& sin, DoubleVectorF& cos) const;

		// functions 2d
		void length2D(float& len1, float& len2) const;
		void sqrLength2D(float& len1, float& len2) const;
		DoubleVectorF VECCALL normalized2D() const;
		DoubleVectorF VECCALL orthogonal2D() const;
		DoubleVectorF VECCALL lengthVec2D() const;
		DoubleVectorF VECCALL sqrLengthVec2D() const;
		DoubleVectorF VECCALL normalizedFast2D() const;

		// functions 3d
		void length3D(float& len1, float& len2) const;
		void sqrLength3D(float& len1, float& len2) const;
		DoubleVectorF VECCALL normalized3D() const;
		DoubleVectorF VECCALL orthogonal3D() const;
		DoubleVectorF VECCALL lengthVec3D() const;
		DoubleVectorF VECCALL sqrLengthVec3D() const;
		DoubleVectorF VECCALL normalizedFast3D() const;

		// functions 4d
		void length4D(float& len1, float& len2) const;
		void sqrLength4D(float& len1, float& len2) const;
		DoubleVectorF VECCALL normalized4D() const;
		DoubleVectorF VECCALL orthogonal4D() const;
		DoubleVectorF VECCALL lengthVec4D() const;
		DoubleVectorF VECCALL sqrLengthVec4D() const;
		DoubleVectorF VECCALL normalizedFast4D() const;
	private:
		M256 m_data{};
	};

	/// Vector functions
	// Vector2
	Vector2 vec2Lerp(const Vector2& vec1, const Vector2& vec2, float value);
	Vector2 vec2Max(const Vector2& vec1, const Vector2& vec2);
	Vector2 vec2Min(const Vector2& vec1, const Vector2& vec2);
	Vector2 vec2Project(const Vector2& vec1, const Vector2& vec2);
	Vector2 vec2IntersectLines(const Vector2& l1p1, const Vector2& l1p2, const Vector2& l2p1, const Vector2& l2p2);
	Vector2 vec2Reflect(const Vector2& vec, const Vector2& normal);
	Vector2 vec2Refract(const Vector2& vec, const Vector2& normal, float refractionIndex);
	Vector2 vec2Pow(const Vector2& vec, const Vector2& pow);
	Vector2 vec2Pow(const Vector2& vec, float pow);
	float vec2Dot(const Vector2& vec1, const Vector2& vec2);
	float vec2Cross(const Vector2& vec1, const Vector2& vec2);
	float vec2Distance(const Vector2& vec1, const Vector2& vec2);
	float vec2LinePointDistance(const Vector2& linePoint1, const Vector2& linePoint2, const Vector2& point);
	float vec2AngleBetween(const Vector2& vec1, const Vector2& vec2);
	float vec2AngleBetweenNormals(const Vector2& vec1, const Vector2& vec2);
	bool vec2InBound(const Vector2& vec, const Vector2& left, const Vector2& right);

	// Vector3
	Vector3 vec3Cross(const Vector3& vec1, const Vector3& vec2);
	Vector3 vec3Lerp(const Vector3& vec1, const Vector3& vec2, float value);
	Vector3 vec3Max(const Vector3& vec1, const Vector3& vec2);
	Vector3 vec3Min(const Vector3& vec1, const Vector3& vec2);
	Vector3 vec3Project(const Vector3& vec1, const Vector3& vec2);
	Vector3 vec3IntersectLines(const Vector3& l1p1, const Vector3& l1p2, const Vector3& l2p1, const Vector3& l2p2);
	Vector3 vec3Reflect(const Vector3& vec, const Vector3& normal);
	Vector3 vec3Refract(const Vector3& vec, const Vector3& normal, float refractionIndex);
	Vector3 vec3Pow(const Vector3& vec, const Vector3& pow);
	Vector3 vec3Pow(const Vector3& vec, float pow);
	float vec3Dot(const Vector3& vec1, const Vector3& vec2);
	float vec3Distance(const Vector3& vec1, const Vector3& vec2);
	float vec3LinePointDistance(const Vector3& linePoint1, const Vector3& linePoint2, const Vector3& point);
	float vec3AngleBetween(const Vector3& vec1, const Vector3& vec2);
	float vec3AngleBetweenNormals(const Vector3& vec1, const Vector3& vec2);
	bool vec3InBound(const Vector3& vec, const Vector3& left, const Vector3& right);

	// Vector4
	Vector4 vec4Cross3D(const Vector4& vec1, const Vector4& vec2);
	Vector4 vec4Lerp(const Vector4& vec1, const Vector4& vec2, float value);
	Vector4 vec4Max(const Vector4& vec1, const Vector4& vec2);
	Vector4 vec4Min(const Vector4& vec1, const Vector4& vec2);
	Vector4 vec4Project(const Vector4& vec1, const Vector4& vec2);
	Vector4 vec4IntersectLines3D(const Vector4& l1p1, const Vector4& l1p2, const Vector4& l2p1, const Vector4& l2p2);
	Vector4 vec4Reflect(const Vector4& vec, const Vector4& normal);
	Vector4 vec4Refract(const Vector4& vec, const Vector4& normal, float refractionIndex);
	Vector4 vec4Pow(const Vector4& vec, const Vector4& pow);
	Vector4 vec4Pow(const Vector4& vec, float pow);
	float vec4Dot(const Vector4& vec1, const Vector4& vec2);
	float vec4Distance(const Vector4& vec1, const Vector4& vec2);
	float vec4LinePointDistance3D(const Vector4& linePoint1, const Vector4& linePoint2, const Vector4& point);
	float vec4AngleBetween(const Vector4& vec1, const Vector4& vec2);
	float vec4AngleBetweenNormals(const Vector4& vec1, const Vector4& vec2);
	bool vec4InBound(const Vector4& vec, const Vector4& left, const Vector4& right);

	// VectorF common
	VectorF VECCALL vecFMax(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFMin(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFPow(VectorF vec, VectorF pow);
	VectorF VECCALL vecFPow(VectorF vec, float pow);
	VectorF VECCALL vecFLerp(VectorF vec1, VectorF vec2, float value);
	bool VECCALL vecFInBound(VectorF vec, VectorF left, VectorF right);

	// VectorF 2D
	VectorF VECCALL vecFCross2D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFProject2D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFReflect2D(VectorF vec, VectorF normal);
	VectorF VECCALL vecFRefract2D(VectorF vec, VectorF normal, float refractionIndex);

	VectorF VECCALL vecFDistanceVec2D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFRefractVec2D(VectorF vec, VectorF normal, VectorF refractionIndex);
	VectorF VECCALL vecFLerpVec2D(VectorF vec1, VectorF vec2, VectorF value);
	VectorF VECCALL vecFDotVec2D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFLinePointDistanceVec2D(VectorF linePoint1, VectorF linePoint2, VectorF point);
	VectorF VECCALL vecFAngleBetweenVec2D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFAngleBetweenNormalsVec2D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFIntersectLines2D(VectorF l1p1, VectorF l1p2, VectorF l2p1, VectorF l2p2);

	float VECCALL vecFDistance2D(VectorF vec1, VectorF vec2);
	float VECCALL vecFDot2D(VectorF vec1, VectorF vec2);
	float VECCALL vecFAngleBetween2D(VectorF vec1, VectorF vec2);
	float VECCALL vecFAngleBetweenNormals2D(VectorF vec1, VectorF vec2);
	float VECCALL vecFLinePointDistance2D2D(VectorF linePoint1, VectorF linePoint2, VectorF point);
	bool VECCALL vecFcmp2D(VectorF vec1, VectorF vec2, int type);

	// VectorF 3D
	VectorF VECCALL vecFCross3D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFProject3D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFReflect3D(VectorF vec, VectorF normal);
	VectorF VECCALL vecFRefract3D(VectorF vec, VectorF normal, float refractionIndex);

	VectorF VECCALL vecFDistanceVec3D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFRefractVec3D(VectorF vec, VectorF normal, VectorF refractionIndex);
	VectorF VECCALL vecFLerpVec3D(VectorF vec1, VectorF vec2, VectorF value);
	VectorF VECCALL vecFDotVec3D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFLinePointDistanceVec3D(VectorF linePoint1, VectorF linePoint2, VectorF point);
	VectorF VECCALL vecFAngleBetweenVec3D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFAngleBetweenNormalsVec3D(VectorF vec1, VectorF vec2);

	float VECCALL vecFDistance3D(VectorF vec1, VectorF vec2);
	float VECCALL vecFDot3D(VectorF vec1, VectorF vec2);
	float VECCALL vecFAngleBetween3D(VectorF vec1, VectorF vec2);
	float VECCALL vecFAngleBetweenNormals3D(VectorF vec1, VectorF vec2);
	float VECCALL vecFLinePointDistance3D(VectorF linePoint1, VectorF linePoint2, VectorF point);
	bool VECCALL vecFcmp3D(VectorF vec1, VectorF vec2, int type);

	// VectorF 4D
	VectorF VECCALL doubleVecFCross4D(VectorF vec1, VectorF vec2);
	VectorF VECCALL doubleVecFProject4D(VectorF vec1, VectorF vec2);
	VectorF VECCALL doubleVecFReflect4D(VectorF vec, VectorF normal);
	VectorF VECCALL doubleVecFRefract4D(VectorF vec, VectorF normal, float refractionIndex);

	VectorF VECCALL doubleVecFDistanceVec4D(VectorF vec1, VectorF vec2);
	VectorF VECCALL doubleVecFRefractVec4D(VectorF vec, VectorF normal, VectorF refractionIndex);
	VectorF VECCALL doubleVecFLerpVec4D(VectorF vec1, VectorF vec2, VectorF value);
	VectorF VECCALL doubleVecFDotVec4D(VectorF vec1, VectorF vec2);
	VectorF VECCALL doubleVecFAngleBetweenVec4D(VectorF vec1, VectorF vec2);
	VectorF VECCALL doubleVecFAngleBetweenNormalsVec4D(VectorF vec1, VectorF vec2);

	float VECCALL doubleVecFDistance4D(VectorF vec1, VectorF vec2);
	float VECCALL doubleVecFDot4D(VectorF vec1, VectorF vec2);
	float VECCALL doubleVecFAngleBetween4D(VectorF vec1, VectorF vec2);
	float VECCALL doubleVecFAngleBetweenNormals4D(VectorF vec1, VectorF vec2);
	bool VECCALL vecFcmp4D(VectorF vec1, VectorF vec2, int type);
	
	// DoubleVectorF common
	DoubleVectorF VECCALL doubleVecFMax(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFMin(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFPow(DoubleVectorF vec, DoubleVectorF pow);
	DoubleVectorF VECCALL doubleVecFPow(DoubleVectorF vec, float pow);
	DoubleVectorF VECCALL doubleVecFLerp(DoubleVectorF vec1, DoubleVectorF vec2, float value);
	bool VECCALL doubleVecFInBound(DoubleVectorF vec, DoubleVectorF left, DoubleVectorF right);

	// DoubleVectorF 2D
	DoubleVectorF VECCALL doubleVecFCross2D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFProject2D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFReflect2D(DoubleVectorF vec, DoubleVectorF normal);
	DoubleVectorF VECCALL doubleVecFRefract2D(DoubleVectorF vec, DoubleVectorF normal, float refractionIndex);

	DoubleVectorF VECCALL doubleVecFDistanceVec2D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFRefractVec2D(DoubleVectorF vec, DoubleVectorF normal, DoubleVectorF refractionIndex);
	DoubleVectorF VECCALL doubleVecFLerpVec2D(DoubleVectorF vec1, DoubleVectorF vec2, DoubleVectorF value);
	DoubleVectorF VECCALL doubleVecFDotVec2D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFLinePointDistanceVec2D(DoubleVectorF linePoint1, DoubleVectorF linePoint2, DoubleVectorF point);
	DoubleVectorF VECCALL doubleVecFAngleBetweenVec2D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFAngleBetweenNormalsVec2D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFIntersectLines2D(DoubleVectorF l1p1, DoubleVectorF l1p2, DoubleVectorF l2p1, DoubleVectorF l2p2);

	float VECCALL doubleVecFDistance2D(DoubleVectorF vec1, DoubleVectorF vec2);
	float VECCALL doubleVecFDot2D(DoubleVectorF vec1, DoubleVectorF vec2);
	float VECCALL doubleVecFAngleBetween2D(DoubleVectorF vec1, DoubleVectorF vec2);
	float VECCALL doubleVecFAngleBetweenNormals2D(DoubleVectorF vec1, DoubleVectorF vec2);
	float VECCALL doubleVecFLinePointDistance2D(DoubleVectorF linePoint1, DoubleVectorF linePoint2, DoubleVectorF point);
	bool VECCALL doubleVecFcmp2D(DoubleVectorF vec1, DoubleVectorF vec2, int type);

	// DoubleVectorF 3D
	DoubleVectorF VECCALL doubleVecFCross3D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFProject3D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFReflect3D(DoubleVectorF vec, DoubleVectorF normal);
	DoubleVectorF VECCALL doubleVecFRefract3D(DoubleVectorF vec, DoubleVectorF normal, float refractionIndex);

	DoubleVectorF VECCALL doubleVecFDistanceVec3D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFRefractVec3D(DoubleVectorF vec, DoubleVectorF normal, DoubleVectorF refractionIndex);
	DoubleVectorF VECCALL doubleVecFLerpVec3D(DoubleVectorF vec1, DoubleVectorF vec2, DoubleVectorF value);
	DoubleVectorF VECCALL doubleVecFDotVec3D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFLinePointDistanceVec3D(DoubleVectorF linePoint1, DoubleVectorF linePoint2, DoubleVectorF point);
	DoubleVectorF VECCALL doubleVecFAngleBetweenVec3D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFAngleBetweenNormalsVec3D(DoubleVectorF vec1, DoubleVectorF vec2);

	float VECCALL doubleVecFDistance3D(DoubleVectorF vec1, DoubleVectorF vec2);
	float VECCALL doubleVecFDot3D(DoubleVectorF vec1, DoubleVectorF vec2);
	float VECCALL doubleVecFAngleBetween3D(DoubleVectorF vec1, DoubleVectorF vec2);
	float VECCALL doubleVecFAngleBetweenNormals3D(DoubleVectorF vec1, DoubleVectorF vec2);
	float VECCALL doubleVecFLinePointDistance3D(DoubleVectorF linePoint1, DoubleVectorF linePoint2, DoubleVectorF point);
	bool VECCALL doubleVecFcmp3D(DoubleVectorF vec1, DoubleVectorF vec2, int type);

	// DoubleVectorF 4D
	DoubleVectorF VECCALL doubleVecFCross4D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFProject4D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFReflect4D(DoubleVectorF vec, DoubleVectorF normal);
	DoubleVectorF VECCALL doubleVecFRefract4D(DoubleVectorF vec, DoubleVectorF normal, float refractionIndex);

	DoubleVectorF VECCALL doubleVecFDistanceVec4D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFRefractVec4D(DoubleVectorF vec, DoubleVectorF normal, DoubleVectorF refractionIndex);
	DoubleVectorF VECCALL doubleVecFLerpVec4D(DoubleVectorF vec1, DoubleVectorF vec2, DoubleVectorF value);
	DoubleVectorF VECCALL doubleVecFDotVec4D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFAngleBetweenVec4D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFAngleBetweenNormalsVec4D(DoubleVectorF vec1, DoubleVectorF vec2);

	float VECCALL doubleVecFDistance4D(DoubleVectorF vec1, DoubleVectorF vec2);
	float VECCALL doubleVecFDot4D(DoubleVectorF vec1, DoubleVectorF vec2);
	float VECCALL doubleVecFAngleBetween4D(DoubleVectorF vec1, DoubleVectorF vec2);
	float VECCALL doubleVecFAngleBetweenNormals4D(DoubleVectorF vec1, DoubleVectorF vec2);
	bool VECCALL doubleVecFcmp4D(DoubleVectorF vec1, DoubleVectorF vec2, int type);
}
