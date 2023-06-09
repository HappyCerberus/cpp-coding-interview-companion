#include "catch2/catch_test_macros.hpp"
#include "merge.h"

TEST_CASE("Empty lists") {
  auto t = std::vector<int>{};
  REQUIRE(std::ranges::equal(t, merge({{}})));
  REQUIRE(std::ranges::equal(t, merge({{}, {}})));
  REQUIRE(std::ranges::equal(t, merge({{}, {}, {}})));
  REQUIRE(std::ranges::equal(t, merge({{}, {}, {}, {}, {}})));
}

TEST_CASE("Single node lists") {
  auto t = {1, 2, 3};
  REQUIRE(std::ranges::equal(t, merge({{1}, {2}, {3}})));
  REQUIRE(std::ranges::equal(t, merge({{3}, {2}, {1}})));
}

TEST_CASE("Full range") {
  auto t = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  REQUIRE(std::ranges::equal(t, merge({{3, 4, 9}, {1, 5, 6, 7, 8}, {2}})));
}