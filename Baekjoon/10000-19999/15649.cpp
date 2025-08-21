#include <iostream>

int arr[9] = {0};
bool check[9];

void print(int n) {
  for (int i = 1; i <= n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

void solve(int n, int idx, int m) {
  if (m != 0) {
    for (int i = 1; i <= n; i++) {
      if (!check[i]) {
        arr[idx] = i;
        check[i] = true;
        solve(n, idx + 1, m - 1);
        check[i] = false;
      }
    }
  } else
    print(idx - 1);
}

int main() {
  int n, m;

  std::cin >> n >> m;
  solve(n, 1, m);
  return 0;
}
