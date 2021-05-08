#include <fstream>

using namespace std;

int main() {

    int nx = 200;
    int ny = 100;

    ofstream imageFile;
    imageFile.open("gradient.ppm");

    imageFile << "P3\n" << nx << " " << ny << "\n255\n";

    for (int i = 0; i < ny; i++)
        for (int j = 0; j < nx; j++)
        {
            float r = float(i) / ny;
            float g = float(j) / nx;
            float b = 0.2;

            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);

            imageFile << ir << " " << ig << " " << ib << "\n";
        }

    imageFile.close();
}
