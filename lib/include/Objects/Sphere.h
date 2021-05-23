#include "Objects/HitableObject.h"

#include "Materials/Material.h"

class Sphere : public HitableObject {
	Vec3 m_center;
	float m_radius;
	std::unique_ptr<Material> m_material;

public:
	Sphere(Vec3 center, float radius, std::unique_ptr<Material>&& material = nullptr); 

	HitRecord testRay(const Ray& ray, const Interval& intervalOfInterest = Interval()) const override;
	const Material* material() const { return m_material.get(); }

private:
	std::tuple<int, float, float> solveHitEquation(const Ray& ray) const;
	HitRecord makeHitRecord(float t, const Ray& ray) const;
};

