#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int g[5050];
int N, T;
int main() {
    fastio;

    g[0] = g[1] = 0;
    g[2] = g[3] = 1;

    for (int i = 4; i <= 5000; i++) {
        vector<int> v;
        for (int j = 0; j <= (i - 2) / 2; j++) {
            v.push_back(g[j] ^ g[i - 2 - j]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        
        int mex = 0;
        for (auto x : v) {
            if (x == mex) mex++;
            else break;
        }
        g[i] = mex;
    } 

    cin >> T;
    while (T--) {
        cin >> N;
        cout << (g[N] ? "First" : "Second") << endl;
    }
    return 0;
}