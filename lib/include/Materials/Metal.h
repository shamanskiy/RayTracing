#pragma once

#include "Material.h"

class Metal : public Material
{
	Vec3 m_color;
	float m_fuzziness;

public:
	Metal(const Vec3& color, float fuzziness = 0.0) : m_color(color), m_fuzziness(fuzziness) {}

	std::optional<Reflection> reflectRay(const Ray& ray, const HitRecord& hit) const override;
};