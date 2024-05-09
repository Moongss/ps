#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
vector<pii> v;
bool visited[11][11];
map<tuple<int, int, int>, int> m;

void solve(int cnt) {
    if (cnt == 3) {
        auto p1 = v[0];
        auto p2 = v[1];
        auto p3 = v[2];
        
        if (p1.first == p2.first && p2.first == p3.first) return;
        if (p1.second == p2.second && p2.second == p3.second) return;
        if (abs(p1.first - p2.first) == abs(p1.second - p2.second)  
         && abs(p1.first - p3.first) == abs(p1.second - p3.second) 
         && abs(p2.first - p3.first) == abs(p2.second - p3.second)) 
            return;

        if (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second 
        == p1.second * p2.first + p2.second * p3.first + p3.second * p1.first) return;
        int d1 = (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
        int d2 = (p1.first - p3.first) * (p1.first - p3.first) + (p1.second - p3.second) * (p1.second - p3.second);
        int d3 = (p2.first - p3.first) * (p2.first - p3.first) + (p2.second - p3.second) * (p2.second - p3.second);
        
        vector<int> tmp;
        tmp.push_back(d1); tmp.push_back(d2); tmp.push_back(d3);
        sort(tmp.begin(), tmp.end());   

        m[{tmp[0], tmp[1], tmp[2]}]++;
        return;
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                v.push_back({i, j});
                solve(cnt + 1);
                v.pop_back();
                visited[i][j] = false;
            }
        }
    }
}
int main() {
    fastio;
    
    cin >> N >> M;
    solve(0);
    cout << m.size() << endl;
    return 0;
}