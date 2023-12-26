#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
int arr[101][101];

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    ll ans = 0;
    pair<int, int> coord;
    for (int i = 0; i < N - 3; i++) {
        for (int j = 0; j < M - 3; j++) {
            ll tmp = 0;
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++) {
                    tmp += arr[k][l];
                }
            }
            if (tmp > ans) {
                coord = {i, j};
                ans = tmp;
            }
        }
    }
    cout << ans << endl;
    cout << coord.first + 1 << " " << coord.second + 1 << endl;
    return 0;
}