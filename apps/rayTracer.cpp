#include <iostream>

#include "Core/Scene.h"
#include "Objects/Sphere.h"
#include "Materials/Diffusive.h"
#include "Materials/Reflective.h"
#include "Materials/Transparent.h"
#include "Core/Camera.h"
#include "Core/Random.h"
#include "Utils/Timer.h"

using namespace std;

Scene makeScene()
{
    Scene scene;
    scene.setSkyGradient(Color::white, Color::lightblue);

    // giant sphere = floor
    scene.addObject(make_unique<Sphere>(Vec3(0.0, -1000.0, 0.0),
                                        1000.0f,make_unique<Diffusive>(Color::mediumGray)));
    // three central spheres
    Vec3 centerA(-2.5, 1.0, 0.4);
    scene.addObject(make_unique<Sphere>(centerA,
                                        1.0f, make_unique<Diffusive>(Color::red)));
    Vec3 centerB(0.0, 1.0, 0.0);
    scene.addObject(make_unique<Sphere>(centerB,
                                        1.0f, make_unique<Transparent>(Color::white,1.5f)));
    Vec3 centerC(2.5, 1.0, 0.0);
    scene.addObject(make_unique<Sphere>(centerC,
                                        1.0f, make_unique<Reflective>(Color::lightGray,0.01f)));

    // random little spheres
    for (int i = -11; i < 11; i++)
        for (int j = -11; j < 11; j++)
        {
            float materialChooser = Random::get()->real01();
            Vec3 center(i + 0.9 * Random::get()->real01(),0.2,j + 0.9*Random::get()->real01());

            if (materialChooser < 0.7 )
                scene.addObject(make_unique<Sphere>(center, 0.2,
                                                    make_unique<Diffusive>(Random::get()->vec01())));
            else if (materialChooser < 0.9)
                scene.addObject(make_unique<Sphere>(center, 0.2,
                      make_unique<Reflective>(0.5 * (Vec3(1.0,1.0,1.0) +
                                                     Random::get()->vec01()),0.5*Random::get()->real01())));
            else
                scene.addObject(make_unique<Sphere>(center,0.2,
                                                    make_unique<Transparent>(Color::white,1.5)));
        }

    return scene;
}

CameraSettings getCameraSettings()
{
    CameraSettings settings;
    settings.imagePixelWidth = 960;
    settings.imagePixelHeight = 540;
    settings.antialiasing = 10;
    settings.lensRadius = 0.005;

    settings.lookFrom = Vec3(3.5, 1.35, 1.9);
    settings.lookAt = Vec3(3.0, 1.25, 1.5);
    settings.verticalFOV = 75.0;

    settings.maxRayReflections = 30;

    settings.verbosity = Verbosity::all;
    return settings;
}

Image renderScene(const Camera& camera, const Scene& scene)
{
    cout << "Rendering...\n";
    Timer timer;

    Image image = camera.render(scene);

    cout << timer.reportElapsedTime() << "\n";
    return image;
}

void saveImage(const Image& image)
{
    cout << "Saving...\n";
    Timer timer;

    string outputFileName("mega_scene.ppm");
    image.save(outputFileName, Verbosity::all);

    cout << timer.reportElapsedTime() << "\n";
    cout << "Image saved to " << outputFileName << "\n";
}

int main() {

    auto scene = makeScene();
    Camera camera(getCameraSettings());

    auto image = renderScene(camera, scene);

    saveImage(image);
}

