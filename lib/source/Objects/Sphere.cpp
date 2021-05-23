#include "Objects/Sphere.h"
#include "Core/QuadraticEquation.h"

Sphere::Sphere(Vec3 center, float radius, std::unique_ptr<Material>&& material) 
    : m_center(center), 
      m_radius(radius), 
      m_material(std::move(material)) 
{}

HitRecord Sphere::testRay(const Ray& ray, const Interval& intervalOfInterest) const
{
    auto [numSolutions, leftSolution, rightSolution] = solveHitEquation(ray);

    if (numSolutions == 0)
        return HitRecord::miss();

    if (intervalOfInterest.includes(leftSolution))
        return makeHitRecord(leftSolution, ray);

    if (intervalOfInterest.includes(rightSolution))
        return makeHitRecord(rightSolution, ray);

    return HitRecord::miss();
}

HitRecord Sphere::makeHitRecord(float t, const Ray& ray) const
{
    Vec3 hitPoint = ray.eval(t);
    Vec3 normal = (hitPoint - m_center) / m_radius;
    return HitRecord{ t, hitPoint, normal };
}

std::tuple<int, float, float> Sphere::solveHitEquation(const Ray& ray) const
{
    Vec3 centerToRayOrigin = ray.origin() - m_center;

    float a = ray.direction().length_sq();
    float b = 2.0 * dot(ray.direction(), centerToRayOrigin);
    float c = (ray.origin() - m_center).length_sq() - m_radius * m_radius;

    QuadraticEquation equation(a, b, c);

    return std::tuple{ equation.numberOfSolutions(), equation.leftSolution(), equation.rightSolution() };
}



