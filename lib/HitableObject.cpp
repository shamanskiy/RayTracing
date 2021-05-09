#include "HitableObject.h"

#include "Equations.h"

HitRecord Sphere::testHit(const Ray& ray, const Interval& intervalOfInterest) const
{
    Vec3 centerToRayOrigin = ray.origin() - m_center;

    float a = ray.direction().length_sq();
    float b = 2.0 * dot(ray.direction(), centerToRayOrigin);
    float c = (ray.origin() - m_center).length_sq() - m_radius * m_radius;

    QuadraticEquation equation(a, b, c);
    if (equation.numberOfSolutions() == 0)
        return HitRecord{ -1.0f, Vec3(), Vec3() };
    else
    {
        float t = equation.leftSolution();
        if (intervalOfInterest.includes(t))
        {
            Vec3 hitPoint = ray.eval(t);
            Vec3 normal = (hitPoint - m_center) / m_radius;
            return HitRecord{ t, hitPoint, normal };
        }

        t = equation.rightSolution();
        if (intervalOfInterest.includes(t))
        {
            Vec3 hitPoint = ray.eval(t);
            Vec3 normal = (hitPoint - m_center) / m_radius;
            return HitRecord{ t, hitPoint, normal };
        }

        return HitRecord{ -1.0f, Vec3(), Vec3() };
    }
}