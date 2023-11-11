#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

const ll SZ = 1 << 19;
ll T[800000];

void Set(int x, ll v) {
    x += SZ; T[x] = v;
    while (x /= 2) T[x] = T[x*2] + T[x*2+1];
}

ll Sum(int l, int r) {
    ll res = 0;
    for (l+=SZ, r+=SZ; l <= r; l/=2, r/=2) {
        if (l % 2 == 1) res += T[l++];
        if (r % 2 == 0) res += T[r--];
    }
    return res;
}

int arr[1001];

int main() {
    fastio;
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int t; cin >> t;
    while (t--) {
        int c, l, r, k;
        cin >> c;
        if (c == 1) {
            cin >> l >> r >> k;
            int cnt = 0;
            for (int i = l; i <= r; i++) {
                if (arr[i] == k) cnt++;
            }
            cout << cnt << endl;
        } else {
            cin >> l >> r;
            for (int i = l; i <= r; i++) {
                arr[i] = 0;
            }
        }
    }
    return 0;
}