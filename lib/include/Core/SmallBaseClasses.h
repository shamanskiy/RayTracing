#pragma once

#include <ostream>
#include <limits>
#include <math.h>

class Vec3 {
private:
	float m_elem[3];

public:
	Vec3() {
		m_elem[0] = 0.0f; m_elem[1] = 0.0f; m_elem[2] = 0.0f;
	}
	Vec3(float x, float y, float z) {
		m_elem[0] = x; m_elem[1] = y; m_elem[2] = z;
	}

	float x() const { return m_elem[0]; }
	float y() const { return m_elem[1]; }
	float z() const { return m_elem[2]; }
	float r() const { return m_elem[0]; }
	float g() const { return m_elem[1]; }
	float b() const { return m_elem[2]; }

	Vec3 operator-() const { return Vec3(-m_elem[0],-m_elem[1],-m_elem[2]); }
	float operator[](int i) const { return m_elem[i]; }
	float& operator[](int i) { return m_elem[i]; }

	Vec3& operator+=(const Vec3& rhs)
	{
		m_elem[0] += rhs.m_elem[0];
		m_elem[1] += rhs.m_elem[1];
		m_elem[2] += rhs.m_elem[2];
		return *this;
	}

	Vec3& operator-=(const Vec3& rhs)
	{
		m_elem[0] -= rhs.m_elem[0];
		m_elem[1] -= rhs.m_elem[1];
		m_elem[2] -= rhs.m_elem[2];
		return *this;
	}

	Vec3& operator*=(const Vec3& rhs)
	{
		m_elem[0] *= rhs.m_elem[0];
		m_elem[1] *= rhs.m_elem[1];
		m_elem[2] *= rhs.m_elem[2];
		return *this;
	}

	Vec3& operator/=(const Vec3& rhs)
	{
		m_elem[0] /= rhs.m_elem[0];
		m_elem[1] /= rhs.m_elem[1];
		m_elem[2] /= rhs.m_elem[2];
		return *this;
	}

	Vec3& operator*=(float rhs)
	{
		m_elem[0] *= rhs;
		m_elem[1] *= rhs;
		m_elem[2] *= rhs;
		return *this;
	}

	Vec3& operator/=(float rhs)
	{
		m_elem[0] /= rhs;
		m_elem[1] /= rhs;
		m_elem[2] /= rhs;
		return *this;
	}

	float length_sq() const {
		return m_elem[0] * m_elem[0] + m_elem[1] * m_elem[1] + m_elem[2] * m_elem[2];
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
		return Vec3(m_elem[0] * l, m_elem[1] * l, m_elem[2] * l);
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

inline float dot(const Vec3& lhs, const Vec3& rhs)
{
	return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
}

inline Vec3 cross(const Vec3& lhs, const Vec3& rhs) 
{
	return Vec3(lhs.y() * rhs.z() - lhs.z() * rhs.y(),
		-lhs.x() * rhs.z() + lhs.z() * rhs.x(),
		lhs.x() * rhs.y() - lhs.y() * rhs.x());
}

inline Vec3 lerp(const Vec3& vecA, const Vec3& vecB, float t)
{
	return (1 - t) * vecA + t * vecB;
}

class Ray {
private:
	Vec3 m_origin;
	Vec3 m_direction;

public:
	Ray() : m_origin(), m_direction(Vec3(1.0, 0.0, 0.0)) {}
	Ray(Vec3 origin, Vec3 direction) : m_origin(origin), m_direction(direction) {}

	const Vec3 & origin() const { return m_origin; }
	const Vec3 & direction() const { return m_direction; }

	Vec3 eval(float t) const { return m_origin + t * m_direction; }
};

class Interval {
	float m_min;
	float m_max;

public:
	static float limit_max() { return std::numeric_limits<float>::max(); }

	Interval() : m_min(0.0), m_max(limit_max()) {}
	Interval(float min, float max) : m_min(min), m_max(max) {}

	float min() const { return m_min; }
	float max() const { return m_max; }
	bool includes(float t) const { return t >= m_min && t <= m_max; }
};

struct HitRecord {
	float t;
	Vec3 point;
	Vec3 normal;

	HitRecord(float t, Vec3 point, Vec3 normal) : t(t), point(point), normal(normal) {}

	static HitRecord miss() {
		return HitRecord{ -1.0, Vec3(), Vec3() };
	}

	static HitRecord farAway() {
		return HitRecord{ Interval::limit_max() , Vec3(), Vec3() };
	}
};

namespace Color
{
	const Vec3 white(1.0, 1.0, 1.0);
	const Vec3 red(1.0, 0.0, 0.0);
	const Vec3 green(0.0, 1.0, 0.0);
	const Vec3 blue(0.0, 0.0, 1.0);
	const Vec3 black(0.0, 0.0, 0.0);
	const Vec3 lightblue(0.5, 0.7, 1.0);
}

namespace Space3D
{
	const Vec3 origin(0.0, 0.0, 0.0);
	const Vec3 xAxis(1.0, 0.0, 0.0);
	const Vec3 yAxis(0.0, 1.0, 0.0);
	const Vec3 zAxis(0.0, 0.0, 1.0);
}