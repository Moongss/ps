#include <iostream>

int N, K;
int W[8];
bool visit[8];
int result = 0;

void solve(int cnt, int curW) {
    if (curW < 500)
        return;
    if (cnt == N) {
        result++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visit[i])
            continue;
        visit[i] = true;
        solve(cnt + 1, curW + W[i] - K);
        visit[i] = false;
    }
}

int main() {
    std::cin >> N >> K;

    for (int i = 0; i < N; i++) {
        std::cin >> W[i];
    }

    solve(0, 500);
    std::cout << result << std::endl;
    return 0;
}