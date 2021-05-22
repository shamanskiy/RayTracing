#pragma once

#include "Core/SmallBaseClasses.h"

class HitableObject {
public:
	virtual HitRecord testRay(const Ray& ray, const Interval& intervalOfInterest = Interval()) const = 0;
    virtual ~HitableObject() {}
};

