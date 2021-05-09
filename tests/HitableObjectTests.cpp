#include "catch_utils.hpp"

#include "HitableObject.h"
#include "Ray.h"

SCENARIO("Sphere hit tests", "[Sphere]")
{
    GIVEN("") {
        Sphere sphere(Vec3(0.0, 0.0, 0.0), 1.0);

        WHEN("") {
            Ray ray(Vec3(2.0, 0.0, 0.0), Vec3(-1.0, 0.0, 0.0));
            auto hit = sphere.testHit(ray);

            THEN("got a hit") {
                REQUIRE(hit.t == 1.0_a);
                REQUIRE(hit.point == Vec3(1.0, 0.0, 0.0));
                REQUIRE(hit.normal == Vec3(1.0, 0.0, 0.0));
            }
        }

        WHEN("") {
            Ray ray(Vec3(2.0, 0.0, 0.0), Vec3(-1.0, 0.0, 0.0));
            Interval interval(0.1, 0.5);
            auto hit = sphere.testHit(ray, interval);

            THEN("hit outside of interval")
                REQUIRE(hit.t == -1.0_a);
        }

        WHEN("") {
            Ray ray(Vec3(2.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0));
            auto hit = sphere.testHit(ray);

            THEN("ray misses the sphere")
                REQUIRE(hit.t == -1.0_a);
        }

        WHEN("") {
            Ray ray(Vec3(2.0, 1.0, 0.0), Vec3(-1.0, 0.0, 0.0));
            auto hit = sphere.testHit(ray);

            THEN("ray touches the sphere"){
                REQUIRE(hit.t == 2.0_a);
                REQUIRE(hit.point == Vec3(0.0, 1.0, 0.0));
                REQUIRE(hit.normal == Vec3(0.0, 1.0, 0.0));
            }
        }
    }
}


