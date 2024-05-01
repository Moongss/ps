#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

string str;
int target;
char arr[11];
bool checked[11];

int cnt = 0;
void dfs(int level) {
    if (level == str.length()) {
        cnt++;
        if (cnt == target) {
            cout << str << " " << target << " = ";
            for (int i = 0; i < str.length(); i++) {
                cout << arr[i];
            }
            cout << endl;
        }
        return;
    }

    for (int i = 0; i < str.length(); i++) {
        arr[level] = str[i];
        if (!checked[i]) {
            checked[i] = true;
            dfs(level + 1);
            checked[i] = false;
        }
    }
}

int main() {
    fastio;
    
    while (true) {
        cnt = 0;
        memset(arr, 0, sizeof(arr));
        memset(checked, 0, sizeof(checked));
        cin >> str >> target;
        if (cin.eof()) break;
        int p = 1;
        for (int i = 1; i <= str.length(); i++) {
            p *= i;
        }
        if (p < target) {
            cout << str << " " << target << " = No permutation" << endl;
        } else {
            dfs(0);
        }
    }
    return 0;
}