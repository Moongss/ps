#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    fastio;
    int A, B; cin >> A >> B;
    cout << (0 ^ A ^ B) << endl;
    return 0;
}