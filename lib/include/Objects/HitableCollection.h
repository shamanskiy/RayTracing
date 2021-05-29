#include <vector>
#include <optional>

#include "Core/SmallBaseClasses.h"
#include "Objects/HitableObject.h"

class HitableCollection {
	std::vector<std::unique_ptr<HitableObject>> m_objects;

public:
	std::optional<HitRecord> testRay(const Ray& ray, const Interval& intervalOfInterest = Interval()) const;
	void addObject(std::unique_ptr<HitableObject>&& object);
};