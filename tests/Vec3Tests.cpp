#include <sstream>

#include "gtest/gtest.h"

#include "Vec3.h"

using namespace std;
TEST(Vec3Test, vec000_len0)
{
    Vec3 vec;
    ASSERT_FLOAT_EQ(vec.length(), 0.0f);
}

TEST(Vec3Test, vec340_len5)
{
    Vec3 vec(3.0f, 4.0f, 0.0f);
    ASSERT_FLOAT_EQ(vec.length(), 5.0f);
}

TEST(Vec3Test, vec340_sqlen25)
{
    Vec3 vec(3.0f, 4.0f, 0.0f);
    ASSERT_FLOAT_EQ(vec.length_sq(), 25.0f);
}

TEST(Vec3Test, vec_xyz)
{
    Vec3 vec(3.0f, 4.0f, 0.0f);

    ASSERT_FLOAT_EQ(vec.x(), 3.0f);
    ASSERT_FLOAT_EQ(vec.y(), 4.0f);
    ASSERT_FLOAT_EQ(vec.z(), 0.0f);
}

TEST(Vec3Test, vec_rgb)
{
    Vec3 vec(3.0f, 4.0f, 0.0f);

    ASSERT_FLOAT_EQ(vec.r(), 3.0f);
    ASSERT_FLOAT_EQ(vec.g(), 4.0f);
    ASSERT_FLOAT_EQ(vec.b(), 0.0f);
}

TEST(Vec3Test, vec_brackets)
{
    Vec3 vec;

    vec[0] = 1.0f;
    vec[1] = 2.0f;
    vec[2] = 3.0f;

    ASSERT_FLOAT_EQ(vec[0], 1.0f);
    ASSERT_FLOAT_EQ(vec[1], 2.0f);
    ASSERT_FLOAT_EQ(vec[2], 3.0f);
}

TEST(Vec3Test, vec_ostream)
{
    Vec3 vec(3.0f, 4.0f, 0.0f);

    ostringstream stream;
    stream << vec;

    ASSERT_STREQ(stream.str().c_str(), "3 4 0");
}

TEST(Vec3Test, vec_minus)
{
    Vec3 vec(3.0f, 4.0f, 0.0f);
    
    Vec3 minus_vec = -vec;

    ASSERT_FLOAT_EQ(minus_vec.x(), -3.0f);
    ASSERT_FLOAT_EQ(minus_vec.y(), -4.0f);
    ASSERT_FLOAT_EQ(minus_vec.z(), 0.0f);
}

TEST(Vec3Test, vec_plus_eq)
{
    Vec3 vec;

    vec += Vec3(1.0f, 2.0f, 3.0f);

    ASSERT_FLOAT_EQ(vec.x(), 1.0f);
    ASSERT_FLOAT_EQ(vec.y(), 2.0f);
    ASSERT_FLOAT_EQ(vec.z(), 3.0f);
}

TEST(Vec3Test, vec_minus_eq)
{
    Vec3 vec;

    vec -= Vec3(1.0f, 2.0f, 3.0f);

    ASSERT_FLOAT_EQ(vec.x(), -1.0f);
    ASSERT_FLOAT_EQ(vec.y(), -2.0f);
    ASSERT_FLOAT_EQ(vec.z(), -3.0f);
}

TEST(Vec3Test, vec_vec_mult_eq)
{
    Vec3 vecA(1.0f,2.0f,3.0f);
    Vec3 vecB(2.0f, 2.0f, 2.0f);

    vecA *= vecB;

    ASSERT_FLOAT_EQ(vecA.x(), 2.0f);
    ASSERT_FLOAT_EQ(vecA.y(), 4.0f);
    ASSERT_FLOAT_EQ(vecA.z(), 6.0f);
}

TEST(Vec3Test, vec_vec_div_eq)
{
    Vec3 vecA(1.0f, 2.0f, 3.0f);
    Vec3 vecB(2.0f, 2.0f, 2.0f);

    vecA /= vecB;

    ASSERT_FLOAT_EQ(vecA.x(), 0.5f);
    ASSERT_FLOAT_EQ(vecA.y(), 1.0f);
    ASSERT_FLOAT_EQ(vecA.z(), 1.5f);
}

TEST(Vec3Test, vec_scalar_mult_eq)
{
    Vec3 vec(1.0f, 2.0f, 3.0f);

    vec *= 2;

    ASSERT_FLOAT_EQ(vec.x(), 2.0f);
    ASSERT_FLOAT_EQ(vec.y(), 4.0f);
    ASSERT_FLOAT_EQ(vec.z(), 6.0f);
}

TEST(Vec3Test, vec_scalar_div_eq)
{
    Vec3 vec(1.0f, 2.0f, 3.0f);

    vec /= 2;

    ASSERT_FLOAT_EQ(vec.x(), 0.5f);
    ASSERT_FLOAT_EQ(vec.y(), 1.0f);
    ASSERT_FLOAT_EQ(vec.z(), 1.5f);
}

TEST(Vec3Test, vec_normalize_inplace)
{
    Vec3 vec(1.0f, 2.0f, 3.0f);

    vec.normalize_inplace();

    ASSERT_FLOAT_EQ(vec.length(), 1.0f);
}

TEST(Vec3Test, vec_vec_plus)
{
    Vec3 vecA(1.0f, 2.0f, 3.0f);
    Vec3 vecB(2.0f, 2.0f, 2.0f);

    Vec3 sum = vecA + vecB;

    ASSERT_FLOAT_EQ(sum.x(), 3.0f);
    ASSERT_FLOAT_EQ(sum.y(), 4.0f);
    ASSERT_FLOAT_EQ(sum.z(), 5.0f);
}

TEST(Vec3Test, vec_vec_minus)
{
    Vec3 vecA(1.0f, 2.0f, 3.0f);
    Vec3 vecB(2.0f, 2.0f, 2.0f);

    Vec3 diff = vecA - vecB;

    ASSERT_FLOAT_EQ(diff.x(), -1.0f);
    ASSERT_FLOAT_EQ(diff.y(), 0.0f);
    ASSERT_FLOAT_EQ(diff.z(), 1.0f);
}

TEST(Vec3Test, vec_vec_mult)
{
    Vec3 vecA(1.0f, 2.0f, 3.0f);
    Vec3 vecB(2.0f, 2.0f, 2.0f);

    Vec3 mult = vecA * vecB;

    ASSERT_FLOAT_EQ(mult.x(), 2.0f);
    ASSERT_FLOAT_EQ(mult.y(), 4.0f);
    ASSERT_FLOAT_EQ(mult.z(), 6.0f);
}

TEST(Vec3Test, vec_vec_div)
{
    Vec3 vecA(1.0f, 2.0f, 3.0f);
    Vec3 vecB(2.0f, 2.0f, 2.0f);

    Vec3 div = vecA / vecB;

    ASSERT_FLOAT_EQ(div.x(), 0.5f);
    ASSERT_FLOAT_EQ(div.y(), 1.0f);
    ASSERT_FLOAT_EQ(div.z(), 1.5f);
}

TEST(Vec3Test, vec_float_mult)
{
    Vec3 vec(1.0f, 2.0f, 3.0f);

    vec = vec * 2;

    ASSERT_FLOAT_EQ(vec.x(), 2.0f);
    ASSERT_FLOAT_EQ(vec.y(), 4.0f);
    ASSERT_FLOAT_EQ(vec.z(), 6.0f);
}

TEST(Vec3Test, float_vec_mult)
{
    Vec3 vec(1.0f, 2.0f, 3.0f);

    vec = 2 * vec;

    ASSERT_FLOAT_EQ(vec.x(), 2.0f);
    ASSERT_FLOAT_EQ(vec.y(), 4.0f);
    ASSERT_FLOAT_EQ(vec.z(), 6.0f);
}

TEST(Vec3Test, vec_normalize)
{
    Vec3 vec(1.0f, 2.0f, 3.0f);

    Vec3 unit_vec = vec.normalize();

    ASSERT_FLOAT_EQ(unit_vec.length(), 1.0f);
}

TEST(Vec3Test, vec_vec_dot)
{
    Vec3 vecA(1.0f, 2.0f, 3.0f);
    Vec3 vecB(2.0f, 2.0f, 2.0f);

    ASSERT_FLOAT_EQ(dot(vecA,vecB), 12.0f);
}

TEST(Vec3Test, vec_vec_cross)
{
    Vec3 vecA(1.0f, 0.0f, 0.0f);
    Vec3 vecB(0.0f, 1.0f, 0.0f);

    Vec3 vecC = cross(vecA, vecB);

    ASSERT_FLOAT_EQ(vecC.x(), 0.0f);
    ASSERT_FLOAT_EQ(vecC.y(), 0.0f);
    ASSERT_FLOAT_EQ(vecC.z(), 1.0f);
}




