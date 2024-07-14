#include <iostream>
#include <vector>

using namespace std;

static int foo(vector<int>& nums) {
  int counter = 0;

  for (const auto& n : nums) {
    if (n % 3 != 0) ++counter;
  }

  return counter;
}

int main() {
  vector<int> nums = {1, 2, 3, 4};
  int result = foo(nums);

  return 0;
}
