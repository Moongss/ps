#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
int arr[101];

int main() {
    fastio;
    
    cin >> N;
    memset(arr, -1, sizeof(arr));

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }

    int M; cin >> M;
    vector<int> v;

    for (int i = 0; i < M; i++) {
        int L; cin >> L;
        v.clear();
        for (int j = 0; j < L; j++) {
            int x; cin >> x; 
            if (arr[x] == -1) continue;
            v.push_back(arr[x]);
        }

        if (v.size() != L) {
            cout << "YOU DIED" << endl;
        } else {
            for (int x : v) cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}