#pragma once

#include "Core/SmallBaseClasses.h"
#include "Core/Image.h"
#include "Utils/UtilityEnums.h"

class Scene;

struct CameraSettings {
    size_t imagePixelWidth{ 100 };
    size_t imagePixelHeight{ 200 };
    int antialiasing{ 100 };

    Vec3 cameraPosition{ 0.0, 0.0, 0.0 };
    Vec3 viewUpperLeftCorner{ -2.0, 1.0, -1.0 };
    Vec3 viewHorizontalSpan{ 4.0, 0.0, 0.0 };
    Vec3 viewVerticalSpan{ 0.0, -2.0, 0.0 };

    Verbosity verbosity{ Verbosity::none };
};

class Camera {
    CameraSettings m_settings;

public:
    Camera(const CameraSettings& settings) : m_settings(settings) {}

    Ray getRay(float u, float v) const;
    Image render(const Scene& scene) const;
    Vec3 computePixelColor(const Scene& scene, size_t i, size_t j) const;
};

