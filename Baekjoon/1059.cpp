#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
bool arr[1001];

int main() {
    fastio;
    
    memset(arr, true, sizeof(arr));
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        arr[x] = false;
    }

    int target; cin >> target;
    if (arr[target] == false) {
        cout << 0 << endl;
    } else {
        int leftIdx, rightIdx;
        
        leftIdx = target;
        while (arr[leftIdx] && leftIdx >= 1) {
            leftIdx--;
        }
        leftIdx++;

        rightIdx = target;
        while (arr[rightIdx] && rightIdx <= 1000) {
            rightIdx++;
        }
        rightIdx--;

        int cnt = 0;
        for (int i = leftIdx; i <= target; i++) {
            for (int j = target; j <= rightIdx; j++) {
                cnt++;
            }
        }
        cnt--;
        cout << cnt << endl;
    }
    return 0;
}