#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
int phone[100001];

int main() {
    fastio;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> phone[i];
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (i == phone[i]) {
            phone[i] = phone[i] % N + 1;
            cnt++;
        }
    }

    cout << cnt << endl;
    for (int i = 1; i <= N; i++) {
        cout << phone[i] << " ";
    }
    cout << endl;
    return 0;
}