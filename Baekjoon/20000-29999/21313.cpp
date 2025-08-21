#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int N; cin >> N;
    for (int i = 0; i < N / 2; i++) {
        cout << "1 2 ";
    }    
    cout << (N % 2 ? "3" : "") << endl;
    return 0;
}