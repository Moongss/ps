#include <iostream>
#include <queue>

#define INF 2100000000

std::vector<std::pair<int, int> > bus[1001]; //endPoint, cost
int cost[1001];

void solve(int startPoint) {
  std::priority_queue<std::pair<int, int> > pq;

  pq.push({0, startPoint});
  cost[startPoint] = 0;

  while (!pq.empty()) {
    std::pair<int, int> currentElement = pq.top();
    pq.pop();

    int currentCost = -currentElement.first;
    int currentNode = currentElement.second;

    if (cost[currentNode] < currentCost)
      continue;
    
    for (int i = 0; i < bus[currentNode].size(); i++) {
      std::pair<int, int> adjElement = bus[currentNode][i];

      int adjNode = adjElement.first;
      int adjCost = adjElement.second;

      if (cost[adjNode] > currentCost + adjCost) {
        cost[adjNode] = currentCost + adjCost;
        pq.push({-cost[adjNode], adjNode});      
      }
    }
  }
  
}


int main() {
  int N, M;
  std::cin >> N >> M;

  int S, E, C;
  for (int i = 0; i < M; i++) {
    std::cin >> S >> E >> C;
    bus[S].push_back({E, C});
  }

  int startPoint, endPoint;
  std::cin >> startPoint >> endPoint;

  std::fill_n(cost, N + 1, INF); 
  solve(startPoint);

  std::cout << cost[endPoint] << std::endl;
  return 0;
}

