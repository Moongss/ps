#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

typedef std::pair<int, int> pair;
std::vector<std::pair<int, int> >tree[10001];
bool visit[10001] = {0, };

std::pair<int, int> solve(int rootNode) {
  int maxLength = 0;
  int maxNode = rootNode;
  visit[rootNode] = true;

  for (int i = 0; i < tree[rootNode].size(); i++) {
    pair connectElement = tree[rootNode][i];
    pair DFSResult;
    int currentLength = 0;
    if (visit[connectElement.first] == false) {
      DFSResult = solve(connectElement.first);
      currentLength = connectElement.second + DFSResult.second;
    }

    if (maxLength < currentLength) {
      maxNode = DFSResult.first;
      maxLength = currentLength;
    }
  }
  return {maxNode, maxLength};
}

int main() {
  int V;
  int targetNode;
  int connectNode, weight;
  
  std::cin >> V;
  for (int i = 0; i < V - 1; i++) {
    std::cin >> targetNode >> connectNode >> weight;
    tree[targetNode].push_back({connectNode, weight});
    tree[connectNode].push_back({targetNode, weight});
  }

  int tmp = 0;
  for (int i = 1; i <= V; i++) {
    std::memset(visit, 0, sizeof(visit));
    int maxLength = solve(i).second;

    tmp = (maxLength > tmp) ? maxLength : tmp;
  }
  std::cout << tmp << std::endl;

  // std::memset(visit, 0, sizeof(visit));
  // std::pair<int, int> result = solve(1);
  // std::cout << "maxNode : " << result.first << std::endl;
  // std::cout << "maxLength : " << result.second << std::endl;
  
  // std::memset(visit, 0, sizeof(visit));
  // result = solve(result.first);
  // std::cout << "maxNode : " << result.first << std::endl;
  // std::cout << "maxLength : " << result.second << std::endl;

  // std::cout << result.second << std::endl;
  return 0;
}
