#include "Materials/Reflective.h"

#include "Core/Random.h"

std::optional<MaterialEffect> Reflective::processRay(const Ray& ray, const HitRecord& hit) const
{
	Vec3 reflectedDirection = reflect(ray.direction(), hit.normal) + 
		Random::get()->vecUnitSphere() * m_fuzziness;
	Ray reflectedRay(hit.point, reflectedDirection);
	return MaterialEffect{ reflectedRay, m_color };
}