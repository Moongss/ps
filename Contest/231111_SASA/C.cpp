#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    string hand = "";
    string machine = "";
    for (int i = 0; i < 100; i++) {
        hand += '2';
    }
    for (int i = 0; i < 100; i++) {
        machine += '5';
    }
    int now; cin >> now;
    int prev = now;
    int idx = 0;
    while (idx < 100 && prev < 100) {
        hand[idx] = '0';
        cout << "? " << hand << endl;
        cout << flush;

        cin >> now;
        if (now < prev) {
            machine[idx] = '5';
        } else if (now == prev) {
            machine[idx] = '0';
        } else {
            machine[idx] = '2';
        }
        prev = now;
        idx++;
    }
    cout << "! " << machine << endl;
    cout << flush;
    return 0;
}