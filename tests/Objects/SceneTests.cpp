#include "TestsUtils.h"

#include "Objects/Scene.h"
#include "Objects/Sphere.h"

SCENARIO("Scene tests", "[Scene]")
{
    GIVEN("A scene with two spheres") {
        Scene scene;
        scene.addObject(std::make_unique<Sphere>(Vec3(0.0, 0.0, 0.0), 2.0f));
        scene.addObject(std::make_unique<Sphere>(Vec3(-5.0, 0.0, 0.0), 2.0f));

        WHEN("") {
            Ray ray(Vec3(5.0, 0.0, 0.0), Vec3(-1.0, 0.0, 0.0));
            auto hit = scene.testRay(ray);

            THEN("hit the first sphere on the front") {
                REQUIRE(hit.t == 3.0_a);
                REQUIRE(hit.point == Vec3(2.0, 0.0, 0.0));
                REQUIRE(hit.normal == Vec3(1.0, 0.0, 0.0));
            }
        }

        WHEN("") {
            Ray ray(Vec3(5.0, 0.0, 0.0), Vec3(-1.0, 0.0, 0.0));
            auto hit = scene.testRay(ray, Interval(5.0, 7.5));

            THEN("hit the first sphere on the back") {
                REQUIRE(hit.t == 7.0_a);
                REQUIRE(hit.point == Vec3(-2.0, 0.0, 0.0));
                REQUIRE(hit.normal == Vec3(-1.0, 0.0, 0.0));
            }
        }

        WHEN("") {
            Ray ray(Vec3(5.0, 0.0, 0.0), Vec3(-1.0, 0.0, 0.0));
            auto hit = scene.testRay(ray, Interval(7.5, 20.0));

            THEN("hit the second sphere on the front") {
                REQUIRE(hit.t == 8.0_a);
                REQUIRE(hit.point == Vec3(-3.0, 0.0, 0.0));
                REQUIRE(hit.normal == Vec3(1.0, 0.0, 0.0));
            }
        }

        WHEN("") {
            Ray ray(Vec3(5.0, 0.0, 0.0), Vec3(1.0, 0.0, 0.0));
            auto hit = scene.testRay(ray);

            THEN("no hit") {
                REQUIRE(hit.t == -1.0_a);
            }
        }

        WHEN("") {
            Ray ray(Vec3(5.0, 2.0, 0.0), Vec3(-1.0, 0.0, 0.0));
            auto hit = scene.testRay(ray);

            THEN("hit the first sphere on the top") {
                REQUIRE(hit.t == 5.0_a);
                REQUIRE(hit.point == Vec3(0.0, 2.0, 0.0));
                REQUIRE(hit.normal == Vec3(0.0, 1.0, 0.0));
            }
        }

    }
}