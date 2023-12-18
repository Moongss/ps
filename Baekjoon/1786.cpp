#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

string T, P;
int fail[1000001];
vector<int> ans;

int main() {
    fastio;
    
    getline(cin, T);
    getline(cin, P);

    for (int i = 1, j = 0; i < P.length(); i++) {
        while (j > 0 && P[i] != P[j]) j = fail[j - 1];
        if (P[i] == P[j]) fail[i] = ++j;
    }

    for (int i = 0, j = 0; i < T.length(); i++) {
        while (j > 0 && T[i] != P[j]) j = fail[j - 1];
        if (T[i] == P[j]) {
            if (j == P.length() - 1) {
                ans.push_back(i - j + 1);
                j = fail[j];
            } 
            else 
                j++;
        }
    }

    cout << ans.size() << endl;
    for (auto elem : ans) {
        cout << elem << endl;
    }
    return 0;
}