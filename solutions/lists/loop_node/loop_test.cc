#include "catch2/catch_test_macros.hpp"
#include "loop.h"

TEST_CASE("No loop") {
  List list;
  REQUIRE(loop_start(list) == nullptr);
  list.new_after(nullptr, 1);
  REQUIRE(loop_start(list) == nullptr);
  list.new_after(list.head, 2);
  REQUIRE(loop_start(list) == nullptr);
}

TEST_CASE("Single node") {
  List list;
  list.new_after(nullptr, 1);
  list.head->next = list.head;
  REQUIRE(loop_start(list) == list.head);
}

TEST_CASE("Two nodes") {
  List list;
  list.new_after(nullptr, 1);
  list.new_after(list.head, 2);
  list.head->next->next = list.head;
  REQUIRE(loop_start(list) == list.head);
}

TEST_CASE("Terminal self-loop") {
  List list;
  list.new_after(nullptr, 1);
  auto *it = list.new_after(list.head, 2);
  it = list.new_after(it, 3);
  it->next = it;
  REQUIRE(loop_start(list) == it);
}

TEST_CASE("Big loop") {
  List list;
  list.new_after(nullptr, 1);
  auto *it = list.new_after(list.head, 2);
  it = list.new_after(it, 3);
  auto *n = it;
  for (int i = 0; i < 9; ++i) {
    n = list.new_after(n, i + 4);
  }
  n->next = it;
  REQUIRE(loop_start(list) == it);
}