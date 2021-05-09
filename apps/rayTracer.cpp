#include <fstream>
#include <iostream>
#include <chrono>

#include "Ray.h"

using namespace std;

float map_y_to_zero_one(const Vec3& vec)
{
    Vec3 unitDirection = vec.normalize();
    return 0.5 * (unitDirection.y() + 1.0);
}

float hit_sphere(const Vec3& center, float radius, const Ray& ray)
{
    Vec3 AB = ray.origin() - center;
    float a = ray.direction().length_sq();
    float b = 2.0 * dot(ray.direction(), AB);
    float c = (ray.origin() - center).length_sq() - radius*radius;
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return -1;
    else
        return (- b - sqrt(discriminant)) / (2.0*a);
}

Vec3 color(const Ray& ray)
{
    float t = hit_sphere(Vec3(0.0, 0.0, -1.0), 0.5, ray);
    if (t > 0.0)
    {
        Vec3 normal = (ray.eval(t) - Vec3(0.0, 0.0, -1.0)).normalize();
        return 0.5* ( normal + Vec3(1.0,1.0,1.0));
    }
        

    t = map_y_to_zero_one(ray.direction());
    Vec3 white(1.0, 1.0, 1.0);
    Vec3 lightBlue(0.5, 0.7, 1.0);
    return lerp(white, lightBlue, t);
}

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    int nx = 200;
    int ny = 100;

    ofstream imageFile;
    imageFile.open("normal_sphere.ppm");

    imageFile << "P3\n" << nx << " " << ny << "\n255\n";

    Vec3 origin(0.0,0.0,0.0);
    Vec3 upper_left_corner(-2.0, 1.0, -1.0);
    Vec3 horizontal(4.0, 0.0, 0.0);
    Vec3 vertical(0.0, -2.0, 0.0);

    for (int i = 0; i < ny; i++)
        for (int j = 0; j < nx; j++)
        {
            float u = float(j) / nx;
            float v = float(i) / ny;
            Ray ray(origin, upper_left_corner + u * horizontal + v * vertical);
            Vec3 col = color(ray);

            int ir = int(255.99 * col.r());
            int ig = int(255.99 * col.g());
            int ib = int(255.99 * col.b());

            imageFile << ir << " " << ig << " " << ib << "\n";
        }

    imageFile.close();

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}
