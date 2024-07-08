#include <iostream>
#include <vector>

using namespace std;

static int foo(int n, int k) {
  // Add all people in the vector
  vector<int> v;
  for (int i = 1; i <= n; ++i) {
    v.push_back(i);
  }

  // Remove one person for every k step
  auto it = v.begin();
  while (v.size() > 1) {
    for (int i = 0; i < k - 1; ++i) {
      ++it;
      if (it == v.end()) it = v.begin();
    }

    it = v.erase(it);
    if (it == v.end()) it = v.begin();
  }

  return v[0];
}

int main() {
  int n = 5;
  int k = 2;

  int result = foo(n, k);

  return 0;
}
