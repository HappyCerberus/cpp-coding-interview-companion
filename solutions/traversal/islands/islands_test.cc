#include "catch2/catch_test_macros.hpp"
#include "islands.h"

TEST_CASE("No islands") {
  std::vector<std::vector<char>> map1{
      {'L', 'L', 'L'},
      {'L', 'W', 'L'},
      {'L', 'L', 'L'},
  };
  REQUIRE(count_islands(map1) == 0);

  std::vector<std::vector<char>> map2{
      {'W', 'W', 'W', 'W', 'W'}, //
      {'W', 'L', 'L', 'L', 'W'}, //
      {'W', 'L', 'L', 'L', 'W'}, //
      {'W', 'L', 'L', 'L', 'L'}, //
      {'W', 'W', 'W', 'W', 'W'}, //
  };
  REQUIRE(count_islands(map2) == 0);
}

TEST_CASE("One island") {
  std::vector<std::vector<char>> map{
      {'W', 'W', 'W'},
      {'W', 'L', 'W'},
      {'W', 'W', 'W'},
  };
  REQUIRE(count_islands(map) == 1);
}

TEST_CASE("Complex case") {
  std::vector<std::vector<char>> map{
      {'L', 'W', 'W', 'L', 'L'}, //
      {'L', 'W', 'L', 'W', 'W'}, //
      {'W', 'L', 'W', 'L', 'W'}, //
      {'W', 'W', 'L', 'W', 'L'}, //
      {'L', 'L', 'W', 'W', 'L'}, //
  };
  assert(count_islands(map) == 4);
}