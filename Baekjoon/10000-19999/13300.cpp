#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int cnt[2][7];
int N, K;

int main() {
    fastio;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int S, Y; cin >> S >> Y;
        cnt[S][Y]++;
    }

    int result = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= 6; j++) {
            result += (cnt[i][j] / K  + (cnt[i][j] % K ? 1 : 0));
        }
    }
    cout << result << endl;
    return 0;
}