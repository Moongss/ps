#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
vector<int> arr;

int main() {
    fastio;
    
    cin >> N; arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<>());

    int sum = 0;
    for (int i = N / 2 + (N % 2 ? 1 : 0); i < N; i++) {
        sum += arr[i];
    }   
    cout << sum << " ";
    sum = 0;
    for (int i = 0; i < N / 2 + (N % 2 ? 1 : 0); i++) {
        sum += arr[i];
    }
    cout << sum << endl;
    
    return 0;
}