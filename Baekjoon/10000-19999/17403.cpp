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

int N;
vector<Point> v;
map<int, Point> itoP;
map<Point, int> ptoI;
Point p[100001];
int level[100001];
int curLevel = 1;

bool cmp1(Point p1, Point p2) {
    if (p1.y == p2.y) return p1.x < p2.x;
    return p1.y < p2.y;
}

bool cmp2(Point p1, Point p2) {
    ll ret = ccw(v[0], p1, p2);
    if (ret == 0) return dist(v[0], p1) < dist(v[0], p2);
    return ret > 0;
}

bool solve() {
    if (v.size() < 3) return false;
    sort(v.begin(), v.end(), cmp1);
    sort(v.begin() + 1, v.end(), cmp2);

    stack<int> s; s.push(0); s.push(1);
    int next = 2;

    while (next < v.size()) {
        while (s.size() >= 2) {
            int first, second;
            second = s.top(); s.pop();
            first = s.top();
            if (ccw(v[first], v[second], v[next]) > 0) {
                s.push(second);
                break;
            }
        }
        s.push(next);
        next++;
    }

    if (s.size() < 3) return false; // 직선 or 점 한개로 모이는 경우
    while (!s.empty()) {
        Point cur = v[s.top()]; s.pop();
        level[ptoI[cur]] = curLevel; 
    }

    v.clear();
    for (int i = 0; i < N; i++) if (level[i] == 0) v.push_back(itoP[i]);
    return true;
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
        itoP.insert({i, p[i]});
        ptoI.insert({p[i], i});
        v.push_back(p[i]);
    }

    while (true) {
        if (!solve()) break;
        curLevel++;
    }

    for (int i = 0; i < N; i++) {
        cout << level[i] << " ";
    }
    cout << endl;
    return 0;
}