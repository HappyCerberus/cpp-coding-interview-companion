#pragma once

#include "lists/list.h"

// Detects whether a list is corrupted i.e. contains a loop.
bool loop_detection(const List &list);