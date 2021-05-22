#include "TestsUtils.h"

TEST_CASE("Hit record: miss", "[HitRecord]")
{
    auto noHit = HitRecord::miss();
    REQUIRE(noHit.t == -1.0_a);
}

TEST_CASE("Hit record: far away", "[HitRecord]")
{
    auto noHit = HitRecord::farAway();
    REQUIRE(noHit.t == Interval::limit_max());
}