#include <iostream>
#include <stack>

using namespace std;

static string foo(string s) {
  stack<char> stack;

  for (auto c : s) {
    string reverse = "";
    if (c == ')') {
      // Reverse the the word within the bracket
      while (stack.top() != '(') {
        reverse += stack.top();
        stack.pop();
      }
      // Remove the opening '('
      stack.pop();

      // Once reversed add it back to the stack
      for (auto r : reverse) stack.push(r);

    } else {
      stack.push(c);
    }
  }

  string result = "";
  while (!stack.empty()) {
    result = stack.top() + result;
    stack.pop();
  }
  return result;
}

int main() {
  string s = "(u(love)i)";
  string result = foo(s);

  return 0;
}
