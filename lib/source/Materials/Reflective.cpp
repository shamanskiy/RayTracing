#include "Materials/Reflective.h"

#include "Core/Random.h"

std::optional<Reflection> Reflective::reflectRay(const Ray& ray, const HitRecord& hit) const
{
	Ray reflectedRay(hit.point, reflect(ray.direction(),hit.normal) + Random::get()->vecUnitSphere()*m_fuzziness);
	return Reflection{ reflectedRay, m_color };
}