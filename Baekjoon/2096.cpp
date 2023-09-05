#include <iostream>

int min[5][2] = {0, };
int max[5][2] = {0, };

int main() {
  int loop, minTmp, maxTmp;
  int arr[5] = {0, };

  std::cin >> loop;

  for (int i = 1; i <= 3; i++) {
    std::cin >> arr[i];
    max[i][0] = min[i][0] = arr[i];
  }
  
  for (int i = 1; i < loop; i++) {
    for (int j = 1; j <= 3; j++) {
      std::cin >> arr[j];
    }

    for (int j = 1; j <= 3; j++) {
      int minUpdate = INT32_MAX;
      int maxUpdate = -1;
      for (int k = -1; k <= 1; k++) {
        if (j + k >= 1 && j + k <= 3) {
          minTmp = min[j + k][0] + arr[j];
          maxTmp = max[j + k][0] + arr[j];

          if (minUpdate > minTmp) minUpdate = minTmp;
          if (maxUpdate < maxTmp) maxUpdate = maxTmp;
        }
      }

      min[j][1] = minUpdate;
      max[j][1] = maxUpdate;
    }

    for (int j = 1; j <= 3; j++) {
      min[j][0] = min[j][1];
      max[j][0] = max[j][1];
    }
  }

  minTmp = min[1][0];
  maxTmp = max[1][0];
  for (int i = 2; i <= 3; i++) {
    if (minTmp > min[i][0]) minTmp = min[i][0];
    if (maxTmp < max[i][0]) maxTmp = max[i][0];
  }

  std::cout << maxTmp << " " << minTmp << "\n";
  
  return 0;
}