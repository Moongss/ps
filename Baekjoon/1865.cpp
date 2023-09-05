#include <iostream>
#include <vector>

#define INF 42424242

std::vector<std::pair<int, int> > adj[501];
int dist[501] = {0, };
int N;

bool solve() {

  dist[1] = 0;
  for (int i = 1; i <= N; i++) {
    for (int start = 1; start <= N; start++) {
      for (int k = 0; k < adj[start].size(); k++) {
        std::pair<int, int> element = adj[start][k];
        int end = element.first;
        int cost = element.second;

        if (dist[end] > dist[start] + cost) {
          dist[end] = dist[start] + cost;
          if (i == N) return true;         
        }
      } 
    } 
  }
  return false;
}


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  
  int TC;
  int M, C;
  int S, E, T;
  
  std::cin >> TC;
  for (int i = 0; i < TC; i++)   {
    std::cin >> N >> M >> C;
    std::fill_n(dist, 501, INF);
    for (int j = 0; j <= 500; j++) {
      adj[j].clear();
    }

    for (int j = 0; j < M; j++) {
      std::cin >> S >> E >> T;
      adj[S].push_back({E, T});
      adj[E].push_back({S, T});
    }
    for (int j = 0; j < C; j++) {
      std::cin >> S >> E >> T;
      adj[S].push_back({E, -T});
    }

    if (solve())
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
  }

  return 0;
}
