#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int ans[10];
int save[10];

ll result = 0;
void dfs(int cur) {
    if (cur == 10) {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            if (i <= 7) {
                if (save[i] == save[i + 1] && save[i + 1] == save[i + 2]) return;
            }
            if (ans[i] == save[i]) sum++;
        }

        if (sum >= 5) {
            result++;
        }
        return;
    }

    for (int i = 1; i <= 5; i++ ){
        save[cur] = i;
        dfs(cur + 1);
    }
}

int main() {
    fastio;
    
    for (int i = 0; i < 10; i++) {
        cin >> ans[i];
    }

    dfs(0);
    cout << result << endl;
    return 0;
}