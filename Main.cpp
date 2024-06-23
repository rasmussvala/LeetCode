#include <iostream>
#include <vector>

using namespace std;

static int foo(vector<vector<int>>& mat) {
  size_t n = mat.size();
  int sum = 0;

  // primary diagonal
  for (size_t i = 0; i < n; i++) sum += mat[i][i];

  // secondary diagonal
  for (size_t i = 0; i < n; ++i) {
    if (i == n - 1 - i) continue;
    sum += mat[i][n - 1 - i];
  }

  return sum;
}

int main() {
  vector<vector<int>> myVec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int result = foo(myVec);

  return 0;
}
