#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

#define ROCK 0
#define SCISSOR 1
#define PAPER 2

int N, M;
bool arr[101][3];
int win[101];
int lose[101];
bool flag = false;

int main() {
    fastio;
    while (true) {
        cin >> N;
        if (N == 0) break;
        cin >> M;

        memset(win, 0, sizeof(win));
        memset(lose, 0, sizeof(lose));
        int total = M * N * (N - 1) / 2;
        for (int i = 0; i < total; i++) {
            int i1, i2;
            string str1, str2;
            cin >> i1 >> str1 >> i2 >> str2;

            if (str1 == str2) continue;
            if (str1 == "rock" && str2 == "scissors" ||
                str1 == "scissors" && str2 == "paper" ||
                str1 == "paper" && str2 == "rock") {
                win[i1]++; lose[i2]++;
            }
            else {
                win[i2]++; lose[i1]++;
            }
        }

        if (flag) cout << endl;
        for (int i = 1; i <= N; i++) {
            if (win[i] + lose[i] == 0) {
                cout << "-" << endl;
            } else {
                // win[i] = 9; lose[i] = 1991;
                // cout << (1.0f * (win[i]) / (win[i] + lose[i])) << endl;
                // cout << (int)(((win[i] * 1000.0) / (win[i] + lose[i])) + 0.5f) << endl;
                double res = (int)(((win[i] * 1000.0) / (win[i] + lose[i])) + 0.5f) / 1000.0f;
                cout << fixed << setprecision(3) << res << endl;
                // printf("%.3lf\n", (double)win[i] / (win[i] + lose[i]));
            }
        }
        flag = true;
    }
    return 0;
}