#include "loop.h"

void loop_fix(List &list) {
  // Phase 1, detect the loop.
  List::Node *slow = list.head;
  List::Node *fast = list.head;
  List::Node *before = nullptr;
  do {
    // nullptr == no loop
    if (slow == nullptr)
      return;
    if (fast == nullptr || fast->next == nullptr)
      return;
    slow = slow->next;
    // Keep track of the node one before the fast pointer
    before = fast->next;
    fast = fast->next->next;
  } while (slow != fast);

  // Phase 2, iterate from head and from meeting point.
  List::Node *onloop = slow;
  List::Node *offloop = list.head;
  while (onloop != offloop) {
    // Keep track of the node one before the onloop pointer
    before = onloop;
    onloop = onloop->next;
    offloop = offloop->next;
  }

  // Phase 3, fix the list, before != nullptr
  before->next = nullptr;
}