#pragma once
#ifdef WIN32
#include <DirectXMath.h>
#endif

// x86_64 platform
#if defined(__x86_64__) || defined(__i386__) || defined(WIN32)
# include <xmmintrin.h>
# include <emmintrin.h>
# include <pmmintrin.h>
# include <smmintrin.h>
# include <immintrin.h>
# define M128 __m128
# define M256 __m256
#endif
// arm_platform
#ifdef __ARM_NEON
#define __ARM_FEATURE_FP16_VECTOR_ARITHMETIC 1
#include <arm_neon.h>
#define M128 float64x1x2_t
#define M256 float64x2x2_t
#define NO_ALIGNS
#define ALIGN(N) 
#endif

#ifndef NO_ALIGNS
#define ALIGN(N) alignas((N))
#endif



namespace M3DM
{
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
		

		// Compare functions
		bool operator==(const Vector2& vector) const;
		bool operator<(const Vector2& vector) const;
		bool operator>(const Vector2& vector) const;
		bool operator<=(const Vector2& vector) const;
		bool operator>=(const Vector2& vector) const;
		bool isEqualPrec(const Vector2& vector, float precision = 0) const;
		bool isEqualPrec(const Vector2& vector, const Vector2& precision) const;
		Vector2 isEqualVec(const Vector2& vector) const;
		Vector2 isEqualPrecVec(const Vector2& vector, const Vector2& precision) const;
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
		VectorF& operator=(const VectorF& vector) = default;
		
		// Conversions
		explicit VectorF(float x = 0, float y = 0, float z = 0, float w = 0);
		explicit VectorF(float* pArray);
		explicit VectorF(const Vector2& vector);
		explicit VectorF(const Vector3& vector);
		explicit VectorF(const Vector4& vector);
		explicit VectorF(const Vector2& vector1, const Vector2& vector2);
		operator M128() const;

		// Base operations
		VectorF operator+(const VectorF& vector) const;
		VectorF operator-(const VectorF& vector) const;
		VectorF operator*(const VectorF& vector) const;
		VectorF operator/(const VectorF& vector) const;
		VectorF operator*(float scale) const;
		VectorF operator/(float scale) const;
		VectorF& operator+=(const VectorF& vector);
		VectorF& operator-=(const VectorF& vector);
		VectorF& operator*=(const VectorF& vector);
		VectorF& operator/=(const VectorF& vector);
		VectorF& operator*=(float scale);
		VectorF& operator/=(float scale);

		// Compare functions
		bool operator==(const VectorF& vector) const;
		bool operator<(const VectorF& vector) const;
		bool operator>(const VectorF& vector) const;
		bool operator<=(const VectorF& vector) const;
		bool operator>=(const VectorF& vector) const;
		bool isEqualPrec(const VectorF& vector, float precision = 0) const;
		bool isEqualPrec(const VectorF& vector, const VectorF& precision) const;
		VectorF isEqualVec(const VectorF& vector) const;
		VectorF isEqualPrecVec(const VectorF& vector, const VectorF& precision) const;

		// load/store
		void load(float x = 0, float y = 0, float z = 0, float w = 0);
		void load(const float* pArray);
		void load(const Vector2& vector);
		void load(const Vector3& vector);
		void load(const Vector4& vector);
		void load(const Vector2& vector1, const Vector2& vector2);

		void store(float& x, float& y, float& z, float& w) const;
		void store(float* pArray) const;
		void store(Vector2& vector) const;
		void store(Vector3& vector) const;
		void store(Vector4& vector) const;
		void store(Vector2& vector1, Vector2& vector2) const;

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
		DoubleVectorF& operator=(const DoubleVectorF& vector) = default;

		// Conversions
		explicit DoubleVectorF(float x1 = 0, float y1 = 0, float z1 = 0, float w1 = 0, float x2 = 0, float y2 = 0, float z2 = 0, float w2 = 0);
		explicit DoubleVectorF(float* pArray);
		explicit DoubleVectorF(const Vector2& vector);
		explicit DoubleVectorF(const Vector3& vector);
		explicit DoubleVectorF(const Vector4& vector);
		explicit DoubleVectorF(const Vector2& vector1, const Vector2& vector2);
		explicit DoubleVectorF(const Vector3& vector1, const Vector3& vector2);
		explicit DoubleVectorF(const Vector4& vector1, const Vector4& vector2);
		explicit DoubleVectorF(const Vector2& vector1, const Vector2& vector2, const Vector2& vector3, const Vector2& vector4);
		explicit DoubleVectorF(const VectorF& vector);
		explicit DoubleVectorF(const VectorF& vector1, const VectorF& vector2);
		operator M256() const;

		// Base operations
		DoubleVectorF operator+(const DoubleVectorF& vector) const;
		DoubleVectorF operator-(const DoubleVectorF& vector) const;
		DoubleVectorF operator*(const DoubleVectorF& vector) const;
		DoubleVectorF operator/(const DoubleVectorF& vector) const;
		DoubleVectorF operator*(float scale) const;
		DoubleVectorF operator/(float scale) const;
		DoubleVectorF& operator+=(const DoubleVectorF& vector);
		DoubleVectorF& operator-=(const DoubleVectorF& vector);
		DoubleVectorF& operator*=(const DoubleVectorF& vector);
		DoubleVectorF& operator/=(const DoubleVectorF& vector);
		DoubleVectorF& operator*=(float scale);
		DoubleVectorF& operator/=(float scale);

		// Compare functions
		bool operator==(const DoubleVectorF& vector) const;
		bool operator<(const DoubleVectorF& vector) const;
		bool operator>(const DoubleVectorF& vector) const;
		bool operator<=(const DoubleVectorF& vector) const;
		bool operator>=(const DoubleVectorF& vector) const;
		bool isEqualPrec(const DoubleVectorF& vector, float precision = 0) const;
		bool isEqualPrec(const DoubleVectorF& vector, const DoubleVectorF& precision) const;
		DoubleVectorF isEqualVec(const DoubleVectorF& vector) const;
		DoubleVectorF isEqualPrecVec(const DoubleVectorF& vector, const DoubleVectorF& precision) const;

		// load/store
		void load(float x1 = 0, float y1 = 0, float z1 = 0, float w1 = 0, float x2 = 0, float y2 = 0, float z2 = 0, float w2 = 0);
		void load(const float* pArray);
		void load(const Vector2& vector);
		void load(const Vector3& vector);
		void load(const Vector4& vector);
		void load(const Vector2& vector1, const Vector2& vector2);
		void load(const Vector3& vector1, const Vector3& vector2);
		void load(const Vector4& vector1, const Vector4& vector2);
		void load(const Vector2& vector1, const Vector2& vector2, const Vector2& vector3, const Vector2& vector4);
		void load(const VectorF& vector);
		void load(const VectorF& vector1, const VectorF& vector2);

		void store(float& x1, float& y1, float& z1, float& w1, float& x2, float& y2, float& z2, float& w2) const;
		void store(float* pArray) const;
		void store(Vector2& vector) const;
		void store(Vector3& vector) const;
		void store(Vector4& vector) const;
		void store(Vector2& vector1, Vector2& vector2) const;
		void store(Vector3& vector1, Vector3& vector2) const;
		void store(Vector4& vector1, Vector4& vector2) const;
		void store(Vector2& vector1, Vector2& vector2, Vector2& vector3, Vector2& vector4) const;
		void store(VectorF& vector) const;
		void store(VectorF& vector1, VectorF& vector2) const;
	private:
		M256 m_data{};
	};
	
}
