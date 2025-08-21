#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

class Trie {
    public:
        int cnt = 0;
        map<char, Trie *> sub;

        ~Trie() {
            for (auto &[key, child]: sub) {
                delete child;
            }
        }

        bool insert(char *s) {
            if (s[0] == '\0') {
                cnt++;
                return false;
            }
            if (cnt) return true;
            if (sub.find(s[0]) == sub.end()) sub[s[0]] = new Trie();
            return sub[s[0]]->insert(s + 1);
        }
};

int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        Trie *root = new Trie();
        vector<string> v;
        int N; cin >> N;
        
        while (N--) {
            string str; cin >> str;
            v.push_back(str);
        }
        sort(v.begin(), v.end());
        
        bool flag = false;
        for (auto s : v) {
            if (root->insert(&s[0])) {
                flag = true;
                break;
            }
        }
        delete root;
        cout << (flag ? "NO" : "YES") << endl;
    }
    return 0;
}