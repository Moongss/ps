#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
char arr[50][50];

int odd_dx[] = {-1, 0, 1, 1, 0, -1};
int odd_dy[] = {-1, -1, -1, 0, 1, 0};
int even_dx[] = {-1, 0, 1, 1, 0, -1};
int even_dy[] = {0, -1, 0, 1, 1, 1};

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == '.') continue;
            for (int k = 0; k < 6; k++) {
                int nx = i + (i % 2 ? even_dx[k] : odd_dx[k]);
                int ny = j + (i % 2 ? even_dy[k] : odd_dy[k]);
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (arr[nx][ny] == '.') ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}