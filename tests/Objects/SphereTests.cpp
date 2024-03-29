#include "TestsUtils.h"

#include "Objects/Sphere.h"

SCENARIO("Sphere hit tests", "[Sphere]")
{
    GIVEN("") {
        Sphere sphere(Vec3(0.0, 0.0, 0.0), 2.0);

        WHEN("") {
            Ray ray(Vec3(5.0, 0.0, 0.0), Vec3(-1.0, 0.0, 0.0));
            auto hit = sphere.testRay(ray);

            THEN("got a hit") {
                REQUIRE(hit);
                REQUIRE(hit->t == 3.0_a);
                REQUIRE(hit->point == Vec3(2.0, 0.0, 0.0));
                REQUIRE(hit->normal == Vec3(1.0, 0.0, 0.0));
            }
        }

        WHEN("") {
            Ray ray(Vec3(5.0, 0.0, 0.0), Vec3(-1.0, 0.0, 0.0));
            Interval interval(1.0, 2.0);
            auto hit = sphere.testRay(ray, interval);

            THEN("hit outside of interval")
                REQUIRE(!hit);
        }

        WHEN("") {
            Ray ray(Vec3(5.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0));
            auto hit = sphere.testRay(ray);

            THEN("ray misses the sphere")
                REQUIRE(!hit);
        }

        WHEN("") {
            Ray ray(Vec3(5.0, 2.0, 0.0), Vec3(-1.0, 0.0, 0.0));
            auto hit = sphere.testRay(ray);

            THEN("ray touches the sphere") {
                REQUIRE(hit);
                REQUIRE(hit->t == 5.0_a);
                REQUIRE(hit->point == Vec3(0.0, 2.0, 0.0));
                REQUIRE(hit->normal == Vec3(0.0, 1.0, 0.0));
            }
        }
    }
}

TEST_CASE("Sphere without material", "[Sphere]")
{
    Sphere sphere(Space3D::origin, 1.0);
    REQUIRE(sphere.material() == nullptr);
}

