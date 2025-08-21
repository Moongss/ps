#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N;
ll road[100000];
ll oilPrice[100000];

int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> road[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> oilPrice[i];
    }

    ll minPrice = 1e9+1;
    ll result = 0;
    for (int i = 0; i < N - 1; i++) {
        if (minPrice > oilPrice[i]) {
            minPrice = oilPrice[i];
        }
        result += minPrice * road[i];
    }
    cout << result << endl;
    return 0;
}