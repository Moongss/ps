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

int N;
int parent[1000001];
vector<int> v;

priority_queue<pair<int, pii>, vector<pair<int, pii>>> pq;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    parent[a] = b;
}

int main() {
    fastio;
    
    cin >> N;
    v.resize(N); for (auto &i : v) cin >> i;
    for (int i = 0; i < N; i++) parent[i] = i;
    for (int i = 1; i < N; i++) {
        pq.push({-max(v[i - 1], v[i]), {i - 1, i}});
    }

    ll ans = 0;
    while (!pq.empty()) {
        auto [e, p] = pq.top(); pq.pop();
        e = -e;
        // cout << "e: " << e << " p: " << p.x << " " << p.y << endl;
        if (v[find(p.x)] != e && v[find(p.y)] != e) {
            pq.push({-max(v[find(p.x)], v[find(p.y)]), {find(p.x), find(p.y)}});
        }
        else {
            if (v[find(p.x)] == e) {merge(p.y, p.x);}
            else {merge(p.x, p.y);}
            ans += e;
        }
    }
    cout << ans << endl;
    return 0;
}