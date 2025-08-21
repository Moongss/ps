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
    
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> v; v.clear();
        if (N % 6 != 2 && N % 6 != 3) {
            for (int i = 1; i <= N / 2; i++) {
                v.push_back(i * 2);
            }     
            for (int i = 1; i <= (N + 1) / 2; i++) {
                v.push_back(i * 2 - 1);
            }
        }
        else if (N % 6 == 2) {
            for (int i = 1; i <= N / 2; i++) {
                v.push_back(i * 2);
            }
            v.push_back(3);
            v.push_back(1);
            for (int i = 4; i <= (N + 1) / 2; i++) {
                v.push_back(i * 2 - 1);
            }
            v.push_back(5);
        }
        else if (N % 6 == 3) {
            for (int i = 2; i <= N / 2; i++) {
                v.push_back(i * 2);
            }
            v.push_back(2);
            for (int i = 3; i <= (N + 1) / 2; i++) {
                v.push_back(i * 2 - 1);
            }
            v.push_back(1);
            v.push_back(3);
        }

        cout << v.size() << endl;
        for (auto e : v) {
            cout << " " << e - 1;
        }
        cout << endl;
    }
    
    return 0;
}