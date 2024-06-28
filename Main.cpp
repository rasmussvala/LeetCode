#include <iostream>
#include <vector>

using namespace std;

static vector<double> foo(double celsius) {
  return {celsius + 273.15, celsius * 1.80 + 32.00};
}

int main() {
  int c = 36.50;
  vector<double> result = foo(c);

  return 0;
}
