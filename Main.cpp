#include <iostream>
#include <vector>

using namespace std;

static bool foo(vector<int>& flowerbed, int n) {
  int counter = 0;
  for (int i = 0; i < flowerbed.size(); i++) {
    if (flowerbed[i] == 0) {
      bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
      bool emptyRightPlot =
          (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);

      // If both plots are empty, we can plant a flower here.
      if (emptyLeftPlot && emptyRightPlot) {
        flowerbed[i] = 1;
        counter++;
        if (counter >= n) return true;
      }
    }
  }
  return counter >= n;
}

int main() {
  vector<int> flowerbed = {1, 0, 0, 0, 0, 1};
  int n = 2;
  cout << foo(flowerbed, n);

  return 0;
}
