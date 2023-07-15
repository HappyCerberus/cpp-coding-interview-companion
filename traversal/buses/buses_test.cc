#include "buses.h"
#include "catch2/catch_test_macros.hpp"

TEST_CASE("Linear connections") {
  std::vector<std::vector<int>> routes = {{1, 2, 3}, {3, 4, 5}, {5, 6, 7}};
  REQUIRE(min_tickets(routes, 3, 3) == 0);
  REQUIRE(min_tickets(routes, 1, 3) == 1);
  REQUIRE(min_tickets(routes, 1, 5) == 2);
  REQUIRE(min_tickets(routes, 1, 9) == -1);
  REQUIRE(min_tickets(routes, 1, 10) == -1);
}

TEST_CASE("Empty connections") {
  std::vector<std::vector<int>> routes = {};
  REQUIRE(min_tickets(routes, 1, 2) == -1);
}

TEST_CASE("Complex example") {
  std::vector<std::vector<int>> routes = {
      {1, 2, 3, 4}, {2, 6, 10, 14}, {3, 6, 13}, {4, 8, 12, 16},
      {5, 9, 13},   {7, 11, 15},    {14, 15}};
  REQUIRE(min_tickets(routes, 1, 7) == 4);
  REQUIRE(min_tickets(routes, 1, 16) == 2);
  REQUIRE(min_tickets(routes, 5, 7) == 5);
}