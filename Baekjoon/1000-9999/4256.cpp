#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int T, N;
int pre[1001];
pair<int, int> in[1001]; //idx, value

void solve(int in_s, int in_e, int pre_s, int pre_e) {
    if (in_s > in_e || pre_s > pre_e) return;

    int rootIdx = in[pre[pre_s]].first;
    int root = in[pre[pre_s]].second;
    int leftChild = rootIdx - in_s;

    solve(in_s, rootIdx - 1, pre_s + 1, pre_s + leftChild);
    solve(rootIdx + 1, in_e, pre_s + leftChild + 1, pre_e);
    cout << root << " ";
}

int main() {
    fastio;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> pre[i];
        }
        for (int i = 0; i < N; i++) {
            int node; cin >> node;
            in[node] = {i, node};
        }
        solve(0, N - 1, 0, N - 1);
        cout << endl;
    }
    return 0;
}