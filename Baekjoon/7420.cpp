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
    bool operator< (const Point& p) const {
        if (y == p.y) return x < p.x;
        return y < p.y;
    }
};

int N, L;
vector<Point> p;

ll ccw(Point p1, Point p2, Point p3) {
    ll ret = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
    if (ret > 0) return 1;
    if (ret < 0) return -1;
    return 0;
}

ll dist(Point &p1, Point &p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

bool cmp(Point& p1, Point& p2) {
    ll ret = ccw(p[0], p1, p2);
    if (ret == 0) return dist(p[0], p1) < dist(p[0], p2);
    return ret > 0;
}

int main() {
    fastio;
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        p.push_back(Point(x, y));
    }

    sort(p.begin(), p.end());
    sort(p.begin() + 1, p.end(), cmp);

    vector<int> cv;
    cv.push_back(0); 
    cv.push_back(1);
    int next = 2;

    while (next < N) {
        while (cv.size() >= 2) {
            int second = cv.back(); cv.pop_back();
            int first = cv.back();
            if (ccw(p[first], p[second], p[next]) > 0) {
                cv.push_back(second);
                break;
            }
        }
        cv.push_back(next++);
    }
    
    ld ans = L * 2 * M_PI;
    for (int cur = 0; cur < cv.size(); cur++) {
        int next = (cur + 1) % cv.size();
        ans += sqrt(dist(p[cv[cur]], p[cv[next]])); //hypot 
    }
    cout << setprecision << fixed << ans << endl;
    return 0;
}