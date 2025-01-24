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

int N; 
vector<int> v;
int main() {
    fastio;
    
    cin >> N;
    v.resize(N); for (auto &i : v) cin >> i;

    int Min = 1e9 + 1;
    int ret = 0;
    for (int i = 0; i < N; i++){
        Min = min(Min, v[i]); 
        ret = max(ret, v[i]-Min);
    }
    cout << ret << endl;

    return 0;
}