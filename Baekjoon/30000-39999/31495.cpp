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
    
    string str; getline(cin, str);
    if (str[0] == '"' && str[str.size() - 1] == '"') {
        bool flag = false;
        for (int i = 1; i < str.length() - 1; i++) {
            if (str[i] != ' ') flag = true;
        }
        if (flag == true) {cout << str.substr(1, str.size() - 2) << endl; return 0;}
    }
    cout << "CE" << endl;
    return 0;
}