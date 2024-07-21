#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

static bool isvowel(char v) {
  unordered_map<char, bool> vowels = {
      {'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true},
      {'A', true}, {'E', true}, {'I', true}, {'O', true}, {'U', true}};

  return vowels.find(v) != vowels.end();
}

static string foo(string s) {
  vector<int> indices;

  // Find all indices of vowels
  for (int i = 0; i < s.length(); ++i)
    if (isvowel(s[i])) indices.push_back(i);

  for (int i = 0; i < indices.size() / 2; i++) {
    char temp = 0;
    int min = indices[i];
    int max = indices[indices.size() - 1 - i];

    if (min > max) break;

    temp = s[min];
    s[min] = s[max];
    s[max] = temp;
  }

  return s;
}

int main() {
  string s = "Egad! Loretta has Adams as mad as a hatter. Old age!";
  cout << foo(s);

  return 0;
}
