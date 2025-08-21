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

int N, K;
int SZ[1 << 18];
vector<int> ret;

int init(int s, int e, int node) {
    if (s == e) return SZ[node] = 1;

    int mid = s + e >> 1;
    return SZ[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

void query(int s, int e, int node, ll target) {
    if (s == e) {
        ret.push_back(s);
        SZ[node] = 0;
    }
    else {
        int m = s + e >> 1;
        int l = node * 2;
        int r = node * 2 + 1;

        int ret;
        if (SZ[l] < target) 
            query(m + 1, e, r, target - SZ[l]);
        else 
            query(s, m, l, target);
        SZ[node] = SZ[l] + SZ[r];
    }
}

int main() {
    fastio;
    
    cin >> N >> K;
    init(1, N, 1);

    int t = K;
    for (int i = 0; i < N; i++) {
        query(1, N, 1, t);

        if (!SZ[1]) break;
        t += K - 1;
        t = (t - 1) % SZ[1] + 1;
    }
    
    cout << "<";
    for (int i = 0; i < N; i++) {
        cout << ret[i];
        if (i < N - 1) cout << ", ";
    }
    cout << ">" << endl;
    return 0;
}