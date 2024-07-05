#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Finds min difference in already sorted vector, critPoints is already sorted
static int findMinDifference(std::vector<int>& nums) {
  int minDiff = INT_MAX;

  for (size_t i = 1; i < nums.size(); ++i) {
    int diff = nums[i] - nums[i - 1];
    if (diff < minDiff) {
      minDiff = diff;
    }
  }

  return minDiff;
}

static vector<int> foo(ListNode* head) {
  int minDistance = -1;
  int maxDistance = -1;
  int i = 0;
  vector<int> critPoints;

  int prevVal = -1;
  int nextVal = -1;
  int currVal = -1;

  for (ListNode* temp = head; temp->next != nullptr; temp = temp->next) {
    prevVal = currVal;
    currVal = temp->val;
    nextVal = temp->next->val;

    // Local minima or local maxima
    if (currVal < nextVal && currVal < prevVal && i != 0 ||
        currVal > nextVal && currVal > prevVal && i != 0)
      critPoints.push_back(i);

    ++i;
  }

  // We need two critical point to calc distance
  if (critPoints.size() < 2) return {-1, -1};

  maxDistance = *prev(critPoints.end()) - *critPoints.begin();
  minDistance = findMinDifference(critPoints);

  return {minDistance, maxDistance};
}

int main() {
  // Create a list with 5,3,1,2,5,1,2
  ListNode* head = new ListNode(5);
  head->next = new ListNode(3);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(2);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(1);
  head->next->next->next->next->next->next = new ListNode(2);

  vector<int> result = foo(head);

  // To print the list and verify
  ListNode* current = head;
  while (current != nullptr) {
    cout << current->val << " ";
    current = current->next;
  }
  cout << endl;

  // Free the allocated memory
  while (head != nullptr) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}
