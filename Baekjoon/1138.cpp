#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
bool visited[11];
int result[11];

int main() {
    fastio;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int tmp; cin >> tmp; tmp++;
        
        int j = 0;
        while (tmp) {
            if (!visited[j]) {tmp--; j++;}
            else j++;
        }
        while (visited[j]) j++;
        result[j] = i;
        visited[j] = true;
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}