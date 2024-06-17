#include <iostream>
#include <vector>

using namespace std;

static void foo(vector<int>& nums) {
  int counter = 0;

  // Find number of zero occurances
  for (const auto& n : nums) {
    if (n == 0) ++counter;
  }

  // Remove all zeros
  // Note: std::remove moves the elements that should be "removed" to the end
  // and returns an iterator to the new logical end of the container. Then we
  // call erase to actually remove those elements.
  nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());

  // Add all zeros in the end
  for (int i = 0; i < counter; i++) {
    nums.push_back(0);
  }
}

int main() {
  vector<int> nums = {0, 0, 1};
  foo(nums);

  return 0;
}
