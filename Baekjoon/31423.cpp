#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
vector<string> v;
int head[500001];
int tail[500001];
int uf[500001];

int find(int x) {
    if (uf[x] == x) return x;
    return uf[x] = find(uf[x]);
}

void setUf(int a, int b) {
    a = find(a);
    b = find(b);

    uf[a] = b;
}


int main() {
    fastio;
    
    cin >> N;
    v.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        head[i] = tail[i] = uf[i] = i;
    }

    int cur;
    for (int i = 1; i <= N - 1; i++) {
        int x, y; cin >> x >> y;

        // cout << "x : " << head[x] << ", " << tail[x] << endl;
        // cout << "y : " << head[y] << ", " << tail[y] << endl;

        head[y] = find(x);
        tail[find(x)] = y;
        setUf(x, y);

        // cout << "x : " << head[x] << ", " << tail[x] << endl;
        // cout << "y : " << head[y] << ", " << tail[y] << endl;
        // cout << find(x) << endl;
        // cout << endl;
        if (i == N - 1) cur = x;
    }

    while (tail[cur] != cur) {
        cout << v[cur];
        cur = tail[cur];
    }
    cout << v[cur] << endl;
    return 0;
}