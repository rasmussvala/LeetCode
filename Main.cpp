#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

static int foo(vector<string>& words, vector<char>& letters,
               vector<int>& score) {
  // Save how many letters we have in a map
  unordered_map<char, int> lettersCounter;
  for (char letter : letters) {
    lettersCounter[letter]++;
  }

  int totalScore = 0;

  // Recursive function to explore combinations of words to maximize score
  function<void(int, unordered_map<char, int>, int)> explore =
      [&](int index, unordered_map<char, int> letterCounter, int currScore) {
        totalScore = max(totalScore, currScore);
        if (index == words.size()) return;

        // Loop through the rest of the words and se if they are valid
        for (int i = index; i < words.size(); ++i) {
          unordered_map<char, int> tmpCounter = letterCounter;
          string word = words[i];
          int wordScore = 0;
          bool isValid = true;

          for (char ch : word) {
            if (tmpCounter[ch] > 0) {
              tmpCounter[ch]--;
              wordScore += score[ch - 'a'];
            } else {
              isValid = false;
              break;
            }
          }

          // If the word was valid, we try to create even more words
          if (isValid) {
            explore(i + 1, tmpCounter, currScore + wordScore);
          }
        }
      };

  explore(0, lettersCounter, 0);
  return totalScore;
}

int main() {
  vector<string> words = {"dog", "cat", "dad", "good"};
  std::vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
  vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0,
                       0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int result = foo(words, letters, score);

  return 0;
}
