#include "islands.h"
#include <cstdint>

bool island(int64_t i, int64_t j, std::vector<std::vector<char>> &grid) {
  // If we managed to reach out of bounds, this is not an island
  if (i == -1 || i == std::ssize(grid) || j == -1 || j == std::ssize(grid[i]))
    return false;
  // If this space is not land, ignore
  if (grid[i][j] != 'L')
    return true;
  // Mark this space as visited
  grid[i][j] = 'V';

  // We can only return true (this is an island) if all four
  // directions of our DFS return true. However, at the same time
  // even if this is not an island we want to explore all spaces
  // of the land mass, just to mark it as visited.
  // If we used a boolean expression, we would run into
  // short-circuiting, the first "false" result would stop
  // the evaluation.
  // Here we take advantage of the bool->int conversion:
  // false == 0, true == 1
  return (island(i - 1, j, grid) + island(i + 1, j, grid) +
          island(i, j - 1, grid) + island(i, j + 1, grid)) == 4;
}

int count_islands(std::vector<std::vector<char>> grid) {
  int cnt = 0;
  // For every space
  for (int64_t i = 0; i < std::ssize(grid); ++i)
    for (int64_t j = 0; j < std::ssize(grid[i]); ++j)
      // If it is an unvisited land space, check if it is an island
      if (grid[i][j] == 'L' && island(i, j, grid))
        ++cnt;
  return cnt;
}