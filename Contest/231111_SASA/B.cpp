#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

bool test[1001];
bool arrP[1001];
bool arrM[1001];
int main() {
    fastio;
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        test[i] = true;
    }
    for (int i = 0; i < M; i++) {
        int a, c; 
        char b;
        cin >> a >> b >> c;

        if (b == 'P' && c == 1)
            arrP[a] = true;
        if (b == 'M' && c == 0)
            arrM[a] = true;
        if (b == 'P' && c == 0 || b == 'M' && c == 1) {
            test[a] = false;
        }
    }

    int cnt = N;
    int sikmul = 0;
    for (int i = 1; i <= N; i++) {
        if (test[i] == false) cnt--;
        if (arrP[i] && arrM[i]) sikmul++;
    }
    cout << sikmul << " " << cnt << endl;
    return 0;
}