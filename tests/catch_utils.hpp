#pragma once

#include "catch.hpp"

#include "Core/Vec3.h"

using namespace Catch::literals;

inline bool operator==(const Vec3& lhs, const Vec3& rhs)
{
    return Approx(lhs.x()) == rhs.x() &&
        Approx(lhs.y()) == rhs.y() &&
        Approx(lhs.z()) == rhs.z();
}