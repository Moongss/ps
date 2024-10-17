#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int SZ[1 << 22];
void update(int s, int e, int target, int node) {
    if (target < s || e < target) return;
    SZ[node]++;

    if (s == e && s == target) return;

    int mid = s + e >> 1;
    update(s, mid, target, node * 2);
    update(mid + 1, e, target, node * 2 + 1);
}

void query(int s, int e, int target, int node) {
    SZ[node]--;
    if (s == e) {cout << s << endl; return;}

    int l = node * 2;
    int r = node * 2 + 1;
    int mid = s + e >> 1;
    if (SZ[l] < target) query(mid + 1, e, target - SZ[l], r);
    else query(s, mid, target, l);
}

int main() {
    fastio;
    
    int Q; cin >> Q;
    while (Q--) {
        int T, X; cin >> T >> X;
        if (T == 1) update(1, 2000000, X, 1);
        else query(1, 2000000, X, 1);
    }

    return 0;
}