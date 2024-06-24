#include <iostream>
#include <string>  // stoi function (String to Integer)
#include <vector>

using namespace std;

static bool isNumber(const std::string& str) {
  if (str.empty()) return false;
  size_t start = (str[0] == '-') ? 1 : 0;
  if (start == 1 && str.length() == 1)
    return false;  // Only a '-' is not a number
  for (size_t i = start; i < str.length(); ++i) {
    if (!std::isdigit(str[i])) return false;
  }
  return true;
}

static int foo(vector<string>& operations) {
  vector<int> res;
  int i = 0;

  for (const auto& o : operations) {
    // Operation is a number
    if (isNumber(o)) {
      res.push_back(stoi(o));
      ++i;
    } else if (o == "C") {
      res.pop_back();
      --i;
    } else if (o == "D") {
      res.push_back(res[i - 1] * 2);
      ++i;
    } else if (o == "+") {
      res.push_back(res[i - 1] + res[i - 2]);
      ++i;
    }
  }

  int sum = 0;
  for (const auto& r : res) sum += r;

  return sum;
}

int main() {
  vector<string> operations = {"5", "-2", "4", "C", "D", "9", "+", "+"};
  int result = foo(operations);

  return 0;
}
