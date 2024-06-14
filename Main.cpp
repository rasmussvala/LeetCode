#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

static int unicodeToIndex(int letter) {
  // Unicode for Latin Alphabet Lowercase:
  // a = 97, b = 98, c = 99...  =>
  // -97                        =>
  // a = 0, b = 1, c = 2...
  return letter - 97;
}

class Graph {
 public:
  map<int, bool> visited;
  map<int, list<int> > adj;

  // Function to add an edge to graph
  void addEdge(int v, int w);

  // DFS traversal of the vertices
  // reachable from v
  void DFS(int v);
};

void Graph::addEdge(int v, int w) {
  // Add w to v’s list.
  adj[v].push_back(w);
}

void Graph::DFS(int v) {
  // Mark the current node as visited and
  // print it
  visited[v] = true;
  cout << v << " ";

  // Recur for all the vertices adjacent
  // to this vertex
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i]) DFS(*i);
}

static int foo(vector<string>& words, vector<char>& letters,
               vector<int>& score) {
  Graph g{};

  for (int i = 0; i < words.size(); i++) {
    for (int j = 0; j < words.size(); j++) {
      if (i != j) g.addEdge(i, j);
    }
  }

  g.DFS(1);

  return 0;
}

int main() {
  vector<string> words = {"dog", "cat", "dad", "good"};
  std::vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
  vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0,
                       0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int result = foo(words, letters, score);

  return 0;
}
