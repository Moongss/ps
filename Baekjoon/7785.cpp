#include <bits/stdc++.h>
using namespace std;

set<string> s;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int N;
    string str, flag;

    cin >> N;
    while (N--) {
        cin >> str >> flag;
        if (flag == "enter")
            s.insert(str);
        else
            s.erase(str);
    }

    for (set<string>::reverse_iterator iter = s.rbegin(); iter != s.rend(); iter++) {
        std::cout << *iter << "\n";
    }
    return 0;
}