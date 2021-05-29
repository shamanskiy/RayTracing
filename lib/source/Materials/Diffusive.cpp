#include "Materials/Diffusive.h"

#include "Core/Random.h"

std::optional<MaterialEffect> Diffusive::processRay(const Ray& ray, const HitRecord& hit) const
{
	Vec3 scatteredDirection = hit.normal + Random::get()->vecUnitSphere();
	Ray scatteredRay(hit.point, scatteredDirection);
	return MaterialEffect{ scatteredRay, m_color };
}