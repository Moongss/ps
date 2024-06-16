#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int arr[1000001];
int main() {
    fastio;
    
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int B, C; cin >> B >> C;
    ll sum = 0;

    for (int i = 0; i < N; i++) {
        arr[i] -= B; 
        sum++;
        if (arr[i] > 0) {
            sum += (arr[i] % C) ? 1 : 0;
            sum += (arr[i] / C);
        }
    } 
    cout << sum << endl;
    return 0;
}