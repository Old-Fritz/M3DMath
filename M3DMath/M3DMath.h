#pragma once
#include <emmintrin.h>

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
		Vector2() : x(0), y(0) {}
		Vector2(const Vector2& vector) = default;
		Vector2(const float x = 0, const float y = 0) : x(x), y(y) {}
		Vector2& operator=(const Vector2& vector) = default;

		// Conversions
		explicit Vector2(const float* pArray) : x(pArray[0]), y(pArray[1]) {}
		explicit Vector2(const Vector3& vector);
		explicit Vector2(const Vector4& vector);

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
		bool operator==(const Vector2& vector) const;
	};

	struct Vector3
	{
		float x, y, z;

		// Constructors
		Vector3() : x(0), y(0), z(0) {}
		Vector3(const Vector3& vector) = default;
		Vector3(const float x = 0, const float y = 0, const float z = 0) : x(x), y(y), z(z) {}
		Vector3& operator=(const Vector3& vector) = default;

		// Conversions
		explicit Vector3(const Vector2& vector) : x(vector.x), y(vector.y), z(0) {}
		explicit Vector3(const float* pArray) : x(pArray[0]), y(pArray[1]), z(pArray[2]) {}
		explicit Vector3(const Vector4& vector);


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
		bool operator==(const Vector3& vector) const;
	};

	struct Vector4
	{
		float x, y, z, w;

		// Constructors
		Vector4() : x(0), y(0), z(0), w(0) {}
		Vector4(const Vector4& vector) = default;
		Vector4(const float x = 0, const float y = 0, const float z = 0, const float w = 0) : x(x), y(y), z(z), w(w) {}
		Vector4& operator=(const Vector4& vector) = default;

		// Conversions
		explicit Vector4(const Vector2& vector) : x(vector.x), y(vector.y), z(0), w(0) {}
		explicit Vector4(const Vector3& vector) : x(vector.x), y(vector.y), z(vector.z), w(0) {}
		explicit Vector4(const float* pArray) : x(pArray[0]), y(pArray[1]), z(pArray[2]), w(pArray[3]) {}
		explicit Vector4(const Vector2& vector1, const Vector2& vector2) : x(vector1.x), y(vector1.y), z(vector2.x), w(vector2.y) {}

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
		bool operator==(const Vector4& vector) const;
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
	class VectorF
	{
	public:
		// Constructors
		VectorF() : m_data() {}
		VectorF(const VectorF& vector) = default;
		VectorF(__m128 data) : m_data(data) {}
		VectorF& operator=(const VectorF& vector) = default;
		
		// Conversions
		explicit VectorF(float x, float y, float z, float w);
		explicit VectorF(float* pArray);
		explicit VectorF(const Vector2& vector);
		explicit VectorF(const Vector3& vector);
		explicit VectorF(const Vector4& vector);
		explicit VectorF(const Vector2& vector1, const Vector2& vector2);
		explicit operator __m128() const;

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
		bool operator==(const VectorF& vector) const;

		// load/store
		void load(float x = 0, float y = 0, float z = 0, float w = 0);
		void load(float* pArray);
		void load(const Vector2& vector);
		void load(const Vector3& vector);
		void load(const Vector4& vector);
		void load(const Vector2& vector1, const Vector2& vector2);

		void store(float& x, float& y, float& z, float& w) const;
		void store(float* pArray) const;
		void store(const Vector2& vector) const;
		void store(const Vector3& vector) const;
		void store(const Vector4& vector) const;
		void store(const Vector2& vector1, const Vector2& vector2) const;
	private:
		__m128 m_data;
	};
}
