#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N;
int l, r;
int w[7] = {100, 50, 20, 10, 5, 2, 1};

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        if (l <= r)
            l += tmp;
        else
            r += tmp;
    }
    
    int sub = max(l, r) - min(l, r);
    int result = 0;
    int i = 0;
    while (i < 7 && sub) {
        result += sub / w[i];
        sub %= w[i];
        i++;
    }
    cout << result << endl;
    
    return 0;
}