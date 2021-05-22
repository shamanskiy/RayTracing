#pragma once

#include "Core/SmallBaseClasses.h"

namespace Rand
{
    float real01() {
        return (float)rand() / RAND_MAX; }

    Vec3 vec01() {
        return Vec3(real01(), real01(), real01());
    }

    Vec3 vecUnitSphere() {
        // rejection algorithm
        Vec3 p;
        do {
            p = 2.0 * vec01() - Vec3(1.0, 1.0, 1.0);
        } while (p.length_sq() >= 1.0);
        return p;
    }
}