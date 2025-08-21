#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
ll sum = 0;
vector<pll> arr;
ll pre[500001];
ll eka[500001];
ll ans[500001];
ll eneka[500001];

int main() {
    fastio;

    cin >> N;
    arr.resize(N); for (auto &[a, b] : arr) cin >> a >> b;
    
    sort(arr.begin(), arr.end());
    ans[1] = arr[0].x;  

    sort(arr.begin(), arr.end(), [&](const pll &a, const pll &b) {
        return a.y < b.y;
    });
    
    // for (int i = 0; i < N; i++) {
    //     cout << arr[i].x << " " << arr[i].y << endl;
    // }


    ll sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += arr[i - 1].y;
        pre[i] = sum;
        // cout << "pre[i] + eka[i + 1] = " << pre[i] + eka[i + 1] << endl;
    }

    eneka[0] = arr[0].x - arr[0].y;
    for (int i = 1; i <= N; i++) {
        eneka[i] = min(eneka[i - 1], arr[i - 1].x - arr[i - 1].y);
        // cout << "pre[i] + eneka[i] = " << pre[i] + eneka[i] << endl;
    }

    eka[N] = arr[N - 1].x;
    for (int i = N - 1; i >= 0; i--) {
        eka[i] = min(eka[i + 1], arr[i].x);
    }

    cout << ans[1] << endl;
    ans[N] = pre[N] + eneka[N];
    for (int i = 2; i < N; i++) {
        ans[i] = min(pre[i - 1] + eka[i], pre[i] + eneka[i]);
        cout << ans[i] << endl;
    }
    cout << ans[N] << endl;

    return 0;
}