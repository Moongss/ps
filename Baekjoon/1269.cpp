#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;

int N, M;
int tmp;
set<int> s;

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N + M; i++) {
        int tmp; cin >> tmp;
        if (s.find(tmp) == s.end())
            s.insert(tmp);
        else
            s.erase(tmp);
    }
    cout << s.size() << endl;
    return 0;
}