#include <iostream>

using namespace std;

static bool foo(string s) {
  int n = s.length();
  int appearances;

  // We only need to loop through half s to create a substring
  for (int i = 1; i <= n / 2; ++i) {
    // String can be divided evenly with substring
    if (n % i == 0) {
      string substring = s.substr(0, i);
      string result = "";
      appearances = n / i;

      // Recreate possible result
      for (int j = 0; j < appearances; ++j) {
        result += substring;
      }

      // They match
      if (result == s) return true;
    }
  }
  return false;
}

int main() {
  string s = "a";
  bool result = foo(s);
  return 0;
}
