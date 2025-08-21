#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int N, weight, height;
  int rank = 1;
  int rankList[50] = {0, };
  std::vector<std::pair<int, int>> infoList;

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> weight >> height;
    infoList.push_back(std::make_pair(weight, height));
  }

  for (int i = 0; i < N; i++) {
    rankList[i] = 1;
    for (int j = 0; j < N; j++) {
      if (infoList[i].first < infoList[j].first &&
          infoList[i].second < infoList[j].second) {
        rankList[i]++;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    std::cout << rankList[i] << " ";
  }

  return 0;
}