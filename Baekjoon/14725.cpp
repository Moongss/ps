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
        bool isEnd = false;
        map<string, Trie *> nxt;

        ~Trie() {
            for (auto &[k, v]: nxt) {
                delete v;
            }
        }

        void insert(vector<string> &v) {
            Trie *cur = this;
            for (auto k : v) {
                if (!cur->nxt[k]) {
                    cur->nxt[k] = new Trie();
                }
                cur = cur->nxt[k];
            }
            cur->isEnd = true;
        }

        void getResult(int level) {
            Trie *cur = this;
            for (auto &[k, v] : cur->nxt) {
                for (int i = 0; i < level; i++) {
                    cout << "--";
                }
                cout << k << endl;
                v->getResult(level + 1);
            }
        }
};

int main() {
    fastio;
    
    int T; cin >> T;
    Trie *root = new Trie();
    while (T--) {
        int N; cin >> N;
        vector<string> tmp;
        while (N--) {
            string str; cin >> str;
            tmp.push_back(str);
        }
        root->insert(tmp);
    }
    root->getResult(0);
    delete root;
    return 0;
}