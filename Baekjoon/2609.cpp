#include <iostream>
#include <string>

int solve(int A, int B) {
  if (B == 0)  // division zero error
    return A;
  else
    return solve(B, A % B);
}

void swap(int &A, int &B) {
  int temp;

  temp = A;
  A = B;
  B = temp;
}

int main() {
  int N, M;

  std::cin >> N >> M;
  if (M > N) swap(M, N);

  int gcd = solve(M, N % M);
  int lcm = N * M / gcd;

  std::cout << gcd << std::endl;  // gcd
  std::cout << lcm << std::endl;

  return 0;
}