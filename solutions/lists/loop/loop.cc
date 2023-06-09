#include "loop.h"

bool loop_detection(const List &list) {
  List::Node *slow = list.head;
  List::Node *fast = list.head;
  do {
    // nullptr == no loop
    if (slow == nullptr)
      return false;
    if (fast == nullptr || fast->next == nullptr)
      return false;
    slow = slow->next;
    fast = fast->next->next;
  } while (slow != fast);

  return true;
}