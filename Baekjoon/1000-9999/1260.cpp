#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

bool isVisited[1001] = {
    false,
};
std::vector<int> connectionList[1001];

void DFS(int start) {
  isVisited[start] = true;
  std::cout << start << " ";
  for (int i = 0; i < connectionList[start].size(); i++) {
    int childNode = connectionList[start][i];
    if (!isVisited[childNode]) DFS(childNode);
  }
}

void BFS(int start) {
  std::cout << "\n";
  std::queue<int> saveNode;

  saveNode.push(start);
  isVisited[start] = true;
  std::cout << start << " ";

  while (!saveNode.empty()) {
    for (int i = 0; i < connectionList[saveNode.front()].size(); i++) {
      int currentNode = connectionList[saveNode.front()][i]; //여기서 틀렸다. 계속 이러면 start만 하니까...

      if (!isVisited[currentNode]) {
        isVisited[currentNode] = true;
        std::cout << currentNode << " ";
        saveNode.push(currentNode);
      }
    }
    saveNode.pop();
  }
}

void init() {
  for (int i = 1; i <= 1000; i++) {
    isVisited[i] = false;
  }
}

int main() {
  int N, M, V;
  int start, dest;

  std::cin >> N >> M >> V;
  for (int i = 0; i < M; i++) {
    std::cin >> start >> dest;
    connectionList[start].push_back(dest);
    connectionList[dest].push_back(start);
  }

  //sort connection list
  for (int i = 1; i <= N; i++) {
    std::sort(connectionList[i].begin(), connectionList[i].end());
  }

  init();
  DFS(V);

  init();
  BFS(V);

  return 0;
}