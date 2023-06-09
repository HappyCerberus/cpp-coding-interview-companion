#pragma once

#include <cstdint>
#include <forward_list>

// Merge a list of sorted lists into one sorted list.
std::forward_list<int64_t>
merge(std::forward_list<std::forward_list<int64_t>> in);