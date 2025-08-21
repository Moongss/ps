#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    
    int cnt = 0;
    string tmp;

    getline(cin, tmp);
    while (true) {
        getline(cin, tmp);
        if (tmp == "고무오리 디버깅 끝") break;

        if (tmp == "문제") cnt++;
        else if (tmp == "고무오리" && cnt == 0) cnt += 2;
        else if (tmp == "고무오리") cnt--;
    }
    cout << (cnt == 0 ? "고무오리야 사랑해" : "힝구") << endl;
    return 0;
}