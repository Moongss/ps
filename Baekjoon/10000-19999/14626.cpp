#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

using ll = long long;
int main() {
    fastio;
    
    string s; cin >> s;

    ll sum = 0;
    int tmp = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {tmp = i; continue;}
        if (i % 2 == 0) 
            sum += (s[i] - '0') * 1;
        else
            sum += (s[i] - '0') * 3;
    }

    for (int i = 0; i < 10; i++) {
        int w = (tmp % 2 == 0) ? 1 : 3;
        if ((sum + w * i) % 10 == 0) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}