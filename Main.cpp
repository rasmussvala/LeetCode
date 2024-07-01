#include <iostream>
#include <vector>

using namespace std;

static bool foo(vector<int>& arr) {
  int counter = 0;
  int maxCounter = 0;

  for (const auto& a : arr) {
    if (a % 2 != 0)
      ++counter;
    else
      counter = 0;
    if (counter > maxCounter) maxCounter = counter;
  }

  return maxCounter >= 3;
}

int main() {
  vector<int> arr = {
      953, 149, 296, 955, 901, 139, 414, 667, 660, 803, 790, 391, 536, 275, 709,
      713, 724, 501, 887, 183, 325, 168, 43,  879, 839, 969, 326, 855, 536, 950,
      241, 463, 967, 503, 786, 481, 99,  445, 815, 357, 284, 38,  970, 588, 820,
      984, 799, 885, 171, 313, 670, 45,  703, 18,  636, 379, 82,  481, 36,  459,
      388, 812, 126, 53,  474, 422, 914, 94,  841, 778, 236, 770, 117, 415, 989,
      846, 407, 763, 784, 148, 886, 828, 842, 909, 299, 564, 501, 731, 850, 361,
      306, 297, 667, 518, 714, 151, 73,  346, 152, 111};
  bool result = foo(arr);
  return 0;
}
