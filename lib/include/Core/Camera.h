#pragma once

#include "Core/SmallBaseClasses.h"
#include "Core/Image.h"
#include "Utils/UtilityEnums.h"

class Scene;

struct CameraSettings {
    float verticalFOV{ 90 };
    size_t imagePixelWidth{ 100 };
    size_t imagePixelHeight{ 200 };
    int antialiasing{ 100 };

    Vec3 lookFrom{ 0.0, 0.0, 0.0 };
    Vec3 lookAt{ 0.0,0.0,-1.0 };
    Vec3 globalUp{ 0.0, 1.0, 0.0 };

    int maxRayReflections{ 1 };

    Verbosity verbosity{ Verbosity::none };
    float lensRadius{0.0};
};

class Camera {
    CameraSettings m_settings;
    Vec3 m_viewUpperLeftCorner;
    Vec3 m_viewHorizontalSpan;
    Vec3 m_viewVerticalSpan;
    Vec3 m_right;
    Vec3 m_up;

public:
    explicit Camera(const CameraSettings& settings);

    Image render(const Scene& scene) const;
    Ray getRay(float uParam, float vParam) const;

private:
    Vec3 computePixelColor(const Scene& scene, size_t row, size_t column) const;
    void configure();
};

