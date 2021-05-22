#include "Core/Random.h"

float Random::real01() {
    return (float)rand() / RAND_MAX;
}

Vec3 Random::vec01() {
    return Vec3(Random::real01(), Random::real01(), Random::real01());
}

Vec3 Random::vecUnitSphere() {
    // rejection algorithm
    Vec3 point;
    do {
        point = 2.0 * Random::vec01() - Vec3(1.0, 1.0, 1.0);
    } while (point.length_sq() >= 1.0);
    return point;
}