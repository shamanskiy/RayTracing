#pragma once

#include "catch.hpp"

#include "Core/SmallBaseClasses.h"

using namespace Catch::literals;

inline bool operator==(const Vec3& lhs, const Vec3& rhs)
{
    return Approx(lhs.x()) == rhs.x() &&
        Approx(lhs.y()) == rhs.y() &&
        Approx(lhs.z()) == rhs.z();
}

inline bool operator==(const Ray& lhs, const Ray& rhs)
{
    return lhs.origin() == rhs.origin() && lhs.direction() == rhs.direction();
}