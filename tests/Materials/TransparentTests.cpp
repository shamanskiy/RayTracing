#include "TestsUtils.h"

#include "Materials/Transparent.h"
#include "Core/Random.h"

TEST_CASE("Transparent material: ray from outside", "[Transparent]") {
	Transparent material(Color::white, sqrt(2));
	Vec3 hitPoint(0.0, 0.0, 0.0);
	Vec3 hitNormal(0.0, 0.0, 1.0);
	HitRecord hit{ 0.0, hitPoint, hitNormal, &material };

	Ray ray(Vec3(3.0, 0.0, 3.0), Vec3(-3.0, 0.0, -3.0));
	Random::get()->enable();
	auto reflection = material.reflectRay(ray, hit);
	Random::get()->disable();

	REQUIRE(reflection);
	REQUIRE(reflection->ray == Ray(hitPoint, Vec3(-1.0/2, 0.0, -sqrt(3)/2)));
	REQUIRE(reflection->attenuation == Color::white);
}

TEST_CASE("Transparent material: ray from inside ", "[Transparent]") {
	Transparent material(Color::white, sqrt(2));
	Vec3 hitPoint(0.0, 0.0, 0.0);
	Vec3 hitNormal(0.0, 0.0, 1.0);
	HitRecord hit{ 0.0, hitPoint, hitNormal, &material };

	Ray ray(Vec3(1.0 / 2, 0.0, -sqrt(3) / 2), Vec3(-1.0 / 2, 0.0, sqrt(3) / 2));
	Random::get()->disable();
	auto reflection = material.reflectRay(ray, hit);
	Random::get()->enable();

	REQUIRE(reflection);
	REQUIRE(reflection->ray == Ray(hitPoint, Vec3(-sqrt(2) / 2, 0.0, sqrt(2) / 2)));
	REQUIRE(reflection->attenuation == Color::white);
}

TEST_CASE("Transparent material: ray from inside at large angle -> internal reflection", "[Transparent]") {
	Transparent material(Color::white, sqrt(2));
	Vec3 hitPoint(0.0, 0.0, 0.0);
	Vec3 hitNormal(0.0, 0.0, 1.0);
	HitRecord hit{ 0.0, hitPoint, hitNormal, &material };

	Ray ray(Vec3(1.0, 0.0, -0.1), Vec3(-1.0, 0.0, 0.1));
	auto reflection = material.reflectRay(ray, hit);

	REQUIRE(reflection);
	REQUIRE(reflection->ray == Ray(hitPoint, Vec3(-1.0,0.0,-0.1)));
	REQUIRE(reflection->attenuation == Color::white);
}