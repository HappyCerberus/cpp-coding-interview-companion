#include "nary_tree.h"

Node *Tree::add_node(uint32_t value, Node *parent) {
  storage_.push_back(std::make_unique<Node>(value));
  if (parent == nullptr)
    root = storage_.back().get();
  else
    parent->children.push_back(storage_.back().get());
  return storage_.back().get();
}

auto operator<=>(const Node &left, const Node &right) {
  if (left.value != right.value)
    return left.value <=> right.value;
  return std::lexicographical_compare_three_way(
      left.children.begin(), left.children.end(), right.children.begin(),
      right.children.end(),
      [](Node *left, Node *right) { return *left <=> *right; });
}

auto operator<=>(const Tree &left, const Tree &right) {
  if (left.root != nullptr && right.root != nullptr)
    return (*left.root) <=> (*right.root);
  return left.root <=> right.root;
}

bool operator==(const Tree &left, const Tree &right) {
  return std::is_eq(left <=> right);
}