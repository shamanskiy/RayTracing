#pragma once

#include <optional>

#include "Core/SmallBaseClasses.h"

class HitableObject {

public:
	virtual std::optional<HitRecord> testRay(const Ray& ray, const Interval& intervalOfInterest = Interval()) const = 0;
	virtual ~HitableObject() {}
};

