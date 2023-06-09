#include "merge.h"

std::forward_list<int64_t>
merge(std::forward_list<std::forward_list<int64_t>> in) {
  std::forward_list<std::forward_list<int64_t>> merged;
  // While we have more than one list
  while (std::next(in.begin()) != in.end()) {
    auto it = in.begin();
    // Take a pair of lists
    while (it != in.end() && std::next(it) != in.end()) {
      // Merge
      it->merge(*std::next(it));
      merged.emplace_front(std::move(*it));
      std::advance(it, 2);
    }
    // If we have odd number of lists
    if (it != in.end())
      merged.emplace_front(std::move(*it));
    // Switch the lists for the next iteration
    in = std::move(merged);
  }
  return std::move(in.front());
}