#include "Materials/Transparent.h"

#include "Core/Random.h"

std::optional<MaterialEffect> Transparent::processRay(const Ray& ray, const HitRecord& hit) const
{
	Vec3 refractedDirection = ray.direction();

	Ray refractedRay(hit.point, refractedDirection);
	return MaterialEffect{ refractedRay, m_color };
}