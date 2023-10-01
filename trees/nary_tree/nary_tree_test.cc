#include "catch2/catch_test_macros.hpp"
#include "nary_tree.h"

TEST_CASE("Empty Tree") {
  std::stringstream s;
  Tree src;
  s << src;
  s.seekg(0);
  Tree dst;
  s >> dst;

  REQUIRE(src == dst);
}

TEST_CASE("Relatively flat") {
  Tree src;
  Node *n1 = src.add_node(15, nullptr);

  src.add_node(9, n1);
  Node *n2 = src.add_node(7, n1);
  Node *n3 = src.add_node(2, n1);

  src.add_node(0, n2);
  src.add_node(99, n2);
  src.add_node(1, n2);
  src.add_node(1, n2);
  src.add_node(1, n2);
  src.add_node(1, n2);
  src.add_node(1, n2);
  src.add_node(22, n2);

  src.add_node(42, n3);

  std::stringstream s;
  s << src; // serialize
  s.seekg(0);
  Tree dst;
  s >> dst; // deserialize

  REQUIRE(src == dst);
}

TEST_CASE("Deep tree") {
  Tree src;

  Node *n1 = src.add_node(1, nullptr);
  src.add_node(2, n1);
  Node *n3 = src.add_node(3, n1);
  Node *n4 = src.add_node(4, n1);
  Node *n5 = src.add_node(5, n1);
  src.add_node(6, n3);
  Node *n7 = src.add_node(7, n3);
  Node *n8 = src.add_node(8, n4);
  Node *n9 = src.add_node(9, n5);
  src.add_node(10, n5);
  Node *n11 = src.add_node(11, n7);
  src.add_node(12, n8);
  src.add_node(13, n9);
  src.add_node(14, n11);

  std::stringstream s;
  s << src;
  s.seekg(0);
  Tree dst;
  s >> dst;

  REQUIRE(src == dst);
}