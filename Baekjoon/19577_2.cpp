#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll N;

int main() {
    fastio;
    cin >> N; 

    vector<int> v;
    for (ll i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            v.push_back(i);
            v.push_back(N / i);
        }
    }
    sort(v.begin(), v.end());

    vector<int> tmp;
    for (auto p : v) {
        ll ret = p;
        tmp.clear();
        for (ll i = 2; i * i <= p; i++) {
            if (p % i) continue;
            else {
                tmp.push_back(i);
                while (!(p % i)) 
                    p /= i;
            }
        }
        if (p > 1) tmp.push_back(p);

        p = ret;
        ll result = 1;
        for (auto pr : tmp) {
            ll a = 0;
            while (!(p % pr)) {
                a++;
                p /= pr;
            }
            result *= (pow(pr, a) - pow(pr, a - 1));
        }
        p = ret;

        if (result == N / p) {
            cout << p << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}