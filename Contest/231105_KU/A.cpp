#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    int N, M;
    int blackLine = -1;
    int cnt = 0;    
    cin >> N >> M;
    while (N--) {
        string str; cin >> str;
        str = '0' + str;
        int curLine = 0;
        int tmp = 0;
        bool flag = true;
        char prev = '0';
        for (int i = 1; i <= M; i++) {
            prev = str[i - 1];
            if (prev == '0' && str[i] == '1') {
                curLine++;
            }
        }
        if (curLine == blackLine) {
            cnt++;
        } else if (curLine > blackLine) {
            cnt = 1;
            blackLine = curLine;
        }
    }
    cout << blackLine << " " << cnt << endl;
    return 0;
}