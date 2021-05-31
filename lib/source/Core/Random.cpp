#include "Core/Random.h"

#include <time.h> 

Random::Random() : m_enabled(true) { srand(time(NULL)); }

Random* Random::random_instance = nullptr;

Random* Random::get()
{
    if (random_instance == nullptr)
        random_instance = new Random();
    return random_instance;
}

float Random::real01() {
    if (m_enabled)
        return (float)rand() / (RAND_MAX + 1);
    else
        return 0.0;
}

Vec3 Random::vec01() {
    if (m_enabled)
        return Vec3(real01(), real01(), real01());
    else
        return Vec3();
}

Vec3 Random::vecUnitSphere() {
    if (!m_enabled)
        return Vec3();

    // rejection algorithm
    Vec3 point;
    do {
        point = 2.0 * vec01() - Vec3(1.0, 1.0, 1.0);
    } while (point.length_sq() >= 1.0);
    return point;
}

Vec3 Random::vecUnitDisk() {
    if (!m_enabled)
        return Vec3();

    // 2D rejection algorithm
    Vec3 point;
    do {
        point = 2.0 * Vec3(real01(),real01(),0.0) - Vec3(1.0,1.0,0.0);
    } while (point.length_sq() >= 1.0);

    return point;
}