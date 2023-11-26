#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N, M;
vector<int> A;
vector<int> B;
vector<int> res;
int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        A.push_back(tmp);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp; cin >> tmp;
        B.push_back(tmp);
    }


    bool Aflag = false;
    bool Bflag = false;
    int Aidx = 0;
    int Bidx = 0;

    int save[2];
    int maxValue = 100;
    bool flag = false;
    while (Aidx < A.size() && Bidx < B.size()) {
        flag = false;
        for (int i = maxValue; i >= 1; i--) {
            Aflag = Bflag = false;
            for (int j = Aidx; j < A.size(); j++) {
                if (A[j] == i) {
                    Aflag = true;
                    save[0] = j;
                    break;
                }
            }
            for (int j = Bidx; j < B.size(); j++) {
                if (B[j] == i) {
                    Bflag = true;
                    save[1] = j;
                    break;
                }
            }
            if (Aflag && Bflag) {
                res.push_back(i);
                maxValue = i;
                Aidx = save[0] + 1;
                Bidx = save[1] + 1;
                flag = true;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}