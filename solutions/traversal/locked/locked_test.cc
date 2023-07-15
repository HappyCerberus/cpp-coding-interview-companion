#include "catch2/catch_test_macros.hpp"
#include "locked.h"
#include <algorithm>

TEST_CASE("Positive cases") {
  REQUIRE(locked_rooms({{1}, {2}, {3}, {}}));
  REQUIRE(locked_rooms({{}}));
  REQUIRE(locked_rooms({{0, 1, 2, 3, 4},
                        {0, 1, 2, 3, 4},
                        {0, 1, 2, 3, 4},
                        {0, 1, 2, 3, 4},
                        {0, 1, 2, 3, 4}}));
}

TEST_CASE("Negative cases") {
  REQUIRE(not locked_rooms({{1}, {3, 1}, {2}, {0}}));
  REQUIRE(not locked_rooms({{}, {}, {}}));
}