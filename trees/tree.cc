#include "tree.h"

namespace Tree {

Node *Tree::add(int value) {
  nodes_.push_back(std::make_unique<Node>(value, nullptr, nullptr));
  return nodes_.back().get();
}

}