#include "Materials/Metal.h"

#include "Core/Random.h"

std::optional<Reflection> Metal::reflectRay(const Ray& ray, const HitRecord& hit) const
{
	Ray reflectedRay(hit.point, reflect(ray.direction(),hit.normal) + Random::get()->vecUnitSphere()*m_fuzziness);
	return Reflection{ reflectedRay, m_color };
}