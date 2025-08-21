#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N;
stack<int> s;
int B[200001];
bool isUsed[200001];
int main() {
    // fastio;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    for (int i = 1; i <= N; i++) {
        if (B[i] >= i + 2 || B[N] != N + 1 || B[i - 1] > B[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    int max = N;
    isUsed[0] = true;
    for (int i = N; i >= 1; i--) {
        if (!isUsed[B[i - 1]]) {
            isUsed[B[i - 1]] = true;
            s.push(B[i - 1]);
        } else {
            while (isUsed[max] && max > 1) {
                max--;
            }
            isUsed[max] = true;
            s.push(max);
        }
    }

    cout << "Yes" << endl; //WA: not printed..
    while (!s.empty()) {
        cout << s.top() << " "; s.pop();
    }
    cout << endl;
    return 0;
}