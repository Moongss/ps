#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, k;
map<string, int> m;
string arr[42];
string tmp[4];
bool check[4];

void solve(int level) {
    if (level == k) {
        string str = "";
        for (int i = 0; i < k; i++) {
            str += tmp[i];
        }
        m[str]++;
        return;
    }

    for (int i = 0; i < n; i++) {
        tmp[level] = arr[i];
        if (!check[i]) {
            check[i] = true;
            solve(level + 1);
            check[i] = false;
        }
    }
}

int main() {
    fastio;
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    solve(0);
    cout << m.size() << endl;
    
    return 0;
}