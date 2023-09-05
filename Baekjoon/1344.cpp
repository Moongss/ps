#include <cmath>
#include <iostream>

double A, B;
int notPrime[12] = {0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18};
int comb[19] = {
    0,
};

void setCombination() {
  comb[0] = comb[18] = 1; // comb[18] = 1, not 0
  for (int i = 1; i <= 9; i++)
    comb[i] = comb[18 - i] = comb[i - 1] * (19 - i) / i;
}

double solve() {
  double probA = A / 100;
  double probB = B / 100;

  // double test = pow(0.5f, 18);
  // std::cout << "test : " << test << std::endl;

  double sumA = 0;
  double sumB = 0;

  // 2ÁßÀ¸·Î ¹­Áö ¸»°í °ö¼ÀÀ¸·Î ¹­¾î¼­ ÇÑ¹ø¿¡ °è»ê.
  for (int i = 0; i < 12; i++) {
    sumA += comb[notPrime[i]] * pow(probA, notPrime[i]) *
            pow(1 - probA, 18 - notPrime[i]);
    sumB += comb[notPrime[i]] * pow(probB, notPrime[i]) *
            pow(1 - probB, 18 - notPrime[i]);
  }

  return (1 - sumA * sumB);
}
int main() {
  std::cin >> A >> B;

  setCombination();
  std::cout << std::fixed;
  std::cout.precision(12);
  std::cout << solve() << std::endl;
  return 0;
}