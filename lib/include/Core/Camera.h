#pragma once

#include "Core/SmallBaseClasses.h"
#include "Core/Image.h"
#include "Utils/UtilityEnums.h"

class Scene;

struct ImageSettings {
    int width;
    int height;
    int antialiasing;
};

class Camera {
    Vec3 m_origin;
    Vec3 m_upperLeftCorner;
    Vec3 m_horizontalSpan;
    Vec3 m_verticalSpan;

public:
    Camera() : m_origin(Vec3(0.0, 0.0, 0.0)),
    m_upperLeftCorner(Vec3(-2.0, 1.0, -1.0)),
    m_horizontalSpan(Vec3(4.0, 0.0, 0.0)),
    m_verticalSpan(Vec3(0.0, -2.0, 0.0)) {}

    Ray getRay(float u, float v) const
    { 
        return Ray(m_origin, m_upperLeftCorner + u * m_horizontalSpan + v * m_verticalSpan - m_origin);
    }

    Image render(const Scene& scene, const ImageSettings& settings, Verbosity verbosity = Verbosity::none) const;
};

