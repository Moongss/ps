#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define BLACK 0
#define WHITE 1

using namespace std;
using ll = long long;

int N, M, K;
int pre[2001][2001];

int main() {
    fastio;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char ch; cin >> ch;
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            if (ch == 'B' && (i + j) % 2 == BLACK || ch == 'W' && (i + j) % 2 == WHITE)
                pre[i][j]++;
        }
    }

    int result = 42424242;
    for (int i = K; i <= N; i++) {
        for (int j = K; j <= M; j++) {
            int sum = pre[i][j] - pre[i][j - K] - pre[i - K][j] + pre[i - K][j - K];
            result = min(result, min(K * K - sum, sum));
        }
    }
    cout << result << endl;
    return 0;
}