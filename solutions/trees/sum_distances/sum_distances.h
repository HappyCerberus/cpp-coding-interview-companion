#pragma once

#include <unordered_map>
#include <vector>

std::vector<int>
distances_in_tree(int n, const std::unordered_multimap<int, int> neighbours);