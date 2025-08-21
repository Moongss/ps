#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

char arr[50][50];

int main() {
    fastio;
    
    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j];
        }
    }

    int ans = 424242;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            int cnt = 0;
            for (int l = 0; l < N; l++) {
                for (int m = 0; m < M; m++) {
                    if (l <= i && arr[l][m] == 'W') continue;
                    else if (i < l && l <= j && arr[l][m] == 'B') continue;
                    else if (l > j && arr[l][m] == 'R') continue;
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}