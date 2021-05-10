#include "catch_utils.hpp"

#include "Ray.h"

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

SCENARIO("Interval tests", "[Interval]")
{
    GIVEN("an interval") {
        Interval interval(1.0, 2.0);

        WHEN("")
            THEN("we can access its limits") {
            REQUIRE(interval.min() == 1.0_a);
            REQUIRE(interval.max() == 2.0_a);
        }

        WHEN("we have a parameter value outside the interval") {
            float t = 0.5;
            THEN("includes returns false")
                REQUIRE_FALSE(interval.includes(t));
        }

        WHEN("we have a parameter value inside the interval") {
            float t = 1.5;
            THEN("includes returns true")
                REQUIRE(interval.includes(t));
        }

        WHEN("we have a parameter value on the interval boundary") {
            float t_min = 1.0;
            float t_max = 2.0;
            THEN("includes returns true") {
                REQUIRE(interval.includes(t_min));
                REQUIRE(interval.includes(t_max));
            }
        }

    }

    GIVEN("a default interval") {
        Interval interval;

        WHEN("")
            THEN("its min is zero and its max is float_max") {
            REQUIRE(interval.min() == 0.0_a);
            REQUIRE(interval.max() == Interval::limit_max());

        }
    }
}

TEST_CASE("Interval limit_max test", "[Interval]")
{
    REQUIRE(Interval::limit_max() == std::numeric_limits<float>::max());
}

