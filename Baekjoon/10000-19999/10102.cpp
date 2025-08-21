#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    
    int N; cin >> N;
    int a = 0, b = 0;
    for (int i = 0; i <N;i++){
        char casd; cin >> casd; 
        if (casd    == 'A') a++; else b++;

    }
    cout << (a == b ? "Tie" : a > b ? "A" : "B") << endl;
    return 0;
}