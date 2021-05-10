#include <fstream>
#include <iostream>
#include <chrono>
#include <random>

#include <time.h>
#include <cstdlib>

#include "HitableObject.h"
#include "Camera.h"

using namespace std;

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

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    int nx = 2000;
    int ny = 1000;
    int ns = 100;
    srand((unsigned)time(0));

    ofstream imageFile;
    imageFile.open("antialiasing.ppm");

    imageFile << "P3\n" << nx << " " << ny << "\n255\n";

    Scene scene;
    scene.addObject(make_unique<Sphere>(Vec3(0.0, 0.0, -1.0), 0.5f));
    scene.addObject(make_unique<Sphere>(Vec3(0.0, -100.5, -1.0), 100.0f));

    Camera camera;

    for (int i = 0; i < ny; i++)
        for (int j = 0; j < nx; j++)
        {
            Vec3 col;
            for (int s = 0; s < ns; s++)
            {
                float u = float(j + (float)rand() / RAND_MAX) / nx;
                float v = float(i + (float)rand() / RAND_MAX) / ny;
                col += color(camera.getRay(u, v), scene);
            }
            
            col /= ns;
            int ir = int(255.99 * sqrt(col.r()));
            int ig = int(255.99 * sqrt(col.g()));
            int ib = int(255.99 * sqrt(col.b()));

            imageFile << ir << " " << ig << " " << ib << "\n";
        }

    imageFile.close();

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}
