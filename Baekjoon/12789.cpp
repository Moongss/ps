#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

stack<int> s;
int main() {
    fastio;
    int N; cin >> N;
    int cur = 1;
    while (N--) {
        int num; cin >> num;

        while (!s.empty() && s.top() == cur) {
            cur++;
            s.pop();
        }

        if (num == cur)
            cur++;
        else
            s.push(num);
    }

    while (!s.empty()) {
        cur++;
        s.pop();
    }

    if (!s.empty())
        cout << "Sad" << endl;
    else
        cout << "Nice" << endl;
    return 0;
}