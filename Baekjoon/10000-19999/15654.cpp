#include <iostream>

int input[9] = {0};
int result[9] = {0};
bool check[9];

void print(int n) {
  for (int i = 1; i <= n; i++) {
    std::cout << result[i] << " ";
  }
  std::cout << "\n";
}

void solve(int n, int idx, int m) {
  if (m != 0) {
    for (int i = 1; i <= n; i++) {
      if (!check[i]) {
        result[idx] = input[i];
        check[i] = true;
        solve(n, idx + 1, m - 1);
        check[i] = false;
      }
    }
  } else
    print(idx - 1);
}

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
  int n, m;

  std::cin >> n >> m;
  
  for (int i = 1; i <= n; i++) {
      std::cin >> input[i];
  }

  for (int i = 1; i <= n - 1; i++) {
      for (int j = i + 1; j <= n; j++) {
          if (input[i] > input[j])
            swap(input[i], input[j]);
      }
  }

  solve(n, 1, m);
  return 0;
}