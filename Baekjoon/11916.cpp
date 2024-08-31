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
    // fastio;
    
    int N;
    int cnt = 0;
    
    cin >> N;
    int ret = 0;
    int person[4] = {0, 0, 0, 0};
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x == 1) cnt++;
        if (x == 3) {
            if (person[3]) {ret++; person[3] = 0;}
            person[3] = person[2];
            person[2] = person[1];
            person[1] = 0;
            cnt++;
        }
        if (x == 2 || cnt == 4) {
            if (person[3] && person[2] && person[1]) {
                ret++;
                person[3] = 0;
            } 
            if (person[2] && person[1]) {
                person[3] = 1;
                person[2] = 0;
            } 
            if (person[1]) {
                person[2] = 1;
                person[1] = 0;
            }
            person[1] = 1;
            cnt = 0;
        }
    }
    cout << ret << endl;
    return 0;
}