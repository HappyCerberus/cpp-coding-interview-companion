#include "obstacles.h"

#include <queue>

struct Dir {
  int64_t row;
  int64_t col;
};

struct Pos {
  int64_t row;
  int64_t col;
  int64_t k;
  int64_t distance;
};

int shortest_path(const std::vector<std::vector<int>> &grid, int64_t k) {
  // Keep track of visited spaces, initialize all spaces as unvisited.
  std::vector<std::vector<std::vector<bool>>> visited(
      grid.size(), std::vector<std::vector<bool>>(
                       grid[0].size(), std::vector<bool>(k + 1, false)));

  // BFS
  std::queue<Pos> q;
  // start in {0,0} with zero removed obstacles
  q.push(Pos{0, 0, 0, 0});
  visited[0][0][0] = true;

  while (!q.empty()) {
    auto current = q.front();
    q.pop();
    // The first time we visit the end coordinate is the shortest path
    if (current.row == std::ssize(grid) - 1 &&
        current.col == std::ssize(grid[current.row]) - 1) {
      return current.distance;
    }

    // For every direction, try to move there
    for (auto dir : {Dir{-1, 0}, Dir{1, 0}, Dir{0, -1}, Dir{0, 1}}) {
      // This space is out of bounds, ignore.
      if ((current.row + dir.row < 0) || (current.col + dir.col < 0) ||
          (current.row + dir.row >= std::ssize(grid)) ||
          (current.col + dir.col >= std::ssize(grid[0])))
        continue;

      // If the space in the current direction is an empty space:
      Pos empty = {current.row + dir.row, current.col + dir.col, current.k,
                   current.distance + 1};
      if (grid[empty.row][empty.col] == 0 &&
          !visited[empty.row][empty.col][empty.k]) {
        // add it to the queue
        q.push(empty);
        // and mark as visited
        visited[empty.row][empty.col][empty.k] = true;
      }

      // If we have have already removed k obstacles,
      // we don't consider removing more.
      if (current.k == k)
        continue;

      // If the space in the current direction is an obstacle:
      Pos wall = {current.row + dir.row, current.col + dir.col, current.k + 1,
                  current.distance + 1};
      if (grid[wall.row][wall.col] == 1 &&
          !visited[wall.row][wall.col][wall.k]) {
        // add it to the queue
        q.push(wall);
        // and mark as visited
        visited[wall.row][wall.col][wall.k] = true;
      }
    }
  }

  // If we are here, we did not reach the end coordinate.
  return -1;
}