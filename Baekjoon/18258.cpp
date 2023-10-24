#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

deque<int> q;
int main() {
    fastio;
    int N; cin >> N;
    while (N--) {
        string str; cin >> str;
        if (str == "push") {
            int n; cin >> n;
            q.push_back(n);
        }
        if (str == "pop") {
            if (!q.empty()) {
                cout << q.front() << endl;
                q.pop_front();
            } else {
                cout << -1 << endl;
            }
        }
        if (str == "size") {
            cout << q.size() << endl;
        }
        if (str == "empty") {
            if (!q.empty())
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        if (str == "front") {
            if (!q.empty()) {
                cout << q.front() << endl;
            } else {
                cout << -1 << endl;
            }
        }
        if (str == "back") {
            if (!q.empty()) {
                cout << q.back() << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}