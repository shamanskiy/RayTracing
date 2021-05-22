#include "Core/Camera.h"
#include "Objects/Scene.h"
#include "Utils/ProgressBar.h"

#include <iostream>

namespace
{
    float map_y_to_zero_one(const Vec3& vec)
    {
        Vec3 unitDirection = vec.normalize();
        return 0.5 * (unitDirection.y() + 1.0);
    }

    Vec3 randomUnitSphere() {
        Vec3 p;
        do {
            p = 2.0 * Vec3((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX) - Vec3(1.0, 1.0, 1.0);
        } while (p.length_sq() >= 1.0);
        return p;
    }

    Vec3 color(const Ray& ray, const Scene& scene)
    {
        auto [t, point, normal] = scene.testRay(ray, Interval(0.001, Interval::limit_max()));
        if (t > 0.0)
            return 0.5 * color(Ray(point, normal + randomUnitSphere()), scene);

        t = map_y_to_zero_one(ray.direction());
        Vec3 white(1.0, 1.0, 1.0);
        Vec3 lightBlue(0.5, 0.7, 1.0);
        return lerp(white, lightBlue, t);
    }

}
Image Camera::render(const Scene& scene, const ImageSettings& settings, Verbosity verbosity) const
{
    Image image(settings.height, settings.width);

    ProgressBar bar(settings.height, 35);
    for (int i = 0; i < settings.height; i++)
    {
        if (verbosity == Verbosity::all)
            bar.displayNext(std::cout);
        for (int j = 0; j < settings.width; j++)
        {
            Vec3 col;
            for (int s = 0; s < settings.antialiasing; s++)
            {
                float u = float(j + (float)rand() / RAND_MAX) / settings.width;
                float v = float(i + (float)rand() / RAND_MAX) / settings.height;
                col += color(getRay(u, v), scene);
            }

            image(i, j) = col / settings.antialiasing;
        }
    }

    return image;
}