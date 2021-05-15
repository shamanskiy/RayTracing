#include "catch_utils.hpp"

#include "Utils/ProgressBar.h"

#include <sstream>

SCENARIO("Progress bar tests", "[ProgressBar]")
{
	GIVEN("A width-3 progress bar for 3 steps")
	{
		ProgressBar bar(3, 3);

		WHEN("we do one step")
		{
			std::ostringstream oss;
			bar.displayNext(oss);

			THEN("")
				REQUIRE(oss.str() == "[=> ]\r");
		}

		WHEN("we do two steps")
		{
			std::ostringstream oss;
			for (int i = 0; i < 2; i++)
				bar.displayNext(oss);

			THEN("")
				REQUIRE(oss.str() == "[=> ]\r[==>]\r");
		}

		WHEN("we do three steps")
		{
			std::ostringstream oss;
			for (int i = 0; i < 3; i++)
				bar.displayNext(oss);

			THEN("")
				REQUIRE(oss.str() == "[=> ]\r[==>]\r[===]\n");
		}
	}

	GIVEN("A width-2 progress bar for 4 steps")
	{
		ProgressBar bar(4, 2);

		WHEN("we do one step")
		{
			std::ostringstream oss;
			bar.displayNext(oss);

			THEN("")
				REQUIRE(oss.str() == "[> ]\r");
		}

		WHEN("we do two steps")
		{
			std::ostringstream oss;
			for (int i = 0; i < 2; i++)
				bar.displayNext(oss);

			THEN("")
				REQUIRE(oss.str() == "[> ]\r[=>]\r");
		}

		WHEN("we do three steps")
		{
			std::ostringstream oss;
			for (int i = 0; i < 3; i++)
				bar.displayNext(oss);

			THEN("")
				REQUIRE(oss.str() == "[> ]\r[=>]\r");
		}

		WHEN("we do four steps")
		{
			std::ostringstream oss;
			for (int i = 0; i < 4; i++)
				bar.displayNext(oss);

			THEN("")
				REQUIRE(oss.str() == "[> ]\r[=>]\r[==]\n");
		}
	}
}