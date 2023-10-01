#include "validate_bst.h"

namespace {
bool is_valid_bst(Tree::Node *root, int min, int max) {
  // Is this node within the bounds?
  if (root->value > max || root->value < min)
    return false;
  // Explore left subtree with the updated bounds
  if (root->left != nullptr) {
    if (root->value == INT_MIN) // avoid underflow
      return false;
    if (!is_valid_bst(root->left, min, root->value - 1))
      return false;
  }
  // Explore right subtree with the updated bounds
  if (root->right != nullptr) {
    if (root->value == INT_MAX) // avoid overflow
      return false;
    if (!is_valid_bst(root->right, root->value + 1, max))
      return false;
  }
  return true;
}
} // namespace

bool is_valid_bst(const Tree::Tree &tree) {
  // Root can be any value
  return is_valid_bst(tree.root, INT_MIN, INT_MAX);
}