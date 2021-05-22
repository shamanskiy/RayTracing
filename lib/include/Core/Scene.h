#pragma once

#include "Core/SmallBaseClasses.h"
#include "Objects/HitableCollection.h"

class Scene
{
	HitableCollection m_objects;
	Vec3 m_skyColorLow;
	Vec3 m_skyColorHigh;
public:
	Scene() : m_skyColorLow(1.0, 1.0, 1.0), m_skyColorHigh(0.5, 0.7, 1.0) {}

	void setSkyGradient(const Vec3& bottomColor, const Vec3& topColor)
	{
		m_skyColorLow = bottomColor;
		m_skyColorHigh = topColor;
	}

	void addObject(std::unique_ptr<HitableObject>&& object) { m_objects.addObject(std::move(object)); }

	Vec3 testRay(const Ray& ray) const;
	Vec3 hitSky(const Ray& ray) const;
};