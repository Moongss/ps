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
    Point() {};
    Point(ll x, ll y) : x(x), y(y) {};
    Point operator- (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    bool operator< (const Point& p) const {
        if (y == p.y) return x < p.x;
        return y < p.y;
    }
};

int N;
vector<Point> p;

ll ccw(Point p1, Point p2, Point p3) {
    ll ret = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
    return (ret > 0) - (ret < 0);
}

ll dist(Point &p1, Point &p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

bool cmp(Point &p1, Point &p2) {
    ll ret = ccw(p[0], p1, p2);
    if (ret == 0) return dist(p[0], p1) < dist(p[0], p2);
    return ret > 0;
}

bool cmp2(Point &p1, Point &p2) {
    return p1.y < p2.y;
}

pair<Point, Point> getMinDist(int s, int e) {
    if (e - s + 1 == 2) return {p[s], p[e]};
    if (e - s + 1 == 3) {
        ll d1 = dist(p[s], p[s + 1]);
        ll d2 = dist(p[s], p[s + 2]);
        ll d3 = dist(p[s + 1], p[s + 2]);
        if (d1 <= d2 && d1 <= d3) return {p[s], p[s + 1]};
        if (d2 <= d1 && d2 <= d3) return {p[s], p[s + 2]};
        return {p[s + 1], p[s + 2]};
    }

    int mid = (s + e) / 2;
    pair<Point, Point> left = getMinDist(s, mid);
    pair<Point, Point> right = getMinDist(mid + 1, e);
    pair<Point, Point> closest = left;

    if (dist(left.first, left.second) > dist(right.first, right.second)) closest = right;

    vector<Point> v;
    for (int i = s; i <= e; i++) {
        ll d = p[i].x - p[mid].x;
        if (d * d < dist(closest.first, closest.second)) v.push_back(p[i]);
    }

    sort(v.begin(), v.end(), cmp2);
    int SZ = v.size();
    for (int i = 0; i < SZ; i++) {
        for (int j = i + 1; j < SZ; j++) {
            ll d = v[i].y - v[j].y;
            if (d * d < dist(closest.first, closest.second)) {
                ll d1 = dist(v[i], v[j]);
                ll d2 = dist(closest.first, closest.second);
                if (d1 < d2) closest = {v[i], v[j]};
            }
            else break;
        }
    }
    return closest;
}

pair<Point, Point> getMaxDist() {
    sort(p.begin(), p.end());
    sort(p.begin() + 1, p.end(), cmp);

    vector<Point> hull;
    hull.push_back(p[0]);
    hull.push_back(p[1]);
    int next = 2;
    while (next < p.size()) {
        while (hull.size() >= 2) {
            Point second = hull.back(); hull.pop_back();
            Point first = hull.back();
            if (ccw(first, second, p[next]) > 0) {
                hull.push_back(second);
                break;
            }
        }
        hull.push_back(p[next++]);
    }

    int SZ = hull.size();
    ll ans = 0;
    pair<Point, Point> ret;
    for (int i = 0, j = 1; i < SZ; i++) {
        while (i != j) {
            Point lVector = hull[(i + 1) % SZ] - hull[i];
            Point rVector = hull[(j + 1) % SZ] - hull[j];
            if (ccw({0, 0}, lVector, rVector) > 0) j = (j + 1) % SZ;
            else break;
        }
        if (ans < dist(hull[i], hull[j])) {
            ans = dist(hull[i], hull[j]);
            ret.first = hull[i];
            ret.second = hull[j];
        }
    }
    return ret;
}

vector<ll> add;
vector<ll> subtract;

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        p.push_back(Point(x, y));
        add.push_back(x + y);
        subtract.push_back(x - y);
    }

    pair<Point, Point> minDist, maxDist;
    minDist = getMinDist(0, N - 1);
    maxDist = getMaxDist();

    cout << dist(maxDist.first, maxDist.second) << endl;
    cout << dist(minDist.first, minDist.second) << endl;

    sort(add.begin(), add.end());
    sort(subtract.begin(), subtract.end());

    ll manhattanMinDist = 1e18;
    sort(p.begin(), p.end());
    for (int i = 1; i < N; i++) {
        manhattanMinDist = min(manhattanMinDist, abs(p[i].x - p[i - 1].x) + abs(p[i].y - p[i - 1].y));
    }
    ll manhattanMaxDist = abs(p.back().x - p.front().x) + abs(p.back().y - p.front().y);

    sort(p.begin(), p.end(), cmp2);
    for (int i = 1; i < N; i++) {
        manhattanMinDist = min(manhattanMinDist, abs(p[i].x - p[i - 1].x) + abs(p[i].y - p[i - 1].y));
    }
    manhattanMaxDist = max(manhattanMaxDist, abs(p.back().x - p.front().x) + abs(p.back().y - p.front().y));
    cout << manhattanMaxDist << endl;
    cout << manhattanMinDist << endl;

    pair<ll, ll> X = {1e18, -1e18};
    pair<ll, ll> Y = {1e18, -1e18};
    for (int i = 0; i < N; i++) {
        X = {min(X.first, p[i].x), max(X.second, p[i].x)};
        Y = {min(Y.first, p[i].y), max(Y.second, p[i].y)};
    }
    ll chebyshevMaxDist = max(X.second - X.first, Y.second - Y.first);
    ll chebyshevMinDist = 1e18;
    for (int i = 1; i < N; i++) {
        chebyshevMinDist = min(chebyshevMinDist, max(abs(p[i].x - p[i - 1].x), abs(p[i].y - p[i - 1].y)));
    }
    
    cout << chebyshevMaxDist << endl;
    cout << chebyshevMinDist << endl;
    return 0;
}