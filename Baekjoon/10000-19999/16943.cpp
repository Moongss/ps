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

int ret = -1;
bool f[10];
string A, B; 
void solve(int cur, int tmp) {
    if (cur == A.length()) {
        if (tmp <= stoi(B)) ret = max(ret, tmp);
        return;
    }

    for (int i = 0; i < A.length(); i++) {
        if (!f[i]) {
            if (cur == 0 && A[i] == '0') continue;
            f[i] = true;
            solve(cur+1, tmp*10 + A[i]-'0');
            f[i] = false;
        }
    }
}
int main() {
    fastio;
    
    cin >> A >> B;
    solve(0, 0);
    cout << ret << endl;
    return 0;
}