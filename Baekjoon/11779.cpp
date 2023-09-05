#include <iostream>
#include <queue>

#define INF 2100000000

std::vector<std::pair<int, int> > bus[1001]; //endPoint, cost

struct info {
  int cost;
  std::queue<int> citySequence;
};

info result[1001];

void solve(int startPoint) {
  std::priority_queue<std::pair<int, int> > pq;
  
  result[startPoint].cost = 0;
  result[startPoint].citySequence.push(startPoint);

  pq.push({-result[startPoint].cost, startPoint});
  while (!pq.empty()) {
    std::pair<int, int> currentElement = pq.top();
    pq.pop();

    int currentCost = -currentElement.first;
    int currentNode = currentElement.second;

    if (result[currentNode].cost < currentCost)
      continue;
    
    for (int i = 0; i < bus[currentNode].size(); i++) {
      std::pair<int, int> adjElement = bus[currentNode][i];

      int adjNode = adjElement.first;
      int adjCost = adjElement.second;

      if (result[adjNode].cost > currentCost + adjCost) {
        //std::cout << "currentNode : " << currentNode << ", adjNode : " << adjNode << std::endl;
        //std::cout << "currentNode's sequence : " << result[currentNode].citySequence.size() << std::endl;
        result[adjNode].citySequence = std::queue<int>();
        std::queue<int> tmp = result[currentNode].citySequence;
        while (!tmp.empty()) {
          result[adjNode].citySequence.push(tmp.front());
          tmp.pop();
        }
        result[adjNode].citySequence.push(adjNode);
        result[adjNode].cost = currentCost + adjCost;
        pq.push({-result[adjNode].cost, adjNode});      
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
    bus[S].push_back({E, C}); //같은 경로로 A -> B = 10, A -> B 5 들어와도 어차피 업데이트 되서 상관없지 않나?
  }

  int startPoint, endPoint;
  std::cin >> startPoint >> endPoint;

  for (int i = 0; i <= N; i++) {
    result[i].cost = INF;
  }
  solve(startPoint);

  std::cout << result[endPoint].cost << std::endl;
  std::cout << result[endPoint].citySequence.size() << std::endl;

  while (!result[endPoint].citySequence.empty()) {
    std::cout << result[endPoint].citySequence.front() << " ";
    result[endPoint].citySequence.pop();
  }
  return 0;
}

