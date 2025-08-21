#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, L, num;
  std::vector<int> numArr;
  std::deque<std::pair<int, int> > minQueue;
  
  std::cin >> N >> L;
  for (int i = 0; i < N; i++) {
    std::cin >> num;
    numArr.push_back(num);
  }

  for (int i = 0; i < N; i++) {
    if (!minQueue.empty() && minQueue.front().first + L == i)
      minQueue.pop_front();
    while (!minQueue.empty() && minQueue.back().second > numArr[i])
      minQueue.pop_back();

    minQueue.push_back({i, numArr[i]});
    // for (int i = 0; i < minQueue.size(); i++) {
    //   std::cout << minQueue[i].second << " ";
    // }
    // std::cout << std::endl;
    std::cout << minQueue.front().second << " ";
  }

  return 0;
} //priority_queue ? 값 추가하고 최소인데 범위 밖이면 빼기? 이게 더 편할려나