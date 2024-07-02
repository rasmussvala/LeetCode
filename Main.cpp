#include <iostream>

using namespace std;

// DisjSet class copied from GeeksfromGeeks:
// https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
class DisjSet {
  int *rank, *parent, n;

 public:
  DisjSet(int n) {
    rank = new int[n];
    parent = new int[n];
    this->n = n;
    makeSet();
  }

  void makeSet() {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);

    return parent[x];
  }

  void Union(int x, int y) {
    int xset = find(x);
    int yset = find(y);

    if (xset == yset) return;

    // Modification from original code to make the smallest set be the parent
    if (xset > yset) {
      parent[xset] = yset;
    } else if (xset < yset) {
      parent[yset] = xset;
    }

    else {
      parent[yset] = xset;
      xset = xset + 1;
    }
  }
};

static string foo(string s1, string s2, string baseStr) {
  int n = 26;  // Since there are 26 letters in the English alphabet
  DisjSet set(n);

  for (size_t i = 0; i < s1.size(); ++i) set.Union(s1[i] - 'a', s2[i] - 'a');

  string result = "";
  for (size_t i = 0; i < baseStr.size(); i++)
    result += set.find(baseStr[i] - 'a') + 'a';

  return result;
}

int main() {
  string s1, s2, baseStr;
  s1 = "parker";
  s2 = "morris";
  baseStr = "parser";
  string result = foo(s1, s2, baseStr);

  return 0;
}
