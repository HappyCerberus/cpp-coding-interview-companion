#include "paren.h"

void generate(std::vector<std::string> &solutions, size_t n,
              std::string &prefix, size_t left, size_t right) {
  // n parentheses, we have solution
  if (prefix.length() == 2 * n)
    solutions.push_back(prefix);

  // We can only add a left parenthesis if we haven't used all of them.
  if (left < n) {
    prefix.push_back('(');
    // Explore all solutions with this prefix
    generate(solutions, n, prefix, left + 1, right);
    prefix.pop_back();
  }
  // We can only add a left parenthesis if we have used more left
  // than right parentheses.
  if (left > right) {
    prefix.push_back(')');
    // Explore all solutions with this prefix
    generate(solutions, n, prefix, left, right + 1);
    prefix.pop_back();
  }
}

std::vector<std::string> valid_parentheses(size_t n) {
  std::vector<std::string> solutions;
  std::string prefix;
  generate(solutions, n, prefix, 0, 0);
  return solutions;
}