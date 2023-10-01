#include "nary_tree.h"

#include <iostream>

void serialize(Node *root, std::ostream &s) {
  // each node is serialized into "value {children} -1"
  s << root->value << " ";
  for (auto c : root->children)
    serialize(c, s);
  s << "-1 ";
}

std::ostream &operator<<(std::ostream &s, Tree &tree) {
  if (tree.root != nullptr)
    serialize(tree.root, s);
  else
    // serialize empty tree as "-1"
    s << "-1 ";
  return s;
}

Node *deserialize(Tree &tree, Node *parent, uint32_t parent_value,
                  std::istream &s) {
  // pre-reading the value allows for cleaner code
  Node *result = tree.add_node(parent_value, parent);
  int64_t value; // we have to use int64_t to represent all values for uint32_t
                 // and -1
  while (s >> value) {
    if (value <
        0) // if we read -1, we are done reading the children of this node
      return result;
    // otherwise recursively de-serialize this child
    deserialize(tree, result, value, s);
  }
  return result;
}

std::istream &operator>>(std::istream &s, Tree &tree) {
  int64_t value;
  if (s >> value && value >= 0)
    deserialize(tree, nullptr, value, s);
  return s;
}