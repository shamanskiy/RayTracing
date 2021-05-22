#include <iostream>

#include "Core/Camera.h"
#include "Core/Scene.h"
#include "Utils/ProgressBar.h"
#include "Core/Random.h"

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
        float uParam = float(column + Random::real01()) / m_settings.imagePixelWidth;
        float vParam = float(row + Random::real01()) / m_settings.imagePixelHeight;
        pixelColor += scene.testRay(getRay(uParam, vParam), m_settings.maxRayReflections);
    }
    return pixelColor / m_settings.antialiasing;
}

Ray Camera::getRay(float u, float v) const
{
    return Ray(m_settings.cameraPosition,
        m_settings.viewUpperLeftCorner + u * m_settings.viewHorizontalSpan + v * m_settings.viewVerticalSpan - m_settings.cameraPosition);
}