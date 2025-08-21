#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;

bool compare(pair<string, int> &p1, pair<string, int> &p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return (p1.second > p2.second);
}
map<string, int> m;

int main() {
    // fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        string name; cin >> name;
        m[name] = 0;
    }
    getchar();

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line); 
        line[line.length()] = '\0';

        string name;
        for (auto x : line) {
            if (x == ' ') {
                m[name]++;
                name = "";
            }
            else {
                name += x;
            }
        }
        if (name != "")
            m[name]++;
    }

    vector<pair<string, int> > v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare);

    for (auto x : v) {
        cout << x.first << " "  << x.second << endl;
    }
    return 0;
}