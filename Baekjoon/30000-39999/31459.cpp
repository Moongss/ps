#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M, x, y;
int visited[51][51];
int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        int result = 0;
        cin >> N >> M >> x >> y;
        memset(visited, -1, sizeof(visited));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == -1) {
                    int sx = i, sy = j;
                    int cnt = 0;
                    while (sx < N && sy < M) {
                        visited[sx][sy] = (cnt % 2) ? false : true;
                        if (cnt % 2 == 0) result++;
                        cnt++;
                        sx += x;
                        sy += y;
                    }
                }
            }
        }
        cout << max(result, N * M - result) << endl;
    }
    return 0;
}