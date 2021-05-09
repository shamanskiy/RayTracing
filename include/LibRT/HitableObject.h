#pragma once

#include <limits>

#include "Vec3.h"
#include "Ray.h"


struct HitRecord {
	float t;
	Vec3 point;
	Vec3 normal;
};

class HitableObject {
	virtual HitRecord testHit(const Ray& ray, const Interval& intervalOfInterest = Interval()) const = 0;
};

class Sphere : public HitableObject {
	Vec3 m_center;
	float m_radius;

public:
	Sphere(Vec3 center, float radius) : m_center(center), m_radius(radius) {};

	HitRecord testHit(const Ray& ray, const Interval& intervalOfInterest = Interval()) const override;
};

