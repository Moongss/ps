#include <bits/stdc++.h>

#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0);

using ll = long long;
using namespace std;

set<string> s;
int main() {
    fastio;
    string str; cin >> str;
    for (int i = 1; i <= str.length(); i++) {
        for (int j = 0; j <= str.length() - i; j++) {
            string tmp = str.substr(j, i);
            s.insert(tmp);
        }
    }
    cout << s.size() << endl;
    return 0;
}