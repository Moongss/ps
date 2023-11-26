#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N;
int arr[200001];
bool check[200001];

ll pre = 0;
int main() {
    fastio;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i]; pre+=arr[i];
    }
    cout << pre << endl;
    
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int q; cin >> q;
        if (q == 1) {
            int idx, v; cin >> idx >> v;
            if (!check[idx])
                pre = pre - arr[idx] + v;
            arr[idx] = v;
        } else {
            int idx; cin >> idx;
            if (!check[idx]) pre -= arr[idx];
            else pre += arr[idx];
            check[idx] = !check[idx];
        }
        cout << pre << endl;
    }
    return 0;
}