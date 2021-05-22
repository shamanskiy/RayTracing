#include "TestsUtils.h"

#include "Core/Scene.h"

SCENARIO("Empty scene: ray hits the sky", "[Scene]")
{
	GIVEN("a scene with red-blue sky") {
		Scene scene;
		scene.setSkyGradient(Color::red, Color::blue);

		WHEN("we shoot an upward ray and it hits the sky") {
			Ray ray(Space3D::origin, Space3D::yAxis);
			Vec3 color = scene.testRay(ray);

			THEN("we should get the top color")
				REQUIRE(color == Color::blue);
		}

		WHEN("we shoot a downward ray and it hits the sky") {
			Ray ray(Space3D::origin, -Space3D::yAxis);
			Vec3 color = scene.testRay(ray);

			THEN("we should get the bottom color")
				REQUIRE(color == Color::red);
		}

		WHEN("we shoot a horizontal ray and it hits the sky") {
			Ray ray(Space3D::origin, Space3D::xAxis);
			Vec3 color = scene.testRay(ray);

			THEN("we should get a perfect blend")
				REQUIRE(color == lerp(Color::red, Color::blue, 0.5));
		}
	}

}