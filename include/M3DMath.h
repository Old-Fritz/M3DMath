#pragma once

#define VECCALL


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
		explicit Vector2(Vector3 vector);
		explicit Vector2(Vector4 vector);
		operator float* ();
		operator float const* () const;

		// Base operations
		Vector2 operator+(Vector2 vector) const;
		Vector2 operator-(Vector2 vector) const;
		Vector2 operator*(Vector2 vector) const;
		Vector2 operator/(Vector2 vector) const;
		Vector2 operator*(float scale) const;
		Vector2 operator/(float scale) const;
		Vector2& operator+=(Vector2 vector);
		Vector2& operator-=(Vector2 vector);
		Vector2& operator*=(Vector2 vector);
		Vector2& operator/=(Vector2 vector);
		Vector2& operator*=(float scale);
		Vector2& operator/=(float scale);
		

		// Compare functions
		bool operator==(Vector2 vector) const;
		bool operator<(Vector2 vector) const;
		bool operator>(Vector2 vector) const;
		bool operator<=(Vector2 vector) const;
		bool operator>=(Vector2 vector) const;
		bool isEqualPrec(Vector2 vector, float precision = 0) const;
		bool isEqualPrec(Vector2 vector, Vector2 precision) const;
		Vector2 isEqualVec(Vector2 vector) const;
		Vector2 isEqualPrecVec(Vector2 vector, Vector2 precision) const;
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
		explicit Vector3(Vector2 vector) : x(vector.x), y(vector.y), z(0) {}
		explicit Vector3(Vector4 vector);
		operator float* ();
		operator float const* () const;

		// Base operations
		Vector3 operator+(Vector3 vector) const;
		Vector3 operator-(Vector3 vector) const;
		Vector3 operator*(Vector3 vector) const;
		Vector3 operator/(Vector3 vector) const;
		Vector3 operator*(float scale) const;
		Vector3 operator/(float scale) const;
		Vector3& operator+=(Vector3 vector);
		Vector3& operator-=(Vector3 vector);
		Vector3& operator*=(Vector3 vector);
		Vector3& operator/=(Vector3 vector);
		Vector3& operator*=(float scale);
		Vector3& operator/=(float scale);

		// Compare functions
		bool operator==(Vector3 vector) const;
		bool operator<(Vector3 vector) const;
		bool operator>(Vector3 vector) const;
		bool operator<=(Vector3 vector) const;
		bool operator>=(Vector3 vector) const;
		bool isEqualPrec(Vector3 vector, float precision = 0) const;
		bool isEqualPrec(Vector3 vector, Vector3 precision) const;
		Vector3 isEqualVec(Vector3 vector) const;
		Vector3 isEqualPrecVec(Vector3 vector, Vector3 precision) const;
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
		explicit Vector4(const Vector2 vector) : x(vector.x), y(vector.y), z(0), w(0) {}
		explicit Vector4(const Vector3 vector) : x(vector.x), y(vector.y), z(vector.z), w(0) {}
		explicit Vector4(const Vector2 vector1, const Vector2& vector2) : x(vector1.x), y(vector1.y), z(vector2.x), w(vector2.y) {}
		operator float*();
		operator float const * () const;

		// Base operations
		Vector4 operator+(Vector4 vector) const;
		Vector4 operator-(Vector4 vector) const;
		Vector4 operator*(Vector4 vector) const;
		Vector4 operator/(Vector4 vector) const;
		Vector4 operator*(float scale) const;
		Vector4 operator/(float scale) const;
		Vector4& operator+=(Vector4 vector);
		Vector4& operator-=(Vector4 vector);
		Vector4& operator*=(Vector4 vector);
		Vector4& operator/=(Vector4 vector);
		Vector4& operator*=(float scale);
		Vector4& operator/=(float scale);

		// Compare functions
		bool operator==(Vector4 vector) const;
		bool operator<(Vector4 vector) const;
		bool operator>(Vector4 vector) const;
		bool operator<=(Vector4 vector) const;
		bool operator>=(Vector4 vector) const;
		bool isEqualPrec(Vector4 vector, float precision = 0) const;
		bool isEqualPrec(Vector4 vector, Vector4 precision) const;
		Vector4 isEqualVec(Vector4 vector) const;
		Vector4 isEqualPrecVec(Vector4 vector, Vector4 precision) const;
	};

	/// Different operator combinations
#pragma region 
	// Vector2 and Vector3
	Vector3 operator*(Vector3 vector1, Vector2 vector2);
	Vector3 operator*(Vector2 vector1, Vector3 vector2);
	Vector3 operator/(Vector3 vector1, Vector2 vector2);
	Vector3 operator/(Vector2 vector1, Vector3 vector2);
	Vector3 operator+(Vector3 vector1, Vector2 vector2);
	Vector3 operator+(Vector2 vector1, Vector3 vector2);
	Vector3 operator-(Vector3 vector1, Vector2 vector2);
	Vector3 operator-(Vector2 vector1, Vector3 vector2);

	// Vector2 and Vector4
	Vector4 operator*(Vector4 vector1, Vector2 vector2);
	Vector4 operator*(Vector2 vector1, Vector4 vector2);
	Vector4 operator/(Vector4 vector1, Vector2 vector2);
	Vector4 operator/(Vector2 vector1, Vector4 vector2);
	Vector4 operator+(Vector4 vector1, Vector2 vector2);
	Vector4 operator+(Vector2 vector1, Vector4 vector2);
	Vector4 operator-(Vector4 vector1, Vector2 vector2);
	Vector4 operator-(Vector2 vector1, Vector4 vector2);

	// Vector3 and Vector4
	Vector4 operator*(Vector4 vector1, Vector3 vector2);
	Vector4 operator*(Vector3 vector1, Vector4 vector2);
	Vector4 operator/(Vector4 vector1, Vector3 vector2);
	Vector4 operator/(Vector3 vector1, Vector4 vector2);
	Vector4 operator+(Vector4 vector1, Vector3 vector2);
	Vector4 operator+(Vector3 vector1, Vector4 vector2);
	Vector4 operator-(Vector4 vector1, Vector3 vector2);
	Vector4 operator-(Vector3 vector1, Vector4 vector2);

	// Scalar operations
	Vector2 operator*(float scale, Vector2 vector);
	Vector3 operator*(float scale, Vector3 vector);
	Vector4 operator*(float scale, Vector4 vector);
	Vector2 operator/(float scale, Vector2 vector);
	Vector3 operator/(float scale, Vector3 vector);
	Vector4 operator/(float scale, Vector4 vector);
#pragma endregion operators
	
	/// SSE vector
	class ALIGN(16) VectorF
	{
	public:
		// Constructors
		VECCALL VectorF() : m_data() {}
		VECCALL VectorF(const VectorF& vector) = default;
		VECCALL VectorF(M128 data) : m_data(data) {}
		VectorF& VECCALL operator=(const VectorF& vector) = default;
		
		// Conversions
		explicit VECCALL VectorF(float x = 0, float y = 0, float z = 0, float w = 0);
		explicit VECCALL VectorF(float* pArray);
		explicit VECCALL VectorF(Vector2 vector);
		explicit VECCALL VectorF(Vector3 vector);
		explicit VECCALL VectorF(Vector4 vector);
		explicit VECCALL VectorF(Vector2 vector1, Vector2 vector2);
		VECCALL operator M128() const;

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
		void VECCALL load(Vector2 vector);
		void VECCALL load(Vector3 vector);
		void VECCALL load(Vector4 vector);
		void VECCALL load(Vector2 vector1, Vector2 vector2);

		void VECCALL store(float& x, float& y, float& z, float& w) const;
		void VECCALL store(float* pArray) const;
		void VECCALL store(Vector2& vector) const;
		void VECCALL store(Vector3& vector) const;
		void VECCALL store(Vector4& vector) const;
		void VECCALL store(Vector2& vector1, Vector2& vector2) const;

	private:
		M128 m_data{};
	};

	/// AVX vector
	class ALIGN(32) DoubleVectorF
	{
	public:
		// Constructors
		VECCALL DoubleVectorF() : m_data() {}
		VECCALL DoubleVectorF(const DoubleVectorF& vector) = default;
		VECCALL DoubleVectorF(M256 data) : m_data(data) {}
		DoubleVectorF& VECCALL operator=(const DoubleVectorF& vector) = default;

		// Conversions
		explicit VECCALL DoubleVectorF(float x1 = 0, float y1 = 0, float z1 = 0, float w1 = 0, float x2 = 0, float y2 = 0, float z2 = 0, float w2 = 0);
		explicit VECCALL DoubleVectorF(float* pArray);
		explicit VECCALL DoubleVectorF(Vector2 vector);
		explicit VECCALL DoubleVectorF(Vector3 vector);
		explicit VECCALL DoubleVectorF(Vector4 vector);
		explicit VECCALL DoubleVectorF(Vector2 vector1, Vector2 vector2);
		explicit VECCALL DoubleVectorF(Vector3 vector1, Vector3 vector2);
		explicit VECCALL DoubleVectorF(Vector4 vector1, Vector4 vector2);
		explicit VECCALL DoubleVectorF(Vector2 vector1, Vector2 vector2, Vector2 vector3, Vector2 vector4);
		explicit VECCALL DoubleVectorF(VectorF vector);
		explicit VECCALL DoubleVectorF(VectorF vector1, VectorF vector2);
		VECCALL operator M256() const;

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
		void VECCALL load(Vector2 vector);
		void VECCALL load(Vector3 vector);
		void VECCALL load(Vector4 vector);
		void VECCALL load(Vector2 vector1, Vector2 vector2);
		void VECCALL load(Vector3 vector1, Vector3 vector2);
		void VECCALL load(Vector4 vector1, Vector4 vector2);
		void VECCALL load(Vector2 vector1, Vector2 vector2, Vector2 vector3, Vector2 vector4);
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
	private:
		M256 m_data{};
	};
	
}
