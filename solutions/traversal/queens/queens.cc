#include "queens.h"

// Helper to store the current state:
struct State {
  State(int64_t n)
      : n(n), solution{}, cols(n), nw_dia(2 * n - 1), ne_dia(2 * n - 1) {}
  // Size of the problem.
  int64_t n;
  // Partial solution
  std::vector<int64_t> solution;
  // Occupied columns
  std::vector<bool> cols;
  // Occupied NorthWest diagonals
  std::vector<bool> nw_dia;
  // Occupied NorthEast diagonals
  std::vector<bool> ne_dia;
  // Check column, and both diagonals
  bool available(int64_t row, int64_t col) const {
    return !cols[col] && !nw_dia[row - col + n - 1] && !ne_dia[row + col];
  }
  // Mark this position as occupied and add it to the partial solution
  void mark(int64_t row, int64_t col) {
    solution.push_back(col);
    cols[col] = true;
    nw_dia[row - col + n - 1] = true;
    ne_dia[row + col] = true;
  }
  // Unmark this position as occupied and remove it from the partial solution
  void erase(int64_t row, int64_t col) {
    solution.pop_back();
    cols[col] = false;
    nw_dia[row - col + n - 1] = false;
    ne_dia[row + col] = false;
  }
};

bool backtrack(auto &state, int64_t row, int64_t n) {
  // All Queens have their positions, we have solution
  if (row == n)
    return true;

  // Try to find a feasible column on this row
  for (int c = 0; c < n; ++c) {
    if (!state.available(row, c))
      continue;
    // Mark this position
    state.mark(row, c);
    // Recurse to the next row
    if (backtrack(state, row + 1, n))
      return true; // We found a solution on this path
    // This position lead to dead-end, erase and try another
    state.erase(row, c);
  }
  // This is dead-end
  return false;
}

bool solve(std::vector<int64_t> &solution, int64_t n) {
  State state(n);
  bool result = backtrack(state, 0, n);
  if (result)
    solution = std::move(state.solution);
  return result;
}