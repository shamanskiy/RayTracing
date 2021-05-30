#include "TestsUtils.h"

#include "Core/Camera.h"
#include "Core/Scene.h"

SCENARIO("Camera positioning tests", "[Camera]") {
    GIVEN("a camera") {
        CameraSettings settings;
        settings.imagePixelHeight = 100;
        settings.imagePixelWidth = 200;
        settings.verticalFOV = 90;
        settings.lookFrom = Space3D::origin;
        settings.lookAt = Vec3(1.0, 0.0, 0.0);
        Camera camera(settings);
    
        WHEN("") {
            Ray ray = camera.getRay(0.0, 0.0);
            
            THEN("") {
                REQUIRE(ray.origin() == Space3D::origin);
                REQUIRE(ray.direction() == Vec3(1.0, 1.0, -2.0));
            }
        }

        WHEN("") {
            Ray ray = camera.getRay(1.0, 1.0);

            THEN("") {
                REQUIRE(ray.origin() == Space3D::origin);
                REQUIRE(ray.direction() == Vec3(1.0, -1.0, 2.0));
            }
        }

        WHEN("") {
            Ray ray = camera.getRay(0.5, 0.5);

            THEN("") {
                REQUIRE(ray.origin() == Space3D::origin);
                REQUIRE(ray.direction() == Vec3(1.0, 0.0, 0.0));
            }
        }
    }
}

SCENARIO("Camera: rendering tests", "[Camera]")
{
    GIVEN("a camera") {
        CameraSettings settings;
        settings.imagePixelHeight = 1;
        settings.imagePixelWidth = 1;
        Camera camera(settings);

        WHEN("we render an empty scene") {
            Scene scene;
            scene.setSkyGradient(Color::red, Color::red);

            Image image = camera.render(scene);

            THEN("we get the color sky") {
                REQUIRE(image.height() == 1);
                REQUIRE(image.width() == 1);
                REQUIRE(image(0, 0) == Color::red);
            }
        }
    }
}