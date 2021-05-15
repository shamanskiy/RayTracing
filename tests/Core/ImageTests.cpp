#include "TestsUtils.h"

#include "Core/Image.h"

SCENARIO("Image tests", "[Image]")
{
	GIVEN("an image of height 100 and width 200") {
		Image image(100, 200);

		THEN("we can check its size") {
			REQUIRE(image.width() == 200);
			REQUIRE(image.height() == 100);
		}

		THEN("by default its pixels are all black") {
			REQUIRE(image(0,0) == Vec3());
			REQUIRE(image(99, 199) == Vec3());
		}

		WHEN("we set pixel color") {
			image(0, 0) = Vec3(1.0, 0.0, 0.0);
			THEN("it changes")
				REQUIRE(image(0, 0) == Vec3(1.0, 0.0, 0.0));
		}
	}

}