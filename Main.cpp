#include <iostream>
#include <vector>

using namespace std;

static void foo(vector<int>& nums) {
  for (int i = 0; i < nums.size() - 1; i++) {
    // Move to the end
    if (nums[i] == 0) {
      for (int j = i; j < nums.size() - 1; j++) {
        swap(nums[j], nums[j + 1]);
      }
    }
  }
}

int main() {
  vector<int> nums = {0, 0, 1};
  foo(nums);

  return 0;
}
