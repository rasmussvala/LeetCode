#include <iostream>

using namespace std;

static int removeSubstring(string& s, string remove, int points) {
  int totalPoints = 0;
  size_t found = s.find(remove);

  while (found != string::npos) {
    s.erase(s.begin() + found, s.begin() + found + 2);
    totalPoints += points;
    found = s.find(remove);
  }

  return totalPoints;
}

static int foo(string s, int x, int y) {
  int totalPoints = 0;

  if (x > y) {
    // Remove "ab" first (higher points), then "ba"
    totalPoints += removeSubstring(s, "ab", x);
    totalPoints += removeSubstring(s, "ba", y);
  } else {
    // Remove "ba" first (higher or equal points), then "ab"
    totalPoints += removeSubstring(s, "ba", y);
    totalPoints += removeSubstring(s, "ab", x);
  }

  return totalPoints;
}

int main() {
  string s = "cdbcbbaaabab";
  int x = 4;
  int y = 5;
  int result = foo(s, x, y);

  return 0;
}
