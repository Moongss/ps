#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

stack<char> st;
int main() {
    fastio;
    
    string s; cin >> s;
    size_t ret = 0;
    for (auto &x : s) {
        if (st.empty()) st.push(x);
        else if (st.top() == 'P') {
            if (x == 'K') st.pop();
            else st.push(x);
        }
        else if (st.top() == 'K') {
            if (x == 'P') st.pop();
            else st.push(x);
        }
        ret = max(ret, st.size());
    }
    cout << ret << endl;
    return 0;
}