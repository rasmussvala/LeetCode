#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static int foo(vector<int>& nums) {
  int n = nums.size();
  if (n <= 4) return 0;

  sort(nums.begin(), nums.end());

  /*
   * We have 4 plans:
   *
   * kill 3 biggest elements
   * kill 2 biggest elements + 1 smallest elements
   * kill 1 biggest elements + 2 smallest elements
   * kill 3 smallest elements
   *
   * We can now create a vector of these for cases and return the smallest
   */
  return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2],
              nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
}

int main() {
  vector<int> nums = {1, 5, 0, 10, 14};
  int result = foo(nums);

  return 0;
}
