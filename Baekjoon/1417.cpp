#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

priority_queue<int, vector<int>> pq;
int main() {
    fastio;

    int N; cin >> N;
    int a; cin >> a;
    for (int i = 1; i < N; i++) {
        int x; cin >> x; pq.push(x);
    }

    int cnt = 0;
    while (!pq.empty()) {
        int e = pq.top(); pq.pop();
        if (e < a) continue;
        e--;
        a++; cnt++;
        pq.push(e);
    }
    cout << cnt << endl;
    
    return 0;
}