#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

set<string> s;
queue<pair<int, string>> q;
int N, K;

int main() {
    fastio;
    cin >> N >> K;
    string str = "";
    string ans = "";
    for (int i = 1; i <= N; i++) {
        char c; cin >> c;
        str += c;
        ans += i + '0';
    }

    q.push({0, str});
    s.insert(str);
    while (!q.empty()) {
        auto [cnt, cur] = q.front(); q.pop();
        
        if (cur == ans) {
            cout << cnt << endl;
            return 0;
        }
        for (int i = 0; i <= N - K; i++) {
            string tmp = cur;
            reverse(tmp.begin() + i, tmp.begin() + i + K);
            if (s.find(tmp) == s.end()) {
                s.insert(tmp);
                q.push({cnt + 1, tmp});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}