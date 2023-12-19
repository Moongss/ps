#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
int cnt[1000001];
vector<int> v;
stack<pair<int, int>> s;
stack<int> result;

int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
        cnt[tmp]++;
    }

    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && s.top().first <= cnt[v[i]]) {
            s.pop();
        }
        if (s.empty()) result.push(-1);
        else result.push(s.top().second);
        s.push({cnt[v[i]], v[i]});
    }

    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
    return 0;
}