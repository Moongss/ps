#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int n, w, L;
int arr[1000];
queue<int> q;

int main() {
    fastio;
    
    cin >> n >> w >> L;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < w; i++) q.push(0);
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (sum + arr[i] <= L) {
            sum -= q.front(); q.pop();
            q.push(arr[i]);
            sum += arr[i];
            res++;
        } else {
            while (sum + arr[i] > L) {
                res++;
                sum -= q.front(); q.pop();
                if (sum + arr[i] <= L) {
                    q.push(arr[i]);
                    sum += arr[i];
                    break;
                } else {
                    q.push(0);
                }
            }
        }
    }
    while (!q.empty()) {
        q.pop();
        res++;
    }
    cout << res << endl;
    return 0;
}