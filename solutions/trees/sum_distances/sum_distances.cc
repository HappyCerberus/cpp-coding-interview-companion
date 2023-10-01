#include "sum_distances.h"

struct TreeInfo {
  TreeInfo(int n) : subtree_sum(n, 0), node_count(n, 0), result(n, 0) {}
  std::vector<int> subtree_sum;
  std::vector<int> node_count;
  std::vector<int> result;
};

void post_order(int node, int parent,
                const std::unordered_multimap<int, int> &neighbours,
                TreeInfo &info) {
  // If there are no children we have zero distance and one node.
  info.subtree_sum[node] = 0;
  info.node_count[node] = 1;

  auto [begin, end] = neighbours.equal_range(node);
  for (auto [from, to] : std::ranges::subrange(begin, end)) {
    // Avoid looping back to the node we came from.
    if (to == parent)
      continue;
    // post_order traversal, visit children first
    post_order(to, node, neighbours, info);
    // accumulate number of nodes and distances
    info.subtree_sum[node] += info.subtree_sum[to] + info.node_count[to];
    info.node_count[node] += info.node_count[to];
  }
}

void pre_order(int node, int parent,
               const std::unordered_multimap<int, int> &neighbours,
               TreeInfo &info) {
  // For the root node the subtree_sum matches the result.
  if (parent == -1) {
    info.result[node] = info.subtree_sum[node];
  } else {
    // Otherwise, we can calculate the result from the parent,
    // because in pre-order we visit the parent before the children.
    info.result[node] =
        info.result[parent] + info.result.size() - 2 * info.node_count[node];
  }
  // Now visit any children.
  auto [begin, end] = neighbours.equal_range(node);
  for (auto [from, to] : std::ranges::subrange(begin, end)) {
    if (to == parent)
      continue;
    pre_order(to, node, neighbours, info);
  }
}

std::vector<int>
distances_in_tree(int n, const std::unordered_multimap<int, int> neighbours) {
  TreeInfo info(n);
  // post-order pass to calculate subtree_sum and node_count
  post_order(0, -1, neighbours, info);
  // pre-order pass to calculate result
  pre_order(0, -1, neighbours, info);
  return info.result;
}