
#include "catch2/catch_test_macros.hpp"
#include "heightmap.h"

TEST_CASE("Simple cases") {
  REQUIRE(shortest_path({{1, 2}, {1, 1}}, {0, 0}, {1, 1}) == 4);
  REQUIRE(shortest_path({{1, 1}, {2, 1}}, {0, 0}, {1, 1}) == 4);
}

TEST_CASE("Slope") {
  REQUIRE(
      shortest_path(
          {{1, 1, 1, 1, 1}, {2, 2, 2, 2, 2}, {3, 3, 3, 3, 3}, {4, 4, 4, 4, 4}},
          {0, 0}, {3, 4}) == 20);
  REQUIRE(
      shortest_path(
          {{1, 1, 1, 1, 1}, {2, 2, 2, 2, 2}, {3, 3, 3, 3, 3}, {4, 4, 4, 4, 4}},
          {3, 4}, {0, 0}) == 11);
}

TEST_CASE("Bridge") {
  REQUIRE(shortest_path({{5, 4, 3, 4, 5},
                         {5, 4, 3, 4, 5},
                         {5, 5, 5, 5, 5},
                         {5, 4, 3, 4, 5},
                         {5, 4, 3, 4, 5}},
                        {0, 0}, {4, 4}) == 16);
}