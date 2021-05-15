#include "Objects/Scene.h"

namespace {
    bool closer(const HitRecord& hit, const HitRecord& closestHit) {
        return hit.t < closestHit.t;
    }
}

HitRecord Scene::testRay(const Ray& ray, const Interval& intervalOfInterest) const
{
    auto closestHit = HitRecord::farAway();
    bool hitAnything = false;

    for (auto& object : m_objects)
    {
        auto hit = object->testRay(ray, intervalOfInterest);
        if (intervalOfInterest.includes(hit.t) && closer(hit, closestHit))
        {
            closestHit = hit;
            hitAnything = true;
        }
    }

    return hitAnything ? closestHit : HitRecord::miss();
}