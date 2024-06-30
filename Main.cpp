#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static bool foo(vector<int>& arr) {
  sort(arr.begin(), arr.end());

  int diff = arr[0] - arr[1];
  int nextDiff = 0;

  for (size_t i = 1; i < arr.size() - 1; ++i) {
    nextDiff = arr[i] - arr[i + 1];
    if (nextDiff != diff) return false;
  }

  return true;
}

int main() {
  vector<int> myVec = {3, 5, 1};
  bool result = foo(myVec);

  return 0;
}
