#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<int> v;
bool sieve[101];
int A, B, N;
void solve(int cur) {
    cout << A;

    N -= 4;
    if (A%10 == 9) cout << 7, N--;
    for (int i = 0; i < N; i++) cout << 1;
    cout << B << endl;
}
int main() {
    fastio;
    
    for (int i = 2; i <= 100; i++) {
        if (sieve[i]) continue;
        v.push_back(i);
        for (int j = i*i; j <= 100; j += i) {
            sieve[j] = true;
        }
    }

    cin >> A >> B >> N;
    if (sieve[A] || sieve[B] || (B/10)%2 == 0 || B/10 == 5) cout << -1 << endl;
    else solve(0);
    return 0;
}