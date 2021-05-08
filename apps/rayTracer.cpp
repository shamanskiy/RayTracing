#include <fstream>
#include <iostream>

#include "Ray.h"

using namespace std;

int main() {

    int nx = 200;
    int ny = 100;

    ofstream imageFile;
    imageFile.open("gradient_vec.ppm");

    imageFile << "P3\n" << nx << " " << ny << "\n255\n";

    for (int i = 0; i < ny; i++)
        for (int j = 0; j < nx; j++)
        {
            Vec3 color(float(i) / ny, float(j) / nx, 0.2);

            int ir = int(255.99 * color.r());
            int ig = int(255.99 * color.g());
            int ib = int(255.99 * color.b());

            imageFile << ir << " " << ig << " " << ib << "\n";
        }

    imageFile.close();
}
