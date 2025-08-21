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
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

pii operator + (pii p1, pii p2) {return {p1.x + p2.x, p1.y + p2.y}; }
pii operator - (pii p1, pii p2) {return {p1.x - p2.x, p1.y - p2.y}; }
ll operator * (pii p1, pii p2) {return {p1.x * p2.x + p1.y * p2.y}; }
ll operator / (pii p1, pii p2) {return {p1.x * p2.y - p1.y * p2.x}; }
ll sign(ll x) { return (x > 0) - (x < 0); }
ll dist(pii p1, pii p2) {return (p2 - p1) * (p2 - p1); }
ll signedArea(pii p1, pii p2, pii p3) {return (p2 - p1) / (p3 - p1); }
ll ccw(pii p1, pii p2, pii p3) {return sign(signedArea(p1, p2, p3)); }

int main() {
    fastio;
    
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    pii s1 = {x1, y1}, e1 = {x2, y2}, s2 = {x3, y3}, e2 = {x4, y4};
    cout << (ccw(s1, e1, s2) * ccw(s1, e1, e2) < 0 &&
             ccw(s2, e2, s1) * ccw(s2, e2, e1) < 0 ? 1 : 0) << endl;
    return 0;
}