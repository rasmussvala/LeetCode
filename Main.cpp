#include <iostream>
#include <unordered_map>

using namespace std;

static int foo(string s) {
  unordered_map<char, int> m;

  m['I'] = 1;
  m['V'] = 5;
  m['X'] = 10;
  m['L'] = 50;
  m['C'] = 100;
  m['D'] = 500;
  m['M'] = 1000;

  int sum = 0;

  for (size_t i = 0; i < s.length(); i++) {
    if (m[s[i]] < m[s[i + 1]])
      sum -= m[s[i]];
    else
      sum += m[s[i]];
  }
  return sum;
}

int main() {
  string s = "XV";
  int result = foo(s);

  return 0;
}
