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
    
    int T; cin >> T; cin.ignore();
    while (T--) {
        string str; getline(cin, str);
        stack<char> s;
        for (auto c : str) {
            if (c == ' ') {
                while (!s.empty()) { cout << s.top(); s.pop(); }
                cout << " ";
            } else {
                s.push(c);
            }
        }
        while (!s.empty()) { cout << s.top(); s.pop(); }
        cout << endl;
    }
    return 0;
}