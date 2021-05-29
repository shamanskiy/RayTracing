#include "Objects/Sphere.h"
#include "Core/QuadraticEquation.h"

Sphere::Sphere(Vec3 center, float radius, std::unique_ptr<Material>&& material) 
    : m_center(center), 
      m_radius(radius),
      m_material(std::move(material))
{}

std::optional<HitRecord> Sphere::testRay(const Ray& ray, const Interval& intervalOfInterest) const
{
    auto [numSolutions, leftSolution, rightSolution] = solveHitEquation(ray);

    if (numSolutions == 0)
        return std::nullopt;

    if (intervalOfInterest.includes(leftSolution))
        return makeHitRecord(leftSolution, ray);

    if (intervalOfInterest.includes(rightSolution))
        return makeHitRecord(rightSolution, ray);

    return std::nullopt;
}

HitRecord Sphere::makeHitRecord(float t, const Ray& ray) const
{
    Vec3 hitPoint = ray.eval(t);
    Vec3 normal = (hitPoint - m_center) / m_radius;
    return HitRecord{ t, hitPoint, normal, m_material.get()};
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

const Material* Sphere::material() const
{
    return m_material.get();
}
