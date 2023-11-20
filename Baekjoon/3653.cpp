#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

const ll SZ = 1 << 19;
ll tree[SZ << 1];
ll location[100001];

void Set(int x, ll v) {
    x += SZ; tree[x] = v;
    while (x /= 2) tree[x] = tree[x*2] + tree[x*2+1];
}

ll Sum(int l, int r) {
    ll res = 0;
    for (l+=SZ, r+=SZ; l <= r; l/=2, r/=2) {
        if (l % 2 == 1) res += tree[l++];
        if (r % 2 == 0) res += tree[r--];
    }
    return res;
}

int main() {
    fastio;
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        memset(tree, 0, sizeof(tree));
        memset(location, 0, sizeof(location));
        for (int i = 1; i <= N; i++) {
            Set(i + 100000, 1);
            location[i] = i + 100000;
        }

        int idx = 100000;
        for (int i = 0; i < M; i++) {
            int num; cin >> num;
            cout << Sum(1, location[num] - 1) << " ";
            Set(location[num], 0);
            Set(idx, 1);
            location[num] = idx;
            idx--;
        }
        cout << endl;
    }
    return 0;
}