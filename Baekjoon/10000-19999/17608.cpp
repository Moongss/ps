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
    stack<int> s;

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        while (!s.empty() && s.top() <= x) {
            s.pop();
        }
        s.push(x);
    }   
    cout << s.size() << endl;
    return 0;
}