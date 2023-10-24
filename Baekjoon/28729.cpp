#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

deque<int> dq;
int main() {
    fastio;
    int N; cin >> N;
    while (N--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {int x; cin >> x; dq.push_front(x);}
        if (cmd == 2) {int x; cin >> x; dq.push_back(x);}
        if (cmd == 3) {
            if (!dq.empty()) {cout << dq.front() << endl; dq.pop_front();}
            else cout << -1 << endl;
        }
        if (cmd == 4) {
            if (!dq.empty()) {cout << dq.back() << endl; dq.pop_back();}
            else cout << -1 << endl;
        }
        if (cmd == 5) cout << dq.size() << endl;
        if (cmd == 6) cout << (dq.empty() ? 1 : 0) << endl;
        if (cmd == 7) cout << (dq.empty() ? -1 : dq.front()) << endl;
        if (cmd == 8) cout << (dq.empty() ? -1 : dq.back()) << endl;
    }
    return 0;
}