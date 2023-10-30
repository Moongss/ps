#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    // fastio;
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string strS, strT;
        cin >> strS >> strT;

        if (n == 1) {cout << "Yes" << endl; continue;}

        bool Scheck[2] = {0, };
        bool tmp = true;

        for (int i = 1; i < n; i++) {
            if (strS[i] == strS[i - 1] && strS[i] == '0') Scheck[0] = true;
            if (strS[i] == strS[i - 1] && strS[i] == '1') Scheck[1] = true;
        }

        if (Scheck[0] == false && Scheck[1] == false) {
            cout << "Yes" << endl;
            continue;
        } else if (Scheck[0] == true && Scheck[1] == true) {
            cout << "No" << endl;
            continue;
        }

        for (int i = 1; i < m; i++) {
            if (strT[i] == strT[i - 1]) {
                tmp = false;
                break;
            }
        }
        int Tcheck;
        if (!tmp) {cout << "No" << endl; continue;}
        if (strT[0] == strT[strT.length() - 1] && strT[0] == '0') Tcheck = 0; //00 or 0
        else if (strT[0] == strT[strT.length() - 1] && strT[0] == '1') Tcheck = 1; //11 or 1
        else Tcheck = -1; //10 01
        
        if (Scheck[0] == true && Tcheck == 1 || Scheck[1] == true && Tcheck == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}