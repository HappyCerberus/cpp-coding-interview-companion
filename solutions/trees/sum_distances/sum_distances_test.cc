#include "catch2/catch_test_macros.hpp"
#include "sum_distances.h"

TEST_CASE("Test for the sum of distances problem.") {
  {
    std::unordered_multimap<int, int> neighbours;
    std::vector<int> expected_result = {0};
    REQUIRE(distances_in_tree(1, neighbours) == expected_result);
  }
  {
    std::unordered_multimap<int, int> neighbours = {{0, 1}, {1, 0}};
    std::vector<int> expected_result = {1, 1};
    REQUIRE(distances_in_tree(2, neighbours) == expected_result);
  }
  {
    std::unordered_multimap<int, int> neighbours = {
        {0, 1}, {1, 0}, {1, 2}, {2, 1}};
    std::vector<int> expected_result = {3, 2, 3};
    REQUIRE(distances_in_tree(3, neighbours) == expected_result);
  }
  {
    std::unordered_multimap<int, int> neighbours = {{0, 1}, {1, 0}, {0, 2},
                                                    {2, 0}, {0, 3}, {3, 0}};
    std::vector<int> expected_result = {3, 5, 5, 5};
    REQUIRE(distances_in_tree(4, neighbours) == expected_result);
  }
  {
    std::unordered_multimap<int, int> neighbours = {
        {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 3}, {3, 2}, {3, 4}, {4, 3}};
    std::vector<int> expected_result = {10, 7, 6, 7, 10};
    REQUIRE(distances_in_tree(5, neighbours) == expected_result);
  }
  {
    std::unordered_multimap<int, int> neighbours = {
        {0, 1}, {1, 0}, {0, 2}, {2, 0}, {1, 3}, {3, 1}, {1, 4}, {4, 1}};
    std::vector<int> expected_result = {6, 5, 9, 8, 8};
    REQUIRE(distances_in_tree(5, neighbours) == expected_result);
  }
}