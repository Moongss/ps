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
    while (true) {
        string str; getline(cin, str);
        if (str == "END") break;
        else {
            reverse(str.begin(), str.end());
            cout << str << endl;
        }
    }
    return 0;
}