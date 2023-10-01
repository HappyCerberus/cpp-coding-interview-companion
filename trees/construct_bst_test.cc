#include "catch2/catch_test_macros.hpp"
#include "construct_bst.h"

TEST_CASE("Balanced tree") {
  auto t1 = Tree::construct_bst({1});
  REQUIRE(t1.root->value == 1);

  auto t2 = Tree::construct_bst({2, 1, 3});
  REQUIRE(t2.root->value == 2);
  REQUIRE(t2.root->left->value == 1);
  REQUIRE(t2.root->right->value == 3);
}

TEST_CASE("Unballanced tree") {
  auto t1 = Tree::construct_bst({1, 2, 3});
  REQUIRE(t1.root->value == 1);
  REQUIRE(t1.root->right->value == 2);
  REQUIRE(t1.root->right->right->value == 3);

  auto t2 = Tree::construct_bst({3, 2, 1});
  REQUIRE(t2.root->value == 3);
  REQUIRE(t2.root->left->value == 2);
  REQUIRE(t2.root->left->left->value == 1);
}