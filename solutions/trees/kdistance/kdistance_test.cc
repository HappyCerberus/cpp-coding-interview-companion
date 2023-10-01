#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_vector.hpp"
#include "kdistance.h"

TEST_CASE("Test for kdistance problem.") {
  using Catch::Matchers::UnorderedEquals;
  Tree::Tree tree;
  auto *n0 = tree.add(0);

  std::vector<int> result;
  REQUIRE_THAT(find_distance_k_nodes(n0, n0, 1), UnorderedEquals(result));
  result = {0};
  REQUIRE_THAT(find_distance_k_nodes(n0, n0, 0), UnorderedEquals(result));

  auto *n1 = tree.add(1);
  auto *n2 = tree.add(2);
  n0->left = n1;
  n0->right = n2;

  result = {1, 2};
  REQUIRE_THAT(find_distance_k_nodes(n0, n0, 1), UnorderedEquals(result));

  auto *n3 = tree.add(3);
  auto *n4 = tree.add(4);
  auto *n5 = tree.add(5);
  n1->left = n3;
  n1->right = n4;
  n2->right = n5;

  result = {1, 2};
  REQUIRE_THAT(find_distance_k_nodes(n0, n0, 1), UnorderedEquals(result));
  result = {3, 4, 5};
  REQUIRE_THAT(find_distance_k_nodes(n0, n0, 2), UnorderedEquals(result));
  result = {3, 0};
  REQUIRE_THAT(find_distance_k_nodes(n0, n4, 2), UnorderedEquals(result));

  auto *n6 = tree.add(6);
  auto *n7 = tree.add(7);
  auto *n8 = tree.add(8);
  auto *n9 = tree.add(9);
  n3->left = n6;
  n4->left = n7;
  n4->right = n8;
  n5->right = n9;

  result = {6, 7, 8};
  REQUIRE_THAT(find_distance_k_nodes(n0, n9, 6), UnorderedEquals(result));
  result = {1, 7};
  REQUIRE_THAT(find_distance_k_nodes(n0, n8, 2), UnorderedEquals(result));
  result = {2, 6};
  REQUIRE_THAT(find_distance_k_nodes(n0, n7, 4), UnorderedEquals(result));
}
