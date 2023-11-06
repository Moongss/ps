#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
int N;
int A[1001];

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        A[tmp]++;
    }

    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        if (A[i] < 2) sum += A[i];
        else sum += 2;
    }
    cout << sum << endl;
    return 0;
}