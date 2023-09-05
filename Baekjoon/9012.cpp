#include <iostream>

int main() {
  int VPSlistnum;
  int ParenthesisCount;
  std::string VPS;

  std::cin >> VPSlistnum;
  for (int i = 0; i < VPSlistnum; i++) {
    ParenthesisCount = 0;
    std::cin >> VPS;
    for (int j = 0; j < VPS.length(); j++) {
      if (VPS[j] == '(')
        ParenthesisCount++;
      else
        ParenthesisCount--;

      if (ParenthesisCount < 0) break;
    }

    if (ParenthesisCount == 0)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }
  return 0;
}