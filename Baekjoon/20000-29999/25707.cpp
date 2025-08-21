#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
vector<int> v;

int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    ll sum = 0;
    for (int i = 1; i < N; i++) {
        sum += v[i] - v[i - 1];
    }
    sum += v[N - 1] - v[0];
    cout << sum << endl;
    return 0;
}