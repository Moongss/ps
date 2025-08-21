#include <bits/stdc++.h>
#define endl "\n"
#define x first
#define y second
using namespace std;
using pii = pair<int, int>;
int N, K; 

pii ret;
int cnt;
int main() {
    
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (i == 0) ret = {x, x};
        else {
            ret = {min(ret.x, x), max(ret.y, x)};
            if (ret.y - ret.x + 1 > K) {
                cnt++;
                ret = {x, x};
            }
        }
    }
    cout << cnt << endl;
    return 0;
}