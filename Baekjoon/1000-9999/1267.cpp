#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    
    int N;
    int asum = 0, bsum = 0;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        asum += (x / 30 + 1) * 10;
        bsum += (x / 60 + 1) * 15;
    }

    if (asum < bsum) cout << "Y " << asum << endl;
    else if (asum > bsum) cout << "M " << bsum << endl;
    else cout << "Y M " << asum << endl;
    return 0;
}