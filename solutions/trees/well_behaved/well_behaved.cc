#include "well_behaved.h"
#include <algorithm>

// UnionFind
int64_t find(std::vector<int64_t> &root, int64_t i) {
  if (root[i] == i) // This is the representative node for this subtree
    return i;
  // Otherwise find the representative node and cache for future lookups.
  return root[i] = find(root, root[i]);
}

int64_t well_behaved_paths(std::vector<int64_t> values,
                           std::vector<std::pair<int64_t, int64_t>> edges) {
  // Start with all nodes disconnected, each node is the
  // representative node of its subtree.
  std::vector<int64_t> root(values.size(), 0);
  std::ranges::iota(root, 0);

  // The frequencies of the maximum value in each subtree.
  std::vector<int64_t> freq(values.size(), 1);

  // Start with trivial paths.
  int64_t result = values.size();

  std::ranges::sort(edges, [&](auto &l, auto &r) {
    return std::max(values[l.first], values[l.second]) <
           std::max(values[r.first], values[r.second]);
  });

  for (auto &edge : edges) {
    // Find the representative nodes for the two ends.
    // The representative nodes are always the maximum value nodes.
    int64_t l_max = find(root, edge.first);
    int64_t r_max = find(root, edge.second);

    // The maximum in both subtrees is the same.
    if (values[l_max] == values[r_max]) {
      // Add path from each maximum node in left subtree to each
      // maximum node in right subtree.
      result += freq[l_max] * freq[r_max];

      // Merge the trees right into left
      freq[l_max] += freq[r_max];
      root[r_max] = l_max;
    } else if (values[l_max] > values[r_max]) {
      // No new paths, but merge the trees
      // right into left.
      root[r_max] = l_max;
      // This doesn't change the frequency because
      // all nodes in r_max subtree < values[l_max].
    } else { // (values[r_max] > values[l_max])
      // No new paths, but merge the trees
      // left into right.
      root[l_max] = r_max;
      // This doesn't change the frequency because
      // all nodes in l_max subtree < values[r_max].
    }
  }
  return result;
}