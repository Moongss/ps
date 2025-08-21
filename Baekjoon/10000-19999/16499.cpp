#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
map<string, int> m;

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        vector<char> v;
        for (auto &c : str) {
            v.push_back(c);
        }
        sort(v.begin(), v.end());
        string res = "";
        for (auto &c : v) {
            res += c;
        }

        m[res]++;
    }
    cout << m.size() << endl;
    return 0;
}