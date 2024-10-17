#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    
    int N; cin >> N;
    int ret = 0;
    int s, e; cin >> s >> e;
    for (int i = 1; i < N; i++) {
        int x, y; cin >> x >> y;
        if (x <= e) {
            e = max(e, y);
        } else {
            ret += e - s; 
            s = x; e = y;
        }
    }
    ret += e - s;
    cout << ret << endl;
    return 0;
}