#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;
    vector<int> pos, neg;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        if (k > 0) pos.push_back(k);
        else neg.push_back(-k);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i <= N; i++) {
        int p = lower_bound(pos.begin(), pos.end(), i + 1) - pos.begin();
        int n = upper_bound(neg.begin(), neg.end(), i) - neg.begin();

        cout << " i = " << i << ", p = " << p << ", n = " << n << endl;
        if (p + n == i) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    cout << endl;

    return 0;
}