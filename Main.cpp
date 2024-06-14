#include <iostream>
#include <vector>

using namespace std;

static int unicodeToIndex(int letter) {
  // Unicode for Latin Alphabet Lowercase:
  // a = 97, b = 98, c = 99...  =>
  // -97                        =>
  // a = 0, b = 1, c = 2...
  return letter - 97;
}

static int foo(vector<string>& words, vector<char>& letters,
               vector<int>& score) {
  vector<char> lettersCopy;
  vector<char>::iterator it;
  vector<pair<string, int>> accaptableWords;  // Word and score
  vector<int> wordScore;
  bool lettersExists;

  // Check if words are ok and add accaptable to vector
  for (const auto& word : words) {
    // Reset letters for every word
    lettersCopy = letters;
    lettersExists = true;

    for (const auto& letter : word) {
      it = find(lettersCopy.begin(), lettersCopy.end(), letter);

      // Element was not found
      if (it == lettersCopy.end()) {
        lettersExists = false;
        break;
      }

      // Remove the letter since "letter can only be used once"
      auto index = it - lettersCopy.begin();
      lettersCopy.erase(next(lettersCopy.begin(), index));
    }

    if (lettersExists) accaptableWords.push_back(make_pair(word, 0));
  }

  // No words accaptable words exists
  if (accaptableWords.size() == 0) return 0;

  // Set scores to all words
  for (auto& pair : accaptableWords) {
    string word = pair.first;
    int sum = 0;
    for (const auto& letter : word) {
      sum += score[unicodeToIndex(letter)];
    }
    // Update the score
    pair.second = sum;
  }

  // Return the greatest word
  auto ptrMaxPair = max_element(
      accaptableWords.begin(), accaptableWords.end(),
      [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; });
  ;
  auto& maxPair = *ptrMaxPair;
  return maxPair.second;
}

int main() {
  vector<string> words = {"dog", "cat", "dad", "good"};
  std::vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
  vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0,
                       0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int result = foo(words, letters, score);

  int test = 'a' - 97;
  return 0;
}
