#include "sudoku.h"

#include <array>
#include <bitset>
#include <cstdint>
#include <utility>

/* Calculate the corresponding box for row/col coordinates:
0 1 2
3 4 5
6 7 8

Any mapping will work, as long as it is consistent.
*/
int64_t get_box(int64_t row, int64_t col) { return (row / 3) * 3 + col / 3; }

struct State {
  // Initialize the state with given digits
  State(const std::vector<std::vector<char>> &puzzle) {
    for (int64_t i = 0; i < 9; ++i)
      for (int64_t j = 0; j < 9; ++j)
        if (puzzle[i][j] != ' ')
          mark(i, j, puzzle[i][j] - '1');
  }

  std::array<std::bitset<9>, 9> row;
  std::array<std::bitset<9>, 9> col;
  std::array<std::bitset<9>, 9> box;

  // Get the already used digits for a specific space.
  std::bitset<9> used(int64_t r_idx, int64_t c_idx) {
    return row[r_idx] | col[c_idx] | box[get_box(r_idx, c_idx)];
  }
  // Mark this digit as used in the corresponding row, column and box.
  void mark(int64_t r_idx, int64_t c_idx, int64_t digit) {
    row[r_idx][digit] = true;
    col[c_idx][digit] = true;
    box[get_box(r_idx, c_idx)][digit] = true;
  }
  // Mark this digit as unused in the corresponding row, column and box.
  void unmark(int64_t r_idx, int64_t c_idx, int64_t digit) {
    row[r_idx][digit] = false;
    col[c_idx][digit] = false;
    box[get_box(r_idx, c_idx)][digit] = false;
  }
};

// Get the next empty space after {row,col}
std::pair<int64_t, int64_t> next(const std::vector<std::vector<char>> &puzzle,
                                 int64_t row, int64_t col) {
  int64_t start = col;
  for (int64_t i = row; i < std::ssize(puzzle); ++i)
    for (int64_t j = std::exchange(start, 0); j < std::ssize(puzzle[i]); ++j)
      if (puzzle[i][j] == ' ')
        return {i, j};
  return {-1, -1};
}

bool backtrack(std::vector<std::vector<char>> &puzzle, State &state,
               int64_t r_curr, int64_t c_curr) {

  // next coordinate to fill
  auto [r_next, c_next] = next(puzzle, r_curr, c_curr);
  // {-1,-1} means there is no unfilled space,
  // i.e. we have solved the puzzle
  if (r_next == -1 && c_next == -1)
    return true;

  // The candidate numbers for this space cannot
  // repeat in the row, column or box.
  auto used = state.used(r_next, c_next);

  // Guess a number
  for (int64_t i = 0; i < 9; ++i) {
    // Already in a row, column or box
    if (used[i])
      continue;

    // Mark it on the puzzle
    puzzle[r_next][c_next] = '1' + i;
    state.mark(r_next, c_next, i);

    if (backtrack(puzzle, state, r_next, c_next))
      return true;
    // we get false if this was a guess
    // that didn't lead to a solution

    // Unmark from the puzzle
    state.unmark(r_next, c_next, i);
    puzzle[r_next][c_next] = ' ';
    // And try the next digit
  }
  return false;
}

bool solve(std::vector<std::vector<char>> &puzzle) {
  State state(puzzle);
  return backtrack(puzzle, state, 0, 0);
}