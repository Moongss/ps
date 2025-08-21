#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    fastio;
    int N; cin >> N;
    queue<int> q;

    for (int i = 1; i <= N; i++)
        q.push(i);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
        if (!q.empty()) {
            q.push(q.front());
            q.pop();
        }
    }
    cout << endl;
    return 0;
}