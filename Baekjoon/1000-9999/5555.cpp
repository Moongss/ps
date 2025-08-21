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
    
    string target; cin >> target;
    int N; cin >> N;
    int result = 0;
    while (N--) {
        string s; cin >> s;
        s += s;
        if (s.find(target) != string::npos) {
            result++;
        }
    }
    cout << result << endl;
    return 0;
}