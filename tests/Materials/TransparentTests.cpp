#include "TestsUtils.h"

#include "Materials/Transparent.h"

TEST_CASE("Transparent material: test 1", "[Transparent]") {
	Transparent material(Color::white, 1.0);
	Vec3 hitPoint(0.0, 0.0, 0.0);
	Vec3 hitNormal(0.0, 0.0, 1.0);
	HitRecord hit{ 0.0, hitPoint, hitNormal, &material };

	Ray ray(Vec3(3.0, 0.0, 3.0), Vec3(-3.0, 0.0, -3.0));
	auto reflection = material.processRay(ray, hit);

	REQUIRE(reflection);
	REQUIRE(reflection->ray == Ray(hitPoint, Vec3(-3.0, 0.0, -3.0)));
	REQUIRE(reflection->attenuation == Color::white);
}