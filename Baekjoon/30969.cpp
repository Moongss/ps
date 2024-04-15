#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N;
int arr[1001];

int main() {
    fastio;
    
    cin >> N;
    int targetCost = 0;
    for (int i = 0; i < N; i++) {
        string str; ll cost;
        cin >> str >> cost;
        if (str == "jinju") {targetCost = cost;}
        if (cost <= 1000) arr[cost]++;
    }

    int cnt = 0;
    for (int i = 0; i <= targetCost; i++) {
        if (arr[i]) cnt += arr[i];
    }
    cout << targetCost << endl;
    cout << N - cnt << endl;
    return 0;
}