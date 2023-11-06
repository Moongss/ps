#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    int N;
    cin >> N;
    if (N % 2 == 0)
        cout << "Duck" << endl;
    else
        cout << "Goose" << endl;
    return 0;
}