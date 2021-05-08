#pragma once

#include "Vec3.h"

class Ray {
private:
	Vec3 m_origin;
	Vec3 m_direction;

public:
	Ray() : m_origin(), m_direction(Vec3(1.0, 0.0, 0.0)) {}
	Ray(Vec3 origin, Vec3 direction) : m_origin(origin), m_direction(direction) {}

	Vec3 origin() const { return m_origin; }
	Vec3 direction() const { return m_direction; }

	Vec3 eval(float t) const { return m_origin + t * m_direction; }
};

