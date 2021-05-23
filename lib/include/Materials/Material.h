#pragma once

#include "Core/SmallBaseClasses.h"

struct Reflection
{
	bool happened;
	Ray ray;
	Vec3 attenuation;
};

class Material
{
public:
	virtual Reflection reflectRay(const Ray& ray, const HitRecord& hit) const = 0;
	virtual ~Material() {}
};