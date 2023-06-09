#pragma once

#include <cstdint>
#include <forward_list>

// Remove the kth elemented (counted) from the end of the list
void remove_kth_from_end(std::forward_list<int64_t> &head, int64_t k);