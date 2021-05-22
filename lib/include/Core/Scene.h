#pragma once

#include "Core/SmallBaseClasses.h"
#include "Objects/HitableCollection.h"

class Scene
{
	HitableCollection m_objects;
	Vec3 m_skyColorLow;
	Vec3 m_skyColorHigh;

public:
	Scene() : m_skyColorLow(Color::white), m_skyColorHigh(Color::lightblue) {}

	void setSkyGradient(const Vec3& bottomColor, const Vec3& topColor)
	{
		m_skyColorLow = bottomColor;
		m_skyColorHigh = topColor;
	}

	void addObject(std::unique_ptr<HitableObject>&& object) { m_objects.addObject(std::move(object)); }
	Vec3 testRay(const Ray& ray) const;

private:
	Vec3 hitSky(const Ray& ray) const;
};