#include <cmath>
#include <iostream>

using namespace std;

static int foo(int n, int time) {
  int full_loops = time / (n - 1);
  int rest = time % (n - 1);

  // we go forward
  if (full_loops % 2 == 0) return 1 + rest;

  // we go backward
  else
    return n - rest;
}

int main() {
  int n = 4;
  int time = 5;

  int result = foo(n, time);

  return 0;
}
