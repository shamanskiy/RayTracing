#include "Materials/Diffusive.h"

#include "Core/Random.h"

std::optional<Reflection> Diffusive::reflectRay(const Ray& ray, const HitRecord& hit) const
{
	Ray reflectedRay(hit.point, hit.normal + Random::get()->vecUnitSphere());
	return Reflection{ reflectedRay, m_color };
}