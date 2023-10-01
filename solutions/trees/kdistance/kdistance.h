#pragma once

#include "trees/tree.h"
#include <vector>

std::vector<int> find_distance_k_nodes(Tree::Node *root, Tree::Node *target,
                                       int k);