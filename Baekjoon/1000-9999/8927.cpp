#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

struct Point {
    ll x, y;
    Point () {};
    Point (ll x, ll y) : x(x), y(y) {};
    Point operator- (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    bool operator< (const Point& p) const {
        if (y == p.y) return x < p.x;
        return y < p.y;
    }
};

int N, T;
vector<Point> p;

ll ccw(Point p1, Point p2, Point p3) {
    ll ret = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
    return (ret > 0) - (ret < 0);
}

ll dist(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

bool cmp(Point p1, Point p2) {
    ll ret = ccw(p[0], p1, p2);
    if (ret == 0) return dist(p[0], p1) < dist(p[0], p2);
    return ret > 0;
}

int main() {
    fastio;
    cin >> T;
    while (T--) {
        cin >> N;
        p.clear();
        for (int i = 0; i < N; i++) {
            ll x, y, w; cin >> x >> y >> w;
            p.push_back(Point(x, y));
            p.push_back(Point(x + w, y));
            p.push_back(Point(x, y + w));
            p.push_back(Point(x + w, y + w));
        }

        sort(p.begin(), p.end());
        sort(p.begin() + 1, p.end(), cmp);

        vector<Point> v;
        v.push_back(p[0]);
        v.push_back(p[1]);
        int next = 2;
        N *= 4;
        while (next < N) {
            while (v.size() >= 2) {
                Point second = v.back(); v.pop_back();
                Point first = v.back();
                if (ccw(first, second, p[next]) > 0) {
                    v.push_back(second);
                    break;
                }
            }
            v.push_back(p[next++]);
        }

        N = v.size();
        ll ans = 0;
        Point originVector = Point(0, 0);
        for (int i = 0, j = 1; i < N; i++) {
            while (i != j) {
                Point lVector = v[(i + 1) % N] - v[i];
                Point rVector = v[(j + 1) % N] - v[j];
                if (ccw(originVector, lVector, rVector) > 0) j = (j + 1) % N;
                else break;
            }
            ans = max(ans, dist(v[i], v[j]));
        }
        cout << ans << endl;
    }
    return 0;
}