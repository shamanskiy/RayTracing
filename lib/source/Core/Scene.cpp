#include "Core/Scene.h"
#include "Core/Random.h"


Vec3 Scene::hitSky(const Ray& ray) const
{
	Vec3 unitDirection = ray.direction().normalize();
	float t = 0.5 * (unitDirection.y() + 1.0);
	return lerp(m_skyColorLow, m_skyColorHigh, t);
}

Vec3 Scene::testRay(const Ray& ray) const
{
    auto [t, point, normal] = m_objects.testRay(ray, Interval(0.001, Interval::limit_max()));
    if (t > 0.0)
        return 0.5 * testRay(Ray(point, normal + Random::vecUnitSphere()));

    return hitSky(ray);
}