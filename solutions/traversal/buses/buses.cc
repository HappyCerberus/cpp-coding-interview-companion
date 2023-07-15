#include "buses.h"

#include <algorithm>
#include <queue>

// There is no convenient is_overlapping algorithm unfortunately
bool overlaps(const std::vector<int> &left, const std::vector<int> &right) {
  ptrdiff_t i = 0;
  ptrdiff_t j = 0;
  while (i < std::ssize(left) && j < std::ssize(right)) {
    while (i < std::ssize(left) && left[i] < right[j])
      ++i;
    while (i < std::ssize(left) && j < std::ssize(right) && left[i] > right[j])
      ++j;
    if (i < std::ssize(left) && j < std::ssize(right) && left[i] == right[j])
      return true;
  }
  return false;
}

int min_tickets(std::vector<std::vector<int>> routes, int source, int target) {
  if (source == target) {
    return 0;
  }

  // Map of bus -> connecting busses
  std::vector<std::vector<int>> connections(routes.size());
  for (auto &route : routes)
    std::ranges::sort(route);

  // Flag for whether a bus stops at target
  std::vector<bool> is_dest(routes.size(), false);
  // Flag for whether this bus was already visited
  std::vector<bool> visited(routes.size(), false);
  // Queue for BFS
  std::queue<std::pair<int, int>> q;

  for (ptrdiff_t i = 0; i < std::ssize(routes); ++i) {
    // The bus stops at source, one of our starting buses
    if (std::ranges::binary_search(routes[i], source)) {
      q.push({i, 1});
      visited[i] = true;
    }
    // The bus stops at target
    if (std::ranges::binary_search(routes[i], target))
      is_dest[i] = true;

    // Find all other busses that connect to this bus
    for (ptrdiff_t j = i + 1; j < std::ssize(routes); ++j) {
      if (overlaps(routes[i], routes[j])) {
        connections[i].push_back(j);
        connections[j].push_back(i);
      }
    }
  }

  // BFS
  while (!q.empty()) {
    auto [current, len] = q.front();
    q.pop();
    if (is_dest[current])
      return len;

    for (auto bus : connections[current]) {
      if (visited[bus])
        continue;
      q.push({bus, len + 1});
      visited[bus] = true;
    }
  }

  return -1;
}