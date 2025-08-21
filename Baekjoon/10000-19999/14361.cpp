#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

bool v2x2[][4][4] = {
    {{1, 1}, {1, 1}},
    {{1, 0}, {0, 1}},
};

bool v3x3[][4][4] = {
    {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},

    {{0, 0, 1}, {1, 1, 0}, {1, 1, 0}},
    {{0, 1, 0}, {1, 0, 1}, {1, 0, 1}},
    {{1, 0, 0}, {0, 1, 1}, {0, 1, 1}},

    {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
};

bool v4x4[][4][4] = {
    // 4x4
    {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}},
    
    // 1x1, 3x3 조합.
    {{1, 0, 0, 0}, {0, 1, 1, 1}, {0, 1, 1, 1}, {0, 1, 1, 1}},
    {{0, 1, 0, 0}, {1, 0, 1, 1}, {1, 0, 1, 1}, {1, 0, 1, 1}},
    {{0, 0, 1, 0}, {1, 1, 0, 1}, {1, 1, 0, 1}, {1, 1, 0, 1}},
    {{0, 0, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, 0}},

    // 2x2, 2x2 조합 (1, 2 row, 3, 4 row 같이)
    {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}},
    {{1, 0, 1, 0}, {1, 0, 1, 0}, {0, 1, 0, 1}, {0, 1, 0, 1}},
    {{1, 0, 0, 1}, {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}},

    // 2x2, 1x1, 1x1 조합
    {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}},
    {{1, 0, 1, 0}, {1, 0, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}},
    {{1, 0, 0, 1}, {1, 0, 0, 1}, {0, 1, 0, 0}, {0, 0, 1, 0}},
    {{0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 1}},
    {{0, 1, 0, 1}, {0, 1, 0, 1}, {1, 0, 0, 0}, {0, 0, 1, 0}},
    {{0, 0, 1, 1}, {0, 0, 1, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}},

    // 1, 1, 1, 1 모든 조합
    {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}},
};

int main() {
    int arr[4][4];
    int T; cin >> T;
    for (int l = 1; l <= T; l++) {
        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%1d", &arr[i][j]);
            }
        }

        int min = 4242; vector<int> c(N);
        for (int i = 0; i < N; i++) c[i] = i;

        if (N == 1) min = (arr[0][0] == 1) ? 0 : 1;
        if (N == 2) {
            do {
                for (auto &check: v2x2) {
                    int cnt = 0;
                    for (int i = 0; i < N * N; i++) {
                        int row = i / N, col = i % N;
                        if (arr[row][col] == 1 && check[c[row]][col] == 0) {cnt = min; break;}
                        if (arr[row][col] != check[c[row]][col]) cnt++;
                    }
                    if (cnt < min) min = cnt;
                }
            } while (next_permutation(all(c)));
        }
        if (N == 3) {
            do {
                for (auto &check: v3x3) {
                    int cnt = 0;
                    for (int i = 0; i < N * N; i++) {
                        int row = i / N, col = i % N;
                        if (arr[row][col] == 1 && check[c[row]][col] == 0) {cnt = min; break;}
                        if (arr[row][col] != check[c[row]][col]) cnt++;
                    }
                    if (cnt < min) min = cnt;
                }
            } while (next_permutation(all(c)));
        }
        if (N == 4) {
            do {
                for (auto &check: v4x4) {
                    int cnt = 0;
                    for (int i = 0; i < N * N; i++) {
                        int row = i / N, col = i % N;
                        if (arr[row][col] == 1 && check[c[row]][col] == 0) {cnt = min; break;}
                        if (arr[row][col] != check[c[row]][col]) cnt++;
                    }
                    if (cnt < min) min = cnt;
                }
            } while (next_permutation(all(c)));
        }
        printf("Case #%d: %d\n", l, min);
    }
    return 0;
}