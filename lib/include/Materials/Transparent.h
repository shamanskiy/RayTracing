#pragma once

#include "Material.h"

class Transparent : public Material
{
	Vec3 m_color;
	float m_refractiveIndex;

public:
	Transparent(const Vec3& color, float refractiveIndex) : m_color(color), m_refractiveIndex(refractiveIndex) {}

	std::optional<MaterialEffect> processRay(const Ray& ray, const HitRecord& hit) const override;
};