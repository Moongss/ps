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

int N;
vector<Point> p;

ll ccw(Point p1, Point p2, Point p3) {
    ll ret = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
    if (ret > 0) return 1;
    if (ret < 0) return -1;
    return 0;
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
        ll x, y; cin >> x >> y;
        p.push_back(Point(x, y));
    }
    
    sort(p.begin(), p.end());
    sort(p.begin() + 1, p.end(), cmp);

    vector<Point> s;
    s.push_back(p[0]);
    s.push_back(p[1]);
    int next = 2;
    while (next < N) {
        while (s.size() >= 2) {
            Point second = s.back(); s.pop_back();
            Point first = s.back();
            if (ccw(first, second, p[next]) > 0) {
                s.push_back(second);
                break;
            }
        }
        s.push_back(p[next++]);
    }

    ld ans = 1e18;
    ld tmp = sqrt(dist(s[0], s[1]) * 1.0);
    int right = 1;
    for (int i = 0; i < s.size(); i++) {
        int left = i;
        int next_l = (i + 1) % s.size();
        tmp -= sqrt(dist(s[next_l], s[left]) * 1.0);
        while (left != right) {
            int next_r = (right + 1) % s.size();
            Point lvector = {s[next_l].x - s[left].x, s[next_l].y - s[left].y};
            Point rvector = {s[next_r].x - s[right].x, s[next_r].y - s[right].y};

            if (ccw(Point(0, 0), lvector, rvector) >= 0) {
                tmp += sqrt(dist(s[right], s[next_r]) * 1.0);
                right = next_r;
            }
            else break;
        }
        ans = min(ans, tmp);
    }
    printf("%.6Lf\n", ans);
    return 0;
}