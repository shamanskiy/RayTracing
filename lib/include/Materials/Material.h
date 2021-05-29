#pragma once

#include <optional>

#include "Core/SmallBaseClasses.h"

struct MaterialEffect
{
	Ray ray;
	Vec3 attenuation;
};

class Material
{
public:
	virtual std::optional<MaterialEffect> processRay(const Ray& ray, const HitRecord& hit) const = 0;
	virtual ~Material() {}
};