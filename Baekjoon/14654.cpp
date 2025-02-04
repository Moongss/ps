#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int l,r;
int arr[2][303];

int main() {
    fastio;
    
    int N; 
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[0][i];
    }
    for (int i = 0; i < N; i++) {
        cin >> arr[1][i];
    }

    int Max = 0;
    for (int i = 0; i < N; i++) {
        if (arr[0][i] == arr[1][i]) {
            if (l) {r++, l=0;}
            else {l++, r=0;}
        }
        else if (arr[0][i] == 1 && arr[1][i] == 3) l++, r=0;
        else if (arr[0][i] == 3 && arr[1][i] == 1) r++, l=0;
        else if (arr[0][i] > arr[1][i]) l++, r=0;
        else if (arr[1][i] > arr[0][i]) r++, l=0;
        Max = max({Max, l, r});
    }
    cout << Max << endl;
    return 0;
}
