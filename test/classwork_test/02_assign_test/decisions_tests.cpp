#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "loops.h"
#include "decision.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify gross_pay function") {
	REQUIRE(gross_pay(40, 10) == 400);
	REQUIRE(gross_pay(50, 10) == 550);
	REQUIRE(gross_pay(20.5, 20.5) == 420.25);
}