#include "Materials/Reflective.h"

#include "Core/Random.h"

std::optional<Reflection> Reflective::reflectRay(const Ray& ray, const HitRecord& hit) const
{
	Vec3 reflectedDirection = reflect(ray.direction(), hit.normal) + 
		Random::get()->vecUnitSphere() * m_fuzziness;
	Ray reflectedRay(hit.point, reflectedDirection);
	return Reflection{ reflectedRay, m_color };
}