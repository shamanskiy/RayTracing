#include "TestsUtils.h"

#include "Materials/Diffusive.h"
#include "Core/Random.h"

SCENARIO("Diffusive material tests", "[Diffusive]") {
	GIVEN("a diffusive material") {
		Diffusive material(Color::red);
		Vec3 hitPoint(1.0, 1.0, 1.0);
		Vec3 hitNormal(1.0, 0.0, 0.0);
		HitRecord hit{0.0, hitPoint, hitNormal, &material};

		WHEN("we reflect any ray") {
			Ray ray;
			Random::get()->disable();
			auto reflection = material.reflectRay(ray, hit);
			Random::get()->enable();

			THEN("the result doesn't depend on the ray") {
				REQUIRE(reflection);
				REQUIRE(reflection->ray == Ray(hitPoint,hitNormal));
				REQUIRE(reflection->attenuation == Color::red);
			}
		}

		WHEN("we reflect any other ray") {
			Ray ray(hitPoint, Space3D::zAxis);
			Random::get()->disable();
			auto reflection = material.reflectRay(ray, hit);
			Random::get()->enable();

			THEN("we get the same result") {
				REQUIRE(reflection);
				REQUIRE(reflection->ray == Ray(hitPoint, hitNormal));
				REQUIRE(reflection->attenuation == Color::red);
			}
		}
	}
}