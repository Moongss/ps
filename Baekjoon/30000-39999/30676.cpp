#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int N; cin >> N;

    if (380 <= N && N < 425)
        cout << "Violet" << endl;
    else if (425 <= N && N < 450)
        cout << "Indigo" << endl;
    else if (450 <= N && N < 495)
        cout << "Blue" << endl;
    else if (495 <= N && N < 570)
        cout << "Green" << endl;
    else if (570 <= N && N < 590)
        cout << "Yellow" << endl;
    else if (590 <= N && N < 620)
        cout << "Orange" << endl;
    else if (620 <= N && N <= 780)
        cout << "Red" << endl;

    return 0;
}