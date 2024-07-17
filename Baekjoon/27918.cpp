#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
int d, p;
int main() {
    fastio;

    cin >> N;
    string ret;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        char ch; cin >> ch;
        if (flag) continue;
        if (ch == 'D') d++;
        else p++;

        if (abs(d - p) == 2) {
            flag = true;
        }
    }
    
    cout << d << ":" << p << endl;
    return 0;
}