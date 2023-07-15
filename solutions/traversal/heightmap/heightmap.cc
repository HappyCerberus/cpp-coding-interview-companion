#include "heightmap.h"

#include <queue>

int64_t shortest_path(const std::vector<std::vector<int>> &map, Coord start,
                      Coord end) {
  struct Pos {
    int64_t length;
    Coord coord;
  };

  // For tracking visited spaces
  std::vector<std::vector<bool>> visited(
      map.size(), std::vector<bool>(map[0].size(), false));

  // Helper to check whether a space can be stepped on
  // not out of bounds, not impassable and not visited
  auto can_step = [&map, &visited](Coord coord) {
    auto [row, col] = coord;
    return row >= 0 && col >= 0 && row < std::ssize(map) &&
           col < std::ssize(map[row]) && map[row][col] >= 0 &&
           !visited[row][col];
  };

  // Priority queue instead of a simple queue
  std::priority_queue<Pos, std::vector<Pos>,
                      decltype([](const Pos &l, const Pos &r) {
                        return l.length > r.length;
                      })>
      q;
  // Start with path length zero at start
  q.push({0, start});

  // Helper to determine the cost of moving between two spaces
  auto step_cost = [&map](Coord from, Coord to) {
    if (map[from.row][from.col] < map[to.row][to.col])
      return 4;
    if (map[from.row][from.col] > map[to.row][to.col])
      return 1;
    return 2;
  };

  while (!q.empty()) {
    // Grab the position closest to the start
    auto [length, pos] = q.top();
    q.pop();

    if (visited[pos.row][pos.col])
      continue;
    // The first time we grab a position from the queue is guaranteed
    // to be the shortest path, so now we need to mark it as visited.
    // If we later visit the same position (already in queue at this point)
    // with a longer path, we skip it based on the above check.
    visited[pos.row][pos.col] = true;

    // First time we would try to exit the end space is the shortest path.
    if (pos.row == end.row && pos.col == end.col)
      return length;

    // Expand to all four directions
    for (auto next :
         {Coord{pos.row - 1, pos.col}, Coord{pos.row + 1, pos.col},
          Coord{pos.row, pos.col - 1}, Coord{pos.row, pos.col + 1}}) {
      if (!can_step(next))
        continue;
      q.push({length + step_cost(pos, next), next});
    }
  }

  return -1;
}
