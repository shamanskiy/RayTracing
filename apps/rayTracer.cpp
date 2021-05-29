#include <iostream>

#include "Core/Scene.h"
#include "Objects/Sphere.h"
#include "Materials/Diffusive.h"
#include "Materials/Metal.h"
#include "Core/Camera.h"
#include "Utils/Timer.h"

using namespace std;

Scene makeScene()
{
    Scene scene;
    scene.addObject(make_unique<Sphere>(Vec3(0.0, 0.0, -1.0), 0.5f, make_unique<Diffusive>(Color::red)));
    scene.addObject(make_unique<Sphere>(Vec3(0.0, 0.0, 1.0), 0.5f, make_unique<Diffusive>(Color::red)));
    scene.addObject(make_unique<Sphere>(Vec3(0.0, -100.5, -1.0), 100.0f,make_unique<Diffusive>(Color::mediumGray)));
    scene.addObject(make_unique<Sphere>(Vec3(1.0, 0.0, -1.0), 0.5f, make_unique<Metal>(Color::gold,1.0f)));
    scene.addObject(make_unique<Sphere>(Vec3(-1.0, 0.0, -1.0), 0.5f, make_unique<Metal>(Color::lightGray,0.1f)));
    scene.setSkyGradient(Color::white, Color::lightblue);
    return scene;
}

CameraSettings getCameraSettings()
{
    CameraSettings settings;
    settings.imagePixelWidth = 400;
    settings.imagePixelHeight = 200;
    settings.antialiasing = 100;

    settings.cameraPosition = Vec3(0.0, 0.0, 0.0);
    settings.viewUpperLeftCorner = Vec3(-2.0, 1.0, -1.0);
    settings.viewHorizontalSpan = Vec3(4.0, 0.0, 0.0);
    settings.viewVerticalSpan = Vec3(0.0, -2.0, 0.0);

    settings.maxRayReflections = 10;

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

    string outputFileName("metal_material.ppm");
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

