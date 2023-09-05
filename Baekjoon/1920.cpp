#include <iostream>
#include <set>

int main() {
  //??
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M, target;
  std::set<int> numList;

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> target;
    numList.insert(target);
  }

  std::cin >> M;
  for (int i = 0; i < M; i++) {
    std::cin >> target;
    if (numList.find(target) != numList.end())
      std::cout << "1\n";
    else
      std::cout << "0\n";
  }
  return 0;
}