#include <iostream>

int A, B, C; //10 11 12 10^11 % 12

long long solve(int A, int B, int C) {
  if (B == 1)
    return A % C;
  
  long long x = solve(A, B / 2, C);
  if (B % 2 == 0)
    return (x * x) % C;
  else
    return ((x * x) % C * (A % C)) % C;
}

int main() {

  std::cin >> A >> B >> C;
  std::cout << solve(A, B, C) << std::endl;
  
  return 0;
}