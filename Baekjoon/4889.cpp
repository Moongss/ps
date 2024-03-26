#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    
    int idx = 1;
    while (true) {
        string s;
        cin >> s;
        if (s[0] == '-') break;

        stack<char> st;
        for (char c : s) {
            if (!st.empty() && st.top() == '{' && c == '}') {
                st.pop();
            } else {
                st.push(c);
            }
        }

        int cnt = 0;
        while (!st.empty()) { //stack is even.
            char c1 = st.top(); st.pop();
            char c2 = st.top(); st.pop();

            cnt += (c1 == '{' && c2 == '}') ? 2 : 1; // }{ : 2, {{, }} : 1
        }
        cout << idx << ". " << cnt << endl;
        idx++;
    }
    return 0;
}