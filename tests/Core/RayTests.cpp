#include "TestsUtils.h"

SCENARIO("Inspecting a ray", "[Ray]")
{
    Vec3 x_direction(1.0, 0.0, 0.0);
    Vec3 origin(0.0, 0.0, 0.0);

    GIVEN("a ray ") {
        Ray ray(origin, x_direction);

        WHEN("")
            THEN("we can access its origin and direction") {
            REQUIRE(ray.origin() == origin);
            REQUIRE(ray.direction() == x_direction);
        }

        WHEN("")
            THEN("we can evaluate it at any parameter") {
            REQUIRE(ray.eval(1) == origin + x_direction);
        }
    }

    GIVEN("a default ray ") {
        Ray ray;

        WHEN("")
            THEN("it has a zero origin and a x unit vector") {
            REQUIRE(ray.origin() == origin);
            REQUIRE(ray.direction() == x_direction);
        }
    }
}


