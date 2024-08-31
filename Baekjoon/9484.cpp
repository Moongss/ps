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

struct Point {
    ll x, y;

    bool operator < (Point& p) const {
        return x == p.x ? y < p.y : x < p.x;
    }

    bool operator == (Point& p) const {
        return x == p.x && y == p.y;
    }
};

struct Line {
    ll i, j, dx, dy;

    Line (int i, int j, Point &p, Point &q) : i(i), j(j), dx(q.x - p.x), dy(q.y - p.y) {}

    bool operator < (const Line &l) const {
        if (dy * l.dx == l.dy * dx) {
            if (i == l.i) return j < l.j;
            return i < l.i;
        } 
        return dy * l.dx < l.dy * dx;
    }

    bool operator == (const Line &l) const {
        return dy * l.dx == l.dy * dx;
    }
};

ll area (Point &p1, Point &p2, Point &p3) {
    return abs(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x);
}

int N;
int pos[2001];
vector<Point> v;
vector<Line> lv;

void solve() {
    sort(all(v));
    for (int i = 0; i < N; i++) pos[i] = i;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            lv.push_back(Line(i, j, v[i], v[j]));
        }
    }
    sort(all(lv));

    ll min = inf, max = 0;
    for (int i = 0, j = 0; i < lv.size(); i = j) {
        while (j < lv.size() && lv[i] == lv[j]) j++;
        for (int k = i; k < j; k++) {
            int a = lv[k].i, b = lv[k].j;

            swap(pos[a], pos[b]);
            swap(v[pos[a]], v[pos[b]]);
            if (pos[a] > pos[b]) swap(a, b);
            
            if (pos[a] > 0) {
                min = std::min(min, area(v[pos[a]], v[pos[b]], v[pos[a] - 1]));
                max = std::max(max, area(v[pos[a]], v[pos[b]], v[0]));
            }
            if (pos[b] < N - 1) {
                min = std::min(min, area(v[pos[a]], v[pos[b]], v[pos[b] + 1]));
                max = std::max(max, area(v[pos[a]], v[pos[b]], v[N - 1]));
            }
        }
    }
    cout << fixed << setprecision(1) << (double) min / 2 << " " << (double) max / 2 << endl;
}
int main() {
    fastio;
    
    while (true) {
        cin >> N; if (N == 0) break;

        v.clear();
        lv.clear();
        for (int i = 0; i < N; i++) {
            int x, y; cin >> x >> y;
            v.push_back({x, y});
        }

        solve();
    }
    return 0;
}