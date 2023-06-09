#include "catch2/catch_test_macros.hpp"
#include "remove_kth.h"

TEST_CASE("Empty") {
  std::forward_list<int64_t> t;
  std::forward_list<int64_t> r;
  remove_kth_from_end(t, 1);
  REQUIRE(std::ranges::equal(t, r));
}

TEST_CASE("Out of bounds") {
  std::forward_list<int64_t> t{1, 2, 3, 4, 5};
  std::forward_list<int64_t> r{1, 2, 3, 4, 5};
  remove_kth_from_end(t, 6);
  REQUIRE(std::ranges::equal(t, r));
}

TEST_CASE("Removing from end") {
  std::forward_list<int64_t> t{1, 2, 3};
  std::forward_list<int64_t> r1{1, 2};
  remove_kth_from_end(t, 1);
  REQUIRE(std::ranges::equal(t, r1));

  std::forward_list<int64_t> r2{1};
  remove_kth_from_end(t, 1);
  REQUIRE(std::ranges::equal(t, r2));

  std::forward_list<int64_t> r3;
  remove_kth_from_end(t, 1);
  REQUIRE(std::ranges::equal(t, r3));
}

TEST_CASE("Removing from head") {
  std::forward_list<int64_t> t{1, 2, 3};
  std::forward_list<int64_t> r1{2, 3};
  remove_kth_from_end(t, 3);
  REQUIRE(std::ranges::equal(t, r1));

  std::forward_list<int64_t> r2{3};
  remove_kth_from_end(t, 2);
  REQUIRE(std::ranges::equal(t, r2));

  std::forward_list<int64_t> r3;
  remove_kth_from_end(t, 1);
  REQUIRE(std::ranges::equal(t, r3));
}

TEST_CASE("Remove from middle") {
  std::forward_list<int64_t> t{1, 2, 3, 4, 5};
  std::forward_list<int64_t> r1{1, 2, 4, 5};
  remove_kth_from_end(t, 3);
  REQUIRE(std::ranges::equal(t, r1));

  std::forward_list<int64_t> r2{1, 2, 5};
  remove_kth_from_end(t, 2);
  REQUIRE(std::ranges::equal(t, r2));

  std::forward_list<int64_t> r3{1, 5};
  remove_kth_from_end(t, 2);
  REQUIRE(std::ranges::equal(t, r3));
}