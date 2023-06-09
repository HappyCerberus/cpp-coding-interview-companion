#include "list.h"

List::Node *List::new_after(List::Node *prev, int64_t value) {
  nodes_.push_back(std::make_unique<List::Node>(value, nullptr));
  if (prev == nullptr)
    return head = nodes_.back().get();
  else
    return prev->next = nodes_.back().get();
}