#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

ll t[100000];
ll b[100000];
ll c[100000];

int main() {
    fastio;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }

    ll time = t[0];
    ll sum = c[0];
    
    for (int i = 1; i < N; i++) {
        cout << "time : " << time << "sum : " << sum << endl;
        cout << "t[i] - b[i] : " << t[i] - b[i] << endl;
        if (t[i] - b[i] > time) {
            time = t[i];
            sum += c[i];
        } else {
            cout << "sum - c[i - 1] + c[i] : " << sum - c[i - 1] + c[i] << endl;
            cout << "sum : " << sum << endl;
            if (c[i] > sum) {
                sum = c[i];
                time = t[i];
            } else if (sum - c[i - 1] + c[i] > sum) {
                sum = sum - c[i - 1] + c[i];
                time = t[i];
            }
        }
    }
    cout << sum << endl;
    return 0;
}