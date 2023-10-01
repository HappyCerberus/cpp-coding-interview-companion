#include "catch2/catch_test_macros.hpp"
#include "maximum_path.h"
#include <queue>

Tree::Tree make_tree(const std::vector<int> &in) {
  Tree::Tree result;
  if (in.empty())
    return result;

  std::queue<Tree::Node *> q;
  auto it = in.begin();
  auto node = result.add(*it);
  q.push(node);
  result.root = q.front();
  it++;

  while (it != in.end()) {
    auto left = result.add(*it);
    q.front()->left = left;
    q.push(left);
    it++;

    if (it == in.end())
      break;
    auto right = result.add(*it);
    q.front()->right = right;
    q.push(right);
    it++;

    q.pop();
  }
  return result;
}

TEST_CASE("Max Path tests") {
  Tree::Tree t1 = make_tree({2, 2, 2, 4, 5, 2, 2});
  REQUIRE(maxPath(t1) == 13);

  Tree::Tree t2 = make_tree({-9, -9, 8, 9, 5, -9, -9});
  REQUIRE(maxPath(t2) == 9);

  Tree::Tree t3 = make_tree({1, 1, -1, 1, -1, -1, -1});
  REQUIRE(maxPath(t3) == 3);

  Tree::Tree t4 = make_tree({1, -1, 1, -1, -1, -1, 1});
  REQUIRE(maxPath(t4) == 3);

  Tree::Tree t5 = make_tree({-4});
  REQUIRE(maxPath(t5) == -4);

  Tree::Tree t6 = make_tree({-9, -8, -8, -7, -7, -7, -5});
  REQUIRE(maxPath(t6) == -5);
}