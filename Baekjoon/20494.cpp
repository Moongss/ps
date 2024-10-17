#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    
    int N; cin >> N;
    int a = 0;
    while (N--) {
        string s; cin >> s; a += s.size();
    }
    cout << a << endl;
    return 0;
}