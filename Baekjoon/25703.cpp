#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
int main() {
    fastio;
    
    cin >> N;
    cout << "int a;" << endl;
    cout << "int *ptr = &a;" << endl;

    for (int i = 2; i <= N; i++) {
        cout << "int ";
        for (int j = 0; j < i; j++) cout << "*";
        cout << "ptr" << i << " = &ptr";
        if (i == 2) cout << ";" << endl;
        else cout << i - 1 << ";" << endl;
    }
    return 0;
}