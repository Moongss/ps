#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N;
priority_queue<int> pq;
int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N * N; i++) {
        int a; cin >> a; pq.push(-a);
        if (pq.size() > N) pq.pop();
    }
    cout << -pq.top() << endl;
    return 0;
}