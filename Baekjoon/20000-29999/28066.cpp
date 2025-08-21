#include <deque>
#include <iostream>

int N, K;
std::deque<int> dq;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  
  std::cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    dq.push_back(i);
  }

  while (dq.size() > K) {
    dq.push_back(dq.front());
    for (int i = 0; i < K; i++)
      dq.pop_front();
  }
  std::cout << dq.front();
  return 0;
}