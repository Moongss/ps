#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
string str;

int main() {
    fastio;
    
    cin >> N >> str;
    
    int cnt[2] = {0, };
    char prev = ' ';
    for (auto x : str) {
        if (x == prev) continue;
        else {
            prev = x;
            if (x == 'B') cnt[0]++;
            else cnt[1]++;
        }
    }

    cout << (min(cnt[0], cnt[1]) + 1) << endl;
    return 0;
}