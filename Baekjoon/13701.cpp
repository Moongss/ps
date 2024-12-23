#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bitset<(1 << 25) - 1> bs;
int A;

int main() {
    fastio;
    
    while (cin >> A) {
        if (!bs[A]) 
            bs[A] = 1, cout << A << " ";
    }
    return 0;
}