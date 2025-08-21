#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    fastio;
    int N; cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string str; getline(cin, str);
        int idx = 0;
        for (idx; idx < str.size(); idx++) {
            if (str[idx] == ' ') {
                idx++;
                break;
            }
        }

        cout << "god";
        for (idx; idx < str.size(); idx++) {
            if (str[idx] != ' ')
                cout << str[idx];
        }
        cout << endl;
    }
    return 0;
}