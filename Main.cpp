#include <iostream>
#include <vector>

using namespace std;

static int foo(vector<int>& nums) {
  int negativeCount = 0;
  for (const auto& n : nums) {
    if (n == 0) return 0;
    if (n < 0) ++negativeCount;
  }

  return (negativeCount % 2 == 0) ? 1 : -1;
}

int main() {
  vector<int> nums = {-1, 1, -1, 1, -1};
  int result = foo(nums);

  return 0;
}
