#include <iostream>
#include <vector>

using namespace std;

static int foo(int n) {
  if (n <= 1) return n;

  vector<int> myVec(n + 1);
  myVec[0] = 0;
  myVec[1] = 1;

  for (int i = 2; i < n + 1; ++i) {
    myVec[i] = myVec[i - 1] + myVec[i - 2];
  }

  return myVec[n];
}

int main() {
  int n = 0;
  int result = foo(n);

  return 0;
}
