#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    
    int N; cin >> N;
    while (N--) {
        string str; cin >> str;
        for (auto &c : str) if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        cout << str << endl;
    }
    return 0;
}