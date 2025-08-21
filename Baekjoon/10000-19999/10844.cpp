#include <iostream>

int main() {
  long save[12] = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}; //padding 
  long tmp[12];
  long sum = 0;
  int N;

  std::cin >> N;
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < 11; j++){
      tmp[j] = (save[j - 1] + save[j + 1]) % 1000000000;
    }

    for (int j = 1; j < 11; j++){
      save[j] = tmp[j];
    }
  }

  for (int i = 1; i < 11; i++) {
    sum += save[i] % 1000000000;
  }

  std::cout << sum % 1000000000;
  return 0;
}