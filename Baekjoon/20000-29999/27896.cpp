#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N, M;
ll sum = 0;
priority_queue<int> pq;

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        sum += x; pq.push(x);
        while (sum >= M) sum -= pq.top() * 2, pq.pop();
    }
    cout << N - pq.size() << endl;
    return 0;
}