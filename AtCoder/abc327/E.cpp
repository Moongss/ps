#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N;
vector<int> P;
ld result;
bool flag = true;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        P.push_back(tmp);
    }

    for (int i = 0; i <= N; i++) {
        vector<bool> comb(P.size(), true);
        for (int j = 0; j < P.size() - i; j++) {
            comb[j] = false;
        }

        do {
            vector<int> test;
            for (int j = 0; j < P.size(); ++j) {
                if(comb[j]) test.push_back(P[j]);
            }

            for (int j = 0; j < test.size(); j++) {
                cout << test[j] << " ";
            }
            cout << endl;

            int cnt = 0;
            ld up = 0;
            ld down = 0;
            ld right = 0;

            for (int j = 0; j < test.size(); j++) {
                up *= 0.9;
                down *= 0.9;

                up += test[j];
                down += 1;
                cnt++;
                right = 1200.0 / sqrt(cnt);

                ld score = up / down - right;
                if (flag) {result = score; flag = false;}
                else result = max(result, score);
            }
        } while (next_permutation(comb.begin(), comb.end()));
    }

    cout << setprecision(10);
    cout << result << endl;
    return 0;
}