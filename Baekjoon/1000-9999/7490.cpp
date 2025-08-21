#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

char tmp[42];
char res[42];
int N;

vector<string> v;

bool isZero(std::string str) {
    vector<int> numV;
    vector<char> operV;

    int tmp = 0;
    for (auto &x : str) {
        if (isdigit(x)) {
            tmp += x - '0';
        } else {
            if (x == '+' || x == '-') {
                numV.push_back(tmp); tmp = 0;
                operV.push_back(x);
            }
            else
                tmp *= 10;
        }
    }
    if (tmp) numV.push_back(tmp);

    int result = numV[0];
    for (int i = 0; i < operV.size(); i++) {
        if (operV[i] == '+') {
            result += numV[i + 1];
        } else {
            result -= numV[i + 1];
        }
    }

    return (result == 0);
}

void dfs(int idx, std::string toPrint) {
    int num = idx + 1;
    char numChar = idx + 1 + '0';
    int operIdx = idx * 2;
    if (idx == N) {
        if (isZero(toPrint)) 
            v.push_back(toPrint);
        return; 
    }  

    dfs(idx + 1, toPrint + ' ' + numChar);
    dfs(idx + 1, toPrint + "+" + numChar);
    dfs(idx + 1, toPrint + "-" + numChar);
}
int main() {
    // fastio;
    
    int T; cin >> T;
    while (T--) {
        cin >> N;
        v.clear();

        dfs(1, "1");

        sort(v.begin(), v.end());
        for (auto &x : v) {
            cout << x << endl;
        }
        cout << endl;
    }
    return 0;
}