#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N;
char arr[2500][2500];
void solve(int N, int r, int w) {
    if (N == 1) {
        arr[r][w] = '*';
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1)
                continue;
            solve(N / 3, r + i * N / 3, w + j * N / 3);
        }
    }
}
int main() {
    fastio;
    cin >> N;
    solve(N, 0, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!arr[i][j]) cout << " ";
            else cout << arr[i][j];
        }
    }
    return 0;
}