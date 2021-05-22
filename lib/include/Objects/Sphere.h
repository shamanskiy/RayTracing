#include "Objects/HitableObject.h"

class Sphere : public HitableObject {
	Vec3 m_center;
	float m_radius;

public:
	Sphere(Vec3 center, float radius) : m_center(center), m_radius(radius) {};

	HitRecord testRay(const Ray& ray, const Interval& intervalOfInterest = Interval()) const override;

private:
	std::tuple<int, float, float> solveHitEquation(const Ray& ray) const;
	HitRecord makeHitRecord(float t, const Ray& ray) const;
};

