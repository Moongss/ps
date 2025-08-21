#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

string circle = "ABCDEFGHIJKLMNOPQRSTUVWXYZ '";
int main() {
    fastio;
    
    int N; cin >> N; cin.ignore();
    while (N--) {
        string aphorism; getline(cin, aphorism);

        ll sum = 0;
        int prev = circle.find(aphorism[0]);
        for (int i = 0; i < aphorism.length(); i++) {
            int cur = circle.find(aphorism[i]);
            
            sum += min(abs(cur - prev), 28 - abs(cur - prev));
            prev = cur;
        }

        double dist = 60 * M_PI / 28.0f;
        cout << fixed << setprecision(6) << ((double)sum * dist / 15) + aphorism.length() << endl;
    }
    return 0;
}