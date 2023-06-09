#include "loop.h"

List::Node *loop_start(const List &list) {
  // Phase 1, detect the loop.
  List::Node *slow = list.head;
  List::Node *fast = list.head;
  do {
    // nullptr == no loop
    if (slow == nullptr)
      return nullptr;
    if (fast == nullptr || fast->next == nullptr)
      return nullptr;
    slow = slow->next;
    fast = fast->next->next;
  } while (slow != fast);

  // Phase 2, iterate from head and from meeting point.
  List::Node *onloop = slow;
  List::Node *offloop = list.head;
  while (onloop != offloop) {
    onloop = onloop->next;
    offloop = offloop->next;
  }
  return onloop;
}