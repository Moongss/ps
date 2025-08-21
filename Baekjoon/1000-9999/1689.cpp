#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N;
priority_queue<int> pq;
vector<pair<int, int>> v;
int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e; cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end());

    int result = -1;
    for (auto [s, e] : v) {
        if (pq.empty()) pq.push(-e);
        else {
            while (!pq.empty() && -pq.top() <= s) pq.pop();
            pq.push(-e);
        }
        result = max(result, (int)pq.size());
    }
    cout << result << endl;
    return 0;
}