#include "Materials/Transparent.h"

#include "Core/Random.h"

std::optional<Reflection> Transparent::reflectRay(const Ray& ray, const HitRecord& hit) const
{
	Vec3 directionIn = ray.direction().normalize();
	float cosIn = dot(directionIn, hit.normal);

	float sinOut2 = 1 - (1 - cosIn * cosIn) / m_refractiveIndex / m_refractiveIndex;
	if (sinOut2 > 0)
	{
		Vec3 refractedDirection =  (directionIn - hit.normal * cosIn) / m_refractiveIndex - hit.normal * sqrt(sinOut2);

		Ray refractedRay(hit.point, refractedDirection);
		return Reflection{ refractedRay, m_color };
	}

	return std::nullopt;
}
	