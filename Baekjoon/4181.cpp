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
    bool operator< (const Point &p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

int N;
vector<Point> p;

ll ccw(Point p1, Point p2, Point p3) {
    ll ret = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) -
             (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
    if (ret > 0) return 1;
    else if (ret < 0) return -1;
    else return 0;
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
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y; char c;
        cin >> x >> y >> c;
        if (c == 'Y') p.push_back(Point(x, y));
    }

    sort(p.begin(), p.end());
    sort(p.begin() + 1, p.end(), cmp);

    int idx = p.size() - 1;
    while (idx > 0 && ccw(p[0], p[idx - 1], p[idx]) == 0) idx--;
    reverse(p.begin() + idx, p.end());

    cout << p.size() << endl;
    for (auto &elem: p) {
        cout << elem.x << " " << elem.y << endl;
    }
    return 0;
}