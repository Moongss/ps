#include <iostream>
#include <memory.h>
#define INF 100

int item[101];
int adj[101][101] = {0, };

int main() {
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      adj[i][j] = INF;
      if (i == j)
        adj[i][j] = 0;
    }
  }

  int N, M, R;
  std::cin >> N >> M >> R;
  for (int i = 1; i <= N; i++){
    std::cin >> item[i];
  }

  for (int i = 0; i < R; i++) {
    int a, b, l;
    std::cin >> a >> b >> l;
    adj[a][b] = adj[b][a] = l;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        if (adj[j][k] > adj[j][i] + adj[i][k])
          adj[j][k] = adj[j][i] + adj[i][k];
      }
    }
  }

  int max = 0;
  for (int i = 1; i <= N; i++) {
    int tmp = 0;
    for (int j = 1; j <= N; j++) {
      if (adj[i][j] <= M)
        tmp += item[j];     
    }
    if (tmp > max) max = tmp;
  }

  std::cout << max << std::endl;
  return 0;  
}