#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

priority_queue<int> pq_end;
priority_queue<pair<int, int>> pq_lec; 

int main() {
    fastio;
    
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int s, t; cin >> s >> t;
        pq_lec.push({-s, -t});
    }

    int result = 0;
    while (!pq_lec.empty()) {
        auto [s, t] = pq_lec.top(); pq_lec.pop();
        s = -s; t = -t;
        if (pq_end.empty()) {
            pq_end.push(-t);
        } else {
            if (-pq_end.top() <= s)
                pq_end.pop();
            pq_end.push(-t);
        }
    }
    cout << pq_end.size() << endl;
    return 0;
}