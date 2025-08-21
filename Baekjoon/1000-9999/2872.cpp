#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N;
vector<int> v;

int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        v.push_back(num);
    }

    int s = N;
    for (int i = N - 1; i >= 0; i--) {
        if (v[i] == s) s--;
    }
    cout << s << endl;
    return 0;
}