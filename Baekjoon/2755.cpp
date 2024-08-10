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
    double sum = 0;
    int sum2 = 0;
    for (int i = 0; i < N; i++) {
        int a; string s; cin >> s;
        cin >> a >> s; sum2 += a;

        if (s == "A+") sum += 4.3 * a;
        else if (s == "A0") sum += 4.0 * a;
        else if (s == "A-") sum += 3.7 * a;
        else if (s == "B+") sum += 3.3 * a;
        else if (s == "B0") sum += 3.0 * a;
        else if (s == "B-") sum += 2.7 * a;
        else if (s == "C+") sum += 2.3 * a;
        else if (s == "C0") sum += 2.0 * a;
        else if (s == "C-") sum += 1.7 * a;
        else if (s == "D+") sum += 1.3 * a;
        else if (s == "D0") sum += 1.0 * a;
        else if (s == "D-") sum += 0.7 * a;
    }
    cout << fixed << setprecision(2) << (sum + 0.005) / sum2 << endl;
    return 0;
}