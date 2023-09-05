#include <iostream>
#include <queue>

#define INF 2100000000

std::vector<std::pair<int, int> > bus[1001]; //endPoint, cost

int cost[1001];
int studentToXCost[1001] = {0, };

void solve(int startPoint) {
  std::priority_queue<std::pair<int, int> > pq;
  
  cost[startPoint] = 0;
  pq.push({0, startPoint});
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
  int N, M, X;
  std::cin >> N >> M >> X;

  int S, E, C;
  for (int i = 0; i < M; i++) {
    std::cin >> S >> E >> C;

    bus[S].push_back({E, C});
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      cost[j] = INF;
    }

    solve(i);
    if (i != X)
      studentToXCost[i] += cost[X];
    else { // a->x, x->a 가능이니까
      for (int j = 1; j <= N; j++) {
       studentToXCost[j] += cost[j]; 
      }
    }
  }

  int max = -1;
  for (int i = 1; i <= N; i++) {
    if (max < studentToXCost[i])
      max = studentToXCost[i];
  }

  std::cout << max << "\n";
  return 0;
}

