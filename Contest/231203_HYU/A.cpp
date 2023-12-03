#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    fastio;
    int N; cin >> N;
    while (N--) {
        int t; cin >> t;
        int k = t / 5;
        int j = t % 5;

        for (int i = 0; i < k; i++) {
            cout << "++++" << " ";
        }
        for (int i = 0; i < j; i++) {
            cout << "|";
        }
        cout << endl;
    }
    return 0;
}