#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int g[2020];
int N;

void init() {
    g[1] = 0;
    for (int i = 2; i <= 2000; i++) {
        set<int> s;
        for (int j = 1; j < i; j++) {
            int result = g[i % j];
            if ((i / j) & 1) result ^= g[j];
            s.insert(result);
        }

        int mex = 0;
        for (auto e : s) {
            if (mex == e) mex++;
            else break;
        }
        g[i] = mex;
    }
}

int main() {
    fastio;
    
    init();
    cin >> N;

    int result = 0;
    while (N--) {
        int P; cin >> P;
        result ^= g[P];
    }

    cout << (result ? "First" : "Second") << endl;
    return 0;
}