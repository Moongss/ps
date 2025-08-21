#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N;

void cantorianSet(int N) {
    if (N == 3) {
        cout << "- -";
        return;        
    }

    cantorianSet(N / 3);
    for (int i = 0; i < N / 3; i++) cout << " ";
    cantorianSet(N / 3);
}

int main() {
    fastio;
    
    int N;

    while (cin >> N) {
        if (N == 0) cout << "-";
        else cantorianSet(pow(3, N));
        cout << endl;
    }
    return 0;
}