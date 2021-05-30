#include "TestsUtils.h"

#include "Core/Random.h"

TEST_CASE("Random number from 0 to 1", "[Random]")
{
	for (int i = 0; i < 10; i++)
	{
		float randomNumber = Random::get()->real01();
		REQUIRE(randomNumber >= 0.0);
		REQUIRE(randomNumber < 1.0);
	}
}

TEST_CASE("Random Vec3 in unit cube", "[Random]")
{
	for (int i = 0; i < 10; i++)
	{
		Vec3 randomVector = Random::get()->vec01();
		REQUIRE(randomVector[0] >= 0.0);
		REQUIRE(randomVector[1] >= 0.0);
		REQUIRE(randomVector[2] >= 0.0);
		REQUIRE(randomVector[0] < 1.0);
		REQUIRE(randomVector[1] < 1.0);
		REQUIRE(randomVector[2] < 1.0);
	}
}

TEST_CASE("Random Vec3 in unit sphere", "[Random]")
{
	for (int i = 0; i < 10; i++)
	{
		Vec3 randomVector = Random::get()->vecUnitSphere();
		REQUIRE(randomVector.length_sq() < 1.0);
	}
}

TEST_CASE("Disable random: single number", "[Random]")
{
	Random::get()->disable();
	for (int i = 0; i < 10; i++)
	{
		float randomNumber = Random::get()->real01();
		REQUIRE(randomNumber == 0.0_a);
	}
	Random::get()->enable();
}

TEST_CASE("Disable random: vector", "[Random]")
{
	Random::get()->disable();
	for (int i = 0; i < 10; i++)
	{
		Vec3 randomVector = Random::get()->vec01();
		REQUIRE(randomVector == Vec3());
	}
	Random::get()->enable();
}

TEST_CASE("Disable random: vector in unit sphere", "[Random]")
{
	Random::get()->disable();
	for (int i = 0; i < 10; i++)
	{
		Vec3 randomVector = Random::get()->vecUnitSphere();
		REQUIRE(randomVector == Vec3());
	}
	Random::get()->enable();
}

TEST_CASE("Disable random: vector in unit disk", "[Random]")
{
    Random::get()->disable();
    for (int i = 0; i < 10; i++)
    {
        Vec3 randomVector = Random::get()->vecUnitDisk();
        REQUIRE(randomVector == Vec3());
    }
    Random::get()->enable();
}