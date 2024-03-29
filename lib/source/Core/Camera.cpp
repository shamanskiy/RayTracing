#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

#include "Core/Camera.h"
#include "Core/Scene.h"
#include "Utils/ProgressBar.h"
#include "Core/Random.h"


Camera::Camera(const CameraSettings& settings) : m_settings(settings)
{
    configure();
}

void Camera::configure()
{
    float verticalFOV_rad = m_settings.verticalFOV * M_PI / 180;
    float aspectRatio = float(m_settings.imagePixelWidth) / m_settings.imagePixelHeight;
    
    float halfHeight = tan(verticalFOV_rad / 2);
    float halfWidth = aspectRatio * halfHeight;

    Vec3 back = (m_settings.lookFrom - m_settings.lookAt).normalize();
    m_right = cross(m_settings.globalUp, back).normalize();
    m_up = cross(back, m_right);

    float focusDistance = (m_settings.lookFrom - m_settings.lookAt).length();

    m_viewUpperLeftCorner = m_settings.lookFrom + (halfHeight * m_up - halfWidth * m_right - back) * focusDistance;
    m_viewHorizontalSpan = 2 * halfWidth * m_right * focusDistance;
    m_viewVerticalSpan = -2 * halfHeight * m_up * focusDistance;
}

Image Camera::render(const Scene& scene) const
{
    Image image(m_settings.imagePixelHeight, m_settings.imagePixelWidth);
    ProgressBar bar(m_settings.imagePixelHeight);

    for (size_t row = 0; row < m_settings.imagePixelHeight; row++)
    {
        if (m_settings.verbosity == Verbosity::all)
            bar.displayNext(std::cout);

        for (size_t column = 0; column < m_settings.imagePixelWidth; column++)
            image(row, column) = computePixelColor(scene, row, column);
    }

    return image;
}

Vec3 Camera::computePixelColor(const Scene& scene, size_t row, size_t column) const
{
    Vec3 pixelColor;
    for (int sample = 0; sample < m_settings.antialiasing; sample++)
    {
        float uParam = float(column + Random::get()->real01()) / m_settings.imagePixelWidth;
        float vParam = float(row + Random::get()->real01()) / m_settings.imagePixelHeight;
        pixelColor += scene.testRay(getRay(uParam, vParam), m_settings.maxRayReflections);
    }
    return pixelColor / m_settings.antialiasing;
}

Ray Camera::getRay(float u, float v) const
{
    Vec3 randomLensPoint = m_settings.lensRadius* Random::get()->vecUnitDisk();
    Vec3 lensOrigin = m_settings.lookFrom + m_right * randomLensPoint.x() + m_up * randomLensPoint.y();
    return Ray(lensOrigin,
        m_viewUpperLeftCorner + u * m_viewHorizontalSpan + v * m_viewVerticalSpan - lensOrigin);
}