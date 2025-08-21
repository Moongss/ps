#include <iostream>

#define MAX 2000000000

int N;
int arr[100001] = {
    0,
};

int getAbs(int x) {
  if (x > 0)
    return x;
  return -x;
}

int main() {
  std::cin >> N;
  int start = 0, end = N - 1;

  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }

  int result = MAX;
  int min, max;

  while (start < end) {
    int tmp = arr[start] + arr[end];
    if (getAbs(tmp) <= getAbs(result)) {
      result = tmp;
      min = arr[start];
      max = arr[end];
    }

    if (tmp > 0) {
      end--;
    } else {
      start++;
    }
  }

  std::cout << min << " " << max << std::endl;
  return 0;
}