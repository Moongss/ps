#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int arr[10];

int main() {
    fastio;
    
    string str; cin >> str;
    for (auto &x : str) {
        int n = x - '0';
        if (n == 9) arr[6]++;
        else arr[x - '0']++;
    }
    arr[6] = (arr[6] + 1)  / 2;
    
    int res = 0;
    for (int i = 0; i < 10; i++) {
        res = max(res, arr[i]);
    }
    cout << res << endl;
    return 0;
}