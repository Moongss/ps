#include <iostream>

int main() {
  int H, W, N;
  int testNum;

  std::cin >> testNum;

  for (int i = 0; i < testNum; i++) {
    std::cin >> H >> W >> N;
    int floor = N % H;
    int roomNumber = N / H + 1;

    if (floor == 0) {
      floor = H;
      roomNumber -= 1;
    }

    if (roomNumber < 10)
      std::cout << floor << "0" << roomNumber << std::endl;
    else
      std::cout << floor << roomNumber << std::endl;
  }

  return 0;
}