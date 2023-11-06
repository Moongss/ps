#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    int N; cin >> N;
    bool flag = true;
    string str; cin >> str;

    for (int i = 1; i < N; i++) {
        if (str[i] == 'a' && str[i - 1] == 'b' ||
            str[i] == 'b' && str[i - 1] == 'a') {
                cout << "Yes" << endl;
                return 0;
            }
    }
    cout << "No" << endl;
    return 0;
}