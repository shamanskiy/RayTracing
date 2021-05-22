#include "TestsUtils.h"

SCENARIO("Inspecting a ray", "[Ray]")
{
    GIVEN("a ray ") {
        Ray ray(Space3D::origin, Space3D::xAxis);

       THEN("we can access its origin and direction") {
            REQUIRE(ray.origin() == Space3D::origin);
            REQUIRE(ray.direction() == Space3D::xAxis);
        }

        THEN("we can evaluate it at any parameter") {
            REQUIRE(ray.eval(1) == Space3D::origin + Space3D::xAxis);
        }
    }

    GIVEN("a default ray ") {
        Ray ray;

        THEN("it has a zero origin and a x unit vector") {
            REQUIRE(ray.origin() == Space3D::origin);
            REQUIRE(ray.direction() == Space3D::xAxis);
        }
    }
}


