#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;


int main() {
    fastio;
    int N; cin >> N;
    set<string> s;
    string str;
    int result = 0;

    cin >> str; N--;
    while (N--) {
        cin >> str;
        if (str != "ENTER") {
            s.insert(str);
        } else {
            result += s.size();
            s.clear();
        }
    }
    result += s.size();
    cout << result << endl;
    return 0;
}