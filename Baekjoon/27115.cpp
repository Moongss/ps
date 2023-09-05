#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

#define MIN_P 1
typedef std::pair<std::pair<int, int>, int> T;

int N, M, K;
int visit[3001][3001];

std::vector<T> input;
std::queue<T> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int inputIdx = 0;

bool compare(T a, T b) { return a.second > b.second; }

void solve() {
  int y, x, p;

  // q.push(input[0]);

  while (!q.empty()) {
    std::pair<std::pair<int, int>, int> elem = q.front();
    y = elem.first.first;
    x = elem.first.second;
    p = elem.second;

    // std::cout << p << std::endl;
    q.pop();
    if (visit[y][x] > p)
      continue;
    visit[y][x] = p;

    while (inputIdx < K) {
      if (p > input[inputIdx].second)
        break;
      q.push(input[inputIdx]);
      inputIdx++;
    }

    for (int i = 0; i < 4; i++) {
      int newY = y + dy[i];
      int newX = x + dx[i];
      int newP = p - 1;
      if (newY < 1 || newY > N || newX < 1 || newX > M)
        continue;
      if (visit[newY][newX] >= newP)
        continue;
      visit[newY][newX] = newP;
      if (newP > 1) {
        q.push({{newY, newX}, newP});
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> M >> K;

  for (int i = 0; i < K; i++) {
    int x, y, p;
    std::cin >> y >> x >> p;
    visit[y][x] = p + 1;
    input.push_back({{y, x}, p + 1});
  }

  std::sort(input.begin(), input.end(), compare);
  q.push(input[inputIdx++]);
  solve();

  int result = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (visit[i][j] > 0)
        result++;
    }
  }
  std::cout << result << "\n";
  return 0;
}
