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
    
    while (cin >> N) {
        if (N == 0) break;
        double h, maxHeight = -1;
        vector<string> v;
        for (int i = 0; i < N; i++) {
            string name; cin >> name >> h;
            if (h > maxHeight) {
                maxHeight = h;
                v.clear();
            }
            if (h == maxHeight)
                v.push_back(name);
        }

        for (auto n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}