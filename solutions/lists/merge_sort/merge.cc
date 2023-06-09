#include "merge.h"

#include <ranges>
#include <set>

std::forward_list<int64_t>
merge(std::forward_list<std::forward_list<int64_t>> in) {
  using fwlst = std::forward_list<int64_t>;

  // Custom comparator, compare based on the first element
  auto cmp = [](const fwlst &l, const fwlst &r) {
    return l.front() < r.front();
  };
  // View of non-empty lists, if we filter here,
  // we don't have to check later.
  auto non_empty = in | std::views::filter([](auto &l) { return !l.empty(); }) |
                   std::views::common;
  // Consume the input using std::move_iterator,
  // avoids making copies of the lists.
  std::multiset<fwlst, decltype(cmp)> q(std::move_iterator(non_empty.begin()),
                                        std::move_iterator(non_empty.end()),
                                        cmp);

  fwlst result;
  fwlst::iterator tail = result.before_begin();
  while (!q.empty()) {
    // Extract the node that holds the element,
    // without making a copy
    auto top = q.extract(q.begin());

    // Splice the first element of the top list to the result
    result.splice_after(tail, top.value(), top.value().before_begin());
    ++tail;

    if (!top.value().empty())
      q.insert(std::move(top)); // put back
  }
  return result;
}