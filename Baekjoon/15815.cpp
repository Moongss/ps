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
    stack<int> s;

    for (auto &x : str) {
        if (x > '9' || x < '0') {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            if (x == '+') {
                s.push(a + b);
            } else if (x == '-') {
                s.push(b - a);
            } else if (x == '*') {
                s.push(a * b);
            } else {
                s.push(b / a);
            }
        } else {
            s.push(x - '0');
        }
    }

    cout << s.top() << endl;
    return 0;
}