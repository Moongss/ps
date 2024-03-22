#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
int main() {
    fastio;
    
    cin >> N; cin.ignore();
    for (int i = 1; i <= N; i++) {
        string str; getline(cin, str);
        cout << i << ". " << str << endl;
    }
    return 0;
}