#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int main() {
    fastio;
    
    int N, K; cin >> N >> K;
    string s; cin >> s;

    if (s[0] == 'R') K--;
    for (int i = 1; i < N; i++) {
        if (s[i] == s[i - 1]) K--;
    }
    cout << max(K, 0) << endl;
    return 0;
}