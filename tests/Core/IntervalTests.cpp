#include "TestsUtils.h"

SCENARIO("Interval tests", "[Interval]")
{
    GIVEN("an interval") {
        Interval interval(1.0, 2.0);

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
