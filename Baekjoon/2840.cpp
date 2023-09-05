#include <iostream>

char wheel[26];
bool isWritten[26];
int N, K, S;
char ch;

int main() {
  for (int i = 0; i <= 25; i++) {
    wheel[i] = '?';
    isWritten[i] = false;
  }

  int pos = 0;
  std::cin >> N >> K;
  while (K--) {
    std::cin >> S >> ch;
    pos = (pos - S + N * 100) % N;

    if (wheel[pos] == '?' && !isWritten[ch - 'A'] || wheel[pos] == ch) {
      wheel[pos] = ch;
      isWritten[ch - 'A'] = true;
    } else {
      std::cout << "!\n";
      return 0;
    }
  }

  for (int i = 0; i < N; i++) {
    std::cout << wheel[(i + pos) % N];
  }
  std::cout << std::endl;

  return 0;
}
