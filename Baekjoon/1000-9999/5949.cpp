#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int main() {
    fastio;
    
    string str; cin >> str;
    for (int i = 0 ; i < str.length(); i++) {
        if (i && (str.length() - i) % 3 == 0) cout << ",";
        cout << str[i];
    }
    cout << endl;
    return 0;
}