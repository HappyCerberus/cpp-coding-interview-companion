#pragma once

#include <cstdint>
#include <iosfwd>
#include <memory>
#include <vector>

struct Node {
  uint32_t value;
  std::vector<Node *> children;

  friend auto operator<=>(const Node &left, const Node &right);
};

struct Tree {
  Node *root = nullptr;
  // Add node to the tree, when parent == nullptr, the method sets the tree root
  Node *add_node(uint32_t value, Node *parent = nullptr);

  friend auto operator<=>(const Tree &left, const Tree &right);
  friend bool operator==(const Tree &left, const Tree &right);

  friend std::istream &operator>>(std::istream &s, Tree &tree);
  friend std::ostream &operator<<(std::ostream &s, Tree &tree);

private:
  std::vector<std::unique_ptr<Node>> storage_;
};
