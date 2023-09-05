#include <iostream>
#include <queue>

int main() {
  int N;
  std::queue<int> numList;

  std::cin >> N;
  for (int i = 1; i <= N; i++) numList.push(i);

  while (numList.size() > 1) {
    numList.pop();
    numList.push(numList.front());
    numList.pop();
  }

  std::cout << numList.front() << std::endl;
}