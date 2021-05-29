#include "Objects/HitableCollection.h"
#include "Objects/HitableObject.h"

namespace {
    bool better(const std::optional<HitRecord>& hit, const std::optional<HitRecord>& closestHit,
        const Interval& intervalOfInterest)
    {
        return !closestHit || hit && intervalOfInterest.includes(hit->t) && hit->t < closestHit->t;
    }
}

std::optional<HitRecord> HitableCollection::testRay(const Ray& ray, const Interval& intervalOfInterest) const
{
    std::optional<HitRecord> closestHit;
    for (auto& object : m_objects)
    {
        auto hit = object->testRay(ray, intervalOfInterest);
        if (better(hit, closestHit,intervalOfInterest))
            closestHit = hit;
    }
    return closestHit;
}


void HitableCollection::addObject(std::unique_ptr<HitableObject>&& object)
{
    m_objects.push_back(std::move(object)); 
}