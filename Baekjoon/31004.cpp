#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int arr[3001][3001];
vector<int> v;
int main() {
    fastio;
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int left, right;
        cout << "? " << 1 << " " << i << endl << flush;
        cin >> arr[1][i];
        cout << "? " << i << " " << N << endl << flush;
        cin >> arr[i][N];
    }

    for (int i = 1; i <= N; i++) {
        if (i == 1 && arr[1][N] == arr[2][N] + 1) v.push_back(i);
        else if (i == N && arr[1][N] == arr[1][N - 1] + 1) v.push_back(i);
        else if (arr[1][i] == arr[1][i - 1] + 1 && 
                 arr[i][N] == arr[i + 1][N] + 1) {
            v.push_back(i);
        }
    }
    cout << "! " << v.size() << " ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl << flush;
    return 0;
}