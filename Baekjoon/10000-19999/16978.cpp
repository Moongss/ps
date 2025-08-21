#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

struct Q1 {
    int idx;
    int value;
};

struct Q2 {
    int idx;
    int queryIdx;
    int s;
    int e;
};

bool cmp(const Q2 &a, const Q2 &b) {
    return a.queryIdx < b.queryIdx;
}

ll SZ[1 << 20];
int N, M; 
int cnt = 0;

vector<ll> v;
vector<ll> result; 

vector<Q1> vQ1;
vector<Q2> vQ2;

void update(int l, int r, int node, int idx, ll diff) {
    if (idx < l || r < idx) return;

    SZ[node] += diff;
    if (l == r && l == idx) return;

    int mid = (l + r) / 2;
    update(l, mid, node * 2, idx, diff);
    update(mid + 1, r, node * 2 + 1, idx, diff);
}

ll query(int l, int r, int s, int e, int node) {
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return SZ[node];

    int mid = (l + r) / 2;
    return query(l, mid, s, e, node * 2)
         + query(mid + 1, r, s, e, node * 2 + 1);
}

int main() {
    fastio;
    
    cin >> N;
    v.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        update(1, N, 1, i, v[i]);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int flag; cin >> flag;
        if (flag == 1) {
            int idx, v; cin >> idx >> v;
            vQ1.push_back({idx, v});
        } else {
            int queryIdx, s, e; cin >> queryIdx >> s >> e;
            vQ2.push_back({cnt, queryIdx, s, e});
            cnt++;
        }
    }

    sort(vQ2.begin(), vQ2.end(), cmp);
    result.resize(vQ2.size());

    int qIdx = 0;
    for (int i = 0; i < vQ2.size(); i++) {
        auto &[resultIdx, queryIdx, s, e] = vQ2[i];
        
        while (queryIdx > qIdx) {
            auto &[idx, value] = vQ1[qIdx];
            update(1, N, 1, idx, value - v[idx]);
            v[idx] = value;
            qIdx++;
        }
        result[resultIdx] = query(1, N, s, e, 1);
    }  

    for (auto &x : result) {
        cout << x << endl;
    }
    return 0;
}