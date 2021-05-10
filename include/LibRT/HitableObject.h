#pragma once

#include <vector>

#include "Vec3.h"
#include "Ray.h"


struct HitRecord {
	float t;
	Vec3 point;
	Vec3 normal;

	HitRecord(float t, Vec3 point, Vec3 normal) : t(t), point(point), normal(normal) {}
	HitRecord() : t(-1.0), point(Vec3()), normal(Vec3()) {}
};

class HitableObject {
public:
	virtual HitRecord testRay(const Ray& ray, const Interval& intervalOfInterest = Interval()) const = 0;
};

class Sphere : public HitableObject {
	Vec3 m_center;
	float m_radius;

public:
	Sphere(Vec3 center, float radius) : m_center(center), m_radius(radius) {};

	HitRecord testRay(const Ray& ray, const Interval& intervalOfInterest = Interval()) const override;

private:
	std::tuple<int,float,float> solveHitEquation(const Ray& ray) const;
	HitRecord makeHitRecord(float t, const Ray& ray) const;
};

class Scene : public HitableObject {
	std::vector<std::unique_ptr<HitableObject>> m_objects;

public:
	HitRecord testRay(const Ray& ray, const Interval& intervalOfInterest = Interval()) const override;
	void addObject(std::unique_ptr<HitableObject> && object) { m_objects.push_back(std::move(object)); }
};