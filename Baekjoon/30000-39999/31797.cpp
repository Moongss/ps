#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int arr[10001];
int N, M;
vector<int> v;

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int x, y; cin >> x >> y;
        arr[x] = i;
        arr[y] = i;
    }

    for (int i = 1; i <= 10000; i++) {
        if (arr[i])
            v.push_back(arr[i]);
    }

    N %= v.size();
    rotate(v.begin(), v.begin() + N, v.end());
    cout << v[v.size() - 1] << endl;
    return 0;
}