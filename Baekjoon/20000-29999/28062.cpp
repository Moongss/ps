#include <iostream>
#include <vector>

int N;
int main() {
  std::cin >> N;

  int num;
  int result = 0;
  int oddSum = 0;
  int oddCnt = 0;
  int oddMin = 1001;
  for (int i = 0; i < N; i++) {
    std::cin >> num;
    if (num % 2 == 0)
      result += num;
    else {
      oddSum += num;
      oddCnt++;
      if (oddMin > num)
        oddMin = num;
    }
  }

  result += oddSum;
  if (oddCnt % 2)
    result -= oddMin;

  std::cout << result << std::endl;
  return 0;
}