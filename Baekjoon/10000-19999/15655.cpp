#include <iostream>

int result[9];
int input[9];

void solve(int range, int cnt, int start, int current) {
    if (current > cnt) {
        for (int i = 1; i <= cnt; i++) {
            std::cout << result[i] << " ";
        }
        std::cout << "\n";
        return;
    }

    for (int i = start; i <= range; i++) {
        result[current] = input[i];
        solve(range, cnt, i + 1, current + 1);
    }
}

void swap(int &a, int &b) {
  int tmp;

  tmp = a;
  a = b;
  b = tmp;
}

int main() {
    int N, M;

    std::cin >> N >> M;
    for (int i = 1; i <= N; i++){
      std::cin >> input[i];
    }

    for (int i = 1; i <= N - 1; i++) {
      for (int j = i + 1; j <= N; j++) {
        if (input[i] > input[j]) {
          swap(input[i], input[j]);
        }
      }
    }
    solve(N, M, 1, 1);
}