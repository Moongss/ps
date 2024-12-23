#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool arr[101];
int main() {
    fastio;
    
    for (int i = 2; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            arr[j] = arr[i*j] = true;
        }
    }
    int N; cin >> N;
    cout << arr[N] << endl;
    return 0;
}