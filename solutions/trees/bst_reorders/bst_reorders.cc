#include "bst_reorders.h"

#include <algorithm>
#include <vector>

constexpr inline int32_t mod = 1e9 + 7;

int32_t count(std::span<int> nums, std::vector<std::vector<int>> &coef) {
  if (nums.size() < 3)
    return 1;

  // Partition into left and right child
  auto rng = std::ranges::stable_partition(
      nums, [pivot = nums[0]](int v) { return v < pivot; });
  auto left = std::span(nums.begin(), rng.begin());
  // Skip the pivot, since the pivot is the parent node
  auto right = std::span(rng.begin() + 1, nums.end());

  // Calculate the number of reorders for both sub-trees
  int64_t left_cnt = count(left, coef) % mod;
  int64_t right_cnt = count(right, coef) % mod;
  // Side note, we need 64bit here because we need
  // to fit 32bit*32bit in the bellow calculation.

  // The result is:
  // left * right * number of ways to pick positions
  // for left.size() elements in nums.size()-1 positions.
  return ((left_cnt * right_cnt) % mod) * coef[nums.size() - 1][left.size()] %
         mod;
}

int32_t number_of_reorders(std::span<int> nums) {
  // Precalculate binomial coefficients upto nums.size()-1
  std::vector<std::vector<int>> binomial_coefficients;
  binomial_coefficients.resize(nums.size());
  for (int64_t i = 0; i < std::ssize(nums); ++i) {
    binomial_coefficients[i].resize(i + 1, 1);
    for (int64_t j = 1; j < i; ++j)
      // Pascal's triangle
      binomial_coefficients[i][j] = (binomial_coefficients[i - 1][j - 1] +
                                     binomial_coefficients[i - 1][j]) %
                                    mod;
  }

  return (count(nums, binomial_coefficients) - 1) % mod;
}