#include "Materials/Transparent.h"

#include "Core/Random.h"

namespace {
	std::optional<Vec3> refract(const Vec3& vec, const Vec3& normal, float refraction)
	{
		float cosIn = dot(vec, normal);
		float sinOut2 = 1 - (1 - cosIn * cosIn) * refraction * refraction;
		if (sinOut2 > 0)
			return (vec - normal * cosIn) * refraction - normal * sqrt(sinOut2);
		else
			return std::nullopt;
	}

	// Reflection probability approximation by Christophe Schlick
	// Peter Shirley: Ray Tracing in a Weekend, page 32
	float schlickLaw(float schlickCos, float refraction)
	{
		float probZero = (1 - refraction) * (1 + refraction);
		probZero *= probZero;
		return probZero + (1 - probZero) * pow(1 - schlickCos, 5);
	}
}


std::optional<Reflection> Transparent::reflectRay(const Ray& ray, const HitRecord& hit) const
{
	Vec3 directionIn = ray.direction().normalize();
	float cosIn = dot(directionIn, hit.normal);
	bool comesFromOutside = cosIn < 0;	
	
	auto refractedDirection = refract(directionIn, comesFromOutside ? hit.normal : -hit.normal,
		comesFromOutside ? 1.0f / m_refractiveIndex : m_refractiveIndex);
	float schlickCosine = cosIn * (comesFromOutside ? -1 : m_refractiveIndex);

	if (refractedDirection)
	{
		float reflectionProbability = schlickLaw(schlickCosine, m_refractiveIndex);
		if (Random::get()->real01() < reflectionProbability)
		{
			Ray refractedRay(hit.point, *refractedDirection);
			return Reflection{ refractedRay, m_color };
		}
	}
	
	Vec3 reflectedDirection = reflect(ray.direction(), hit.normal);
	Ray reflectedRay(hit.point, reflectedDirection);
	return Reflection{ reflectedRay, m_color };
}
	