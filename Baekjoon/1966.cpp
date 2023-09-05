#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
  int N;
  int M, importance, targetIndex;
  int cnt;
  std::vector<int> importanceList;
  std::queue<std::pair<int, int>> printer;
  std::pair<int, int> printData;

  std::cin >> N;
  while (N > 0) {
    cnt = 0;
    importanceList.clear();
    while (!printer.empty()) {
      printer.pop();
    }

    std::cin >> M;
    std::cin >> targetIndex;

    for (int i = 0; i < M; i++) {
      std::cin >> importance;
      importanceList.push_back(importance);
      printer.push(std::make_pair(i, importance));
    }

    std::sort(importanceList.begin(), importanceList.end());

    while(!printer.empty()) {
      printData = printer.front();
      if (printData.second == importanceList.back()) {
        if (printData.first == targetIndex) {
          std::cout << ++cnt << std::endl;
          break;
        }
        printer.pop();
        importanceList.pop_back();
        cnt++;
      }
      else {
        printer.pop();
        printer.push(printData);
      }
    }

    N--;
  }
}