#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "NB.h"
using namespace std;
string A;
int cnt;
bool solve;
void wa() {
    cout << "WA\n";
    exit(1);
}
pair<int,int> guess(string B) {
    if (A.length() != B.length()) {
        wa();
    }
    if (solve) {
        wa();
    }
    cnt += 1;
    if (cnt > 9) {
        wa();
    }
    int strike = 0;
    int ball = 0;
    vector<int> index_a(10, -1);
    vector<int> index_b(10, -1);
    for (int i=0; i<A.length(); i++) {
        if (!('0' <= B[i] && B[i] <= '9')) {
            wa();
        }
        int a = A[i]-'0';
        int b = B[i]-'0';
        index_a[a] = i;
        if (index_b[b] != -1) {
            wa();
        }
        index_b[b] = i;
    }
    for (int i=0; i<=9; i++) {
        if (index_a[i] == -1 || index_b[i] == -1) {
            continue;
        }
        if (index_a[i] == index_b[i]) {
            strike += 1;
        } else {
            ball += 1;
        }
    }
    if (strike == (int)A.length() && ball == 0) {
        solve = true;
    }
    return make_pair(strike, ball);
}
int main() {
    int T, N;
    cin >> T >> N;
    init(T, N);
    while (T--) {
        cin >> A;
        solve = false;
        cnt = 0;
        game();
        if (solve == false) {
            wa();
        }
    }
    cout << "AC\n";
    return 0;
}
