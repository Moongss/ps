#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    
    string str; cin >> str;
    int zeroCnt = 0;
    int oneCnt = 0;

    char cur = str[0];
    if (cur == '0') zeroCnt++; else oneCnt++;
    for (auto &c : str) {
        if (c != cur) {
            if (c == '0') zeroCnt++; else oneCnt++;
            cur = c;
        }
    }
    cout << min(zeroCnt, oneCnt) << endl;
    return 0;
}