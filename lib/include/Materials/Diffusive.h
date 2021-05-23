#pragma once

#include "Material.h"

class Diffusive : public Material
{
	Vec3 m_color;

public:
	Diffusive(const Vec3& color) : m_color(color) {}

	Reflection reflectRay(const Ray& ray, const HitRecord& hit) const override;
};