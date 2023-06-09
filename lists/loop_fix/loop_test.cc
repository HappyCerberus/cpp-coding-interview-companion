#include "catch2/catch_test_macros.hpp"
#include "loop.h"

TEST_CASE("No loop") {
  List list;

  loop_fix(list);
  REQUIRE(list.head == nullptr);

  auto *n1 = list.new_after(nullptr, 1);
  loop_fix(list);
  REQUIRE(list.head == n1);
  REQUIRE(n1->next == nullptr);

  auto *n2 = list.new_after(list.head, 2);
  loop_fix(list);
  REQUIRE(list.head == n1);
  REQUIRE(n1->next == n2);
  REQUIRE(n2->next == nullptr);
}

TEST_CASE("Single node") {
  List list;
  auto *head = list.new_after(nullptr, 1);
  list.head->next = list.head;

  loop_fix(list);
  REQUIRE(list.head == head);
  REQUIRE(head->next == nullptr);
}

TEST_CASE("Two nodes") {
  List list;
  auto *head = list.new_after(nullptr, 1);
  auto *n1 = list.new_after(list.head, 2);
  list.head->next->next = list.head;

  loop_fix(list);
  REQUIRE(list.head == head);
  REQUIRE(list.head->next == n1);
  REQUIRE(n1->next == nullptr);
}

TEST_CASE("Terminal self-loop") {
  List list;
  auto *head = list.new_after(nullptr, 1);
  auto *n1 = list.new_after(list.head, 2);
  auto *n2 = list.new_after(n1, 3);
  n2->next = n2;

  loop_fix(list);
  REQUIRE(list.head == head);
  REQUIRE(list.head->next == n1);
  REQUIRE(n1->next == n2);
  REQUIRE(n2->next == nullptr);
}

TEST_CASE("Big loop") {
  List list;
  std::vector<List::Node *> nodes;

  nodes.push_back(list.new_after(nullptr, 1));
  nodes.push_back(list.new_after(nodes.back(), 2));
  nodes.push_back(list.new_after(nodes.back(), 3));
  auto *loop = nodes.back();
  for (int i = 0; i < 9; ++i) {
    nodes.push_back(list.new_after(nodes.back(), i + 4));
  }
  nodes.back()->next = loop;

  loop_fix(list);

  List::Node *curr = list.head;
  for (auto *it : nodes) {
    REQUIRE(curr == it);
    curr = curr->next;
  }
  REQUIRE(curr == nullptr);
}