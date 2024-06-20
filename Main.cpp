#include <iostream>

using namespace std;

static string foo(string s) {
  string result = "";

  for (auto& l : s) {
    if (l <= 90 && l >= 65) {
      // Lower case are 32 steps higher in ASCII
      l += 32;
    }
    result += l;
  }

  return result;
}

int main() {
  string s = "Hello";
  string result = foo(s);

  return 0;
}
