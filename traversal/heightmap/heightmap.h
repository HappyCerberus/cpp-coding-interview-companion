#pragma once

#include <cstdint>
#include <vector>

struct Coord {
  int64_t row;
  int64_t col;
};

int64_t shortest_path(const std::vector<std::vector<int>> &map, Coord start,
                      Coord end);