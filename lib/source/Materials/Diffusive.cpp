#include "Materials/Diffusive.h"

#include "Core/Random.h"

std::optional<Reflection> Diffusive::reflectRay(const Ray& ray, const HitRecord& hit) const
{
	Vec3 scatteredDirection = hit.normal + Random::get()->vecUnitSphere();
	Ray scatteredRay(hit.point, scatteredDirection);
	return Reflection{ scatteredRay, m_color };
}