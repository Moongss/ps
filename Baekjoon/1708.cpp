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
    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}

    bool operator< (const Point &p) const {
        if (y == p.y) return x < p.x;
        return y < p.y;
    }
};

Point p[100001];
ll ccw(Point p1, Point p2, Point p3) {
    ll ret = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
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
    
    int N; cin >> N;
    for (int i = 0; i < N; i++)
        cin >> p[i].x >> p[i].y;
    
    sort(p, p + N);
    sort(p + 1, p + N, cmp);

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
        s.push(next);
        next++;
    }

    cout << s.size() << endl;
    return 0;
}