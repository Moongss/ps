#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int itoN[301];
int Ntoi[301];
int tmp[301];
int main() {
    fastio;
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        itoN[i] = a;
        Ntoi[a] = i;
        tmp[a] = i;
    }
    int T; cin >> T;
    while (T--) {
        int L, R; cin >> L >> R;
        for (int i = L; i <= R - 1; i++) {
            for (int j = i + 1; j <= R; j++) {
                if (tmp[i] > tmp[j]) {
                    swap(tmp[i], tmp[j]);
                }
            }
        }

        int result[301] = {0, };
        for (int i = 1; i <= N; i++) {
            result[tmp[i]] = i;
        }
        for (int i = 1; i <= N; i++) {
            cout << result[i] << " ";
            tmp[i] = Ntoi[i];
        }
        cout << endl;
    }
    return 0;
}