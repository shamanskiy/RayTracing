#include "Objects/HitableObject.h"

#include <vector>

class Scene : public HitableObject {
	std::vector<std::unique_ptr<HitableObject>> m_objects;

public:
	HitRecord testRay(const Ray& ray, const Interval& intervalOfInterest = Interval()) const override;
	void addObject(std::unique_ptr<HitableObject>&& object) { m_objects.push_back(std::move(object)); }
};