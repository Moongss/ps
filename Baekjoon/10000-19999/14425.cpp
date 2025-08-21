#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

set<string> s;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        s.insert(str);
    }

    int sum = 0;
    for (int i = 0; i < M; i++) {
        string str; cin >> str;
        if (s.find(str) != s.end())
            sum++;
    }
    cout << sum << "\n";
    return 0;
}