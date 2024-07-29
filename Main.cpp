#include <iostream>
#include <stack>

using namespace std;

static string foo(string s) {
  stack<string> my_stack;

  string word = "";
  for (auto it = s.begin(); it != s.end(); ++it) {
    char l = *it;
    // We have a word we want to add to stack
    if (l == ' ' and word != "") {
      my_stack.push(word);
      word = "";
    }

    // We are at the end and need to add the last word
    else if (it == s.end() - 1 and l != ' ') {
      word += l;
      my_stack.push(word);
    }

    // We have no more word to add, only white space
    else if (l == ' ' and word == "") {
      continue;
    }

    // We have a char we can add to word
    else {
      word += l;
    }
  }

  string result = "";
  while (!my_stack.empty()) {
    result += my_stack.top() + " ";
    my_stack.pop();
  }

  // Remove the last white space
  result.pop_back();

  return result;
}

int main() {
  string s = "the sky is blue";
  cout << foo(s);

  return 0;
}
