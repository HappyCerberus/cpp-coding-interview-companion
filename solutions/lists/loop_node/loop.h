#pragma once

#include "lists/list.h"

// Detects whether a list is corrupted i.e. contains a loop and returns the
// first node on the loop.
List::Node *loop_start(const List &list);