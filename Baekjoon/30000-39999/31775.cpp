#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool chk[3];

void valid(char c) {
    if (c == 'l') chk[0] = true;
    if (c == 'k') chk[1] = true;
    if (c == 'p') chk[2] = true;
}

int main() {
    fastio;
    
    string a, b, c;
    cin >> a >> b >> c;
    valid(a[0]); valid(b[0]); valid(c[0]);
    cout << (chk[0] && chk[1] && chk[2] ? "GLOBAL" : "PONIX") << endl;
    return 0;
}