#include "catch2/catch_test_macros.hpp"
#include "well_behaved.h"

TEST_CASE("Test for well behaved paths.") {
  REQUIRE(well_behaved_paths({1}, {}) == 1);
  REQUIRE(well_behaved_paths({1, 1}, {{0, 1}}) == 3);
  REQUIRE(well_behaved_paths({1, 1, 1}, {{0, 1}, {1, 2}}) == 6);
  REQUIRE(well_behaved_paths({1, 0, 1, 0, 1},
                             {{0, 1}, {1, 2}, {2, 3}, {3, 4}}) == 8);
  REQUIRE(well_behaved_paths({1, 0, 5, 0, 1},
                             {{0, 1}, {1, 2}, {2, 3}, {3, 4}}) == 5);
  REQUIRE(
      well_behaved_paths(
          {1, 1, 1, 1, 1, 1, 1, 1, 1},
          {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 6}, {2, 7}, {2, 8}}) ==
      45);
  REQUIRE(well_behaved_paths({0, 3, 1, 2, 3},
                             {{0, 1}, {0, 2}, {0, 3}, {3, 4}}) == 6);
}