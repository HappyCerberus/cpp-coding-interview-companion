#include "kgroups.h"
#include <utility>

List::Node *reverse(List::Node *head, int64_t k) {
  List::Node *result = nullptr;
  List::Node *iter = head;

  for (int64_t i = 0; i < k; ++i)
    iter = std::exchange(iter->next, std::exchange(result, iter));
  /* we want to put iter to the front of the list
      but we want the original value of result to be the new iter->next
      but we want the original value of iter->next to be the new iter
  */
  return result;
}

void reverse_groups(List &list, int64_t k) {
  List::Node *unprocessed_head = list.head;
  List::Node *processed_tail = nullptr;
  List::Node *result = nullptr;
  List::Node *iter = list.head;

  while (iter != nullptr) {
    // advanced by k elements
    int cnt = 0;
    iter = unprocessed_head;
    while (cnt < k && iter != nullptr) {
      iter = iter->next;
      ++cnt;
    }

    // if we have a full set of k elements
    if (cnt == k) {
      List::Node *processed_head = reverse(unprocessed_head, k);
      // initialize the result if this is the first group
      if (result == nullptr)
        result = processed_head;
      // if this isn't the first group, link the existing tail
      if (processed_tail != nullptr)
        processed_tail->next = processed_head;

      // what was head is now the tail of the reversed section
      processed_tail = unprocessed_head;
      // and iter is the new head
      unprocessed_head = iter;
    }
  }
  if (processed_tail != nullptr)
    processed_tail->next = unprocessed_head;
  list.head = result == nullptr ? unprocessed_head : result;
}