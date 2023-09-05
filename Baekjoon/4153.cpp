#include <iostream>

int main() {
  int A, B, C;

  while (true) {
    std::cin >> A >> B >> C;
    if (A == B && B == C && C == 0) break;

    if (A * A + B * B == C * C || A * A + C * C == B * B ||
        B * B + C * C == A * A)
      std::cout << "right" << std::endl;
    else
      std::cout << "wrong" << std::endl;
  }

  return 0;
}