#include "catch2/catch_test_macros.hpp"
#include "queens.h"
#include <algorithm>

TEST_CASE("Validate Solutions") {
  std::vector<std::vector<std::vector<int64_t>>> solutions = {
      {{0}},                        // 1
      {},                           // 2
      {},                           // 3
      {{1, 3, 0, 2}, {2, 0, 3, 1}}, // 4
      {{0, 2, 4, 1, 3},
       {0, 3, 1, 4, 2},
       {1, 3, 0, 2, 4},
       {1, 4, 2, 0, 3},
       {2, 0, 3, 1, 4},
       {2, 4, 1, 3, 0},
       {3, 0, 2, 4, 1},
       {3, 1, 4, 2, 0},
       {4, 1, 3, 0, 2},
       {4, 2, 0, 3, 1}}, // 5
      {{1, 3, 5, 0, 2, 4},
       {2, 5, 1, 4, 0, 3},
       {3, 0, 4, 1, 5, 2},
       {4, 2, 0, 5, 3, 1}}, // 6
      {{0, 2, 4, 6, 1, 3, 5}, {0, 3, 6, 2, 5, 1, 4}, {0, 4, 1, 5, 2, 6, 3},
       {0, 5, 3, 1, 6, 4, 2}, {1, 3, 0, 6, 4, 2, 5}, {1, 3, 5, 0, 2, 4, 6},
       {1, 4, 0, 3, 6, 2, 5}, {1, 4, 2, 0, 6, 3, 5}, {1, 4, 6, 3, 0, 2, 5},
       {1, 5, 2, 6, 3, 0, 4}, {1, 6, 4, 2, 0, 5, 3}, {2, 0, 5, 1, 4, 6, 3},
       {2, 0, 5, 3, 1, 6, 4}, {2, 4, 6, 1, 3, 5, 0}, {2, 5, 1, 4, 0, 3, 6},
       {2, 6, 1, 3, 5, 0, 4}, {2, 6, 3, 0, 4, 1, 5}, {3, 0, 2, 5, 1, 6, 4},
       {3, 0, 4, 1, 5, 2, 6}, {3, 1, 6, 4, 2, 0, 5}, {3, 5, 0, 2, 4, 6, 1},
       {3, 6, 2, 5, 1, 4, 0}, {3, 6, 4, 1, 5, 0, 2}, {4, 0, 3, 6, 2, 5, 1},
       {4, 0, 5, 3, 1, 6, 2}, {4, 1, 5, 2, 6, 3, 0}, {4, 2, 0, 5, 3, 1, 6},
       {4, 6, 1, 3, 5, 0, 2}, {4, 6, 1, 5, 2, 0, 3}, {5, 0, 2, 4, 6, 1, 3},
       {5, 1, 4, 0, 3, 6, 2}, {5, 2, 0, 3, 6, 4, 1}, {5, 2, 4, 6, 0, 3, 1},
       {5, 2, 6, 3, 0, 4, 1}, {5, 3, 1, 6, 4, 2, 0}, {5, 3, 6, 0, 2, 4, 1},
       {6, 1, 3, 5, 0, 2, 4}, {6, 2, 5, 1, 4, 0, 3}, {6, 3, 0, 4, 1, 5, 2},
       {6, 4, 2, 0, 5, 3, 1}} // 7
  };

  for (int64_t i = 1; i <= std::ssize(solutions); ++i) {
    std::vector<int64_t> solution;
    if (solutions[i - 1].empty()) {
      REQUIRE(!solve(solution, i));
    } else {
      REQUIRE(solve(solution, i));
      REQUIRE(std::ranges::contains(solutions[i - 1], solution));
    }
  }
}