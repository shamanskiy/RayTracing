#include <sstream>

#include "TestsUtils.h"

using namespace std;

SCENARIO("Inspecting a vector", "[Vec3]")
{
    GIVEN("a vector ") {
        Vec3 vec(3.0, 4.0, 0.0);

        WHEN("") {
            ostringstream stream;
            stream << vec;
            THEN("we can pass it to an output stream")      
                REQUIRE(stream.str() == "3 4 0");
        }

        THEN("we can access its elements as xyz") {
            REQUIRE(vec.x() == 3.0_a);
            REQUIRE(vec.y() == 4.0_a);
            REQUIRE(vec.z() == 0.0_a);
        }

        THEN("we can access its elements as rgb") {
            REQUIRE(vec.r() == 3.0_a);
            REQUIRE(vec.g() == 4.0_a);
            REQUIRE(vec.b() == 0.0_a);
        }

        WHEN("") {
            vec[0] = 1.0;
            vec[1] = 1.0;
            vec[2] = 1.0;
            THEN("we can access and modify its elements with brackets") {
                REQUIRE(vec[0] == 1.0_a);
                REQUIRE(vec[1] == 1.0_a);
                REQUIRE(vec[2] == 1.0_a);
            }
        }
    }
}

SCENARIO("Default vector", "[Vec3]")
{
    GIVEN("a default vector ") {
        Vec3 vec;

        THEN("its elements are all zero")
            REQUIRE(vec == Vec3(0.0, 0.0, 0.0));
    }
}

SCENARIO("Vector length operations", "[Vec3]")
{
    GIVEN("a vector ") {
        Vec3 vec(3.0, 4.0, 0.0);

        THEN("we can compute its length")
            REQUIRE(vec.length() == 5.0_a);

        THEN("we can compute its squared length")
            REQUIRE(vec.length_sq() == 25.0_a);
  
        WHEN("we normalize it")
        {
            Vec3 unit_vec = vec.normalize();
            THEN("we get a new unit vector")
            {
                REQUIRE(vec.length() == 5.0_a);
                REQUIRE(unit_vec.length() == 1.0_a);
            }
        }

        WHEN("we normalize it in place")
        {
            vec.normalize_inplace();
            THEN("its length becomes 1")
                REQUIRE(vec.length() == 1.0_a);
        }

        WHEN("we negate it") {
            Vec3 vec_neg = -vec;
            THEN("we get a vector with negated components")
                REQUIRE(vec_neg == Vec3(-3.0, -4.0, 0.0));
        }   
    }
}

SCENARIO("Vector arithmetic in-place", "[Vec3]")
{
    GIVEN("two vectors ") {
        Vec3 vecA(1.0, 2.0, 3.0);
        Vec3 vecB(2.0, 2.0, 2.0);

        WHEN("we add one to another in place") {
            vecA += vecB;
            THEN("the first one changes")
                REQUIRE(vecA == Vec3(3.0, 4.0, 5.0));
        }

        WHEN("we subtract one from another in place") {
            vecA -= vecB;
            THEN("the first one changes")
                REQUIRE(vecA == Vec3(-1.0, 0.0, 1.0));
        }

        WHEN("we multiply one by another in place") {
            vecA *= vecB;
            THEN("the first one changes")
                REQUIRE(vecA == Vec3(2.0, 4.0, 6.0));
        }

        WHEN("we divide one by another in place") {
            vecA /= vecB;
            THEN("the first one changes")
                REQUIRE(vecA == Vec3(0.5, 1.0, 1.5));
        }
    }

    GIVEN("a vector and a scalar ") {
        Vec3 vec(1.0, 2.0, 3.0);
        float scalar = 2.0;

        WHEN("we multiply the vector by the scalar in place") {
            vec *= scalar;
            THEN("the vector changes")
                REQUIRE(vec == Vec3(2.0, 4.0, 6.0));
        }

        WHEN("we divide the vector by the scalar in place") {
            vec /= scalar;
            THEN("the vector changes")
                REQUIRE(vec == Vec3(0.5, 1.0, 1.5));
        }
    }
}

SCENARIO("Vector arithmetic", "[Vec3]")
{
    GIVEN("two vectors ") {
        Vec3 vecA(1.0, 2.0, 3.0);
        Vec3 vecB(2.0, 2.0, 2.0);

        WHEN("") {
            Vec3 sum = vecA + vecB;
            THEN("we can add them")
                REQUIRE(sum == Vec3(3.0, 4.0, 5.0));
        }

        WHEN("") {
            Vec3 diff = vecA - vecB;
            THEN("we can subtract one from another")
                REQUIRE(diff == Vec3(-1.0, 0.0, 1.0));
        }

        WHEN("") {
            Vec3 product = vecA * vecB;
            THEN("we can multiply them element-wise")
                REQUIRE(product == Vec3(2.0, 4.0, 6.0));
        }

        WHEN("") {
            Vec3 ratio = vecA / vecB;
            THEN("we can divide one by another element-wise")
                REQUIRE(ratio == Vec3(0.5, 1.0, 1.5));
        }

        WHEN("") {
            float dot_product = dot(vecA,vecB);
            THEN("we can compute their dot product")
                REQUIRE(dot_product == 12.0_a);
        }
    }

    GIVEN("two vectors ") {
        Vec3 vecA(1.0, 0.0, 0.0);
        Vec3 vecB(0.0, 1.0, 0.0);

        WHEN("") {
            Vec3 cross_product = cross(vecA, vecB);
            THEN("we can compute their cross product")
                REQUIRE(cross_product == Vec3(0.0, 0.0, 1.0));
        }
    }

    GIVEN("a vector and a scalar ") {
        Vec3 vec(1.0, 2.0, 3.0);
        float scalar = 2.0;

        WHEN("") {
            Vec3 result = vec * scalar;
            THEN("we can multiply the vector by the scalar from the right")
                REQUIRE(result == Vec3(2.0, 4.0, 6.0));
        }

        WHEN("") {
            Vec3 result = scalar * vec;
            THEN("we can multiply the vector by the scalar from the left")
                REQUIRE(result == Vec3(2.0, 4.0, 6.0));
        }

        WHEN("") {
            Vec3 result = vec / scalar;
            THEN("we can divide the vector by the scalar")
                REQUIRE(result == Vec3(0.5, 1.0, 1.5));
        }
    }
}

SCENARIO("Vector linear interpolation", "[Vec3]")
{
    GIVEN("two vectors ") {
        Vec3 vecA(1.0, 0.0, 0.0);
        Vec3 vecB(0.0, 1.0, 0.0);

        WHEN("")
            THEN("we can blend them equally")
                REQUIRE(lerp(vecA,vecB, 0.5) == Vec3(0.5, 0.5, 0.0));

        WHEN("")
            THEN("we can lerp to the first one")
                REQUIRE(lerp(vecA, vecB, 0.0) == Vec3(1.0, 0.0, 0.0));

        WHEN("")
            THEN("we can lerp to the last one")
                REQUIRE(lerp(vecA, vecB, 1.0) == Vec3(0.0, 1.0, 0.0));
    }
}
