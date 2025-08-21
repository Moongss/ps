#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int score[101];
int personIdx[101];
int getScore[101];

int main() {
    fastio;
    
    int N, M; cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> score[i];
    }

    int resultIdx = 0;
    int minScore = -1;
    for (int i = 1; i <= M; i++) {
        cin >> personIdx[i];
        for (int j = 1; j <= N; j++) {
            char tmp; cin >> tmp;
            if (tmp == 'O') getScore[i] += score[j];
        }

        if (minScore < getScore[i]) {
            minScore = getScore[i];
            resultIdx = personIdx[i];
        } else if (minScore == getScore[i]) {
            resultIdx = min(resultIdx, personIdx[i]);
        }
     }
     cout << resultIdx << " " << minScore << endl;
    return 0;
}