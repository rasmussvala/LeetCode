#include <cmath>
#include <iostream>

using namespace std;

static int foo(string s) {
  int sum = 0;
  int diff = 0;

  for (int i = 0; i < s.size() - 1; ++i) {
    diff = s[i] - s[i + 1];
    sum += abs(diff);
  }
  return sum;
}

int main() {
  string s = "hello";
  int result = foo(s);

  return 0;
}
