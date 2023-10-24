#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N, M;
int A[100000];
stack<int> s;

int main() {
    fastio;
    cin >> N;
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        if (!A[i]) {cnt++; s.push(num);}
    }

    cin >> M;
    if (M > cnt) {
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cnt = M - cnt;
        for (int i = 0; i < M; i++) {
            int num; cin >> num;
            if (cnt > 0) {cout << num << " "; cnt--;}
        }
    } else {
        for (int i = 0; i < M; i++) {
            int num; cin >> num;
        }
        while (!s.empty() && M) {
            cout << s.top() << " ";
            s.pop();
            M--;
        }
    }
    return 0;
}