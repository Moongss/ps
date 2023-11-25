#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N;
vector<pair<int, int>> v;
vector<pair<int, int>> tmp;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}

ll getDist(pair<int, int> &a, pair<int, int> &b) {
    ll x = a.first - b.first;
    ll y = a.second - b.second;
    return x * x + y * y;
}

ll getClosest(int start, int end) {
    if (end - start + 1 == 2) return getDist(v[start], v[end]);
    if (end - start + 1 == 3) {
        ll x = getDist(v[start], v[start + 1]);
        ll y = getDist(v[start + 1], v[end]);
        ll z = getDist(v[start], v[end]);
        return min(x, min(y, z));
    }
    
    int mid = (start + end) / 2;
    ll closest = min(getClosest(start, mid), getClosest(mid + 1, end));

    tmp.clear();
    for (int i = start; i <= end; i++) {
        ll x = v[i].first - v[mid].first;
        if (x * x < closest) tmp.push_back(v[i]);
    }

    sort(tmp.begin(), tmp.end(), compare);
    for (int i = 0; i < tmp.size(); i++) {
        for (int j = i + 1; j < tmp.size(); j++) {
            ll y = tmp[i].second - tmp[j].second;
            if (y * y >= closest) break;
            closest = min(closest, getDist(tmp[i], tmp[j]));
        }
    }

    return closest;
}

int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());
    cout << getClosest(0, N - 1) << endl;
    return 0;
}