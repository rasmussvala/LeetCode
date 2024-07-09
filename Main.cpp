#include <iostream>
#include <vector>

using namespace std;

static double foo(vector<vector<int>>& customers) {
  // All I did was a code review, it's late
  int n = customers.size();
  double time_waiting = customers[0][1];
  int finished_prev = customers[0][0] + customers[0][1];

  for (int customer_ind = 1; customer_ind < n; ++customer_ind) {
    vector<int> times = customers[customer_ind];
    int arrive = times[0];

    int start_cook = max(arrive, finished_prev);
    int end_time = start_cook + times[1];
    finished_prev = end_time;
    time_waiting += end_time - arrive;
  }

  return time_waiting / n;
}

int main() {
  vector<vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};
  int result = foo(customers);

  return 0;
}
