#include "catch2/catch_test_macros.hpp"
#include "trees/construct_bst.h"
#include "validate_bst.h"

TEST_CASE("Valid BST") {
  auto t1 = Tree::construct_bst({1});
  REQUIRE(is_valid_bst(t1));

  auto t2 = Tree::construct_bst({1, 2, 3});
  REQUIRE(is_valid_bst(t2));

  auto t3 = Tree::construct_bst({3, 2, 1});
  REQUIRE(is_valid_bst(t3));

  auto t4 = Tree::construct_bst({2, 3, 1});
  REQUIRE(is_valid_bst(t4));

  auto t5 = Tree::construct_bst({INT_MAX, INT_MIN});
  REQUIRE(is_valid_bst(t5));

  auto t6 = Tree::construct_bst({INT_MIN, INT_MAX});
  REQUIRE(is_valid_bst(t6));

  auto t7 = Tree::construct_bst({0, INT_MAX, INT_MIN});
  REQUIRE(is_valid_bst(t7));
}

TEST_CASE("Invalid BST") {
  auto t1 = Tree::construct_bst({2, 1, 3});
  t1.root->left->value = 3;
  REQUIRE(not is_valid_bst(t1));

  t1.root->left->value = 1;
  t1.root->value = -1;
  REQUIRE(not is_valid_bst(t1));

  t1.root->value = 2;
  t1.root->right->value = 1;
  REQUIRE(not is_valid_bst(t1));
}

TEST_CASE("One BST") {
  Tree::Tree t1;
  t1.root = t1.add(0);
  REQUIRE(is_valid_bst(t1));

  t1.root->left = t1.add(-1);
  t1.root->right = t1.add(1);
  REQUIRE(is_valid_bst(t1));

  t1.root->left->left = t1.add(-1);
  REQUIRE(not is_valid_bst(t1));

  t1.root->left->left->value = -2;
  REQUIRE(is_valid_bst(t1));

  t1.root->right->right = t1.add(INT_MAX);
  REQUIRE(is_valid_bst(t1));

  t1.root->right->right->right = t1.add(INT_MAX);
  REQUIRE(not is_valid_bst(t1));
}