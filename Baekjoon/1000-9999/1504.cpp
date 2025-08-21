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

    // by question condition..
    // if (cost[currentNode] < currentCost)
    //   continue;
    
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

void initCost(int N) {
  for (int i = 0; i <= N; i++) {
    cost[i] = INF;
  }
}

int main() {
  int N, M;
  std::cin >> N >> M;

  int S, E, C;
  for (int i = 0; i < M; i++) {
    std::cin >> S >> E >> C;

    bus[S].push_back({E, C});
    bus[E].push_back({S, C});
  }

  int u, v;
  std::cin >> u >> v;

  //1 -> u -> v -> N
  //1 -> v -> u -> N
  
  //1 -> u, v
  initCost(N);
  solve(1);
  int startToU = cost[u];
  int startToV = cost[v];

  //v -> u, N
  initCost(N);
  solve(u);
  int uToV = cost[v];
  int uToEnd = cost[N];
  
  //u -> v, N
  initCost(N);
  solve(v);
  int vToU = cost[u]; //maybe same uToV -> 무방향이라..
  int vToEnd = cost[N];

  
  long result = -1;
  if (startToU != INF && uToV != INF && vToEnd != INF)
    result = startToU + uToV + vToEnd;
  if (startToV != INF && vToU != INF && uToEnd != INF) //if로 한건 둘 다 경로가 있을 수 있어서
    result = (startToV + vToU + uToEnd < result) ? startToV + vToU + uToEnd : result;

  std::cout << result << "\n";
  return 0;
}

