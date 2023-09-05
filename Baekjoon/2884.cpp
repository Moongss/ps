#include <iostream>

int main() {
  
  int H, M;

  std::cin >> H >> M;

    if (M - 45 < 0)
      H -= 1;
    
    std::cout << ((H + 24) % 24)<< " " << ((M - 45 + 60) % 60) << std::endl;
  
  return 0;
}