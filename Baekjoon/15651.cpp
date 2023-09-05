#include <iostream>

int arr[8];

void solve(int range, int cnt, int current) {
    if (current > cnt) {
        for (int i = 1; i <= cnt; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << '\n';
        return;
    }

    for (int i = 1; i <= range; i++) {
        arr[current] = i;
        solve(range, cnt, current + 1);
    }
}

int main() {
    int N, M;

    std::cin >> N >> M;
    solve(N, M, 1);
}