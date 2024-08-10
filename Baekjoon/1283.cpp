#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

// 앞글자만 처리해서 맞다면 -> 그거 출력
// 아니면 -> 순서대로 돌면서 출력.
bool cnt[26];

bool f(string &str) {
    bool c = true;
    vector<char> v;

    for (auto &x : str) {
        if (c) {
            if (x >= 'a' && x <= 'z' && !cnt[x - 'a'] ||
                x >= 'A' && x <= 'Z' && !cnt[x - 'A']) {
                v.push_back(x);
            } 
            c = false;
        }
        else if (x == ' ') c = true;
    }

    for (auto &x : v) {
        if (x >= 'a' && x <= 'z' && !cnt[x - 'a']) return true;
        if (x >= 'A' && x <= 'Z' && !cnt[x - 'A']) return true;
    }
    return false;
}

string getResult(string &str) {
    bool f = false;

    string ret = "";
    for (auto &x : str) {
        if (!f) {
            if (x >= 'a' && x <= 'z' && !cnt[x - 'a'] ||
                x >= 'A' && x <= 'Z' && !cnt[x - 'A']) {
                ret += "[", ret += x, ret += "]", f = true;
                if (x <= 'Z') cnt[x - 'A'] = true;
                else cnt[x - 'a'] = true;
            }
            else ret += x;
        }
        else ret += x;
    }
    return ret;
}

int main() {
    fastio;
    
    int N; cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string str; getline(cin, str);
        if (f(str)) {
            bool c = true;
            for (int i = 0; i < str.length(); i++) {
                if (c) {
                    if (str[i] >= 'a' && str[i] <= 'z' && !cnt[str[i] - 'a'] ||
                        str[i] >= 'A' && str[i] <= 'Z' && !cnt[str[i] - 'A']) {
                        if (str[i] <= 'Z') cnt[str[i] - 'A'] = true;
                        else cnt[str[i] - 'a'] = true;
                        
                        cout << str.substr(0, i);
                        cout << "[" << str[i] << "]";
                        cout << str.substr(i + 1) << endl;
                        break;
                    } 
                    c = false;
                } 
                else if (str[i] == ' ') c = true;
            }
        } else {
            cout << getResult(str) << endl;
        }
    }
    return 0;
}