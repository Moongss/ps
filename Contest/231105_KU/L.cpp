#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N, M;
vector<int> A;

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        A.push_back(tmp);
    }

    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());

    ll cnt = 0;
    for (int i = 1; i < M; i++) {
        if (i < A.size())
            cnt += i;
    }    
    cout << cnt << endl;
    return 0;
}