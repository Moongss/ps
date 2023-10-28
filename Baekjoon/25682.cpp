#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define BLACK 0
#define WHITE 1

using namespace std;
using ll = long long;

int N, M, K;
int pre[2][2001][2001];

int main() {
    fastio;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char ch; cin >> ch;
            if (ch == 'B' && (abs(i - j) % 2 == 0))
                pre[BLACK][i][j] = 1;
            if (ch == 'W' && (abs(i - j) % 2 == 1))
                pre[WHITE][i][j] = 1;
        }
        for (int j = 1; j <= M; j++) {
            pre[BLACK][i][j] += pre[BLACK][i][j - 1];
            pre[WHITE][i][j] += pre[WHITE][i][j - 1];
        }
    }

    for (int j = 1; j <= M; j++) {
        for (int i = 1; i <= N; i++) {
            pre[BLACK][i][j] += pre[BLACK][i - 1][j];
            pre[WHITE][i][j] += pre[WHITE][i - 1][j];
        }
    }

    int result = 42424242;
    for (int i = K; i <= N; i++) {
        for (int j = K; j <= M; j++) {
            int blackCnt = pre[BLACK][i][j] - pre[BLACK][i][j - K] - pre[BLACK][i - K][j] + pre[BLACK][i - K][j - K];
            int whiteCnt = pre[WHITE][i][j] - pre[WHITE][i][j - K] - pre[WHITE][i - K][j] + pre[WHITE][i - K][j - K];
            result = min(result, min(K * K - (blackCnt + whiteCnt), blackCnt + whiteCnt));
        }
    }
    cout << result << endl;
    return 0;
}