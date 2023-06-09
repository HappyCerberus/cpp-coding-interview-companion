#pragma once

#include <cstdint>
#include <memory>
#include <vector>

struct List {
  struct Node {
    int64_t value;
    Node *next;
  };
  Node *head = nullptr;
  Node *new_after(Node *prev, int64_t value);

private:
  std::vector<std::unique_ptr<Node>> nodes_;
};