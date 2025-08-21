#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
vector<pii> v;

bool compare1(pii a, pii b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

bool compare2(pii a, pii b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}
int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), compare1);
    cout << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << endl;

    sort(v.begin(), v.end(), compare2);
    cout << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << endl;
    return 0;
}