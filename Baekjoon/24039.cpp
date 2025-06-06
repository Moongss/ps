#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

bool prime[150];
vector<int> v;
void sieve() {
    for (int i = 2; i < 150; i++) {
        if (!prime[i]) {
            for (int j = i * i; j < 150; j += i) {
                prime[j] = 1;
            }
        }
    }

    for (int i = 2; i < 150; i++) {
        if (!prime[i]) v.push_back(i);
    }
}

int main() {
    fastio;
    
    sieve();
    int N; cin >> N;
    for (int i = 1; i < v.size(); i++) {
        int x = v[i] * v[i - 1];
        if (x > N) {
            cout << x << endl;
            return 0;
        }
    }
    return 0;
}