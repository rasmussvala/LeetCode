#include <iostream>
#include <vector>

using namespace std;

static int foo(vector<string>& logs) {
  int depth = 0;

  for (const auto& l : logs) {
    if (l == "./")
      continue;
    else if (l == "../" && depth != 0)
      --depth;
    else if (l[0] != '.')
      ++depth;
  }

  return depth;
}

int main() {
  vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};
  int result = foo(logs);

  return 0;
}
