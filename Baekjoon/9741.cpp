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

int main() {
    fastio;
    
    int N; cin >> N;
    int x1, x2, x3, y1, y2, y3;

    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int S = abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2;

        int sum = 0;

        sum += gcd(x1 - x2, y1 - y2);
        sum += gcd(x1 - x3, y1 - y3);
        sum += gcd(x2 - x3, y2 - y3);

        // 격자점 겹치는거 3개빼기 -> 그냥 gcd(dx, dy)로 가능함?
        // 다각형 넓이 -> cross product로 구하기 v[i] / v[i + 1]; (x*y - x*y);
        // (넓이) = (테두리 위의 격자점의 개수) / 2 + (내부 격자점의 개수) - 1
        cout << max(0, S + 1 - sum / 2) << endl;
    }

    return 0;
}