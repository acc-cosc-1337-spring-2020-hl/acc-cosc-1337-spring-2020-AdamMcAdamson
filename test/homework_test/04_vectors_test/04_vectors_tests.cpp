#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "vectors.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test get_max_from_vector function")
{
	vector<int> nums1 = { 3,8,1,99,1000 };
	vector<int> nums2 = { 15,12,11,99,88 };
	vector<int> nums3 = { 150,120,11,990,88888 };

	REQUIRE(get_max_from_vector(nums1) == 1000);
	REQUIRE(get_max_from_vector(nums2) == 99);
	REQUIRE(get_max_from_vector(nums3) == 88888);
}

TEST_CASE("Test is_prime function")
{
	REQUIRE(is_prime(2) == true);
	REQUIRE(is_prime(4) == false);
	REQUIRE(is_prime(43) == true);
	REQUIRE(is_prime(44) == false);
	REQUIRE(is_prime(45) == false);
}

TEST_CASE("Test vector_of_primes function")
{
	vector<int> primes10 = { 2,3,5,7 };
	vector<int> primes50 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };

	REQUIRE(vector_of_primes(10) == primes10);
	REQUIRE(vector_of_primes(50) == primes50);
}
