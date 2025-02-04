#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int a[10101], b[10101];
int carry;
vector<int> ret;
int main() {
    fastio;
    
    string A, B; cin >> A >> B;
    reverse(all(A)); reverse(all(B));
    for (int i = 0; i < A.length(); i++) a[i] = A[i] - '0';
    for (int i = 0; i < B.length(); i++) b[i] = B[i] - '0';

    int len = max(A.length(), B.length());
    for (int i = 0; i < len; i++) {
        int sum = a[i] + b[i] + carry;
        ret.push_back(sum % 10);
        carry = sum / 10;
    }
    if (carry) ret.push_back(carry);
    reverse(all(ret));
    for (int i : ret) cout << i;
    return 0;
}