#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

// 단어 cnt 세고
// 각 퍼즐 알파벳 들어오면 따로 카운트해서
// 단어에 있는 알파벳이 퍼즐 개수보다 많거나 같은지 확인 -> flag체크
// flag true면, 알파벳 카운트 하기
int cnt[200000][26];
int puzzleCnt[26];
map<char, int> m;

int main() {
    fastio;
    
    int wordNum = 0;
    while (true) {
        string word; cin >> word; 
        if (word == "-") break;

        for (auto &c : word) cnt[wordNum][c - 'A']++;
        wordNum++;
    }

    while (true) {
        m.clear();
        memset(puzzleCnt, 0, sizeof(puzzleCnt));
        string puzzle; cin >> puzzle;
        if (puzzle == "#") break;

        for (auto &c : puzzle) {
            puzzleCnt[c - 'A']++;
        }

        for (auto &c : "ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
            m[c] = 0;
        }

        for (int i = 0; i < wordNum; i++) {
            bool flag = true;
            for (int j = 0; j < 26; j++) {
                if (cnt[i][j] > puzzleCnt[j]) {
                    flag = false;
                    break;
                } 
            }

            if (flag) {
                for (int j = 0; j < 26; j++) {
                    if (cnt[i][j] && puzzleCnt[j]) {
                        m[(char)('A' + j)]++;
                    }
                }
            }
        }

        int mmin = 42424242;
        int mmax = 0;
        for (int i = 0; i < 26; i++) {
            if (puzzleCnt[i]) {
                mmin = min(mmin, m[(char)('A' + i)]);
                mmax = max(mmax, m[(char)('A' + i)]);
            }
        }

        for (int i = 0; i < 26; i++) {
            if (puzzleCnt[i] && m[(char)('A' + i)] == mmin) {
                cout << (char)('A' + i);
            }
        }
        cout << " " << mmin << " ";
        for (int i = 0; i < 26; i++) {
            if (puzzleCnt[i] && m[(char)('A' + i)] == mmax) {
                cout << (char)('A' + i);
            }
        }
        cout << " " << mmax << endl;
    }
    return 0;
}