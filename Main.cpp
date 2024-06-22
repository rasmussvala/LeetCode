#include <iostream>

using namespace std;

static int foo(int low, int high) {
  int counter = 0;
  for (int i = low; i <= high; ++i) {
    if (i % 2 != 0) ++counter;
  }
  return counter;
}

int main() {
  int low = 3;
  int high = 7;
  int result = foo(low, high);

  return 0;
}
