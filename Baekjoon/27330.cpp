#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;

    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    int M; cin >> M;
    vector<int> w(M);
    for (int i = 0; i < M; i++) cin >> w[i];

    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i];
        for (int j = 0; j < M; j++) {
            if (sum == w[j]) {
                sum = 0;
                break;
            }
        }
    }
    cout << sum << endl;
    return 0;
}