#include "kdistance.h"

#include <unordered_map>

// Search for target and build distances to root
int distance_search(Tree::Node *root, Tree::Node *target,
                    std::unordered_map<int, int> &distances) {
  if (root == nullptr)
    return -1;
  if (root == target) {
    distances[root->value] = 0;
    return 0;
  }
  // Target in the left sub-tree
  if (int left = distance_search(root->left, target, distances); left >= 0) {
    distances[root->value] = left + 1;
    return left + 1;
  }
  // Target in the right sub-tree
  if (int right = distance_search(root->right, target, distances); right >= 0) {
    distances[root->value] = right + 1;
    return right + 1;
  }
  // Target not in this sub-tree
  return -1;
}

// Second pass traversal.
void dfs(Tree::Node *root, Tree::Node *target, int k, int dist,
         std::unordered_map<int, int> &distances, std::vector<int> &result) {
  if (root == nullptr)
    return;
  // Check if this node is on the path to target.
  auto it = distances.find(root->value);
  // Node is on the path to target, update distance.
  if (it != distances.end())
    dist = it->second;
  // This node is k distance from the target.
  if (dist == k)
    result.push_back(root->value);

  // Distances to children are one more, unless they are on the path
  // which is handled above.
  dfs(root->left, target, k, dist + 1, distances, result);
  dfs(root->right, target, k, dist + 1, distances, result);
}

std::vector<int> find_distance_k_nodes(Tree::Node *root, Tree::Node *target,
                                       int k) {
  // First pass
  std::unordered_map<int, int> distances;
  distance_search(root, target, distances);
  // Second pass
  std::vector<int> result;
  dfs(root, target, k, distances[root->value], distances, result);
  return result;
}