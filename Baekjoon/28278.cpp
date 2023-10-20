#include <iostream>
#include <bits/stdc++.h>
using namespace std;
stack<int> s;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int N; cin >> N;
    while (N--) {
        int flag, num; 
        
        cin >> flag;
        if (flag == 1) {
            cin >> num;
            s.push(num);
        } else if (flag == 2) {
            if (!s.empty()) {cout << s.top() << "\n"; s.pop(); } else {cout << -1 << "\n";}
        } else if (flag == 3) {
            cout << s.size() << "\n";
        } else if (flag == 4) {
            if (s.empty()) cout << 1 << "\n"; else cout << 0 << "\n";
        } else {
            if (!s.empty()) cout << s.top() << "\n"; else {cout << -1 << "\n";}
        }
    }

    return 0;
}