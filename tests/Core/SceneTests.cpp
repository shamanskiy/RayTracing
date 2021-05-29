#include "TestsUtils.h"

#include "Core/Scene.h"
#include "Objects/Sphere.h"
#include "Materials/Diffusive.h"

SCENARIO("Empty scene: ray hits the sky", "[Scene]")
{
	GIVEN("a scene with red-blue sky") {
		Scene scene;
		scene.setSkyGradient(Color::red, Color::blue);

		WHEN("we shoot an upward ray and it hits the sky") {
			Ray ray(Space3D::origin, Space3D::yAxis);
			Vec3 color = scene.testRay(ray,1);

			THEN("we should get the top color")
				REQUIRE(color == Color::blue);
		}

		WHEN("we shoot a downward ray and it hits the sky") {
			Ray ray(Space3D::origin, -Space3D::yAxis);
			Vec3 color = scene.testRay(ray,1);

			THEN("we should get the bottom color")
				REQUIRE(color == Color::red);
		}

		WHEN("we shoot a horizontal ray and it hits the sky") {
			Ray ray(Space3D::origin, Space3D::xAxis);
			Vec3 color = scene.testRay(ray,1);

			THEN("we should get a perfect blend")
				REQUIRE(color == lerp(Color::red, Color::blue, 0.5));
		}
	}
}

SCENARIO("Single sphere scene", "[Scene]")
{
	GIVEN("a scene with red sky and a blue-diffusive sphere") {
		Scene scene;
		Vec3 skyColor = Color::red;
		Vec3 sphereColor = Color::blue;
		scene.setSkyGradient(skyColor, skyColor);
		scene.addObject(std::make_unique<Sphere>(Vec3(0.0f,0.0f,-5.0f), 1.0f, std::make_unique<Diffusive>(sphereColor)));

		WHEN("we shoot a ray that misses the sphere") {
			Ray ray(Space3D::origin, Space3D::yAxis);
			Vec3 color = scene.testRay(ray, 1);

			THEN("we should get the sky color")
				REQUIRE(color == skyColor);
		}

		WHEN("we shoot a ray at the sphere") {
			Ray ray(Space3D::origin, -Space3D::zAxis);
			Vec3 color = scene.testRay(ray, 1);

			THEN("we get sky color times sphere color")
				REQUIRE(color == skyColor * sphereColor);
		}

		WHEN("we shoot a ray at the sphere with 0 reflections") {
			Ray ray(Space3D::origin, -Space3D::zAxis);
			Vec3 color = scene.testRay(ray, 0);

			THEN("we get blackcolor")
				REQUIRE(color == Color::black);
		}
	}
}