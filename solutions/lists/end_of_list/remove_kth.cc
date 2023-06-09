#include "remove_kth.h"

void remove_kth_from_end(std::forward_list<int64_t> &head, int64_t k) {
  auto node = head.before_begin();
  auto tail = head.begin();
  // advance the tail by k-1 steps
  for (int64_t i = 1; i < k && tail != head.end(); ++i)
    ++tail;

  // there is no k-the element from the back
  if (tail == head.end())
    return;

  // advance both node and tail, until we reach the end with tail
  // this means that node is poiting to the k-th element from the back
  while (std::next(tail) != head.end()) {
    ++node;
    ++tail;
  }

  // remove the node
  head.erase_after(node);
}