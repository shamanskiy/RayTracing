#pragma once

#include "Core/SmallBaseClasses.h"

class Material
{
	virtual std::tuple<Ray, Vec3> reflectRay(const Ray& ray, const HitRecord& hit) const = 0;
	virtual ~Material() {}
};