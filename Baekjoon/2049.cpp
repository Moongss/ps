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
        if (y == p.y) return x < p.x;
        return y < p.y;
    }
};

int T, N;
vector<Point> p;

ll ccw(Point p1, Point p2, Point p3) {
    ll ret = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) -
             (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
    if (ret > 0) return 1;
    else if (ret < 0) return -1;
    else return 0;
}

ll dist (Point p1, Point p2) {
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

    stack<int> s; s.push(0); s.push(1);
    int next = 2;
    while (next < N) {
        while (s.size() >= 2) {
            int first, second;
            second = s.top(); s.pop();
            first = s.top();

            if (ccw(p[first], p[second], p[next]) > 0) {
                s.push(second);
                break;
            }
        }
        s.push(next++);
    }   

    vector<Point> convex;
    while (!s.empty()) {
        convex.push_back(p[s.top()]); s.pop();
    }
    reverse(convex.begin(), convex.end());

    int right = 1;
    ll ans = 0;
    Point minPoint = convex[0], maxPoint = convex[0];
    for (int i = 0; i < convex.size(); i++) {
        int left = i;
        int next_l = (i + 1) % convex.size();

        while (true) {
            int next_r = (right + 1) % convex.size();
            Point leftVec = {convex[next_l].x - convex[left].x, convex[next_l].y - convex[left].y};
            Point rightVec = {convex[next_r].x - convex[right].x, convex[next_r].y - convex[right].y};

            if (ccw({0, 0}, leftVec, rightVec) > 0) right = next_r;
            else break;
        }
        if (dist(convex[left], convex[right]) > ans) {
            ans = dist(convex[left], convex[right]);
            minPoint = convex[left];
            maxPoint = convex[right];
        }
    }
    cout << ans << endl;

    return 0;
}