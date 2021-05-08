#pragma once

#include <ostream>

class Vec3 {
private:
	float elem[3];

public:
	Vec3() {
		elem[0] = 0.0f; elem[1] = 0.0f; elem[2] = 0.0f;
	}
	Vec3(float x, float y, float z) {
		elem[0] = x; elem[1] = y; elem[2] = z;
	}

	float x() const { return elem[0]; }
	float y() const { return elem[1]; }
	float z() const { return elem[2]; }
	float r() const { return elem[0]; }
	float g() const { return elem[1]; }
	float b() const { return elem[2]; }

	Vec3 operator-() const { return Vec3(-elem[0],-elem[1],-elem[2]); }
	float operator[](int i) const { return elem[i]; }
	float& operator[](int i) { return elem[i]; }

	Vec3& operator+=(const Vec3& rhs)
	{
		elem[0] += rhs.elem[0];
		elem[1] += rhs.elem[1];
		elem[2] += rhs.elem[2];
		return *this;
	}

	Vec3& operator-=(const Vec3& rhs)
	{
		elem[0] -= rhs.elem[0];
		elem[1] -= rhs.elem[1];
		elem[2] -= rhs.elem[2];
		return *this;
	}

	Vec3& operator*=(const Vec3& rhs)
	{
		elem[0] *= rhs.elem[0];
		elem[1] *= rhs.elem[1];
		elem[2] *= rhs.elem[2];
		return *this;
	}

	Vec3& operator/=(const Vec3& rhs)
	{
		elem[0] /= rhs.elem[0];
		elem[1] /= rhs.elem[1];
		elem[2] /= rhs.elem[2];
		return *this;
	}

	Vec3& operator*=(float rhs)
	{
		elem[0] *= rhs;
		elem[1] *= rhs;
		elem[2] *= rhs;
		return *this;
	}

	Vec3& operator/=(float rhs)
	{
		elem[0] /= rhs;
		elem[1] /= rhs;
		elem[2] /= rhs;
		return *this;
	}

	float length_sq() const {
		return elem[0] * elem[0] + elem[1] * elem[1] + elem[2] * elem[2];
	}

	float length() const {
		return sqrt(length_sq());
	}

	void normalize_inplace() {
		float l = 1. / length();
		operator*=(l);
	}

	Vec3 normalize() const {
		float l = 1. / length();
		return Vec3(elem[0] * l, elem[1] * l, elem[2] * l);
	}

};

inline std::ostream& operator<<(std::ostream& os, const Vec3& vec)
{
	os << vec[0] << " " << vec[1] << " " << vec[2];
	return os;
}

inline Vec3 operator+(const Vec3& lhs, const Vec3& rhs)
{
	return Vec3(lhs[0] + rhs[0], lhs[1] + rhs[1], lhs[2] + rhs[2]);
}

inline Vec3 operator-(const Vec3& lhs, const Vec3& rhs)
{
	return Vec3(lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2]);
}

inline Vec3 operator*(const Vec3& lhs, const Vec3& rhs)
{
	return Vec3(lhs[0] * rhs[0], lhs[1] * rhs[1], lhs[2] * rhs[2]);
}

inline Vec3 operator/(const Vec3& lhs, const Vec3& rhs)
{
	return Vec3(lhs[0] / rhs[0], lhs[1] / rhs[1], lhs[2] / rhs[2]);
}

inline Vec3 operator*(float lhs, const Vec3& rhs)
{
	return Vec3(lhs * rhs[0], lhs * rhs[1], lhs * rhs[2]);
}

inline Vec3 operator*(const Vec3& lhs, float rhs)
{
	return Vec3(lhs[0] * rhs, lhs[1] * rhs, lhs[2] * rhs);
}

inline Vec3 operator/(const Vec3& lhs, float rhs)
{
	return Vec3(lhs[0] / rhs, lhs[1] / rhs, lhs[2] / rhs);
}

inline float dot(const Vec3& lhs, const Vec3& rhs) {
	return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
}

inline Vec3 cross(const Vec3& lhs, const Vec3& rhs) {
	return Vec3(lhs.y() * rhs.z() - lhs.z() * rhs.y(),
		-lhs.x() * rhs.z() + lhs.z() * rhs.x(),
		lhs.x() * rhs.y() - lhs.y() * rhs.x());
}