#pragma once

#include <memory>
#include <vector>

namespace Tree {

struct Node {
  int value;
  Node *left;
  Node *right;
};

struct Tree {
  Node *root = nullptr;
  Node *add(int value);

private:
  std::vector<std::unique_ptr<Node>> nodes_;
};

}