#include <iostream>

using namespace std;

static int foo(int numBottles, int numExchange) {
  int sum = numBottles;

  while (numBottles >= numExchange) {
    int newBottles = numBottles / numExchange;
    int rest = numBottles % numExchange;
    sum += newBottles;
    numBottles = newBottles + rest;
  }

  return sum;
}

int main() {
  int numBottles = 15;
  int numExchange = 4;
  int result = foo(numBottles, numExchange);

  return 0;
}
