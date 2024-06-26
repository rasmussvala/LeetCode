#include <iostream>

using namespace std;

static int foo(string s, string t) {
  int n = s.size();
  int diff = 0;
  int sum = 0;

  for (int i = 0; i < n; ++i) {
    diff = s[i] - t[i];
    sum += abs(diff);
  }

  return sum;
}

int main() {
  string s = "rwohu";
  string t = "rwuoh";
  int result = foo(s, t);

  return 0;
}
