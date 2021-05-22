#include "TestsUtils.h"

#include <sstream>

#include "Core/Image.h"

SCENARIO("Image tests", "[Image]")
{
	GIVEN("an image of height 1 and width 2") {
		Image image(1, 2);

		THEN("we can check its size") {
			REQUIRE(image.width() == 2);
			REQUIRE(image.height() == 1);
		}

		THEN("by default its pixels are all black") {
			REQUIRE(image(0, 0) == Color::black);
			REQUIRE(image(0, 1) == Color::black);
		}

		WHEN("we set pixel color") {
			image(0, 0) = Color::red;
			THEN("it changes")
				REQUIRE(image(0, 0) == Color::red);
		}

		WHEN("") {
			std::ostringstream oss;
			image.saveAsPPM(oss, Verbosity::none);
			THEN("we can save it in .ppm format")
				REQUIRE(oss.str() == "P3\n2 1\n255\n0 0 0\n0 0 0\n");
		}
	}

}