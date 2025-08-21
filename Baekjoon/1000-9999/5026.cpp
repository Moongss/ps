#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int calc(string str) {
    size_t operIdx = str.find('+');
    int a = stoi(str.substr(0, operIdx));
    int b = stoi(str.substr(operIdx + 1));
    return a + b;
}

int main() {
    // fastio;
    
    int N; cin >> N;
    while (N--) {
        string str; cin >> str;
        if (str == "P=NP") {
            cout << "skipped" << endl;
        } else {
            cout << calc(str) << endl;
        }
    }
    return 0;
}