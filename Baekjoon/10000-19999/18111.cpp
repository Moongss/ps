#include <iostream>

int main() {
  int N, M, B;
  int max = -1, min = 257;
  int tmp, time, maxHeight = -1;
  int minTime = 2147483647;
  int map[500][500];
  std::cin >> N >> M >> B;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> map[i][j];
      if (map[i][j] < min) min = map[i][j];
      if (map[i][j] > max) max = map[i][j];
    }
  }

  for (int currentHeight = min; currentHeight <= max; currentHeight++) {
    time = 0;
    tmp = B;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (map[i][j] - currentHeight > 0) {
          time += 2 * (map[i][j] - currentHeight);
          tmp += 1 * (map[i][j] - currentHeight);
        }

        if (map[i][j] - currentHeight < 0) {
          time += (currentHeight - map[i][j]);
          tmp -= (currentHeight - map[i][j]);
        }
      }
    }
  
    if (time <= minTime && tmp >= 0) {
      minTime = time;
      if (currentHeight > maxHeight)
        maxHeight = currentHeight;
    }
  }

  std::cout << minTime << " " << maxHeight << std::endl;
}