#include "construct_bst.h"

namespace Tree {

Node *&find_place_for(Node *&root, int value) {
  // The first empty (null) node we encounter
  // is the place where we want to insert.
  if (root == nullptr)
    return root;
  // Higher values go to the right
  if (root->value > value)
    return find_place_for(root->left, value);
  // Lower values go to the left
  if (root->value <= value) // == is for equivalent values
    return find_place_for(root->right, value);
  return root;
}

Tree construct_bst(const std::vector<int> &rng) {
  Tree t;
  for (int v : rng)
    find_place_for(t.root, v) = t.add(v);
  return t;
}

}