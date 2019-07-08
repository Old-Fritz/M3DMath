#pragma once

#define VECCALL
#define M128 __m128
#define M256 __m256


#ifdef WIN32
#include <DirectXMath.h>
#define DIRECTX
#define VECCALL __vectorcall
#endif

// x86_64 platform
#if defined(__x86_64__) || defined(__i386__) || defined(WIN32)
# define _AVX2_
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

/// CMP defines
#define CMP_EQ 0
#define CMP_LT 1
#define CMP_LE 2
#define CMP_GT 3
#define CMP_GE 4


/// Improved shuffles

#define vecFMakeShuffleMask(x,y,z,w)           (x | (y<<2) | (z<<4) | (w<<6))

// vec(0, 1, 2, 3) -> (vec[x], vec[y], vec[z], vec[w])
#define vecFSwizzleMask(vec, mask)          _mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(vec), mask))
#define vecFSwizzle(vec, x, y, z, w)        vecFSwizzleMask(vec, vecFMakeShuffleMask(x,y,z,w))
#define vecFSwizzle1(vec, x)                vecFSwizzleMask(vec, vecFMakeShuffleMask(x,x,x,x))
// special swizzle
#define vecFSwizzle_0022(vec)               _mm_moveldup_ps(vec)
#define vecFSwizzle_1133(vec)               _mm_movehdup_ps(vec)
// return (vec1[x], vec1[y], vec2[z], vec2[w])
#define vecFShuffle(vec1, vec2, x,y,z,w)    _mm_shuffle_ps(vec1, vec2, vecFMakeShuffleMask(x,y,z,w))
// special shuffle
#define vecFShuffle_0101(vec1, vec2)        _mm_movelh_ps(vec1, vec2)
#define vecFShuffle_2323(vec1, vec2)        _mm_movehl_ps(vec2, vec1)


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
#ifdef DIRECTX
		DirectX::XMFLOAT2* XMFloat2Ptr()
		{
			return reinterpret_cast<DirectX::XMFLOAT2*>(this);
		}
		DirectX::XMVECTOR VECCALL XMVec()
		{
			return DirectX::XMLoadFloat2(XMFloat2Ptr());
		}
#endif

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
		Vector2* Vec2Ptr()
		{
			return reinterpret_cast<Vector2*>(this);
		}
#ifdef DIRECTX
		DirectX::XMFLOAT3* XMFloat3Ptr()
		{
			return reinterpret_cast<DirectX::XMFLOAT3*>(this);
		}
		DirectX::XMVECTOR VECCALL XMVec()
		{
			return DirectX::XMLoadFloat3(XMFloat3Ptr());
		}
#endif

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
		explicit operator Vector2* ();
		explicit operator Vector3* ();
		Vector2* Vec2Ptr()
		{
			return reinterpret_cast<Vector2*>(this);
		}
		Vector3* Vec3Ptr()
		{
			return reinterpret_cast<Vector3*>(this);
		}
#ifdef DIRECTX
		DirectX::XMFLOAT4* XMFloat4Ptr()
		{
			return reinterpret_cast<DirectX::XMFLOAT4*>(this);
		}
		DirectX::XMVECTOR VECCALL XMVec()
		{
			return DirectX::XMLoadFloat4(XMFloat4Ptr());
		}
#endif

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
		explicit VectorF(const float* pArray);
		explicit VectorF(const Vector2& vector);
		explicit VectorF(const Vector3& vector);
		explicit VectorF(const Vector4& vector);
		explicit VectorF(const Vector2& vector1, const Vector2& vector2);
		M128 VECCALL getData() const
		{
			return m_data;
		}
		M128& VECCALL getDataRef()
		{
			return m_data;
		}
		const M128& VECCALL getDataConstRef() const
		{
			return m_data;
		}
#ifdef DIRECTX
		DirectX::XMVECTOR VECCALL XMVec()
		{
			return m_data;
		}
#endif

		// getters and setters
		float VECCALL get(char  ind) const;
		void VECCALL set(char ind, float value);
		int VECCALL getInt(char ind) const;
		void VECCALL setInt(char ind, int value);

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

		friend VectorF VECCALL operator*(float scale, VectorF vector);
		friend VectorF VECCALL operator/(float scale, VectorF vector);

		// Compare functions
		bool VECCALL operator==(VectorF vector) const;
		bool VECCALL operator<(VectorF vector) const;
		bool VECCALL operator>(VectorF vector) const;
		bool VECCALL operator<=(VectorF vector) const;
		bool VECCALL operator>=(VectorF vector) const;
		bool VECCALL isEqualPrec(VectorF vector, float precision = 0, int mask = 0b1111) const;
		bool VECCALL isEqualPrec(VectorF vector, VectorF precision, int mask = 0b1111) const;
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
		void VECCALL sincos(VectorF& sin, VectorF& cos) const;
		VectorF VECCALL reciprocalFast() const;

		// functions 2d
		float VECCALL length2D() const;
		float VECCALL sqrLength2D() const;
		VectorF VECCALL normalized2D() const;
		VectorF VECCALL orthogonal2D() const;
		VectorF VECCALL lengthVec2D() const;
		VectorF VECCALL sqrLengthVec2D() const;
		VectorF VECCALL normalizedFast2D() const;

		// functions 3d
		float VECCALL length3D() const;
		float VECCALL sqrLength3D() const;
		VectorF VECCALL normalized3D() const;
		VectorF VECCALL orthogonal3D() const;
		VectorF VECCALL lengthVec3D() const;
		VectorF VECCALL sqrLengthVec3D() const;
		VectorF VECCALL normalizedFast3D() const;

		// functions 4d
		float VECCALL length4D() const;
		float VECCALL sqrLength4D() const;
		VectorF VECCALL normalized4D() const;
		VectorF VECCALL orthogonal4D() const;
		VectorF VECCALL lengthVec4D() const;
		VectorF VECCALL sqrLengthVec4D() const;
		VectorF VECCALL normalizedFast4D() const;
		
	private:
		M128 m_data;
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
		explicit DoubleVectorF(const float* pArray);
		explicit DoubleVectorF(const Vector2& vector);
		explicit DoubleVectorF(const Vector3& vector);
		explicit DoubleVectorF(const Vector4& vector);
		explicit DoubleVectorF(const Vector2& vector1, const Vector2& vector2);
		explicit DoubleVectorF(const Vector3& vector1, const Vector3& vector2);
		explicit DoubleVectorF(const Vector4& vector1, const Vector4& vector2);
		explicit DoubleVectorF(const Vector2& vector1, const Vector2& vector2, const Vector2& vector3, const Vector2& vector4);
		explicit DoubleVectorF(VectorF vector);
		explicit DoubleVectorF(VectorF vector1, VectorF vector2);
		M256 VECCALL getData() const
		{
			return m_data;
		}
		M256& VECCALL getDataRef()
		{
			return m_data;
		}
		const M256& VECCALL getDataConstRef() const
		{
			return m_data;
		}

		// getters and setters
		float VECCALL get(char ind) const;
		void VECCALL set(char ind, float value);
		int VECCALL getInt(char ind) const;
		void VECCALL setInt(char ind, int value);

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

		friend DoubleVectorF VECCALL operator*(float scale, DoubleVectorF vector);
		friend DoubleVectorF VECCALL operator/(float scale, DoubleVectorF vector);

		// Compare functions
		bool VECCALL operator==(DoubleVectorF vector) const;
		bool VECCALL operator<(DoubleVectorF vector) const;
		bool VECCALL operator>(DoubleVectorF vector) const;
		bool VECCALL operator<=(DoubleVectorF vector) const;
		bool VECCALL operator>=(DoubleVectorF vector) const;
		bool VECCALL isEqualPrec(DoubleVectorF vector, float precision = 0, int mask = 0b11111111) const;
		bool VECCALL isEqualPrec(DoubleVectorF vector, DoubleVectorF precision, int mask = 0b11111111) const;
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
		void VECCALL sincos(DoubleVectorF& sin, DoubleVectorF& cos) const;

		// functions 2d
		void VECCALL length2D(float& len1, float& len2) const;
		void VECCALL sqrLength2D(float& len1, float& len2) const;
		DoubleVectorF VECCALL normalized2D() const;
		DoubleVectorF VECCALL orthogonal2D() const;
		DoubleVectorF VECCALL lengthVec2D() const;
		DoubleVectorF VECCALL sqrLengthVec2D() const;
		DoubleVectorF VECCALL normalizedFast2D() const;

		// functions 3d
		void VECCALL length3D(float& len1, float& len2) const;
		void VECCALL sqrLength3D(float& len1, float& len2) const;
		DoubleVectorF VECCALL normalized3D() const;
		DoubleVectorF VECCALL orthogonal3D() const;
		DoubleVectorF VECCALL lengthVec3D() const;
		DoubleVectorF VECCALL sqrLengthVec3D() const;
		DoubleVectorF VECCALL normalizedFast3D() const;

		// functions 4d
		void VECCALL length4D(float& len1, float& len2) const;
		void VECCALL sqrLength4D(float& len1, float& len2) const;
		DoubleVectorF VECCALL normalized4D() const;
		DoubleVectorF VECCALL orthogonal4D() const;
		DoubleVectorF VECCALL lengthVec4D() const;
		DoubleVectorF VECCALL sqrLengthVec4D() const;
		DoubleVectorF VECCALL normalizedFast4D() const;
	private:
		M256 m_data{};
	};

	// Scalar operations
	VectorF VECCALL operator*(float scale, VectorF vector);
	DoubleVectorF VECCALL operator*(float scale, DoubleVectorF vector);
	VectorF VECCALL operator/(float scale, VectorF vector);
	DoubleVectorF VECCALL operator/(float scale, DoubleVectorF vector);


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
	

	// VectorF 2D
	VectorF VECCALL vecFCross2D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFProject2D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFReflect2D(VectorF vec, VectorF normal);
	VectorF VECCALL vecFRefract2D(VectorF vec, VectorF normal, float refractionIndex);
	VectorF VECCALL vecFIntersectLines2D(VectorF l1p1, VectorF l1p2, VectorF l2p1, VectorF l2p2);

	VectorF VECCALL vecFDistanceVec2D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFRefractVec2D(VectorF vec, VectorF normal, VectorF refractionIndex);
	VectorF VECCALL vecFDotVec2D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFLinePointDistanceVec2D(VectorF linePoint1, VectorF linePoint2, VectorF point);
	VectorF VECCALL vecFAngleBetweenVec2D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFAngleBetweenNormalsVec2D(VectorF vec1, VectorF vec2);

	float VECCALL vecFDistance2D(VectorF vec1, VectorF vec2);
	float VECCALL vecFDot2D(VectorF vec1, VectorF vec2);
	float VECCALL vecFAngleBetween2D(VectorF vec1, VectorF vec2);
	float VECCALL vecFAngleBetweenNormals2D(VectorF vec1, VectorF vec2);
	float VECCALL vecFLinePointDistance2D(VectorF linePoint1, VectorF linePoint2, VectorF point);
	bool VECCALL vecFCmp2D(VectorF vec1, VectorF vec2, int type);
	bool VECCALL vecFInBound2D(VectorF vec, VectorF left, VectorF right);

	// VectorF 3D
	VectorF VECCALL vecFCross3D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFProject3D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFReflect3D(VectorF vec, VectorF normal);
	VectorF VECCALL vecFRefract3D(VectorF vec, VectorF normal, float refractionIndex);
	VectorF VECCALL vecFIntersectLines3D(VectorF l1p1, VectorF l1p2, VectorF l2p1, VectorF l2p2);

	VectorF VECCALL vecFDistanceVec3D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFRefractVec3D(VectorF vec, VectorF normal, VectorF refractionIndex);
	VectorF VECCALL vecFDotVec3D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFLinePointDistanceVec3D(VectorF linePoint1, VectorF linePoint2, VectorF point);
	VectorF VECCALL vecFAngleBetweenVec3D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFAngleBetweenNormalsVec3D(VectorF vec1, VectorF vec2);

	float VECCALL vecFDistance3D(VectorF vec1, VectorF vec2);
	float VECCALL vecFDot3D(VectorF vec1, VectorF vec2);
	float VECCALL vecFAngleBetween3D(VectorF vec1, VectorF vec2);
	float VECCALL vecFAngleBetweenNormals3D(VectorF vec1, VectorF vec2);
	float VECCALL vecFLinePointDistance3D(VectorF linePoint1, VectorF linePoint2, VectorF point);
	bool VECCALL vecFCmp3D(VectorF vec1, VectorF vec2, int type);
	bool VECCALL vecFInBound3D(VectorF vec, VectorF left, VectorF right);

	// VectorF 4D
	VectorF VECCALL vecFProject4D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFReflect4D(VectorF vec, VectorF normal);
	VectorF VECCALL vecFRefract4D(VectorF vec, VectorF normal, float refractionIndex);

	VectorF VECCALL vecFDistanceVec4D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFRefractVec4D(VectorF vec, VectorF normal, VectorF refractionIndex);
	VectorF VECCALL vecFDotVec4D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFAngleBetweenVec4D(VectorF vec1, VectorF vec2);
	VectorF VECCALL vecFAngleBetweenNormalsVec4D(VectorF vec1, VectorF vec2);

	float VECCALL vecFDistance4D(VectorF vec1, VectorF vec2);
	float VECCALL vecFDot4D(VectorF vec1, VectorF vec2);
	float VECCALL vecFAngleBetween4D(VectorF vec1, VectorF vec2);
	float VECCALL vecFAngleBetweenNormals4D(VectorF vec1, VectorF vec2);
	bool VECCALL vecFCmp4D(VectorF vec1, VectorF vec2, int type);
	bool VECCALL vecFInBound4D(VectorF vec, VectorF left, VectorF right);
	
	// DoubleVectorF common
	DoubleVectorF VECCALL doubleVecFMax(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFMin(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFPow(DoubleVectorF vec, DoubleVectorF pow);
	DoubleVectorF VECCALL doubleVecFPow(DoubleVectorF vec, float pow);
	DoubleVectorF VECCALL doubleVecFLerp(DoubleVectorF vec1, DoubleVectorF vec2, float value);

	// DoubleVectorF 2D
	DoubleVectorF VECCALL doubleVecFCross2D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFProject2D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFReflect2D(DoubleVectorF vec, DoubleVectorF normal);
	DoubleVectorF VECCALL doubleVecFRefract2D(DoubleVectorF vec, DoubleVectorF normal, float refractionIndex);
	DoubleVectorF VECCALL doubleVecFIntersectLines2D(DoubleVectorF l1p1, DoubleVectorF l1p2, DoubleVectorF l2p1, DoubleVectorF l2p2);

	DoubleVectorF VECCALL doubleVecFDistanceVec2D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFRefractVec2D(DoubleVectorF vec, DoubleVectorF normal, DoubleVectorF refractionIndex);
	DoubleVectorF VECCALL doubleVecFDotVec2D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFLinePointDistanceVec2D(DoubleVectorF linePoint1, DoubleVectorF linePoint2, DoubleVectorF point);
	DoubleVectorF VECCALL doubleVecFAngleBetweenVec2D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFAngleBetweenNormalsVec2D(DoubleVectorF vec1, DoubleVectorF vec2);

	void VECCALL doubleVecFDistance2D(DoubleVectorF vec1, DoubleVectorF vec2, float& dist1, float& dist2);
	void VECCALL doubleVecFDot2D(DoubleVectorF vec1, DoubleVectorF vec2, float& dot1, float& dot2);
	void VECCALL doubleVecFAngleBetween2D(DoubleVectorF vec1, DoubleVectorF vec2, float& angle1, float& angle2);
	void VECCALL doubleVecFAngleBetweenNormals2D(DoubleVectorF vec1, DoubleVectorF vec2, float& angle1, float& angle2);
	void VECCALL doubleVecFLinePointDistance2D(DoubleVectorF linePoint1, DoubleVectorF linePoint2, DoubleVectorF point, float& dist1, float& dist2);
	void VECCALL doubleVecFCmp2D(DoubleVectorF vec1, DoubleVectorF vec2, int type, bool& result1, bool& result2);
	void VECCALL doubleVecFInBound2D(DoubleVectorF vec, DoubleVectorF left, DoubleVectorF right, bool& result1, bool& result2);

	// DoubleVectorF 3D
	DoubleVectorF VECCALL doubleVecFCross3D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFProject3D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFReflect3D(DoubleVectorF vec, DoubleVectorF normal);
	DoubleVectorF VECCALL doubleVecFRefract3D(DoubleVectorF vec, DoubleVectorF normal, float refractionIndex);
	DoubleVectorF VECCALL doubleVecFIntersectLines3D(DoubleVectorF l1p1, DoubleVectorF l1p2, DoubleVectorF l2p1, DoubleVectorF l2p2);

	DoubleVectorF VECCALL doubleVecFDistanceVec3D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFRefractVec3D(DoubleVectorF vec, DoubleVectorF normal, DoubleVectorF refractionIndex);
	DoubleVectorF VECCALL doubleVecFDotVec3D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFLinePointDistanceVec3D(DoubleVectorF linePoint1, DoubleVectorF linePoint2, DoubleVectorF point);
	DoubleVectorF VECCALL doubleVecFAngleBetweenVec3D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFAngleBetweenNormalsVec3D(DoubleVectorF vec1, DoubleVectorF vec2);

	void VECCALL doubleVecFDistance3D(DoubleVectorF vec1, DoubleVectorF vec2, float& dist1, float& dist2);
	void VECCALL doubleVecFDot3D(DoubleVectorF vec1, DoubleVectorF vec2, float& dot1, float& dot2);
	void VECCALL doubleVecFAngleBetween3D(DoubleVectorF vec1, DoubleVectorF vec2, float& angle1, float& angle2);
	void VECCALL doubleVecFAngleBetweenNormals3D(DoubleVectorF vec1, DoubleVectorF vec2, float& angle1, float& angle2);
	void VECCALL doubleVecFLinePointDistance3D(DoubleVectorF linePoint1, DoubleVectorF linePoint2, DoubleVectorF point, float& dist1, float& dist2);
	void VECCALL doubleVecFCmp3D(DoubleVectorF vec1, DoubleVectorF vec2, int type, bool& result1, bool& result2);
	void VECCALL doubleVecFInBound3D(DoubleVectorF vec, DoubleVectorF left, DoubleVectorF right, bool& result1, bool& result2);

	// DoubleVectorF 4D
	DoubleVectorF VECCALL doubleVecFCross4D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFProject4D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFReflect4D(DoubleVectorF vec, DoubleVectorF normal);
	DoubleVectorF VECCALL doubleVecFRefract4D(DoubleVectorF vec, DoubleVectorF normal, float refractionIndex);

	DoubleVectorF VECCALL doubleVecFDistanceVec4D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFRefractVec4D(DoubleVectorF vec, DoubleVectorF normal, DoubleVectorF refractionIndex);
	DoubleVectorF VECCALL doubleVecFDotVec4D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFAngleBetweenVec4D(DoubleVectorF vec1, DoubleVectorF vec2);
	DoubleVectorF VECCALL doubleVecFAngleBetweenNormalsVec4D(DoubleVectorF vec1, DoubleVectorF vec2);

	void VECCALL doubleVecFDistance4D(DoubleVectorF vec1, DoubleVectorF vec2, float& dist1, float& dist2);
	void VECCALL doubleVecFDot4D(DoubleVectorF vec1, DoubleVectorF vec2, float& dot1, float& dot2);
	void VECCALL doubleVecFAngleBetween4D(DoubleVectorF vec1, DoubleVectorF vec2, float& angle1, float& angle2);
	void VECCALL doubleVecFAngleBetweenNormals4D(DoubleVectorF vec1, DoubleVectorF vec2, float& angle1, float& angle2);
	void VECCALL doubleVecFCmp4D(DoubleVectorF vec1, DoubleVectorF vec2, int type, bool& result1, bool& result2);
	void VECCALL doubleVecFInBound4D(DoubleVectorF vec, DoubleVectorF left, DoubleVectorF right, bool& result1, bool& result2);


	/// Matrix math

	// base matrix
	struct MatrixScalar
	{
		float m11, m12, m13, m14;
		float m21, m22, m23, m24;
		float m31, m32, m33, m34;
		float m41, m42, m43, m44;

		// Constructors
		MatrixScalar() : m11(0), m12(0), m13(0), m14(0),
			m21(0), m22(0), m23(0), m24(0),
			m31(0), m32(0), m33(0), m34(0),
			m41(0), m42(0), m43(0), m44(0) {}
		MatrixScalar(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44) : 
			m11(m11), m12(m12), m13(m13), m14(m14),
			m21(m21), m22(m22), m23(m23), m24(m24),
			m31(m31), m32(m32), m33(m33), m34(m34),
			m41(m41), m42(m42), m43(m43), m44(m44) {}
		MatrixScalar(const MatrixScalar& matrix) = default;
		MatrixScalar& operator=(const MatrixScalar& matrix) = default;

		// Conversions
		explicit MatrixScalar(const float* pArray) : 
			m11(pArray[0]), m12(pArray[1]), m13(pArray[2]), m14(pArray[3]),
			m21(pArray[4]), m22(pArray[5]), m23(pArray[6]), m24(pArray[7]),
			m31(pArray[8]), m32(pArray[9]), m33(pArray[10]), m34(pArray[11]),
			m41(pArray[12]), m42(pArray[13]), m43(pArray[14]), m44(pArray[15]) {}
		operator float* ();
		operator float const* () const;
#ifdef DIRECTX
		MatrixScalar(DirectX::XMMATRIX matrix)
		{
			DirectX::XMStoreFloat4x4(XMFloat4x4Ptr(), matrix);
		}
		DirectX::XMFLOAT4X4* XMFloat4x4Ptr()
		{
			return reinterpret_cast<DirectX::XMFLOAT4X4*>(this);
		}
		DirectX::XMMATRIX XMMatrix()
		{
			return DirectX::XMLoadFloat4x4(XMFloat4x4Ptr());
		}
#endif

		// base operations
		MatrixScalar operator+(const MatrixScalar& matrix) const;
		MatrixScalar operator-(const MatrixScalar& matrix) const;
		MatrixScalar operator*(const MatrixScalar& matrix) const;
		MatrixScalar operator*(float scale) const;
		MatrixScalar operator/(float scale) const;
		MatrixScalar& operator+=(const MatrixScalar& matrix);
		MatrixScalar& operator-=(const MatrixScalar& matrix);
		MatrixScalar& operator*=(const MatrixScalar& matrix);
		MatrixScalar& operator*=(float scale);
		MatrixScalar& operator/=(float scale);
		MatrixScalar operator-() const;

		// compare
		bool operator==(const MatrixScalar& matrix) const;
		bool operator<(const MatrixScalar& matrix) const;
		bool operator>(const MatrixScalar& matrix) const;
		bool operator<=(const MatrixScalar& matrix) const;
		bool operator>=(const MatrixScalar& matrix) const;
		bool isEqualPrec(const MatrixScalar& matrix, float precision = 0) const;
		bool isEqualPrec(const MatrixScalar& matrix, const MatrixScalar& precision) const;

		// methods
		MatrixScalar transpose() const;
		MatrixScalar inverse() const;
		float determinant() const;
	};

	// additional operations
	MatrixScalar operator*(float scale, const MatrixScalar& matrix);
	MatrixScalar operator/(float scale, const MatrixScalar& matrix);

	// matrix functions
	float matrixScalar3Determinant(float m11, float m12, float m13,
		float m21, float m22, float m23,
		float m31, float m32, float m33);
	MatrixScalar matrixScalarIdentity();
	MatrixScalar matrixScalarInfinity();

	// Transforms
	MatrixScalar matrixScalarScaling(float x, float y, float z);
	MatrixScalar matrixScalarScaling(Vector3 scale);

	MatrixScalar matrixScalarRotationX(float angle);
	MatrixScalar matrixScalarRotationY(float angle);
	MatrixScalar matrixScalarRotationZ(float angle);
	MatrixScalar matrixScalarRotationAxis(Vector3 axis, float angle);
	MatrixScalar matrixScalarRotationNormal(Vector3 normal, float angle);
	MatrixScalar matrixScalarRotationYawPitchRoll(float yaw, float pitch, float roll);
	MatrixScalar matrixScalarRotationYawPitchRoll(Vector3 yawPitchRoll);
	//MatrixScalar matrixScalarRotationQuaternion(Vector4 quaternion);

	MatrixScalar matrixScalarTranslation(float x, float y, float z);
	MatrixScalar matrixScalarTranslation(Vector3 vector);

	//MatrixScalar matrixScalarTransformation(Vector3 scale,
	//	Vector3 rotationOrigin, Vector4 rotationQuaternion, Vector3 translation);

	Vector3 matrixScalarTransformCoord3D(Vector3 vector, MatrixScalar matrix);
	Vector3 matrixScalarTransformNormal3D(Vector3 vector, MatrixScalar matrix);
	Vector4 matrixScalarTransform(Vector4 vector, MatrixScalar matrix);

	// special matricies LH
	MatrixScalar matrixScalarOrthoLH();
	MatrixScalar matrixScalarPerspectiveLH();
	MatrixScalar matrixScalarPerspectiveFovLH();
	MatrixScalar matrixScalarLookAtLH();

	// special matricies RH
	MatrixScalar matrixScalarOrthoRH();
	MatrixScalar matrixScalarPerspectiveRH();
	MatrixScalar matrixScalarPerspectiveFovRH();
	MatrixScalar matrixScalarLookAtRH();

	// vector simd matrix
	class ALIGN(32)  MatrixF
	{

	public: 
		// Constructors
		MatrixF();
		MatrixF(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);
		MatrixF(const MatrixF& matrix) = default;
		MatrixF& operator=(const MatrixF& matrix) = default;

		// Conversions
		explicit MatrixF(const float* pArray);
		explicit MatrixF(const MatrixScalar & matrix);
		explicit MatrixF(VectorF row1, VectorF row2, VectorF row3, VectorF row4);
#ifdef DIRECTX
		MatrixF(DirectX::XMMATRIX matrix);
		DirectX::XMMATRIX VECCALL XMMatrix();
#endif
		
		// getters and setters
		float VECCALL get(char  ind) const;
		void VECCALL set(char ind, float value);
		int VECCALL getInt(char ind) const;
		void VECCALL setInt(char ind, int value);

		// base operations
		MatrixF VECCALL operator+(MatrixF matrix) const;
		MatrixF VECCALL operator-(MatrixF matrix) const;
		MatrixF VECCALL operator*(MatrixF matrix) const;
		MatrixF VECCALL operator*(float scale) const;
		MatrixF VECCALL operator/(float scale) const;
		MatrixF& VECCALL operator+=(MatrixF matrix);
		MatrixF& VECCALL operator-=(MatrixF matrix);
		MatrixF& VECCALL operator*=(MatrixF matrix);
		MatrixF& VECCALL operator*=(float scale);
		MatrixF& VECCALL operator/=(float scale);
		MatrixF VECCALL operator-() const;

		// additional operations
		friend MatrixF VECCALL operator*(float scale, MatrixF matrix);
		friend MatrixF VECCALL operator/(float scale, MatrixF matrix);

		// compare
		bool VECCALL operator==(MatrixF matrix) const;
		bool VECCALL operator<(MatrixF matrix) const;
		bool VECCALL operator>(MatrixF matrix) const;
		bool VECCALL operator<=(MatrixF matrix) const;
		bool VECCALL operator>=(MatrixF matrix) const;
		bool VECCALL isEqualPrec(MatrixF matrix, float precision = 0) const;
		bool VECCALL isEqualPrec(MatrixF matrix, MatrixF precision) const;

		// store/load
		void VECCALL load(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);
		void VECCALL load(const float* pArray);
		void VECCALL load(const MatrixScalar& matrix);
		void VECCALL load(VectorF row1, VectorF row2, VectorF row3, VectorF row4);

		void VECCALL store(float& m11, float& m12, float& m13, float& m14,
			float& m21, float& m22, float& m23, float& m24,
			float& m31, float& m32, float& m33, float& m34,
			float& m41, float& m42, float& m43, float& m44) const;
		void VECCALL store(float* pArray) const;
		void VECCALL store(MatrixScalar& matrix) const;
		void VECCALL store(VectorF& row1, VectorF& row2, VectorF& row3, VectorF& row4) const;

		// methods
		MatrixF VECCALL transpose() const;
		MatrixF VECCALL inverse() const;
		MatrixF VECCALL inverseTransform() const;
		MatrixF VECCALL inverseTransformNoScale() const;
		VectorF VECCALL determinantVec() const;
		float VECCALL determinant() const;

	private:
		M128 m_rows[4];
	};

	// additional operations
	MatrixF VECCALL operator*(float scale, MatrixF matrix);
	MatrixF VECCALL operator/(float scale, MatrixF matrix);

	// matrix functions
	VectorF VECCALL matrixF3DeterminantVec(VectorF vec1, VectorF vec2, VectorF vec3);
	float VECCALL matrixF3Determinant(VectorF vec1, VectorF vec2, VectorF vec3);
	MatrixF VECCALL matrixFIdentity();
	MatrixF VECCALL matrixFInfinity();

	// Transforms
	MatrixF matrixFScaling(float x, float y, float z);
	MatrixF matrixFScaling(VectorF scale);

	MatrixF matrixFRotationX(float angle);
	MatrixF matrixFRotationY(float angle);
	MatrixF matrixFRotationZ(float angle);
	MatrixF matrixFRotationAxis(VectorF axis, float angle);
	MatrixF matrixFRotationNormal(VectorF normal, float angle);
	MatrixF matrixFRotationYawPitchRoll(float yaw, float pitch, float roll);
	MatrixF matrixFRotationYawPitchRoll(VectorF yawPitchRoll);
	//MatrixF matrixFRotationQuaternion(VectorF quaternion);

	MatrixF matrixFTranslation(float x, float y, float z);
	MatrixF matrixFTranslation(VectorF vector);

	//matrixF matrixFTransformation(VectorF scale,
	//	VectorF rotationOrigin, VectorF rotationQuaternion, VectorF translation);

	Vector3 matrixFTransformCoord3D(VectorF vector, MatrixF matrix);
	Vector3 matrixFTransformNormal3D(VectorF vector, MatrixF matrix);
	Vector4 matrixFTransform(VectorF vector, MatrixF matrix);

	// special matricies LH
	MatrixF matrixFOrthoLH();
	MatrixF matrixFPerspectiveLH();
	MatrixF matrixFPerspectiveFovLH();
	MatrixF matrixFLookAtLH();

	// special matricies RH
	MatrixF matrixFOrthoRH();
	MatrixF matrixFPerspectiveRH();
	MatrixF matrixFPerspectiveFovRH();
	MatrixF matrixFLookAtRH();
	
}
