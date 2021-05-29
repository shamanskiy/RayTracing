#pragma once

#include "Core/SmallBaseClasses.h"

class Random
{
    static Random* random_instance;
    bool m_enabled;

    Random();

public:
    Random(const Random&) = delete;
    Random& operator=(const Random&) = delete;

    static Random* get();
    void enable() { m_enabled = true; }
    void disable() { m_enabled = false; }

    float real01();
    Vec3 vec01();
    Vec3 vecUnitSphere();
};