#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second

int main() {
    fastio;
    
    int N; cin >> N;
    queue<pair<string, int>> q;
    for (int i = 0; i < N; i++) {
        string s; int x; cin >> s >> x;
        q.push({s, x});
    }

    while (q.size() > 1) {
        auto [s, x] = q.front(); q.pop(); x--;
        while (x-- > 0) {
            auto [ss, y] = q.front(); q.pop();
            q.push({ss, y});
        }
        q.pop();
    }
    cout << q.front().x << endl;
    return 0;
}