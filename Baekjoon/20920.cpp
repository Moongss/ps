#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

bool cmp(const pair<string,int>& a, const pair<string,int>& b) {
    if (a.second != b.second)
        return a.second > b.second;
    if (a.first.length() != b.first.length())
        return a.first.length() > b.first.length();
	return a.first < b.first;
}

int main() {
    fastio;
    int N, M; cin >> N >> M;
    map<string, int> m;
    while (N--) {
        string str; cin >> str;
        if (str.length() < M) continue;
        if (m.find(str) == m.end())
            m.insert({str, 1});
        else
            m[str]++;
    }

    vector<pair<string, int>>v;
    while (!m.empty()) {
        v.push_back(*m.begin());
        m.erase(m.begin());
    }

    sort(v.begin(), v.end(), cmp);
    for (auto elem : v) {
        cout << elem.first << endl;
    }
    return 0;
}