#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using piii = pair<int, pair<int, int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

vector<piii> v;
int arr[101];
int N;
int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, score; cin >> x >> y >> score;
        v.push_back({score, {x, y}});
    }

    sort(v.begin(), v.end(), greater<piii>());

    int cnt = 0;
    for (auto &e : v) {
        if (cnt == 3) break;
        if (arr[e.second.first] >= 2) continue;

        cout << e.second.first << " " << e.second.second << endl;
        arr[e.second.first]++; cnt++;
    }
    return 0;
}