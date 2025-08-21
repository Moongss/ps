#include <deque>
#include <iostream>

int N;
std::deque<std::pair<int, int>> dq;

int main() {
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    int num;
    std::cin >> num;
    dq.push_back({i + 1, num});
  }

  while (!dq.empty()) {
    int id = dq.front().first;
    int value = dq.front().second;
    dq.pop_front();

    std::cout << id << " ";
    if (value > 0) {
      while (--value) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
    } else {
      while (value++) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }
  }

  std::cout << std::endl;
  return 0;
}