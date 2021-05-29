#include "TestsUtils.h"

#include "Core/Camera.h"
#include "Core/Scene.h"

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