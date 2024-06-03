#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
set<ll> s;

void dfs(int N, ll num) {
    if (N == 0) {
        return;
    }

    for (int i = 1; i <= 9; i++) {
        s.insert(num * i);
        dfs(N - 1, num * i);
    }
}

int main() {
    fastio;
    
    cin >> N;
    dfs(N, 1);
    cout << s.size() << endl;
    return 0;
}