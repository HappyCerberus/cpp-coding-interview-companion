#include "catch2/catch_test_macros.hpp"
#include "kgroups.h"

TEST_CASE("Empty list") {
  List list;
  reverse_groups(list, 2);
  REQUIRE(list.head == nullptr);
}

TEST_CASE("Single node list") {
  List list;
  list.new_after(nullptr, 1);
  reverse_groups(list, 2);
  REQUIRE(list.head->value == 1);
  REQUIRE(list.head->next == nullptr);
}

TEST_CASE("Two node list") {
  List list;
  list.new_after(nullptr, 1);
  list.new_after(list.head, 2);
  reverse_groups(list, 2);
  REQUIRE(list.head->value == 2);
  REQUIRE(list.head->next->value == 1);
  REQUIRE(list.head->next->next == nullptr);
}

TEST_CASE("Five node list, k==2") {
  List list;
  list.new_after(nullptr, 1);
  list.new_after(list.head, 2);
  list.new_after(list.head->next, 3);
  list.new_after(list.head->next->next, 4);
  list.new_after(list.head->next->next->next, 5);
  reverse_groups(list, 2);
  REQUIRE(list.head->value == 2);
  REQUIRE(list.head->next->value == 1);
  REQUIRE(list.head->next->next->value == 4);
  REQUIRE(list.head->next->next->next->value == 3);
  REQUIRE(list.head->next->next->next->next->value == 5);
  REQUIRE(list.head->next->next->next->next->next == nullptr);
}

TEST_CASE("Five node list, k==1") {
  List list;
  list.new_after(nullptr, 1);
  list.new_after(list.head, 2);
  list.new_after(list.head->next, 3);
  list.new_after(list.head->next->next, 4);
  list.new_after(list.head->next->next->next, 5);
  reverse_groups(list, 1);
  REQUIRE(list.head->value == 1);
  REQUIRE(list.head->next->value == 2);
  REQUIRE(list.head->next->next->value == 3);
  REQUIRE(list.head->next->next->next->value == 4);
  REQUIRE(list.head->next->next->next->next->value == 5);
  REQUIRE(list.head->next->next->next->next->next == nullptr);
}

TEST_CASE("Six node list, k==3") {
  List list;
  list.new_after(nullptr, 1);
  list.new_after(list.head, 2);
  list.new_after(list.head->next, 3);
  list.new_after(list.head->next->next, 4);
  list.new_after(list.head->next->next->next, 5);
  list.new_after(list.head->next->next->next->next, 6);
  reverse_groups(list, 3);
  REQUIRE(list.head->value == 3);
  REQUIRE(list.head->next->value == 2);
  REQUIRE(list.head->next->next->value == 1);
  REQUIRE(list.head->next->next->next->value == 6);
  REQUIRE(list.head->next->next->next->next->value == 5);
  REQUIRE(list.head->next->next->next->next->next->value == 4);
  REQUIRE(list.head->next->next->next->next->next->next == nullptr);
}