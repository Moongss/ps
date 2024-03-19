#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
priority_queue<int, vector<int>, less<>> v;

int main() {
    fastio;
    
    cin >> N;
    while (N--) {
        int x; cin >> x;
        if (x == 0 && v.empty()) cout << -1 << endl;
        else if (x == 0) {
            cout << v.top() << endl;
            v.pop();
        } else {
            for (int i = 0; i < x; i++) {
                int t; cin >> t; v.push(t);
            }
        }
    }
    return 0;
}