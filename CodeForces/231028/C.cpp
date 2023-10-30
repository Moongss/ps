#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    // fastio;
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        string str; cin >> str;

        if (N % 2 == 1) {cout << -1 << endl; continue;}

        if (str[0] == '1') {
            bool flag = true;
            for (int i = 0; i < N / 2; i++) {
                if (str[i] == str[N - 1 - i]) {
                    flag = false;
                    break;
                }
            }

            if (flag)
                cout << 0 << endl << endl;
            else
                cout << -1 << endl;
        } else {
            bool flag = true;
            for (int i = 0; i < N / 2; i++) {
                if (str[i] == str[N - 1 - i]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                cout << 0 << endl << endl;
                continue;
            }

            int idx = 0;
            int cnt[2] = {0, }; //zero, one
            while (str[idx] == '0' && idx < N) {
                cnt[0]++;
                idx++;
            }
            while (str[idx] == '1' && idx < N) {
                cnt[1]++;
                idx++;
            }

            int tmp = 0;
            while (idx < N) {
                if (str[idx] == '0') tmp++;
                else tmp--;
                idx++;
            }

            if (tmp > 0) cnt[1] -= tmp;
            else cnt[0] += tmp;
            if (cnt[0] != cnt[1] || cnt[0] > 300) {
                cout << -1 << endl; 
            } else {
                cout << cnt[0] << endl;
                for (int i = 0; i < cnt[0]; i++) {
                    cout << N + i << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}