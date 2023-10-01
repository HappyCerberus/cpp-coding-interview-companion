#include "bst_reorders.h"
#include "catch2/catch_test_macros.hpp"

TEST_CASE("Test for bst reorders.") {
  std::vector<int> t1{1};
  REQUIRE(number_of_reorders(t1) == 0);
  std::vector<int> t2{2, 3, 1};
  REQUIRE(number_of_reorders(t2) == 1);
  std::vector<int> t3{2, 1, 3};
  REQUIRE(number_of_reorders(t3) == 1);
  std::vector<int> t4{3, 1, 2};
  REQUIRE(number_of_reorders(t4) == 0);
  std::vector<int> t5{1, 2, 3, 4};
  REQUIRE(number_of_reorders(t5) == 0);
  std::vector<int> t6{8, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15};
  REQUIRE(number_of_reorders(t6) == 3431);
  std::vector<int> t7{8, 4, 1, 2, 3, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15};
  REQUIRE(number_of_reorders(t7) == 68639);
  std::vector<int> t8{8, 4, 1, 2, 3, 5, 6, 7, 12, 9, 10, 11, 13, 14, 15};
  REQUIRE(number_of_reorders(t8) == 1372799);
  std::vector<int> t9{8, 4, 2, 1, 3, 6, 5, 7, 12, 10, 9, 11, 14, 13, 15};
  REQUIRE(number_of_reorders(t9) == 21964799);
}