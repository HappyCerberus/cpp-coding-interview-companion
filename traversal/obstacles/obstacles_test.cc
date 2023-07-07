#include "catch2/catch_test_macros.hpp"
#include "obstacles.h"

TEST_CASE("No obstacles") {
  std::vector<std::vector<int>> t0{{0}};
  REQUIRE(shortest_path(t0, 0) == 0);

  std::vector<std::vector<int>> t1{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  REQUIRE(shortest_path(t1, 0) == 4);
  REQUIRE(shortest_path(t1, 1) == 4);

  std::vector<std::vector<int>> t2{{0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0}};
  REQUIRE(shortest_path(t2, 0) == 8);
  REQUIRE(shortest_path(t2, 1) == 8);
}

TEST_CASE("One wall") {
  std::vector<std::vector<int>> t{{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
  REQUIRE(shortest_path(t, 0) == -1);
  REQUIRE(shortest_path(t, 1) == 4);
  REQUIRE(shortest_path(t, 2) == 4);
}

TEST_CASE("Two walls") {
  std::vector<std::vector<int>> t{{0, 1, 0, 1, 0},
                                  {0, 1, 0, 1, 0},
                                  {0, 1, 0, 1, 0},
                                  {0, 1, 0, 1, 0},
                                  {0, 1, 0, 1, 0}};
  REQUIRE(shortest_path(t, 0) == -1);
  REQUIRE(shortest_path(t, 1) == -1);
  REQUIRE(shortest_path(t, 2) == 8);
  REQUIRE(shortest_path(t, 3) == 8);
}

TEST_CASE("Complex case") {
  std::vector<std::vector<int>> t{{0, 1, 0, 1, 0},
                                  {0, 1, 1, 1, 1},
                                  {0, 1, 0, 1, 0},
                                  {0, 1, 1, 1, 1},
                                  {0, 1, 0, 1, 0}};
  REQUIRE(shortest_path(t, 0) == -1);
  REQUIRE(shortest_path(t, 1) == -1);
  REQUIRE(shortest_path(t, 2) == 8);
  REQUIRE(shortest_path(t, 3) == 8);
}

TEST_CASE("Distance changes with k") {
  std::vector<std::vector<int>> t{
      {0, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 1, 1, 0},
      {0, 1, 1, 0, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 1, 0, 1, 1, 0},
      {0, 1, 1, 1, 1, 0, 1, 1, 0}, {0, 0, 0, 1, 1, 0, 1, 1, 0},
      {0, 0, 0, 0, 0, 0, 1, 1, 0}};
  REQUIRE(shortest_path(t, 0) == -1);
  REQUIRE(shortest_path(t, 1) == 30);
  REQUIRE(shortest_path(t, 2) == 14);
  REQUIRE(shortest_path(t, 3) == 14);
}