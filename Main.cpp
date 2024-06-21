#include <iostream>

using namespace std;

static int foo(string s) {
  int counter = 0;
  int lastValue = 0;
  for (const auto& l : s) {
    // 32 is the unicode for space or empty idk
    if (l == 32) {
      counter = 0;
    } else {
      ++counter;
      lastValue = counter;
    }
  }

  return lastValue;
}

int main() {
  string s = "hello world";
  int result = foo(s);

  return 0;
}
