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
        int t; cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    cout << N - 1 + v[N - 1] << endl;
    return 0;
}