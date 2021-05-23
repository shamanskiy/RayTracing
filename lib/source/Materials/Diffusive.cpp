#include "Materials/Diffusive.h"

#include "Core/Random.h"

Reflection Diffusive::reflectRay(const Ray& ray, const HitRecord& hit) const
{
	Ray reflectedRay(hit.point, hit.normal + Random::get()->vecUnitSphere());
	return Reflection{ true, reflectedRay, m_color };
}