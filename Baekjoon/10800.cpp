#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N;
ll result[200001];
ll preC[200001];
vector<ll>preS[2001]; //vector has idx.
vector<pair< pair<ll, ll>, ll> > v;

int main() {
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        ll C, S; cin >> C >> S;
        v.push_back({{S, C}, i});
    }
    sort(v.begin(), v.end());

    ll sum = 0;
    for (auto elem : v) {
        ll S = elem.first.first;
        ll C = elem.first.second;
        ll idx = elem.second;

        ll sameBallCnt = upper_bound(preS[S].begin(), preS[S].end(), C) - lower_bound(preS[S].begin(), preS[S].end(), C);
        result[idx] = sum - preC[C] - (preS[S].size() - sameBallCnt) * S; //preFixSum - sameColorSum - sameSize(all - sameColor)
        sum += S;
        preC[C] += S;
        preS[S].push_back(C);

    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << endl;
    }
    return 0;
}