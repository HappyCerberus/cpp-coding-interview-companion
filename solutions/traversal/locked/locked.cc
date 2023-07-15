#include "locked.h"

#include <algorithm>
#include <stack>

bool locked_rooms(const std::vector<std::vector<int>> &rooms) {
  // Keep track of the keys we have collected
  std::vector<bool> keys(rooms.size(), false);

  std::stack<int> keys_to_use;
  keys_to_use.push(0); // We start with the key to room 0
  keys[0] = true;

  while (!keys_to_use.empty()) {
    // Use the key to open a room
    int key = keys_to_use.top();
    keys_to_use.pop();

    // Check if any of the keys in the room are new
    for (int k : rooms[key])
      if (!keys[k]) {
        keys_to_use.push(k);
        keys[k] = true;
      }
  }

  // Do we have all the keys?
  return std::ranges::all_of(keys, std::identity{});
}