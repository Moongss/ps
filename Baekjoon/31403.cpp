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
    string A, B, C; cin >> A >> B >> C;
    cout << stoi(A) + stoi(B) - stoi(C) << endl;
    cout << stoi(A+B) - stoi(C) << endl; 
    return 0;
}