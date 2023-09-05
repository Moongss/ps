#include <iostream>

int arr[2001];
bool dp[2001][2001];
int N, M;

void init() {

  for (int i = 1; i <= N; i++) {
    dp[i][i] = true;
    if (i < N && arr[i] == arr[i + 1])
      dp[i][i + 1] = true;
  }

  for (int i = 3; i <= N; i++) {
    for (int j = 1; j <= N - i + 1; j++) {
      int a = j;
      int b = j + i - 1;
      if (dp[a + 1][b - 1] && arr[a] == arr[b])
        dp[a][b] = true;
    }
  }

  // for (int i = 1; i <= N; i++) {
  //   for (int j = 1; j <= N; j++) {
  //     std::cout << dp[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 1; i <= N; i++)
    std::cin >> arr[i];

  init();
  int S, E;
  std::cin >> M;
  for (int i = 0; i < M; i++) {
    std::cin >> S >> E;
    std::cout << dp[S][E] << '\n';
    // std::cout << solve(S, E) << std::endl;
  }
}
