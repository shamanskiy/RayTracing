#include "TestsUtils.h"

#include "Materials/Reflective.h"

SCENARIO("Reflective material tests", "[Reflective]") {
	GIVEN("a reflective material") {
		Reflective material(Color::gold, 0.0);
		Vec3 hitPoint(0.0, 0.0, 0.0);
		Vec3 hitNormal(0.0, 0.0, 1.0);
		HitRecord hit{ 0.0, hitPoint, hitNormal, &material };

		WHEN("we reflect a ray") {
			Ray ray(Vec3(3.0, 0.0, 4.0), Vec3(-3.0, 0.0, -4.0));

			auto reflection = material.processRay(ray, hit);
			
			THEN("") {
				REQUIRE(reflection);
				REQUIRE(reflection->ray == Ray(hitPoint, Vec3(-3.0,0.0,4.0)));
				REQUIRE(reflection->attenuation == Color::gold);
			}
		}

	}
}