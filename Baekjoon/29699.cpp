#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    string str = "WelcomeToSMUPC";
    int N; cin >> N;
    cout << str[(N - 1) % 14] << endl;
    
    return 0;
}