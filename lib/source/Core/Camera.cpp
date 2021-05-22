#include "Core/Camera.h"
#include "Objects/Scene.h"
#include "Utils/ProgressBar.h"
#include "Core/Random.h"
#include <iostream>

namespace
{
    Vec3 hitSky(const Ray& ray)
    {
        Vec3 unitDirection = ray.direction().normalize();
        float t = 0.5 * (unitDirection.y() + 1.0);
        Vec3 white(1.0, 1.0, 1.0);
        Vec3 lightBlue(0.5, 0.7, 1.0);
        return lerp(white, lightBlue, t);
    }

    Vec3 sendRay(const Ray& ray, const Scene& scene)
    {
        auto [t, point, normal] = scene.testRay(ray, Interval(0.001, Interval::limit_max()));
        if (t > 0.0)
            return 0.5 * sendRay(Ray(point, normal + Random::vecUnitSphere()), scene);

        return hitSky(ray);
    }

}

Ray Camera::getRay(float u, float v) const
{
    return Ray(m_settings.cameraPosition,
        m_settings.viewUpperLeftCorner + u * m_settings.viewHorizontalSpan + v * m_settings.viewVerticalSpan - m_settings.cameraPosition);
}

Vec3 Camera::computePixelColor(const Scene& scene, size_t row, size_t column) const
{
    Vec3 pixelColor;
    for (int sample = 0; sample < m_settings.antialiasing; sample++)
    {
        float uParam = float(column + Random::real01()) / m_settings.imagePixelWidth;
        float vParam = float(row + Random::real01()) / m_settings.imagePixelHeight;
        pixelColor += sendRay(getRay(uParam, vParam), scene);   
    }
    return pixelColor / m_settings.antialiasing;
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