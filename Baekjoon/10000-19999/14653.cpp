#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int checked[26];
int main() {
    fastio;
    
    fill(checked, checked + 26, 42424242);
    int N, K, Q; cin >> N >> K >> Q; Q--;
    for (int i = 0; i < K; i++) {
        int a; char b; cin >> a >> b;
        checked[b-'A'] = i;
    }

    bool f = false;
    for (int i = 0; i < N; i++) {
        if (checked[i] > Q) {
            f = true;
            cout << (char)(i + 'A') << " ";
        }
    }
    if (!f) cout << "-1" << endl;


    return 0;
}