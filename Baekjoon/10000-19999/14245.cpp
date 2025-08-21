#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

constexpr int SZ = 1 << 19;

using namespace std;
using ll = long long;
using ld = long double;

int arr[SZ << 1];
int lazy[SZ << 1];

int query(int s, int e, int node, int target) {
    if (target < s || e < target) return 0;
    if (s == e && s == target) return lazy[node];

    int mid = (s + e) / 2;
    return lazy[node] ^ query(s, mid, node * 2, target) 
                      ^ query(mid + 1, e, node * 2 + 1, target);
} 

void update(int l, int r, int s, int e, int node, int val) {
    if (e < l || r < s) return;
    if (l <= s && e <= r) {
        lazy[node] ^= val;
        return;
    }

    int mid = (s + e) / 2;
    update(l, r, s, mid, node * 2, val);
    update(l, r, mid + 1, e, node * 2 + 1, val);
}

int N, M;

int main() {
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++) 
        cin >> arr[i];

    cin >> M;
    for (int i = 0; i < M; i++) {
        int t, a, b, c;
        cin >> t;
        if (t == 1) {
            cin >> a >> b >> c;
            update(a + 1, b + 1, 1, N, 1, c);
        } else {
            cin >> a;
            cout << (arr[a + 1] ^ query(1, N, 1, a + 1)) << endl;
        }
    }
    return 0;
}