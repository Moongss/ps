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

int N, M;
int parent[101010];
int sz[101010];
int A[101010], B[101010];

int cnt;

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;
    // 일단 홍수였던거 싹 빼기
    if (A[a] < B[a]) cnt -= sz[a];
    if (A[b] < B[b]) cnt -= sz[b];

    if (sz[a] < sz[b]) swap(a, b); // a>b
    parent[b] = a;
    sz[a] += sz[b];
    A[a] += A[b];
    B[a] += B[b];

    if (A[a] < B[a]) cnt += sz[a];
}

int main() {
    fastio;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i; sz[i] = 1;
    }
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];

    for (int i = 1; i <= N; i++) {
        if (A[i] < B[i]) cnt++;
    }

    while (M--) {
        int q; cin >> q;
        if (q == 1) {
            int a, b; cin >> a >> b;
            merge(a, b);
        }
        else { // 출력
            cout << cnt << endl;
        }
    }    
    return 0;
}