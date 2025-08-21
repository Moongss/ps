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
int cnt = 0;

void dfs(string cur) {
    if (cur.size() == N) {
        if (stoi(cur) % 3 == 0)
            cnt++;
        return;
    }
    dfs(cur + "0");
    dfs(cur + "1");
    dfs(cur + "2");
}

int main() {
    fastio;
    
    cin >> N;
    dfs("1");
    dfs("2");
    cout << cnt << endl;
    return 0;
}