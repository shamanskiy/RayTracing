#pragma once

#include "Core/Ray.h"

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

    Ray getRay(float u, float v) { return Ray(m_origin, m_upperLeftCorner + u * m_horizontalSpan + v * m_verticalSpan - m_origin);
    }
};

