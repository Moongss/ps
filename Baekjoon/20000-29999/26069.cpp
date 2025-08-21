#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    int N; cin >> N;
    set<string> m;
    int result = 1;
    while (N--) {
        string a, b; cin >> a >> b;
        if (a == "ChongChong") {
            if (m.find(b) == m.end()) {
                m.insert(b);
                result++;
            }
        } else if (b == "ChongChong") {
            if (m.find(a) == m.end()) {
                m.insert(a);
                result++;  
            }
        } else if (m.find(a) != m.end() && m.find(b) == m.end()) {
            m.insert(b);
            result++;
        } else if (m.find(b) != m.end() && m.find(a) == m.end()) {
            m.insert(a);
            result++;
        }
    }
    cout << result << endl;
    return 0;
}