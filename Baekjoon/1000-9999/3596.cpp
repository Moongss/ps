#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
int g[2001] = {0, 1, 1, 1};
bool check[2001];

int mex(int x) {
    memset(check, false, sizeof(check));
    int l = 0, r = x - 1;
    while (l <= r) {
        if (l >= 3 && r >= 3) check[g[l - 2] ^ g[r - 2]] = true;
        else if (r >= 3) check[g[r - 2]] = true;
        else if (l >= 3) check[g[l - 2]] = true;
        else check[0] = true;
        l++, r--;
    }

    int mex = 0;
    for (int i = 0;;i++) {
        if (!check[i]) break;
        mex++;
    }
    return mex;
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 4; i <= N; i++) {
        g[i] = mex(i);
    }

    cout << (g[N] ? 1 : 2) << endl;
    return 0;
}