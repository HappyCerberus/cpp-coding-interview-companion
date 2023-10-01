#include "maximum_path.h"
#include <algorithm>
#include <utility>

std::pair<int, int> maxPath(Tree::Node *node) {
  // initialize with single-node paths
  int max_path = node->value;
  int max_subtree = node->value;
  int full_path = node->value;

  if (node->left != nullptr) {
    // Calculate recursive values for the left path
    auto [path, tree] = maxPath(node->left);
    // Path terminating in this node: max of case 1 and 2
    max_path = std::max(max_path, path + node->value);
    // maximum path might not be crossing this node,
    // contained in the left subtree
    max_subtree = std::max(max_subtree, tree);
    // value of the crossing path (case 4)
    full_path += path;
  }
  if (node->right != nullptr) {
    // Calculate recursive values for the right path
    auto [path, tree] = maxPath(node->right);
    // Path terminating in this node: max of case 1 and 3
    // note, we already included the case 2 in the left-node if
    max_path = std::max(max_path, path + node->value);
    // maximum path might not be crossing this node,
    // contained in the right subtree
    max_subtree = std::max(max_subtree, tree);
    // value of the crossing path (case 4)
    full_path += path;
  }
  // the full path is the path starting in the left subtree,
  // crossing this node, continuing into the right subtree
  // the maximum path in this subtree is any of the paths
  max_subtree = std::max(max_subtree, std::max(full_path, max_path));
  // max_path is the longest path terminating in this node
  return {max_path, max_subtree};
}

// Final computation, simply return the maximum
int maxPath(const Tree::Tree &t) {
  auto [path, tree] = maxPath(t.root);
  return tree;
}