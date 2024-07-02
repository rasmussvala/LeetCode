#include <iostream>
#include <vector>

using namespace std;

static vector<int> foo(vector<int>& nums1, vector<int>& nums2) {
  vector<int> intersect;
  for (auto n1 : nums1) {
    for (auto it = nums2.begin(); it != nums2.end();) {
      if (n1 == *it) {
        intersect.push_back(*it);
        nums2.erase(it);
        break;
      } else
        it++;
    }
  }
  return intersect;
}

int main() {
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 1};
  vector<int> result = foo(nums1, nums2);

  return 0;
}
