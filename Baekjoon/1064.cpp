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

double Min;
double Max;
int main() {
    fastio;
    
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    if ((ax - bx) *  (by - cy) == (bx - cx) * (ay - by)) {
        cout << -1 << endl; return 0;
    }
    
    Min = 0x3f3f3f3f3f3f;
    Max = -1;

    Min = min(Min, hypot(ax - bx, ay - by) * 2 + hypot(bx - cx, by - cy) * 2);
    Min = min(Min, hypot(bx - cx, by - cy) * 2 + hypot(cx - ax, cy - ay) * 2);
    Min = min(Min, hypot(cx - ax, cy - ay) * 2 + hypot(ax - bx, ay - by) * 2);
    
    Max = max(Max, hypot(ax - bx, ay - by) * 2 + hypot(bx - cx, by - cy) * 2);
    Max = max(Max, hypot(bx - cx, by - cy) * 2 + hypot(cx - ax, cy - ay) * 2);
    Max = max(Max, hypot(cx - ax, cy - ay) * 2 + hypot(ax - bx, ay - by) * 2);
    cout << fixed << setprecision(9) << abs(Max - Min) << endl;
    return 0;
}