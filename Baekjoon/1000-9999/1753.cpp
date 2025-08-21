#include <iostream>
#include <queue>
#include <vector>

#define INF 42424242

struct compare {
  bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
    return a.second > b.second;
  }
};

int V, E;
std::vector<std::pair<int, int> >adj[20001]; //adj list
int dist[20001];

void solve(int targetNode) {
  std::priority_queue<std::pair<int, int>> pq; //adj node, dist

  dist[targetNode] = 0;
  pq.push({0, targetNode});

  while (!pq.empty()) {
    std::pair<int, int> minElement = pq.top();
    pq.pop();
    int currentDist = -minElement.first;
    int currentNode = minElement.second;

    //optional


    for (int i = 0; i < adj[currentNode].size(); i++) {
      std::pair<int, int> adjElement = adj[currentNode][i];
      int adjNode = adjElement.first;
      int adjDist = adjElement.second;

      if (dist[adjNode] > currentDist + adjDist) {
        dist[adjNode] = currentDist + adjDist;
        pq.push({-dist[adjNode], adjNode});
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int targetNode;
  int u, v, w;

  std::cin >> V >> E;
  std::cin >> targetNode;

  for (int i = 0; i < E; i++) {
    std::cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  std::fill_n(dist, V + 1, INF);
  solve(targetNode);

  for (int i = 1; i <= V; i++) {
    if (dist[i] == INF)
      std::cout << "INF" << "\n";
    else
      std::cout << dist[i] << "\n";
  }
  return 0;
}