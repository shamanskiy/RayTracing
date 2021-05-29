#include "Core/Scene.h"
#include "Core/Random.h"
#include "Materials/Material.h"

Vec3 Scene::hitSky(const Ray& ray) const
{
	Vec3 unitDirection = ray.direction().normalize();
	float t = 0.5 * (unitDirection.y() + 1.0);
	return lerp(m_skyColorLow, m_skyColorHigh, t);
}

Vec3 Scene::testRay(const Ray& ray, int maxReflectionDepth, int reflectionDepth) const
{
    auto hit = m_objects.testRay(ray, Interval(0.001, Interval::limit_max()));
    if (hit)
    {
        if (reflectionDepth < maxReflectionDepth)
        {
            auto reflection = hit->material->reflectRay(ray, *hit);
            if (reflection)
                return reflection->attenuation * testRay(reflection->ray, maxReflectionDepth, reflectionDepth + 1);
        }
        return Color::black;
    }
    else
        return hitSky(ray);
}

Vec3 Scene::testRay(const Ray& ray, int maxReflectionDepth) const
{
    return testRay(ray, maxReflectionDepth, 0);
}