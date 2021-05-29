#pragma once

#include <optional>

#include "Core/SmallBaseClasses.h"

struct Reflection
{
	Ray ray;
	Vec3 attenuation;
};

class Material
{
public:
	virtual std::optional<Reflection> reflectRay(const Ray& ray, const HitRecord& hit) const = 0;
	virtual ~Material() {}
};