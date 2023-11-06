#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

ll A[2000];
ll B[40000];
vector<ll> tmp;
int main() {
    fastio;
    int N, M;
    ll R;

    cin >> N >> M >> R;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    sort(A, A + N);
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            tmp.push_back(abs(A[j] - A[i]));
        }
    }
    sort(tmp.begin(), tmp.end());
    R *= 2;
    ll result = -1;
    for (int i = 0; i < M; i++) {
        int lo = 0;
        int hi = tmp.size(); 
        int mid;
        while (lo + 1 < hi) {
            mid = (lo + hi) / 2;
            if (B[i] * tmp[mid] <= R) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        if (B[i] * tmp[lo] <= R)
            result = max(result, B[i] * tmp[lo]);
    }
    
    if (result == -1)
        printf("-1\n");
    else
        printf("%.1Lf\n", result / (ld)2.0);
    return 0;
}