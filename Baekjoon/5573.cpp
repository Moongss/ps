#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

bool arr[1001][1001];
int dp[1001][1001];

int H, W;
int N;

int main() {
    fastio;
    cin >> H >> W >> N;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = N - 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (dp[i][j] < 0) continue;
            if (arr[i][j]) { // right
                dp[i][j + 1] += (dp[i][j] + 1) / 2;
                dp[i + 1][j] += dp[i][j] / 2;
            } else { // down
                dp[i][j + 1] += dp[i][j] / 2;
                dp[i + 1][j] += (dp[i][j] + 1) / 2;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            arr[i][j] = (dp[i][j] % 2 ? !arr[i][j] : arr[i][j]);
        }
    }

    int x = 0, y = 0;
    while (y < H && x < W) {
        if (arr[y][x]) x++;
        else y++;
    }

    cout << y + 1 << " " << x + 1 << endl;
    return 0;
}