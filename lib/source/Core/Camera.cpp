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

    m_viewUpperLeftCorner = Vec3(-halfWidth, halfHeight, -1.0);
    m_viewHorizontalSpan = Vec3(2 * halfWidth, 0.0, 0.0);
    m_viewVerticalSpan = Vec3(0.0, -2 * halfHeight, 0.0);
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
    return Ray(m_settings.cameraPosition,
        m_viewUpperLeftCorner + u * m_viewHorizontalSpan + v * m_viewVerticalSpan - m_settings.cameraPosition);
}